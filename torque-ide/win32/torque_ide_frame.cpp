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

#ifdef __GNUG__
    #pragma implementation "torque_ide_frame.cpp"
#endif

/* for compilers that support precompilation
   includes "wx/wx.h" */

#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif


#include "torque_ide_frame.h"

////Header Include Start
////Header Include End


//----------------------------------------------------------------------------
// torque_ide_frame
//----------------------------------------------------------------------------

    ////Event Table Start
BEGIN_EVENT_TABLE(torque_ide_frame,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(torque_ide_frame::Close)
END_EVENT_TABLE()
    ////Event Table End



torque_ide_frame::torque_ide_frame( wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style )
    : wxFrame( parent, id, title, position, size, style)
{
    CreateGUIControls();
}

torque_ide_frame::~torque_ide_frame()
{
    
} 

void torque_ide_frame::CreateGUIControls(void)
{
    ////GUI Items Creation Start

	this->SetSize(8,8,324,334);
	this->SetTitle(_("Torque IDE"));
	this->Center();
	this->SetIcon(wxNullIcon);
	
    ////GUI Items Creation End
}

void torque_ide_frame::Close(wxCloseEvent& event)
{
    // --> Don't use Close with a Frame,
    // use Destroy instead.
    Destroy();
}
 
