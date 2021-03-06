#include "window_styles.h"
#include <Windows.h>
#include <map>
#include <string>

const std::map<std::wstring,unsigned> _exStylesMap = {
    { L"WS_EX_DLGMODALFRAME",       WS_EX_DLGMODALFRAME },
    { L"WS_EX_NOPARENTNOTIFY",      WS_EX_NOPARENTNOTIFY },
    { L"WS_EX_TOPMOST",             WS_EX_TOPMOST },
    { L"WS_EX_ACCEPTFILES",         WS_EX_ACCEPTFILES },
    { L"WS_EX_TRANSPARENT",         WS_EX_TRANSPARENT },
    { L"WS_EX_MDICHILD",            WS_EX_MDICHILD },
    { L"WS_EX_TOOLWINDOW",          WS_EX_TOOLWINDOW },
    { L"WS_EX_WINDOWEDGE",          WS_EX_WINDOWEDGE },
    { L"WS_EX_CLIENTEDGE",          WS_EX_CLIENTEDGE },
    { L"WS_EX_CONTEXTHELP",         WS_EX_CONTEXTHELP },
    { L"WS_EX_RIGHT",               WS_EX_RIGHT },
    { L"WS_EX_LEFT",                WS_EX_LEFT },
    { L"WS_EX_RTLREADING",          WS_EX_RTLREADING },
    { L"WS_EX_LTRREADING",          WS_EX_LTRREADING },
    { L"WS_EX_LEFTSCROLLBAR",       WS_EX_LEFTSCROLLBAR },
    { L"WS_EX_RIGHTSCROLLBAR",      WS_EX_RIGHTSCROLLBAR },
    { L"WS_EX_CONTROLPARENT",       WS_EX_CONTROLPARENT },
    { L"WS_EX_STATICEDGE",          WS_EX_STATICEDGE },
    { L"WS_EX_APPWINDOW",           WS_EX_APPWINDOW },
    { L"WS_EX_LAYERED",             WS_EX_LAYERED },
    { L"WS_EX_NOINHERITLAYOUT",     WS_EX_NOINHERITLAYOUT },
    { L"WS_EX_LAYOUTRTL",           WS_EX_LAYOUTRTL },
    { L"WS_EX_COMPOSITED",          WS_EX_COMPOSITED },
    { L"WS_EX_NOACTIVATE",          WS_EX_NOACTIVATE },
    { L"WS_EX_OVERLAPPEDWINDOW",    WS_EX_OVERLAPPEDWINDOW },
    { L"WS_EX_PALETTEWINDOW",       WS_EX_PALETTEWINDOW },
};

const std::map<std::wstring,unsigned> _stylesMap = {
    { L"WS_OVERLAPPED", WS_OVERLAPPED },
    { L"WS_POPUP", WS_POPUP },
    { L"WS_CHILD", WS_CHILD },
    { L"WS_MINIMIZE", WS_MINIMIZE },
    { L"WS_VISIBLE", WS_VISIBLE },
    { L"WS_DISABLED", WS_DISABLED },
    { L"WS_CLIPSIBLINGS", WS_CLIPSIBLINGS },
    { L"WS_CLIPCHILDREN", WS_CLIPCHILDREN },
    { L"WS_MAXIMIZE", WS_MAXIMIZE },
    { L"WS_BORDER", WS_BORDER },
    { L"WS_DLGFRAME", WS_DLGFRAME },
    { L"WS_VSCROLL", WS_VSCROLL },
    { L"WS_HSCROLL", WS_HSCROLL },
    { L"WS_SYSMENU", WS_SYSMENU },
    { L"WS_THICKFRAME", WS_THICKFRAME },
    { L"WS_GROUP", WS_GROUP },
    { L"WS_TABSTOP", WS_TABSTOP },
    { L"WS_MINIMIZEBOX", WS_MINIMIZEBOX },
    { L"WS_MAXIMIZEBOX", WS_MAXIMIZEBOX },
    { L"WS_CAPTION", WS_CAPTION },
    { L"WS_TILED", WS_TILED },
    { L"WS_ICONIC", WS_ICONIC },
    { L"WS_SIZEBOX", WS_SIZEBOX },
    { L"WS_OVERLAPPEDWINDOW", WS_OVERLAPPEDWINDOW },
    { L"WS_POPUPWINDOW", WS_POPUPWINDOW },
    { L"WS_CHILDWINDOW", WS_CHILDWINDOW },
    { L"WS_TILEDWINDOW", WS_TILEDWINDOW },

    /* Edit control styles */
    { L"ES_LEFT", ES_LEFT },
    { L"ES_CENTER", ES_CENTER },
    { L"ES_RIGHT", ES_RIGHT },
    { L"ES_MULTILINE", ES_MULTILINE },
    { L"ES_UPPERCASE", ES_UPPERCASE },
    { L"ES_LOWERCASE", ES_LOWERCASE },
    { L"ES_PASSWORD", ES_PASSWORD },
    { L"ES_AUTOVSCROLL", ES_AUTOVSCROLL },
    { L"ES_AUTOHSCROLL", ES_AUTOHSCROLL },
    { L"ES_NOHIDESEL", ES_NOHIDESEL },
    { L"ES_OEMCONVERT", ES_OEMCONVERT },
    { L"ES_READONLY", ES_READONLY },
    { L"ES_WANTRETURN", ES_WANTRETURN },
    { L"ES_NUMBER", ES_NUMBER },

    /* Combo box styles */
    { L"CBS_SIMPLE", CBS_SIMPLE },
    { L"CBS_DROPDOWN", CBS_DROPDOWN },
    { L"CBS_DROPDOWNLIST", CBS_DROPDOWNLIST },
    { L"CBS_OWNERDRAWFIXED", CBS_OWNERDRAWFIXED },
    { L"CBS_OWNERDRAWVARIABLE", CBS_OWNERDRAWVARIABLE },
    { L"CBS_AUTOHSCROLL", CBS_AUTOHSCROLL },
    { L"CBS_OEMCONVERT", CBS_OEMCONVERT },
    { L"CBS_SORT", CBS_SORT },
    { L"CBS_HASSTRINGS", CBS_HASSTRINGS },
    { L"CBS_NOINTEGRALHEIGHT", CBS_NOINTEGRALHEIGHT },
    { L"CBS_DISABLENOSCROLL", CBS_DISABLENOSCROLL },
    { L"CBS_UPPERCASE", CBS_UPPERCASE },
    { L"CBS_LOWERCASE", CBS_LOWERCASE },

    /* Scrollbar styles */
    { L"SBS_HORZ", SBS_HORZ },
    { L"SBS_VERT", SBS_VERT },
    { L"SBS_TOPALIGN", SBS_TOPALIGN },
    { L"SBS_LEFTALIGN", SBS_LEFTALIGN },
    { L"SBS_BOTTOMALIGN", SBS_BOTTOMALIGN },
    { L"SBS_RIGHTALIGN", SBS_RIGHTALIGN },
    { L"SBS_SIZEBOXTOPLEFTALIGN", SBS_SIZEBOXTOPLEFTALIGN },
    { L"SBS_SIZEBOXBOTTOMRIGHTALIGN", SBS_SIZEBOXBOTTOMRIGHTALIGN },
    { L"SBS_SIZEBOX", SBS_SIZEBOX },
    { L"SBS_SIZEGRIP", SBS_SIZEGRIP },

    /* Button styles */
    { L"BS_PUSHBUTTON", BS_PUSHBUTTON },
    { L"BS_DEFPUSHBUTTON", BS_DEFPUSHBUTTON },
    { L"BS_CHECKBOX", BS_CHECKBOX },
    { L"BS_AUTOCHECKBOX", BS_AUTOCHECKBOX },
    { L"BS_RADIOBUTTON", BS_RADIOBUTTON },
    { L"BS_3STATE", BS_3STATE },
    { L"BS_AUTO3STATE", BS_AUTO3STATE },
    { L"BS_GROUPBOX", BS_GROUPBOX },
    { L"BS_USERBUTTON", BS_USERBUTTON },
    { L"BS_AUTORADIOBUTTON", BS_AUTORADIOBUTTON },
    { L"BS_PUSHBOX", BS_PUSHBOX },
    { L"BS_OWNERDRAW", BS_OWNERDRAW },
    { L"BS_TYPEMASK", BS_TYPEMASK },
    { L"BS_LEFTTEXT", BS_LEFTTEXT },
    { L"BS_RIGHTBUTTON", BS_RIGHTBUTTON },
    { L"BS_TEXT", BS_TEXT },
    { L"BS_ICON", BS_ICON },
    { L"BS_BITMAP", BS_BITMAP },
    { L"BS_LEFT", BS_LEFT },
    { L"BS_RIGHT", BS_RIGHT },
    { L"BS_CENTER", BS_CENTER },
    { L"BS_TOP", BS_TOP },
    { L"BS_BOTTOM", BS_BOTTOM },
    { L"BS_VCENTER", BS_VCENTER },
    { L"BS_PUSHLIKE", BS_PUSHLIKE },
    { L"BS_MULTILINE", BS_MULTILINE },
    { L"BS_NOTIFY", BS_NOTIFY },
    { L"BS_FLAT", BS_FLAT },

    /* Listbox styles */
    { L"LBS_NOTIFY", LBS_NOTIFY },
    { L"LBS_SORT", LBS_SORT },
    { L"LBS_NOREDRAW", LBS_NOREDRAW },
    { L"LBS_MULTIPLESEL", LBS_MULTIPLESEL },
    { L"LBS_OWNERDRAWFIXED", LBS_OWNERDRAWFIXED },
    { L"LBS_OWNERDRAWVARIABLE", LBS_OWNERDRAWVARIABLE },
    { L"LBS_HASSTRINGS", LBS_HASSTRINGS },
    { L"LBS_USETABSTOPS", LBS_USETABSTOPS },
    { L"LBS_NOINTEGRALHEIGHT", LBS_NOINTEGRALHEIGHT },
    { L"LBS_MULTICOLUMN", LBS_MULTICOLUMN },
    { L"LBS_WANTKEYBOARDINPUT", LBS_WANTKEYBOARDINPUT },
    { L"LBS_EXTENDEDSEL", LBS_EXTENDEDSEL },
    { L"LBS_DISABLENOSCROLL", LBS_DISABLENOSCROLL },
    { L"LBS_NODATA", LBS_NODATA },
    { L"LBS_NOSEL", LBS_NOSEL },
    { L"LBS_COMBOBOX", LBS_COMBOBOX },
    { L"LBS_STANDARD", LBS_STANDARD },

};


