/*
 * Torque IDE -- An open source integrated development environment for the
 *   Torque Game Engine
 *
 * Copyright (C) 2004 Robert Pierce
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
 
#ifndef __TORQUEIDE_HPP_
#define __TORQUEIDE_HPP_


#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif



////Header Include Start
////Header Include End

#include <wx/frame.h>

////GUI Control ID Start
////GUI Control ID End

////Dialog Style Start
	#define THIS_DIALOG_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxTHICK_FRAME | wxMINIMIZE_BOX | wxMAXIMIZE_BOX |  wxCLOSE_BOX
////Dialog Style End

class torque_ide_frame : public wxFrame
{
private:
    DECLARE_EVENT_TABLE()
public:
    torque_ide_frame( wxWindow *parent, wxWindowID id = 1, const wxString &title = _T("Torque IDE"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = THIS_DIALOG_STYLE);
    virtual ~torque_ide_frame();
public:
  ////GUI Control Declaration Start
  ////GUI Control Declaration End

public:
    void Close(wxCloseEvent& event);
    void CreateGUIControls(void);

};


#endif
 
 
 
 
