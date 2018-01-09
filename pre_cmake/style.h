#ifndef SNDGUI_STYLE_H
#define SNDGUI_STYLE_H

#include <QtCore>
#include <QtWidgets>

class SndGuiSyle
{
public:

    SndGuiSyle();

    QColor col_window;
    QColor col_window_text;
    QColor col_base;
    QColor col_alt_base;

    QPalette global_palette;
    QStyle *style;
};

extern SndGuiSyle sndgui_style;

#endif // SNDGUI_STYLE_H
