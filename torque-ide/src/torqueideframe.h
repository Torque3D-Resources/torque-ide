#ifndef _TORQUEIDEFRAME_H
#define _TORQUEIDEFRAME_H
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

#include <wx/frame.h>

#include "torqueidestc.h"

class TorqueIDEFrame : public wxFrame
{
	public:
		/**
		* Constructor
		*/
		TorqueIDEFrame(const wxString &title);

		/**
		* Destructor
		*/
		~TorqueIDEFrame();

		/**
		* Processes menu File|New
		*/
		void OnMenuFileNew(wxCommandEvent &event);

		/**
		* Processes menu File|Open
		*/
		void OnMenuFileOpen(wxCommandEvent &event);

		/**
		* Processes menu File|Save
		*/
		void OnMenuFileSave(wxCommandEvent &event);

		/**
		* Processes menu File|Save As
		*/
		void OnMenuFileSaveAs(wxCommandEvent &event);

		/**
		* Processes menu File|Quit
		*/
		void OnMenuFileQuit(wxCommandEvent &event);

		/**
		* Processes menu Edit|Undo
		*/
		void OnMenuEditUndo(wxCommandEvent &event);

		/**
		* Processes menu Edit|Redo
		*/
		void OnMenuEditRedo(wxCommandEvent &event);

		/**
		* Processes menu Edit|Cut
		*/
		void OnMenuEditCut(wxCommandEvent &event);

		/**
		* Processes menu Edit|Copy
		*/
		void OnMenuEditCopy(wxCommandEvent &event);

		/**
		* Processes menu Edit|Paste
		*/
		void OnMenuEditPaste(wxCommandEvent &event);

		/**
		* Processes menu Edit|Clear
		*/
		void OnMenuEditClear(wxCommandEvent &event);

		/**
		* Processes menu Edit|Select All
		*/
		void OnMenuEditSelectAll(wxCommandEvent &event);

		/**
		* Processes menu Edit|Select Line
		*/
		void OnMenuEditSelectLine(wxCommandEvent &event);

		/**
		* Processes menu Search|Find
		*/
		void OnMenuSearchFind(wxCommandEvent &event);

		/**
		* Processes menu Search|Find Next
		*/
		void OnMenuSearchFindNext(wxCommandEvent &event);

		/**
		* Processes menu Search|Replace
		*/
		void OnMenuSearchReplace(wxCommandEvent &event);

		/**
		* Processes menu Search|Replace Next
		*/
		void OnMenuSearchReplaceNext(wxCommandEvent &event);

		/**
		* Processes menu Search|Goto
		*/
		void OnMenuSearchGoto(wxCommandEvent &event);

		/**
		* Processes menu Help|About
		*/
		void OnMenuHelpAbout(wxCommandEvent &event);

		/**
		* Processes menu Help|Help
		*/
		void OnMenuHelpHelp(wxCommandEvent &event);

	protected:
		DECLARE_EVENT_TABLE()

	private:
		// Editor
		TorqueIDESTC *scintilla;
		
		// Statusbar
		wxStatusBar *statusbar;
		void InitStatusBar();
		
		// Toolbar
		wxToolBar *toolbar;
		void InitToolBar();
		
		// Menu
		wxMenuBar *menubar;
		void InitMenu();

	enum
	{
		// File
		MENU_FILE_NEW,
		MENU_FILE_OPEN,
		MENU_FILE_SAVE,
		MENU_FILE_SAVEAS,
		MENU_FILE_QUIT,
		// Edit
		MENU_EDIT_UNDO,
		MENU_EDIT_REDO,
		MENU_EDIT_CUT,
		MENU_EDIT_COPY,
		MENU_EDIT_PASTE,
		MENU_EDIT_CLEAR,
		MENU_EDIT_SELECTALL,
		MENU_EDIT_SELECTLINE,
		// Search
		MENU_SEARCH_FIND,
		MENU_SEARCH_FINDNEXT,
		MENU_SEARCH_REPLACE,
		MENU_SEARCH_REPLACENEXT,
		MENU_SEARCH_GOTO,
		// Help
		MENU_HELP_ABOUT,
		MENU_HELP_HELP
	};
};

#endif _TORQUEIDEFRAME_H
