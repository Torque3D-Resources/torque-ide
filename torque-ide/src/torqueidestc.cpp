/*
 * Torque IDE -- An open source integrated development environment for the
 *   Torque Game Engine
 *
 * Copyright (C) 2005 Robert Pierce
 ** Adapted from wxWidgets STC example
 *
 * Refer to the file CONTRIB.txt for the people who have helped.
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation;
 * either version 2 of the License, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the Free
 * Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307 USA
 */

// For compilers that supports precompilation, include "wx/wx.h"
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include <wx/file.h>
#include <wx/filename.h>

#include "torqueidestc.h"

TorqueIDESTC::TorqueIDESTC(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size, long style)
	: wxStyledTextCtrl(parent, id, pos, size, style)
{
    filename = _T("");

    lineNumID = 0;
    dividerID = 1;
    foldingID = 2;

    // initialize language
    language = NULL;

    // default font for all styles
    SetViewEOL(commonPrefs.displayEOLEnable);
    SetIndentationGuides(commonPrefs.indentGuideEnable);
    SetEdgeMode(commonPrefs.longLineOnEnable? wxSTC_EDGE_LINE: wxSTC_EDGE_NONE);
    SetViewWhiteSpace(commonPrefs.whiteSpaceEnable? wxSTC_WS_VISIBLEALWAYS: wxSTC_WS_INVISIBLE);
    SetOvertype(commonPrefs.overTypeInitial);
    SetReadOnly(commonPrefs.readOnlyInitial);
    SetWrapMode(commonPrefs.wrapModeInitial? wxSTC_WRAP_WORD: wxSTC_WRAP_NONE);
    wxFont font(10, wxMODERN, wxNORMAL, wxNORMAL);
    StyleSetFont(wxSTC_STYLE_DEFAULT, font);
    StyleSetForeground(wxSTC_STYLE_DEFAULT, wxColour (_T("BLACK")));
    StyleSetBackground(wxSTC_STYLE_DEFAULT, wxColour (_T("WHITE")));
    StyleSetForeground(wxSTC_STYLE_LINENUMBER, wxColour (_T("DARK GREY")));
    StyleSetBackground(wxSTC_STYLE_LINENUMBER, wxColour (_T("WHITE")));
    StyleSetForeground(wxSTC_STYLE_INDENTGUIDE, wxColour (_T("DARK GREY")));
    InitializePrefs(DEFAULT_LANGUAGE);

    // set visibility
    SetVisiblePolicy(wxSTC_VISIBLE_STRICT|wxSTC_VISIBLE_SLOP, 1);
    SetXCaretPolicy(wxSTC_CARET_EVEN|wxSTC_VISIBLE_STRICT|wxSTC_CARET_SLOP, 1);
    SetYCaretPolicy(wxSTC_CARET_EVEN|wxSTC_VISIBLE_STRICT|wxSTC_CARET_SLOP, 1);

    // markers
    MarkerDefine(wxSTC_MARKNUM_FOLDER, wxSTC_MARK_DOTDOTDOT, _T("BLACK"), _T("BLACK"));
    MarkerDefine(wxSTC_MARKNUM_FOLDEROPEN, wxSTC_MARK_ARROWDOWN, _T("BLACK"), _T("BLACK"));
    MarkerDefine(wxSTC_MARKNUM_FOLDERSUB, wxSTC_MARK_EMPTY,     _T("BLACK"), _T("BLACK"));
    MarkerDefine(wxSTC_MARKNUM_FOLDEREND, wxSTC_MARK_DOTDOTDOT, _T("BLACK"), _T("WHITE"));
    MarkerDefine(wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_ARROWDOWN, _T("BLACK"), _T("WHITE"));
    MarkerDefine(wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_EMPTY,     _T("BLACK"), _T("BLACK"));
    MarkerDefine(wxSTC_MARKNUM_FOLDERTAIL, wxSTC_MARK_EMPTY,     _T("BLACK"), _T("BLACK"));

    // miscelaneous
    lineNumMargin = TextWidth(wxSTC_STYLE_LINENUMBER, _T("_999999"));
    foldingMargin = 16;
    CmdKeyClear(wxSTC_KEY_TAB, 0); // this is done by the menu accelerator key
    SetLayoutCache(wxSTC_CACHE_PAGE);
}

TorqueIDESTC::~TorqueIDESTC()
{
}

wxString TorqueIDESTC::DeterminePrefs(const wxString &file) 
{
	LanguageInfo const* curInfo;

	// Determine Language Filepatterns
	int languageNum;
	for (languageNum = 0; languageNum < languagePrefsSize; languageNum++) {
		curInfo = &languagePrefs[languageNum];
		wxString filepattern = curInfo->filepattern;
		filepattern.Lower();
		while (!filepattern.IsEmpty()) {
			wxString cur = filepattern.BeforeFirst (';');
			if ((cur == file) || (cur == (file.BeforeLast ('.') + _T(".*"))) || (cur == (_T("*.") + file.AfterLast ('.')))) 
			{
				return curInfo->name;
			}
			filepattern = filepattern.AfterFirst (';');
		}
	}
	return wxEmptyString;
}

bool TorqueIDESTC::InitializePrefs (const wxString &name) 
{
	// Init Styles
	StyleClearAll();
	LanguageInfo const* curInfo = NULL;

	// Determine Language
	bool found = false;
	int languageNum;
	for(languageNum = 0; languageNum < languagePrefsSize; languageNum++) {
		curInfo = &languagePrefs[languageNum];
		if (curInfo->name == name) {
			found = true;
			break;
		}
	}
	if(!found)
	{
		return false;
	}
	
	// Set Lexer and Language
	SetLexer(curInfo->lexer);
	language = curInfo;

	// Set Margin for Line Numbers
	SetMarginType(lineNumID, wxSTC_MARGIN_NUMBER);
	StyleSetForeground(wxSTC_STYLE_LINENUMBER, wxColour(_T("DARK GREY")));
	StyleSetBackground(wxSTC_STYLE_LINENUMBER, wxColour(_T("WHITE")));
    SetMarginWidth(lineNumID, 0); // Start out invisible

	// Default Fonts for Styles
	int Num;
	for(Num = 0; Num < wxSTC_STYLE_LASTPREDEFINED; Num++) {
		wxFont font(10, wxMODERN, wxNORMAL, wxNORMAL);
		StyleSetFont(Num, font);
	}

	// Set Common Styles
	StyleSetForeground(wxSTC_STYLE_DEFAULT, wxColour (_T("DARK GREY")));
	StyleSetForeground(wxSTC_STYLE_INDENTGUIDE, wxColour (_T("DARK GREY")));
	
    // Init Settings
	if(commonPrefs.syntaxEnable) {
		int keywordNum = 0;
		for(Num = 0; Num < STYLE_TYPES_COUNT; Num++) {
			if(curInfo->styles[Num].type == -1) continue;
			const StyleInfo &curType = stylePrefs [curInfo->styles[Num].type];
            wxFont font(curType.fontsize, wxMODERN, wxNORMAL, wxNORMAL, false, curType.fontname);
			StyleSetFont(Num, font);
			if(curType.foreground) {
				StyleSetForeground(Num, wxColour (curType.foreground));
			}
			if(curType.background) {
				StyleSetBackground(Num, wxColour (curType.background));
			}
			StyleSetBold(Num, (curType.fontstyle & TORQUEIDESTC_STYLE_BOLD) > 0);
			StyleSetItalic(Num, (curType.fontstyle & TORQUEIDESTC_STYLE_ITALIC) > 0);
			StyleSetUnderline(Num, (curType.fontstyle & TORQUEIDESTC_STYLE_UNDERL) > 0);
			StyleSetVisible(Num, (curType.fontstyle & TORQUEIDESTC_STYLE_HIDDEN) == 0);
			StyleSetCase(Num, curType.lettercase);
			const wxChar *pwords = curInfo->styles[Num].words;
			if(pwords) {
				SetKeyWords(keywordNum, pwords);
				keywordNum += 1;
			}
		}
	}

	// Set Margin as unused
	SetMarginType(dividerID, wxSTC_MARGIN_SYMBOL);
	SetMarginWidth(dividerID, 0);
	SetMarginSensitive(dividerID, false);

	// Folding
	SetMarginType(foldingID, wxSTC_MARGIN_SYMBOL);
	SetMarginMask(foldingID, wxSTC_MASK_FOLDERS);
	StyleSetBackground(foldingID, wxColour (_T("WHITE")));
	SetMarginWidth(foldingID, 0);
	SetMarginSensitive(foldingID, false);
	if (commonPrefs.foldEnable) {
		SetMarginWidth(foldingID, curInfo->folds != 0? foldingMargin: 0);
		SetMarginSensitive(foldingID, curInfo->folds != 0);
		SetProperty(_T("fold"), curInfo->folds != 0? _T("1"): _T("0"));
		SetProperty(_T("fold.comment"), (curInfo->folds & TORQUEIDESTC_FOLD_COMMENT) > 0? _T("1"): _T("0"));
		SetProperty(_T("fold.compact"), (curInfo->folds & TORQUEIDESTC_FOLD_COMPACT) > 0? _T("1"): _T("0"));
		SetProperty(_T("fold.preprocessor"), (curInfo->folds & TORQUEIDESTC_FOLD_PREPROC) > 0? _T("1"): _T("0"));
		SetProperty(_T("fold.html"), (curInfo->folds & TORQUEIDESTC_FOLD_HTML) > 0? _T("1"): _T("0"));
		SetProperty(_T("fold.html.preprocessor"), (curInfo->folds & TORQUEIDESTC_FOLD_HTMLPREP) > 0? _T("1"): _T("0"));
		SetProperty(_T("fold.comment.python"), (curInfo->folds & TORQUEIDESTC_FOLD_COMMENTPY) > 0? _T("1"): _T("0"));
		SetProperty(_T("fold.quotes.python"), (curInfo->folds & TORQUEIDESTC_FOLD_QUOTESPY) > 0? _T("1"): _T("0"));
	}
	SetFoldFlags(wxSTC_FOLDFLAG_LINEBEFORE_CONTRACTED | wxSTC_FOLDFLAG_LINEAFTER_CONTRACTED);

    // Set Tabs and Indentation
	SetTabWidth(4);
	SetUseTabs(true);
	SetTabIndents(true);
	SetBackSpaceUnIndents(true);
	SetIndent(commonPrefs.indentEnable? 4: 0);

    // Others
	SetViewEOL(commonPrefs.displayEOLEnable);
	SetIndentationGuides(commonPrefs.indentGuideEnable);
	SetEdgeColumn(80);
	SetEdgeMode(commonPrefs.longLineOnEnable? wxSTC_EDGE_LINE: wxSTC_EDGE_NONE);
	SetViewWhiteSpace(commonPrefs.whiteSpaceEnable? wxSTC_WS_VISIBLEALWAYS: wxSTC_WS_INVISIBLE);
	SetOvertype(commonPrefs.overTypeInitial);
	SetReadOnly(commonPrefs.readOnlyInitial);
	SetWrapMode(commonPrefs.wrapModeInitial? wxSTC_WRAP_WORD: wxSTC_WRAP_NONE);

	return true;
}

bool TorqueIDESTC::LoadFile() 
{
	// Get Filename
	if (!filename) 
	{
		wxFileDialog dlg (this, _T("Open file"), _T(""), _T(""), _T("Any file (*)|*"), wxOPEN | wxFILE_MUST_EXIST | wxCHANGE_DIR);
		if (dlg.ShowModal() != wxID_OK) return false;
		filename = dlg.GetPath();
	}
	
	// Load File
	return LoadFile(filename);
}

bool TorqueIDESTC::LoadFile(const wxString &file) 
{
	// Load File and clear undo
	if (!file.IsEmpty())
	{
		filename = file;
	}
//	wxFile file(filename);
//	if (!file.IsOpened()) return false;
	ClearAll();
//	long lng = file.Length ();
//	if (lng > 0) {
//		wxString buf;
//		wxChar *buff = buf.GetWriteBuf (lng);
//		file.Read (buff, lng);
//		buf.UngetWriteBuf ();
//		InsertText (0, buf);
//	}
//	file.Close();

	wxStyledTextCtrl::LoadFile(file);

	EmptyUndoBuffer();

    // Determine Lexer Language
    wxFileName fname(file);
	InitializePrefs(DeterminePrefs(fname.GetFullName()));
	
	return true;
}

bool TorqueIDESTC::SaveFile() 
{
    // return if no change
    if (!Modified()) return true;

	// Get Filename
	if (!filename) {
		wxFileDialog dlg (this, _T("Save file"), _T(""), _T(""), _T("Any file (*)|*"), wxSAVE | wxOVERWRITE_PROMPT);
		if (dlg.ShowModal() != wxID_OK) return false;
		filename = dlg.GetPath();
	}

	// Save File
	return SaveFile(filename);
}

bool TorqueIDESTC::SaveFile(const wxString &file) 
{
	// return if no change
	if (!Modified()) return true;

//	// Save file and clear undo
//	if (!filename.IsEmpty()) m_filename = filename;
//	wxFile file (m_filename, wxFile::write);
//	if (!file.IsOpened()) return false;
//	wxString buf = GetText();
//	bool okay = file.Write (buf);
//	file.Close();
//	if (!okay) return false;
//	EmptyUndoBuffer();
//	SetSavePoint();

//     return true;

	return wxStyledTextCtrl::SaveFile(file);
}

bool TorqueIDESTC::Modified () 
{
	// Return Modified State

	return(GetModify() && !GetReadOnly());
}

/**
 * Events and Event Handlers
 */
BEGIN_EVENT_TABLE(TorqueIDESTC, wxStyledTextCtrl)
	EVT_SIZE(TorqueIDESTC::OnSize)
    EVT_STC_MARGINCLICK(wxID_ANY, TorqueIDESTC::OnMarginClick)
	EVT_STC_CHARADDED(wxID_ANY, TorqueIDESTC::OnCharAdded)
END_EVENT_TABLE()

void TorqueIDESTC::OnSize(wxSizeEvent& event) 
{
	int x = GetClientSize().x + (commonPrefs.lineNumberEnable? lineNumMargin: 0) + (commonPrefs.foldEnable? foldingMargin: 0);
	if (x > 0) SetScrollWidth(x);
	event.Skip();
}

void TorqueIDESTC::OnMarginClick(wxStyledTextEvent &event) {
	if(event.GetMargin() == 2) {
		int lineClick = LineFromPosition (event.GetPosition());
		int levelClick = GetFoldLevel (lineClick);
		if ((levelClick & wxSTC_FOLDLEVELHEADERFLAG) > 0) {
			ToggleFold (lineClick);
		}
	}
}

void TorqueIDESTC::OnCharAdded(wxStyledTextEvent &event) 
{
	char chr = (char)event.GetKey();
	int currentLine = GetCurrentLine();
	// Change this if support for mac files with \r is needed
	if (chr == '\n') {
		int lineInd = 0;
		if(currentLine > 0) {
			lineInd = GetLineIndentation(currentLine - 1);
		}
		if(lineInd == 0) return;
		SetLineIndentation(currentLine, lineInd);
		GotoPos(PositionFromLine (currentLine) + lineInd);
	}
}