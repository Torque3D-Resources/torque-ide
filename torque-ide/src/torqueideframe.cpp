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

#define TORQUEIDE_VER _T("0.25 Alpha") // The current version of the torque-ide using the wxWidgets "_T" macro
#define TORQUEIDE_BUILD __DATE__ // The build date, set to the current date.

#include "torqueideframe.h"
#include "torqueideabout.h"
#include "torqueidestc.h"

TorqueIDEFrame::TorqueIDEFrame(const wxString &title) : wxFrame ((wxFrame *)NULL, wxID_ANY, title, wxDefaultPosition, wxSize(750,550), wxDEFAULT_FRAME_STYLE | wxNO_FULL_REPAINT_ON_RESIZE)
{
	scintilla = new TorqueIDESTC(this); // The other params default
	
	// StatusBar
	InitStatusBar();
	
	// ToolBar
	InitToolBar();

	// Menu
	InitMenu();

	// Margin for line numbers
	scintilla->SetMarginWidth(0, 30);        // turn on the linenumbers margin, set width to 30pixels
	scintilla->SetMarginWidth(1, 0);            // turn off the folding margin
	scintilla->SetMarginType(0, 1);            // set margin type to linenumbers
}

TorqueIDEFrame::~TorqueIDEFrame()
{
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
	
	menubar = new wxMenuBar();
	
	// File
	menu_file = new wxMenu();
	menu_file->Append(MENU_FILE_NEW, "&New", "Creates a new document");
	menu_file->Append(MENU_FILE_OPEN, "&Open", "Opens an existing document");
	menu_file->Append(MENU_FILE_SAVE, "&Save", "Saves the document");
	menu_file->Append(MENU_FILE_SAVEAS, "Save &As", "Saves the document with a new name");
	menu_file->AppendSeparator();
	menu_file->Append(MENU_FILE_QUIT, "&Quit", "Quits the application; prompts to save documents");
	menubar->Append(menu_file, "&File");
	
	// Edit
	menu_edit = new wxMenu();
	menu_edit->Append(MENU_EDIT_UNDO, "&Undo", "Undoes the last action");
	menu_edit->Append(MENU_EDIT_REDO, "&Redo", "Redoes the previously undone action");
	menu_edit->AppendSeparator();
	menu_edit->Append(MENU_EDIT_CUT, "Cu&t", "Cuts the selection and moves it to the clipboard");
	menu_edit->Append(MENU_EDIT_COPY, "&Copy", "Copies the selection to the clipboard");
	menu_edit->Append(MENU_EDIT_PASTE, "&Paste", "Inserts the clipboard contents at the insertion point");
	menu_edit->AppendSeparator();
	menu_edit->Append(MENU_EDIT_CLEAR, "C&lear", "Clears the selection");
	menu_edit->Append(MENU_EDIT_SELECTALL, "Select A&ll", "Selects the entire document");
	menu_edit->Append(MENU_EDIT_SELECTLINE, "Select Lin&e", "Selects the current line");
	menubar->Append(menu_edit, "&Edit");
	
	// Search
	menu_search = new wxMenu();
	menu_search->Append(MENU_SEARCH_FIND, "&Find", "Finds the specified text");
	menu_search->Append(MENU_SEARCH_FINDNEXT, "Find &Next", "Finds the next occurence of the specified text");
	menu_search->Append(MENU_SEARCH_REPLACE, "&Replace", "Replaces the specified text with different text");
	menu_search->Append(MENU_SEARCH_REPLACENEXT, "R&eplace Next", "Replaces the next occurence of the specified text");
	menu_search->AppendSeparator();
	menu_search->Append(MENU_SEARCH_GOTO, "&Goto", "Goto the specified line");
	menubar->Append(menu_search, "&Search");
	
	// Help
	menu_help = new wxMenu();
	menu_help->Append(MENU_HELP_ABOUT, "&About", "Displays the program information and copyright");
	menu_help->AppendSeparator();
	menu_help->Append(MENU_HELP_HELP, "&Help", "Displays the online documentation");
	menubar->Append(menu_help, "&Help");

	SetMenuBar(menubar); // Make this the TorqueIDE's menubar
}

/**
* Construct ToolBar and Buttons
*/
void TorqueIDEFrame::InitToolBar()
{
	toolbar = CreateToolBar(wxNO_BORDER | wxTB_HORIZONTAL | wxTB_3DBUTTONS);
}

/**
* Construct StatusBar
*/
void TorqueIDEFrame::InitStatusBar()
{
	statusbar = CreateStatusBar(2);
}

/**
* Events and Event Handlers
*/
BEGIN_EVENT_TABLE(TorqueIDEFrame, wxFrame)
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
END_EVENT_TABLE()

void TorqueIDEFrame::OnMenuFileNew(wxCommandEvent &event)
{
	wxBell();
}

void TorqueIDEFrame::OnMenuFileOpen(wxCommandEvent &event)
{
	wxFileDialog *dlg = new wxFileDialog(this, "Open", "", "", "TorqueSCRIPT Files(*.cs)|*.cs|All files(*.*)|*.*", wxOPEN, wxDefaultPosition);
	if(dlg->ShowModal() == wxID_OK)
	{
		scintilla->LoadFile(dlg->GetPath());
		SetStatusText(dlg->GetFilename(), 1);
	}
	dlg->Destroy();
}

void TorqueIDEFrame::OnMenuFileSave(wxCommandEvent &event)
{
	if(scintilla->GetModify())
	{
		scintilla->SaveFile();
		scintilla->SetSavePoint();
	}
}

void TorqueIDEFrame::OnMenuFileSaveAs(wxCommandEvent &event)
{
	wxFileDialog *dlg = new wxFileDialog(this, "Save As", "", "", "TorqueSCRIPT Files(*.cs)|*.cs|All files(*.*)|*.*", wxSAVE, wxDefaultPosition);
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
		return;
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
	dlg->SetText("Torque IDE\nAn Open Source Project\nReleased under the GPL v2");
	dlg->ShowModal();
}
