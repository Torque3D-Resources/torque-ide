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

// For compilers that support precompilation, includes "wx/wx.h"
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include "torqueideframe.h"

TorqueIDEFrame::TorqueIDEFrame(const wxChar *title) : wxFrame((wxFrame *) NULL, -1, title)
{
	scintilla = new wxStyledTextCtrl(this, -1);  // Scintilla Edit
	statusbar = CreateStatusBar(2); // Creates the status bar
	toolbar = CreateToolBar(wxNO_BORDER | wxTB_HORIZONTAL | wxTB_3DBUTTONS); // Creates the toolbar
	// Menu
	menubar = new wxMenuBar();
	// File Menu
	menu_file = new wxMenu();
	menu_file->Append(MENU_FILE_NEW, "&New", "Creates a new document");
	menu_file->Append(MENU_FILE_OPEN, "&Open", "Opens an existing document");
	menu_file->Append(MENU_FILE_SAVE, "&Save", "Saves the document");
	menu_file->Append(MENU_FILE_SAVEAS, "Save &As", "Saves the document with a new name");
	menu_file->AppendSeparator();
	menu_file->Append(MENU_FILE_QUIT, "&Quit", "Quits the application; prompts to save documents");
	menubar->Append(menu_file, "&File");
	menu_edit = new wxMenu();
	menu_edit->Append(MENU_EDIT_UNDO, "&Undo", "Undoes the last action");
	menu_edit->Append(MENU_EDIT_REDO, "&Redo", "Redoes the previously undone action");
	menu_edit->AppendSeparator();
	menu_edit->Append(MENU_EDIT_CUT, "Cu&t", "Cuts the selection and moves it to the clipboard");
	menu_edit->Append(MENU_EDIT_COPY, "&Copy", "Copies the selection to the clipboard");
	menu_edit->Append(MENU_EDIT_PASTE, "&Paste", "Inserts the clipboard contents at the insertion point");
	menubar->Append(menu_edit, "&Edit");
	menu_help = new wxMenu();
	menu_help->Append(MENU_HELP_ABOUT, "&About", "Displays the program information and copyright");
	menu_help->AppendSeparator();
	menu_help->Append(MENU_HELP_HELP, "&Help", "Displays the online documentation");
	menubar->Append(menu_help, "&Help");

	SetMenuBar(menubar);

		// Scintilla initialization
	scintilla->SetLexer(wxSTC_LEX_CPP); // use the C++ lexer since TorqueSCRIPT is almost C++.
	// CPP Lexer Properties
	scintilla->SetProperty("fold.comment", "1");
	scintilla->SetProperty("fold.preprocessor", "1");
	scintilla->SetProperty("fold.compact", "1"); 
	// Line Numbers
	scintilla->SetMarginWidth(0, 30);        // turn on the linenumbers margin, set width to 30pixels
  scintilla->SetMarginWidth(1, 0);            // turn off the folding margin
  scintilla->SetMarginType(0, 1);            // set margin type to linenumbers
	// Keywords
	scintilla->SetKeyWords(0, wxT("break case continue datablock default else false function if for new or package return switch switch$ true and while"));
  scintilla->SetKeyWords(1, wxT("OpenALInitDriver OpenALShutdownDriver OpenALRegisterExtensions"
                        " alGetString alxCreateSource alxSourcef alxSource3f alxSourcei"
                        " alxGetSourcef alxGetSource3f alxGetSourcei alxPlay alxStop"
                        " alxStopAll alxIsPlaying alxListener alListener3f alxGetListenerf"
                        " alxGetListener3f alxGetListeneri alxGetChannelVolume alxSetChannelVolume"
                        " dumpConsoleClasses expandFilename strcmp stricmp strlen strstr"
                        " strpos ltrim rtrim trim sripChars strlwr strupr strchr strreplace"
                        " getSubStr getWord getWords setWord removeWord getWordCount"
                        " getField getFields setField removeField getFieldCount getRecord"
                        " getRecords setRecord  removeRecord getRecordCount firstWord restWords"
                        " detag getTag echo warn error expandEscape collapseEscape"
                        " quit call compile exec export deleteVariables trace debug"
                        " findFirstFile findNextFile getFileCount getFileCRC isFile"
                        " isWriteableFileName fileExt fileBase fileName filePath nextToken"
                        " setLogMode setEchoFileLoads backtrace isPackage activatePackage"
                        " deactivatePackage nameToID isObject cancel isEventPending schedule"
                        " deleteDataBlocks telnetSetParameters dbgSetParameters dnetSetLogging"
                        " setNPatch toggleNPatch increaseNPatch decreaseNPatch setFSAA"
                        " IncreaseFSAA decreaseFSAA setOpenGLMipReduction setOpenGLSkyMipReduction"
                        " setOpenGLInteriorMipReduction setOpenGLTextureCompressionHint"
                        " setOpenGLAnisotropy clearTextureHolds addMaterialMapping aiConnect"
                        " aiAddPlayer setPowerAudioProfiles calcExplosionCoverage"
                        " gotoWebPage deactivateDirectInput activateDirectInput strToPlayerName"
                        " stripTrailingSpaces setDefaultFov setZoomSpeed setFov screenShot"
                        " panoramaScreenShot purgeResources lightScene flushTextureCache"
                        " dumpTextureStats dumpResourceStats getControlObjectAltitude"
                        " getControlObjectSpeed containerFindFirst containerFindNext"
                        " snapToggle getVersionNumber getVersionString getCompileTimeString"
                        " getSimTime getRealTime setNetPort lockMouse rebuildModPaths"
                        " setModPaths getModPaths createCanvas saveJournal playJournal"
                        " addTaggedString removeTaggedString getTaggedString buildTaggedString"
                        " commandToServer commandToClient allowConnections connect localConnect"
                        " startRecord stopRecord playDemo isDemoRecording msg queryMasterServer"
                        " cancelServerQuery stopServerQuery startHeartbeat stopHeartbeat"
                        " getServerCount setServerInfo setShadowDetailLevel showShapeLoad showSequenceLoad"
                        " showTurnLeft showTurnRight showUpdateThreadControl showSelectSequence"
                        " showPlay showStop showSetScale showSetPos showNewThread showDeleteThread"
                        " showToggleRoot showToggleStick showSetCamera showSetKeyboard showSetLightDirection"
                        " showSetDetailSlider StripMLControlChars setInteriorRenderMode setInteriorFocusedDebug"
                        " isPointInside VectorAdd VectorSub VectorScale VectorNormalize VectorDot"
                        " VectorCross VectorDist VectorLen VectorOrthoBasis MatrixCreate"
                        " MatrixMultiply MatrixMulVector MatrixMulPoint getBoxCenter"
                        " setRandomSeed getRandomSeed getRandom MatrixCreateFromEuler mSolveQuadratic"
                        " mSolveCubic mSolveQuartic mFloor mCeil mFloatLength mAbs mSqrt"
                        " mPow mLog mSin mCos mTan mAsin mAcos mAtan mRadToDeg mDegToRad"
                        " ValidateMemory FreeMemoryDump dumpMemSnapshot redbookOpen redbookClose"
                        " redbookPlay redbookStop redbookGetTrackCount redbookGetVolume"
                        " redbookSetVolume redbookGetDeviceCount redbookGetDeviceName redbookGetLastError"
                        " videoSetGammaCorrection setDisplayDevice setScreenMode toggleFullScreen"
                        " isFullScreen switchBitDepth prevResolution nextResolution getResolution"
                        " setResolution setRes getDisplayDeviceList getResolutionList getVideoDriverInfo"
                        " isDeviceFullScreenOnly setVerticalSync profilerMarkerEnable profilerEnable"
                        " profilerDump profilerDumpToFile enableWinConsole isJoystickDetected"
                        " getJoystickAxes enableMouse disableMouse echoInputState toggleInputState"
                        " MathInit AddCardProfile addOSCardProfile getDesktopResolution activateKeyboard"
                        " deactivateKeyboard GLEnableLogging GLEnableOutline GLEnableMetrics"
                        " inputLog launchDedicatedServer isKoreanBuild debug_testx86unixmutex"
                        " debug_debugbreak resetLighting getMaxFrameAllocation dumpNetStringTable"
                        " InitContainerRadiusSearch ContainerSearchNext ContainerSearchCurrDist"
                        " ContainerSearchCurrRadiusDist ContainerRayCast ContainerBoxEmpty"
                        " pathOnMissionLoadDone makeTestTerrain getTerrainHeight")
												); //end scintilla->SetKeyWords(1, <blah>)
}

TorqueIDEFrame::~TorqueIDEFrame()
{
}

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
	// Help
	EVT_MENU(MENU_HELP_HELP, TorqueIDEFrame::OnMenuHelpHelp)
	EVT_MENU(MENU_HELP_ABOUT, TorqueIDEFrame::OnMenuHelpAbout)
END_EVENT_TABLE()

void TorqueIDEFrame::OnMenuFileNew(wxCommandEvent &event)
{
  wxLogMessage("File New Menu Selected");
}

void TorqueIDEFrame::OnMenuFileOpen(wxCommandEvent &event)
{
	wxFileDialog *opendlg = new wxFileDialog(this, "Open", "", "", "TorqueSCRIPT Files(*.cs)|*.cs|All files(*.*)|*.*", wxOPEN, wxDefaultPosition);
	if ( opendlg->ShowModal() == wxID_OK )
	{
		scintilla->LoadFile(opendlg->GetFilename());
		SetStatusText(opendlg->GetFilename(), 1);
	}
	opendlg->Destroy();
}

void TorqueIDEFrame::OnMenuFileSave(wxCommandEvent &event)
{
  wxLogMessage("File Save Menu Selected");
}

void TorqueIDEFrame::OnMenuFileSaveAs(wxCommandEvent &event)
{
	wxFileDialog *savedlg = new wxFileDialog(this, "Save As", "", "", "TorqueSCRIPT Files(*.cs)|*.cs|All files(*.*)|*.*", wxSAVE, wxDefaultPosition);
	if ( savedlg->ShowModal() == wxID_OK )
	{
		scintilla->SaveFile(savedlg->GetFilename());
		SetStatusText(savedlg->GetFilename(), 1);
	}
	savedlg->Destroy();
}

void TorqueIDEFrame::OnMenuFileQuit(wxCommandEvent &event)
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
  wxLogMessage("Edit Cut Menu Selected");
}

void TorqueIDEFrame::OnMenuEditCopy(wxCommandEvent &event)
{
  wxLogMessage("Edit Copy Menu Selected");
}

void TorqueIDEFrame::OnMenuEditPaste(wxCommandEvent &event)
{
  wxLogMessage("Edit Paste Menu Selected");
}

void TorqueIDEFrame::OnMenuHelpHelp(wxCommandEvent &event)
{
  wxLogMessage("Help Help Menu Selected");
}

void TorqueIDEFrame::OnMenuHelpAbout(wxCommandEvent &event)
{
  wxLogMessage("Help About Menu Selected");
}

