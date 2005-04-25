/*
 * Torque IDE -- An open source integrated development environment for the
 *   Torque Game Engine
 *
 * Copyright (C) 2005 Robert Pierce
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

// For compilers that support precompilation, includes "wx/wx.h"
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include <wx/config.h>
#include <wx/filedlg.h>
#include <wx/filename.h>
#include <wx/notebook.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/image.h>

// For Windows and OS/2, icon is a resource.
#if defined(__WXGTK__) || defined(__WXMOTIF__) || defined(__WXMAC__) || defined(__WXMGL__) || defined(__WXX11__)
    #include "torque.xpm"
#endif

#define TORQUEIDE_VER _T("0.2 Alpha") // The current version of the torque-ide using the wxWidgets "_T" macro
#define TORQUEIDE_BUILD __DATE__ // The build date, set to the current date.

#include "torqueideframe.h"
#include "torqueideabout.h"
#include "torqueidestc.h"

TorqueIDEFrame::TorqueIDEFrame(const wxString &title) : wxFrame ((wxFrame *)NULL, wxID_ANY, title, wxDefaultPosition, wxSize(750,550), wxDEFAULT_FRAME_STYLE | wxNO_FULL_REPAINT_ON_RESIZE)
{
	/* Anyone care to try and get the wxNotebook to work?
	panel = new wxPanel(this, MAIN_PANEL);
	notebook = new wxNotebook(this, MAIN_NOTEBOOK);
	CreateEditPage(notebook);
	*/
	
	scintilla = new TorqueIDESTC(this);
	
	/**
	 * Scintilla initialization
	 */
	// Margin for line numbers
	scintilla->SetMarginWidth(0, 30);        // turn on the linenumbers margin, set width to 30pixels
	scintilla->SetMarginWidth(1, 0);            // turn off the folding margin
	scintilla->SetMarginType(0, 1);            // set margin type to linenumbers
	
	// Give the app our icon
	SetIcon(wxIcon("torque")); // Does this mess with cross-platform abilities?
	
	// StatusBar
	InitStatusBar();
	
	// ToolBar
	InitToolBar();

	// Menu
	InitMenu();
}

TorqueIDEFrame::~TorqueIDEFrame()
{
}

/**
 * Construct new edit control tab
 */
void CreateEditPage(wxNotebook *parent)
{
    TorqueIDESTC *scintilla = new TorqueIDESTC(parent);
    
    /**
     * Scintilla initialization
     */
    // Margin for line numbers
	scintilla->SetMarginWidth(0, 30);        // turn on the linenumbers margin, set width to 30pixels
	scintilla->SetMarginWidth(1, 0);            // turn off the folding margin
	scintilla->SetMarginType(0, 1);            // set margin type to linenumbers
	
	parent->AddPage(scintilla, "untitled", true);
}

/**
 * Construct MenuBar and Menus
 */
void TorqueIDEFrame::InitMenu()
{
	wxMenu *menu_file;
	wxMenu *menu_edit;
	wxMenu *menu_search;
	wxMenu *menu_help;
	
	menuBar = new wxMenuBar();
	
	// File
	menu_file = new wxMenu();
	menu_file->Append(MENU_FILE_NEW, _("&New"), _("Creates a new document"));
	menu_file->Append(MENU_FILE_OPEN, _("&Open"), _("Opens an existing document"));
	menu_file->Append(MENU_FILE_SAVE, _("&Save"), _("Saves the document"));
	menu_file->Append(MENU_FILE_SAVEAS, _("Save &As"), _("Saves the document with a new name"));
	menu_file->AppendSeparator();
	menu_file->Append(MENU_FILE_QUIT, _("&Quit"), _("Quits the application; prompts to save documents"));
	menuBar->Append(menu_file, _("&File"));
	
	// Edit
	menu_edit = new wxMenu();
	menu_edit->Append(MENU_EDIT_UNDO, _("&Undo"), _("Undoes the last action"));
	menu_edit->Append(MENU_EDIT_REDO, _("&Redo"), _("Redoes the previously undone action"));
	menu_edit->AppendSeparator();
	menu_edit->Append(MENU_EDIT_CUT, _("Cu&t"), _("Cuts the selection and moves it to the clipboard"));
	menu_edit->Append(MENU_EDIT_COPY, _("&Copy"), _("Copies the selection to the clipboard"));
	menu_edit->Append(MENU_EDIT_PASTE, _("&Paste"), _("Inserts the clipboard contents at the insertion point"));
	menu_edit->AppendSeparator();
	menu_edit->Append(MENU_EDIT_CLEAR, _("C&lear"), _("Clears the selection"));
	menu_edit->Append(MENU_EDIT_SELECTALL, _("Select A&ll"), _("Selects the entire document"));
	menu_edit->Append(MENU_EDIT_SELECTLINE, _("Select Lin&e"), _("Selects the current line"));
	menuBar->Append(menu_edit, _("&Edit"));
	
	// Search
	menu_search = new wxMenu();
	menu_search->Append(MENU_SEARCH_FIND, _("&Find"), _("Finds the specified text"));
	menu_search->Append(MENU_SEARCH_FINDNEXT, _("Find &Next"), _("Finds the next occurence of the specified text"));
	menu_search->Append(MENU_SEARCH_REPLACE, _("&Replace"), _("Replaces the specified text with different text"));
	menu_search->Append(MENU_SEARCH_REPLACENEXT, _("R&eplace Next"), _("Replaces the next occurence of the specified text"));
	menu_search->AppendSeparator();
	menu_search->Append(MENU_SEARCH_GOTO, _("&Goto"), _("Goto the specified line"));
	menuBar->Append(menu_search, _("&Search"));
	
	// Help
	menu_help = new wxMenu();
	menu_help->Append(MENU_HELP_ABOUT, _("&About"), _("Displays the program information and copyright"));
	menu_help->AppendSeparator();
	menu_help->Append(MENU_HELP_HELP, _("&Help"), _("Displays the online documentation"));
	menuBar->Append(menu_help, _("&Help"));

	SetMenuBar(menuBar); // Make this the TorqueIDE's menubar
	
	menuBar = menuBar;
}

/**
 * Construct ToolBar and Buttons
 */
void TorqueIDEFrame::InitToolBar()
{
	toolBar = CreateToolBar(wxNO_BORDER | wxTB_HORIZONTAL | wxTB_3DBUTTONS);
}

/**
 * Construct StatusBar
 */
void TorqueIDEFrame::InitStatusBar()
{
	statusBar = CreateStatusBar(2);
}

/**
 * Events and Event Handlers
 */
BEGIN_EVENT_TABLE(TorqueIDEFrame, wxFrame)
	/**
	 * Menu Events
	 */
	// File
	EVT_MENU(MENU_FILE_NEW, TorqueIDEFrame::OnMenuFileNew)
	EVT_MENU(MENU_FILE_OPEN, TorqueIDEFrame::OnMenuFileOpen)
	EVT_MENU(MENU_FILE_SAVE, TorqueIDEFrame::OnMenuFileSave)
	EVT_MENU(MENU_FILE_SAVEAS, TorqueIDEFrame::OnMenuFileSaveAs)
	EVT_MENU(MENU_FILE_QUIT, TorqueIDEFrame::OnMenuFileQuit)
	// Edit
	EVT_MENU(MENU_EDIT_UNDO, TorqueIDEFrame::OnMenuEditUndo)
	EVT_MENU(MENU_EDIT_REDO, TorqueIDEFrame::OnMenuEditRedo)
	EVT_MENU(MENU_EDIT_CUT, TorqueIDEFrame::OnMenuEditCut)
	EVT_MENU(MENU_EDIT_COPY, TorqueIDEFrame::OnMenuEditCopy)
	EVT_MENU(MENU_EDIT_PASTE, TorqueIDEFrame::OnMenuEditPaste)
	EVT_MENU(MENU_EDIT_CLEAR, TorqueIDEFrame::OnMenuEditClear)
	EVT_MENU(MENU_EDIT_SELECTALL, TorqueIDEFrame::OnMenuEditSelectAll)
	EVT_MENU(MENU_EDIT_SELECTLINE, TorqueIDEFrame::OnMenuEditSelectLine)
	// Search
	EVT_MENU(MENU_SEARCH_FIND, TorqueIDEFrame::OnMenuSearchFind)
	EVT_MENU(MENU_SEARCH_FINDNEXT, TorqueIDEFrame::OnMenuSearchFindNext)
	EVT_MENU(MENU_SEARCH_REPLACE, TorqueIDEFrame::OnMenuSearchReplace)
	EVT_MENU(MENU_SEARCH_REPLACENEXT, TorqueIDEFrame::OnMenuSearchReplaceNext)
	EVT_MENU(MENU_SEARCH_GOTO, TorqueIDEFrame::OnMenuSearchGoto)
	// Help
	EVT_MENU(MENU_HELP_HELP, TorqueIDEFrame::OnMenuHelpHelp)
	EVT_MENU(MENU_HELP_ABOUT, TorqueIDEFrame::OnMenuHelpAbout)
	/**
	 * Notebook Events
	 */
	EVT_NOTEBOOK_PAGE_CHANGED(MAIN_NOTEBOOK, TorqueIDEFrame::OnNotebook)
	EVT_NOTEBOOK_PAGE_CHANGING(MAIN_NOTEBOOK, TorqueIDEFrame::OnNotebook)
END_EVENT_TABLE()

/**
 * Menu Events
 */
void TorqueIDEFrame::OnMenuFileNew(wxCommandEvent &event)
{
	CreateEditPage(notebook);
}

void TorqueIDEFrame::OnMenuFileOpen(wxCommandEvent &event)
{
	wxFileDialog *dlg = new wxFileDialog(this, _("Open"), "", "", _("TorqueSCRIPT Files(*.cs, *.gui, *.mis)|*.cs;*.gui;*.mis|All files(*.*)|*.*"), wxOPEN, wxDefaultPosition);
	if(dlg->ShowModal() == wxID_OK)
	{
//		scintilla->LoadFile(dlg->GetPath());
		SetStatusText(dlg->GetFilename(), 1);
	}
	dlg->Destroy();
}

void TorqueIDEFrame::OnMenuFileSave(wxCommandEvent &event)
{
/*
	if(scintilla->GetModify())
	{
		scintilla->SaveFile();
		scintilla->SetSavePoint();
	}
*/
}

void TorqueIDEFrame::OnMenuFileSaveAs(wxCommandEvent &event)
{
	wxFileDialog *dlg = new wxFileDialog(this, _("Save As"), "", "", _("TorqueSCRIPT Files(*.cs)|*.cs|All files(*.*)|*.*"), wxSAVE, wxDefaultPosition);
	if(dlg->ShowModal() == wxID_OK)
	{
		scintilla->SaveFile(dlg->GetPath());
		scintilla->SetSavePoint();
		
		SetStatusText(dlg->GetPath(), 1); // GetFilename for just the filename
	}
	dlg->Destroy();
}

void TorqueIDEFrame::OnMenuFileQuit(wxCommandEvent &event)
{
	if(!scintilla->GetModify())
	{
		Close(FALSE);

}

void TorqueIDEFrame::OnMenuEditUndo(wxCommandEvent &event)
{
	if(scintilla->CanUndo())
	{
		scintilla->Undo();
	}
	else
	{
		wxBell();
	}
}

void TorqueIDEFrame::OnMenuEditRedo(wxCommandEvent &event)
{
	if(scintilla->CanRedo())
	{
		scintilla->Redo();
	}
	else
	{
		wxBell();
	}
}

void TorqueIDEFrame::OnMenuEditCut(wxCommandEvent &event)
{
	scintilla->Cut();
}

void TorqueIDEFrame::OnMenuEditCopy(wxCommandEvent &event)
{
	scintilla->Copy();
}

void TorqueIDEFrame::OnMenuEditPaste(wxCommandEvent &event)
{
	if(scintilla->CanPaste())
	{
		scintilla->Paste();
	}
	else
	{
		wxBell();
	}
}

void TorqueIDEFrame::OnMenuEditClear(wxCommandEvent &event)
{
	scintilla->Clear();
}

void TorqueIDEFrame::OnMenuEditSelectAll(wxCommandEvent &event)
{
	scintilla->SelectAll();
}

void TorqueIDEFrame::OnMenuEditSelectLine(wxCommandEvent &event)
{
	int lineStart = scintilla->PositionFromLine(scintilla->GetCurrentLine());
	int lineEnd = scintilla->PositionFromLine(scintilla->GetCurrentLine() + 1);
	scintilla->SetSelection(lineStart, lineEnd);
}

void TorqueIDEFrame::OnMenuSearchFind(wxCommandEvent &event)
{
	wxBell();
}

void TorqueIDEFrame::OnMenuSearchFindNext(wxCommandEvent &event)
{
	wxBell();
}

void TorqueIDEFrame::OnMenuSearchReplace(wxCommandEvent &event)
{
	wxBell();
}

void TorqueIDEFrame::OnMenuSearchReplaceNext(wxCommandEvent &event)
{
	wxBell();
}

void TorqueIDEFrame::OnMenuSearchGoto(wxCommandEvent &event)
{
	wxBell();
}

void TorqueIDEFrame::OnMenuHelpHelp(wxCommandEvent &event)
{
	wxBell();
}

void TorqueIDEFrame::OnMenuHelpAbout(wxCommandEvent &event)
{
	TorqueIDEAbout *dlg = new TorqueIDEAbout(this);
	dlg->SetText(_("Torque IDE\nAn Open Source Project\nReleased under the GPL v2\n\nTiff Support is:\nCopyright (c) 1988-1997 Sam Leffler\nCopyright (c) 1991-1997 Silicon Graphics, Inc.\n\nThis software is based in part on the work of the Independent JPEG Group\n\nVersion: ${TORQUEIDE_VER}\nBuilt on: ${TORQUEIDE_BUILD}"));
	dlg->ShowModal();
}

/**
 * GUI Events
 */
void TorqueIDEFrame::OnNotebook(wxNotebookEvent &event)
{
	event;
}