/*
 * Torque IDE -- An open source integrated development editor for the
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
 
#include "torque_ide.h"
#include "torque_ide_frame.h"

IMPLEMENT_APP(torque_ide)

bool torque_ide::OnInit()
{
	torque_ide_frame *main_frame = new  torque_ide_frame(NULL);
	SetTopWindow(main_frame);
	main_frame->Show(TRUE);		
	return TRUE;
}
 
int torque_ide::OnExit()
{
	return 0;
}
