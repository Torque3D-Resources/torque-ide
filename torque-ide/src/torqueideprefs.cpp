/*
 * Torque IDE -- An open source integrated development environment for the
 *   Torque Game Engine
 *
 * Copyright (C) 2005 Robert Pierce
 ** Adapted from wxWidgets STC example
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

#include "TorqueIDEPrefs.h"

// Language Types
const CommonInfo commonPrefs = {
    // Editor Functionality
    true,  // syntaxEnable
    true,  // foldEnable
    true,  // indentEnable
    // Display Defaults
    false, // overTypeInitial
    false, // readOnlyInitial
    false,  // wrapModeInitial
    false, // displayEOLEnable
    false, // IndentGuideEnable
    true,  // lineNumberEnable
    false, // longLineOnEnable
    false, // whiteSpaceEnable
};

// Keyword Lists
/**
 * C++
 */
wxChar* CppWordlist1 =
    _T("asm auto bool break case catch char class const const_cast ")
    _T("continue default delete do double dynamic_cast else enum explicit ")
    _T("export extern false float for friend goto if inline int long ")
    _T("mutable namespace new operator private protected public register ")
    _T("reinterpret_cast return short signed sizeof static static_cast ")
    _T("struct switch template this throw true try typedef typeid ")
    _T("typename union unsigned using virtual void volatile wchar_t ")
    _T("while");
wxChar* CppWordlist2 =
    _T("file");
wxChar* CppWordlist3 =
    _T("a addindex addtogroup anchor arg attention author b brief bug c ")
    _T("class code date def defgroup deprecated dontinclude e em endcode ")
    _T("endhtmlonly endif endlatexonly endlink endverbatim enum example ")
    _T("exception f$ f[ f] file fn hideinitializer htmlinclude ")
    _T("htmlonly if image include ingroup internal invariant interface ")
    _T("latexonly li line link mainpage name namespace nosubgrouping note ")
    _T("overload p page par param post pre ref relates remarks return ")
    _T("retval sa section see showinitializer since skip skipline struct ")
    _T("subsection test throw todo typedef union until var verbatim ")
    _T("verbinclude version warning weakgroup $ @ \"\" & < > # { }");

/**
 * Python
 */
wxChar* PythonWordlist1 =
    _T("and assert break class continue def del elif else except exec ")
    _T("finally for from global if import in is lambda None not or pass ")
    _T("print raise return try while yield");
wxChar* PythonWordlist2 =
    _T("ACCELERATORS ALT AUTO3STATE AUTOCHECKBOX AUTORADIOBUTTON BEGIN ")
    _T("BITMAP BLOCK BUTTON CAPTION CHARACTERISTICS CHECKBOX CLASS ")
    _T("COMBOBOX CONTROL CTEXT CURSOR DEFPUSHBUTTON DIALOG DIALOGEX ")
    _T("DISCARDABLE EDITTEXT END EXSTYLE FONT GROUPBOX ICON LANGUAGE ")
    _T("LISTBOX LTEXT MENU MENUEX MENUITEM MESSAGETABLE POPUP PUSHBUTTON ")
    _T("RADIOBUTTON RCDATA RTEXT SCROLLBAR SEPARATOR SHIFT STATE3 ")
    _T("STRINGTABLE STYLE TEXTINCLUDE VALUE VERSION VERSIONINFO VIRTKEY");
	
/**
 * TorqueSCRIPT
 */
wxChar* TorqueSCRIPTWordlist1 =
	_T("break case continue datablock default else false function ")
	_T("if for new or package return switch switch$ true and while");
wxChar* TorqueSCRIPTWordlist2 =
	_T("dumpConsoleClasses expandFilename strcmp stricmp strlen strstr ")
	_T("strpos ltrim rtrim trim sripChars strlwr strupr strchr strreplace ")
	_T("getSubStr getWord getWords setWord removeWord getWordCount getField ")
	_T("getFields setField removeField getFieldCount getRecord getRecords setRecord  ")
	_T("removeRecord getRecordCount firstWord restWords detag getTag echo warn error ")
	_T("expandEscape collapseEscape quit call compile exec export deleteVariables trace ")
	_T("debug findFirstFile findNextFile getFileCount getFileCRC isFile isWriteableFileName ")
	_T("fileExt fileBase fileName filePath nextToken setLogMode setEchoFileLoads backtrace ")
	_T("isPackage activatePackage deactivatePackage nameToID isObject cancel isEventPending schedule");

// Languages
const LanguageInfo languagePrefs [] = {
    // C++
    {_T("C++"),
     _T("*.c;*.cc;*.cpp;*.cxx;*.cs;*.h;*.hh;*.hpp;*.hxx;*.sma"),
     wxSTC_LEX_CPP,
     {{TORQUEIDESTC_TYPE_DEFAULT, NULL},
      {TORQUEIDESTC_TYPE_COMMENT, NULL},
      {TORQUEIDESTC_TYPE_COMMENT_LINE, NULL},
      {TORQUEIDESTC_TYPE_COMMENT_DOC, NULL},
      {TORQUEIDESTC_TYPE_NUMBER, NULL},
      {TORQUEIDESTC_TYPE_WORD1, CppWordlist1}, // KEYWORDS
      {TORQUEIDESTC_TYPE_STRING, NULL},
      {TORQUEIDESTC_TYPE_CHARACTER, NULL},
      {TORQUEIDESTC_TYPE_UUID, NULL},
      {TORQUEIDESTC_TYPE_PREPROCESSOR, NULL},
      {TORQUEIDESTC_TYPE_OPERATOR, NULL},
      {TORQUEIDESTC_TYPE_IDENTIFIER, NULL},
      {TORQUEIDESTC_TYPE_STRING_EOL, NULL},
      {TORQUEIDESTC_TYPE_DEFAULT, NULL}, // VERBATIM
      {TORQUEIDESTC_TYPE_REGEX, NULL},
      {TORQUEIDESTC_TYPE_COMMENT_SPECIAL, NULL}, // DOXY
      {TORQUEIDESTC_TYPE_WORD2, CppWordlist2}, // EXTRA WORDS
      {TORQUEIDESTC_TYPE_WORD3, CppWordlist3}, // DOXY KEYWORDS
      {TORQUEIDESTC_TYPE_ERROR, NULL}, // KEYWORDS ERROR
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL}},
     TORQUEIDESTC_FOLD_COMMENT | TORQUEIDESTC_FOLD_COMPACT | TORQUEIDESTC_FOLD_PREPROC},
    // TorqueSCRIPT
    {_T("TorqueSCRIPT"),
     _T("*.cs;*.gui;*.mis"),
     wxSTC_LEX_CPP,
     {{TORQUEIDESTC_TYPE_DEFAULT, NULL},
      {TORQUEIDESTC_TYPE_COMMENT, NULL},
      {TORQUEIDESTC_TYPE_COMMENT_LINE, NULL},
      {TORQUEIDESTC_TYPE_COMMENT_DOC, NULL},
      {TORQUEIDESTC_TYPE_NUMBER, NULL},
      {TORQUEIDESTC_TYPE_WORD1, TorqueSCRIPTWordlist1}, // KEYWORDS
      {TORQUEIDESTC_TYPE_STRING, NULL},
      {TORQUEIDESTC_TYPE_CHARACTER, NULL},
      {TORQUEIDESTC_TYPE_UUID, NULL},
      {TORQUEIDESTC_TYPE_PREPROCESSOR, NULL},
      {TORQUEIDESTC_TYPE_OPERATOR, NULL},
      {TORQUEIDESTC_TYPE_IDENTIFIER, NULL},
      {TORQUEIDESTC_TYPE_STRING_EOL, NULL},
      {TORQUEIDESTC_TYPE_DEFAULT, NULL}, // VERBATIM
      {TORQUEIDESTC_TYPE_REGEX, NULL},
      {TORQUEIDESTC_TYPE_COMMENT_SPECIAL, NULL}, // DOXY
      {TORQUEIDESTC_TYPE_WORD2, TorqueSCRIPTWordlist2}, // EXTRA WORDS
      {TORQUEIDESTC_TYPE_WORD3, CppWordlist3}, // DOXY KEYWORDS // Stealing from C++ as it is just a repeat
      {TORQUEIDESTC_TYPE_ERROR, NULL}, // KEYWORDS ERROR
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL}},
     TORQUEIDESTC_FOLD_COMMENT | TORQUEIDESTC_FOLD_COMPACT | TORQUEIDESTC_FOLD_PREPROC},
    // Python
    {_T("Python"),
     _T("*.py;*.pyw"),
     wxSTC_LEX_PYTHON,
     {{TORQUEIDESTC_TYPE_DEFAULT, NULL},
      {TORQUEIDESTC_TYPE_COMMENT_LINE, NULL},
      {TORQUEIDESTC_TYPE_NUMBER, NULL},
      {TORQUEIDESTC_TYPE_STRING, NULL},
      {TORQUEIDESTC_TYPE_CHARACTER, NULL},
      {TORQUEIDESTC_TYPE_WORD1, PythonWordlist1}, // KEYWORDS
      {TORQUEIDESTC_TYPE_DEFAULT, NULL}, // TRIPLE
      {TORQUEIDESTC_TYPE_DEFAULT, NULL}, // TRIPLEDOUBLE
      {TORQUEIDESTC_TYPE_DEFAULT, NULL}, // CLASSNAME
      {TORQUEIDESTC_TYPE_DEFAULT, PythonWordlist2}, // DEFNAME
      {TORQUEIDESTC_TYPE_OPERATOR, NULL},
      {TORQUEIDESTC_TYPE_IDENTIFIER, NULL},
      {TORQUEIDESTC_TYPE_DEFAULT, NULL}, // COMMENT_BLOCK
      {TORQUEIDESTC_TYPE_STRING_EOL, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL}},
     TORQUEIDESTC_FOLD_COMMENTPY | TORQUEIDESTC_FOLD_QUOTESPY},
    // * (any)
    {(wxChar *)DEFAULT_LANGUAGE,
     _T("*.*"),
     wxSTC_LEX_PROPERTIES,
     {{TORQUEIDESTC_TYPE_DEFAULT, NULL},
      {TORQUEIDESTC_TYPE_DEFAULT, NULL},
      {TORQUEIDESTC_TYPE_DEFAULT, NULL},
      {TORQUEIDESTC_TYPE_DEFAULT, NULL},
      {TORQUEIDESTC_TYPE_DEFAULT, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL},
      {-1, NULL}},
     0},
    };

const int languagePrefsSize = WXSIZEOF(languagePrefs);

//----------------------------------------------------------------------------
//! style types
const StyleInfo stylePrefs [] = {
    // TORQUEIDESTC_TYPE_DEFAULT
    {_T("Default"),
     _T("BLACK"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // TORQUEIDESTC_TYPE_WORD1
    {_T("Keyword1"),
     _T("BLUE"), _T("WHITE"),
     _T(""), 10, TORQUEIDESTC_STYLE_BOLD, 0},

    // TORQUEIDESTC_TYPE_WORD2
    {_T("Keyword2"),
     _T("DARK BLUE"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // TORQUEIDESTC_TYPE_WORD3
    {_T("Keyword3"),
     _T("CORNFLOWER BLUE"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // TORQUEIDESTC_TYPE_WORD4
    {_T("Keyword4"),
     _T("CYAN"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // TORQUEIDESTC_TYPE_WORD5
    {_T("Keyword5"),
     _T("DARK GREY"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // TORQUEIDESTC_TYPE_WORD6
    {_T("Keyword6"),
     _T("GREY"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // TORQUEIDESTC_TYPE_COMMENT
    {_T("Comment"),
     _T("FOREST GREEN"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // TORQUEIDESTC_TYPE_COMMENT_DOC
    {_T("Comment (Doc)"),
     _T("FOREST GREEN"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // TORQUEIDESTC_TYPE_COMMENT_LINE
    {_T("Comment line"),
     _T("FOREST GREEN"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // TORQUEIDESTC_TYPE_COMMENT_SPECIAL
    {_T("Special comment"),
     _T("FOREST GREEN"), _T("WHITE"),
     _T(""), 10, TORQUEIDESTC_STYLE_ITALIC, 0},

    // TORQUEIDESTC_TYPE_CHARACTER
    {_T("Character"),
     _T("KHAKI"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // TORQUEIDESTC_TYPE_CHARACTER_EOL
    {_T("Character (EOL)"),
     _T("KHAKI"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // TORQUEIDESTC_TYPE_STRING
    {_T("String"),
     _T("BROWN"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // TORQUEIDESTC_TYPE_STRING_EOL
    {_T("String (EOL)"),
     _T("BROWN"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // TORQUEIDESTC_TYPE_DELIMITER
    {_T("Delimiter"),
     _T("ORANGE"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // TORQUEIDESTC_TYPE_PUNCTUATION
    {_T("Punctuation"),
     _T("ORANGE"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // TORQUEIDESTC_TYPE_OPERATOR
    {_T("Operator"),
     _T("BLACK"), _T("WHITE"),
     _T(""), 10, TORQUEIDESTC_STYLE_BOLD, 0},

    // TORQUEIDESTC_TYPE_BRACE
    {_T("Label"),
     _T("VIOLET"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // TORQUEIDESTC_TYPE_COMMAND
    {_T("Command"),
     _T("BLUE"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // TORQUEIDESTC_TYPE_IDENTIFIER
    {_T("Identifier"),
     _T("BLACK"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // TORQUEIDESTC_TYPE_LABEL
    {_T("Label"),
     _T("VIOLET"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // TORQUEIDESTC_TYPE_NUMBER
    {_T("Number"),
     _T("SIENNA"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // TORQUEIDESTC_TYPE_PARAMETER
    {_T("Parameter"),
     _T("VIOLET"), _T("WHITE"),
     _T(""), 10, TORQUEIDESTC_STYLE_ITALIC, 0},

    // TORQUEIDESTC_TYPE_REGEX
    {_T("Regular expression"),
     _T("ORCHID"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // TORQUEIDESTC_TYPE_UUID
    {_T("UUID"),
     _T("ORCHID"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // TORQUEIDESTC_TYPE_VALUE
    {_T("Value"),
     _T("ORCHID"), _T("WHITE"),
     _T(""), 10, TORQUEIDESTC_STYLE_ITALIC, 0},

    // TORQUEIDESTC_TYPE_PREPROCESSOR
    {_T("Preprocessor"),
     _T("GREY"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // TORQUEIDESTC_TYPE_SCRIPT
    {_T("Script"),
     _T("DARK GREY"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // TORQUEIDESTC_TYPE_ERROR
    {_T("Error"),
     _T("RED"), _T("WHITE"),
     _T(""), 10, 0, 0},

    // TORQUEIDESTC_TYPE_UNDEFINED
    {_T("Undefined"),
     _T("ORANGE"), _T("WHITE"),
     _T(""), 10, 0, 0}

    };

const int stylePrefsSize = WXSIZEOF(stylePrefs);