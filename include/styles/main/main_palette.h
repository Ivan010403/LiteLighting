#ifndef MAIN_STYLE_H
#define MAIN_STYLE_H

#include "styles/color_constants.h"
#include <QPalette>

QPalette СreateAppPalette() {
    QPalette palette;

    palette.setColor(QPalette::Window, MainColors::kWindow);
    palette.setColor(QPalette::WindowText, MainColors::kWindowText);

    palette.setColor(QPalette::Base, MainColors::kBase);
    palette.setColor(QPalette::Text, MainColors::kText);
    palette.setColor(QPalette::AlternateBase, MainColors::kAlternateBase);

    palette.setColor(QPalette::ToolTipBase, MainColors::kToolTipBase);
    palette.setColor(QPalette::ToolTipText, MainColors::kToolTipText);

    palette.setColor(QPalette::PlaceholderText, MainColors::kPlaceholderText);
    palette.setColor(QPalette::BrightText, MainColors::kBrightText);

    palette.setColor(QPalette::Button, MainColors::kButton);
    palette.setColor(QPalette::ButtonText, MainColors::kButtonText);

    palette.setColor(QPalette::Light, MainColors::kLight);
    palette.setColor(QPalette::Midlight, MainColors::kMidlight);
    palette.setColor(QPalette::Dark, MainColors::kDark);
    palette.setColor(QPalette::Mid, MainColors::kMid);
    palette.setColor(QPalette::Shadow, MainColors::kShadow);

    palette.setColor(QPalette::Highlight, MainColors::kHighlight);
    palette.setColor(QPalette::HighlightedText, MainColors::kHighlightedText);

    palette.setColor(QPalette::Link, MainColors::kLink);
    palette.setColor(QPalette::LinkVisited, MainColors::kLinkVisited);

    return palette;
}

#endif // MAIN_STYLE_H
