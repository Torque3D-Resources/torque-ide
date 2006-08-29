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
 
// For compilers that supports precompilation, include "wx/wx.h"
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include "torqueideabout.h"

TorqueIDEAbout::TorqueIDEAbout(wxWindow *parent) 
	: wxDialog(parent, -1, _("About the Torque IDE"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE)
{
	SetAutoLayout(TRUE);
	
	wxLayoutConstraints *layout = new wxLayoutConstraints();
	layout->top.SameAs(this, wxTop, 10);
	layout->centreX.SameAs(this, wxCentreX);
	layout->width.AsIs();
	layout->height.AsIs();
	
	aboutText = new wxStaticText(this, -1, _(""), wxPoint(-1, -1), wxDefaultSize, wxALIGN_CENTER);
	aboutText->SetConstraints(layout);
	
	layout = new wxLayoutConstraints();
	layout->top.Below(aboutText, 10);
	layout->centreX.SameAs(this, wxCentreX);
	layout->width.PercentOf(this, wxWidth, 80);
	layout->height.AsIs();
	
	ok = new wxButton(this, wxID_OK, _("Ok"), wxPoint(-1, -1));
	ok->SetConstraints(layout);
	
	Layout();
}

void TorqueIDEAbout::SetText(const wxString& text)
{
	aboutText->SetLabel(text);
	
	Layout(); // This command could have messed with the layout, so redo.
}
