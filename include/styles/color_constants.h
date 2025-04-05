#ifndef COLOR_CONSTANTS_H
#define COLOR_CONSTANTS_H

#include <QColor>

namespace MainColors {
    constexpr QColor kWindow = QColor(92,92,92);                // цвет окна
    constexpr QColor kWindowText = QColor(0, 0, 0);         // цвет текста окна

    constexpr QColor kBase = QColor(80,80,80);                  // задний фон виджетов (например, фон строчки ввода)
    constexpr QColor kText = QColor(178,178,178);               // текст виджетов
    constexpr QColor kAlternateBase = QColor(167, 121, 0);      // альтернативный фон (например, чтобы подсветить нечётные строчки в списке

    constexpr QColor kToolTipBase = QColor(178,178,178);        // цвет фона QToolTip, использует inactive group
    constexpr QColor kToolTipText = QColor(178,178,178);        // цвет шрифта QToolTip, использует inactive group

    constexpr QColor kButton = QColor(0,0,0);                   // цвет кнопки
    constexpr QColor kButtonText = QColor(178,178,178);         // цвет текст кнопки

    constexpr QColor kPlaceholderText = QColor(178,178,178);    // цвет заполнителя для различных виджетов ввода текста
    constexpr QColor kBrightText = QColor(178,178,178);         // Обычно используется для текста, который нужно нарисовать там, где Text или WindowText дадут плохой контраст, например, на нажатых кнопках.

    constexpr QColor kLight = QColor(178,178,178);              // 3д
    constexpr QColor kMidlight = QColor(178,178,178);           // 3д
    constexpr QColor kDark = QColor(178,178,178);               // 3д
    constexpr QColor kMid = QColor(178,178,178);                // 3д
    constexpr QColor kShadow = QColor(178,178,178);             // 3д

    constexpr QColor kHighlight = QColor(213, 156, 1);          // цвет выделения
    constexpr QColor kHighlightedText = QColor(178,178,178);    // цвет выделенного текста

    constexpr QColor kLink = QColor(178,178,178);               // цвет ссылки
    constexpr QColor kLinkVisited = QColor(178,178,178);        // цвет посещённой ссылки
}

#endif // COLOR_CONSTANTS_H
