#ifndef _TORQUEIDESCINTILLA_H
#define _TORQUEIDESCINTILLA_H
/*
 * Torque IDE -- An open source integrated development environment for the
 *   Torque Game Engine
 *
 * Copyright (C) 2005 Robert Pierce
 **Adapted from wxWidgets STC example
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

#include <wx/stc/stc.h>

#include "torqueideprefs.h"

class TorqueIDESTC : public wxStyledTextCtrl
{
	public:
		/**
		 * Constructor
		 */
		TorqueIDESTC(wxWindow *parent, wxWindowID id = wxID_ANY, 
			const wxPoint &pos = wxDefaultPosition,
			const wxSize &size = wxDefaultSize,
			long style = wxSUNKEN_BORDER|wxVSCROLL
       		 );

		/**
		 * Destructor
		 */
		~TorqueIDESTC();
		
		// Events
		void OnSize(wxSizeEvent &event);
		void OnMarginClick(wxStyledTextEvent &event);
		void OnCharAdded(wxStyledTextEvent &event);
		
		
		// Language/Lexer
		wxString DeterminePrefs(const wxString &file);
		bool InitializePrefs(const wxString &file);
		LanguageInfo const* GetLanguageInfo() {return language;};
		
		// Loading/Saving
		bool LoadFile();
		bool LoadFile(const wxString &file);
		bool SaveFile();
		bool SaveFile(const wxString &file);
		bool Modified();
		wxString GetFilename() {return filename;};
		void SetFilename(const wxString &file) {filename = file;};
		
	private:
		wxString filename;
		
		LanguageInfo const* language;
		
		// Margin Variables
		int lineNumID;
		int lineNumMargin;
		int foldingID;
		int foldingMargin;
		int dividerID;
		
		DECLARE_EVENT_TABLE()
};

#endif _TORQUEIDESCINTILLA_H
