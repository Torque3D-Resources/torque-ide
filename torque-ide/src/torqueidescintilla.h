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

#ifndef _TORQUEIDESCINTILLA_H
#define _TORQUEIDESCINTILLA_H

#include <wx/stc/stc.h>

// TorqueSCRIPT keywords
const wxString torquescript_primary  = "break case continue datablock default else false function if for new or package return switch switch$ true and while"; // Primary TorqueSCRIPT keywords
const wxString torquescript_secondary = "dumpConsoleClasses expandFilename strcmp stricmp strlen strstr strpos ltrim rtrim trim sripChars strlwr strupr strchr strreplace getSubStr getWord getWords setWord removeWord getWordCount getField getFields setField removeField getFieldCount getRecord getRecords setRecord  removeRecord getRecordCount firstWord restWords detag getTag echo warn error expandEscape collapseEscape quit call compile exec export deleteVariables trace debug findFirstFile findNextFile getFileCount getFileCRC isFile isWriteableFileName fileExt fileBase fileName filePath nextToken setLogMode setEchoFileLoads backtrace isPackage activatePackage deactivatePackage nameToID isObject cancel isEventPending schedule"; // Secondary TorqueSCRIPT keywords

#endif _TORQUEIDESCINTILLA_H