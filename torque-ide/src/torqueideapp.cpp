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

#include "torqueideapp.h"
#include "torqueideframe.h"

IMPLEMENT_APP(TorqueIDEApp)

bool TorqueIDEApp::OnInit()
{
	TorqueIDEFrame *frame = new TorqueIDEFrame("Torque IDE");

	frame->Layout();
	frame->Show(TRUE);

//	frame->Maximize(!frame->IsMaximized()); // If the frame is not maximized, maximize it.

	SetTopWindow(frame);


	return TRUE;
}

int TorqueIDEApp::OnExit() 
{
	// TODO: Delete special global stuff here
	return 0;
}