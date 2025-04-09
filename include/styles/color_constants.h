#ifndef COLOR_CONSTANTS_H
#define COLOR_CONSTANTS_H

#include <QColor>

namespace MainColors {
    constexpr QColor kWindow = QColor(92,92,92);                    // цвет окна
    constexpr QColor kWindowText = QColor(255, 255, 255);           // цвет текста окна

    constexpr QColor kBase = QColor(29,33,34);                      // задний фон виджетов (например, фон строчки ввода)
    constexpr QColor kText = QColor(255,255,255);                   // текст виджетов
    constexpr QColor kAlternateBase = QColor(59, 63, 64);           // альтернативный фон (например, чтобы подсветить нечётные строчки в списке

    constexpr QColor kToolTipBase = QColor(178,178,178); // хз      // цвет фона QToolTip, использует inactive group
    constexpr QColor kToolTipText = QColor(178,178,178); // хз      // цвет шрифта QToolTip, использует inactive group

    constexpr QColor kButton = QColor(29,33,34);                    // цвет кнопки
    constexpr QColor kButtonText = QColor(255,255,255);             // цвет текст кнопки

    constexpr QColor kPlaceholderText = QColor(178,178,178);// хз   // цвет заполнителя для различных виджетов ввода текста
    constexpr QColor kBrightText = QColor(178,178,178); // хз       // Обычно используется для текста, который нужно нарисовать там, где Text или WindowText дадут плохой контраст, например, на нажатых кнопках.

    constexpr QColor kLight = QColor(72,75,76);                     // 3д
    constexpr QColor kMidlight = QColor(40,43,44);                  // 3д
    constexpr QColor kDark = QColor(6,8,9);                         // 3д
    constexpr QColor kMid = QColor(15,18,19);                       // 3д
    constexpr QColor kShadow = QColor(0,0,0);                       // 3д

    constexpr QColor kHighlight = QColor(105, 69, 27);  //ПОМЕНЯТЬ  // цвет выделения
    constexpr QColor kHighlightedText = QColor(0,0,0); // ПОМЕНЯТЬ  // цвет выделенного текста

    constexpr QColor kLink = QColor(178,178,178);                   // цвет ссылки
    constexpr QColor kLinkVisited = QColor(178,178,178);            // цвет посещённой ссылки
}

#endif // COLOR_CONSTANTS_H
