#ifndef _TORQUEIDEPREFS_H
#define _TORQUEIDEPREFS_H
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
 
#include <wx/stc/stc.h>

// STC Related Prefs
#define DEFAULT_LANGUAGE _("*.*")
#define STYLE_TYPES_COUNT 32

// General Style Types
#define TORQUEIDESTC_TYPE_DEFAULT 0

#define TORQUEIDESTC_TYPE_WORD1 1
#define TORQUEIDESTC_TYPE_WORD2 2
#define TORQUEIDESTC_TYPE_WORD3 3
#define TORQUEIDESTC_TYPE_WORD4 4
#define TORQUEIDESTC_TYPE_WORD5 5
#define TORQUEIDESTC_TYPE_WORD6 6

#define TORQUEIDESTC_TYPE_COMMENT 7
#define TORQUEIDESTC_TYPE_COMMENT_DOC 8
#define TORQUEIDESTC_TYPE_COMMENT_LINE 9
#define TORQUEIDESTC_TYPE_COMMENT_SPECIAL 10

#define TORQUEIDESTC_TYPE_CHARACTER 11
#define TORQUEIDESTC_TYPE_CHARACTER_EOL 12
#define TORQUEIDESTC_TYPE_STRING 13
#define TORQUEIDESTC_TYPE_STRING_EOL 14

#define TORQUEIDESTC_TYPE_DELIMITER 15

#define TORQUEIDESTC_TYPE_PUNCTUATION 16

#define TORQUEIDESTC_TYPE_OPERATOR 17

#define TORQUEIDESTC_TYPE_BRACE 18

#define TORQUEIDESTC_TYPE_COMMAND 19
#define TORQUEIDESTC_TYPE_IDENTIFIER 20
#define TORQUEIDESTC_TYPE_LABEL 21
#define TORQUEIDESTC_TYPE_NUMBER 22
#define TORQUEIDESTC_TYPE_PARAMETER 23
#define TORQUEIDESTC_TYPE_REGEX 24
#define TORQUEIDESTC_TYPE_UUID 25
#define TORQUEIDESTC_TYPE_VALUE 26

#define TORQUEIDESTC_TYPE_PREPROCESSOR 27
#define TORQUEIDESTC_TYPE_SCRIPT 28

#define TORQUEIDESTC_TYPE_ERROR 29

// Stylebit Types
#define TORQUEIDESTC_STYLE_BOLD 1
#define TORQUEIDESTC_STYLE_ITALIC 2
#define TORQUEIDESTC_STYLE_UNDERL 4
#define TORQUEIDESTC_STYLE_HIDDEN 8

// Folding Types
#define TORQUEIDESTC_FOLD_COMMENT 1
#define TORQUEIDESTC_FOLD_COMPACT 2
#define TORQUEIDESTC_FOLD_PREPROC 4

#define TORQUEIDESTC_FOLD_HTML 16
#define TORQUEIDESTC_FOLD_HTMLPREP 32

#define TORQUEIDESTC_FOLD_COMMENTPY 64
#define TORQUEIDESTC_FOLD_QUOTESPY 128

// Flags
#define TORQUEIDESTC_FLAG_WRAPMODE 16

// Common Information
struct CommonInfo {
    // Editor Functionality
    bool syntaxEnable;
    bool foldEnable;
    bool indentEnable;
    // Display Defaults
    bool readOnlyInitial;
    bool overTypeInitial;
    bool wrapModeInitial;
    bool displayEOLEnable;
    bool indentGuideEnable;
    bool lineNumberEnable;
    bool longLineOnEnable;
    bool whiteSpaceEnable;
};
extern const CommonInfo commonPrefs;

// Language Information
struct LanguageInfo {
    wxChar *name;
    wxChar *filepattern;
    int lexer;
    struct {
        int type;
        const wxChar *words;
    } styles [STYLE_TYPES_COUNT];
    int folds;
};

extern const LanguageInfo languagePrefs[];
extern const int languagePrefsSize;

// Style Information
struct StyleInfo {
    wxChar *name;
    wxChar *foreground;
    wxChar *background;
    wxChar *fontname;
    int fontsize;
    int fontstyle;
    int lettercase;
};

extern const StyleInfo stylePrefs[];
extern const int stylePrefsSize;
 
#endif _TORQUEIDEPREFS_H