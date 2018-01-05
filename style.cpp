#include "style.h"

#define COL_WINDOW              "#b3cde0"
#define COL_WINDOW_TEXT         "#03396c"
#define COL_BASE                QColor(45,48,71)
#define COL_ALT_BASE            "#005b96"
#define COL_TEXT                Qt::white
#define COL_BUTTON              Qt::white
#define COL_BUTTON_TEXT         Qt::black
#define COL_BRIGHT_TEXT         Qt::red
#define COL_LINK                QColor(42, 130, 218)
#define COL_HIGHLIGHT           QColor(42, 130, 218)
#define COL_HIGHLIGHTED_TEXT    Qt::white

// http://www.color-hex.com/color-palette/1294
// #011f4b 	(1,31,75)
// #03396c 	(3,57,108)
// #005b96 	(0,91,150)
// #6497b1 	(100,151,177)
// #b3cde0 	(179,205,224)

SndGuiSyle::SndGuiSyle():
    style(QStyleFactory::create("Fusion")),
    col_window(COL_WINDOW),
    col_window_text(COL_WINDOW_TEXT),
    col_base(COL_BASE),
    col_alt_base(COL_ALT_BASE)
{
    global_palette.setColor(QPalette::Window, col_window);
    global_palette.setColor(QPalette::WindowText, col_window_text);
    global_palette.setColor(QPalette::Base, col_base);
    global_palette.setColor(QPalette::AlternateBase, col_alt_base);
    global_palette.setColor(QPalette::Text, COL_TEXT);
    global_palette.setColor(QPalette::Button, COL_BUTTON);
    global_palette.setColor(QPalette::ButtonText, COL_BUTTON_TEXT);
    global_palette.setColor(QPalette::BrightText, COL_BRIGHT_TEXT);
    global_palette.setColor(QPalette::Link, COL_LINK);
    global_palette.setColor(QPalette::Highlight, COL_HIGHLIGHT);
    global_palette.setColor(QPalette::HighlightedText, COL_HIGHLIGHTED_TEXT);
}

// Global declaration
SndGuiSyle sndgui_style;
