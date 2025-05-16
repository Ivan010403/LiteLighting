cmake_minimum_required(VERSION 3.5)

project(LiteLighting VERSION 0.1 LANGUAGES CXX)

# set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

SET(MYCOMPILE_FLAGS "-g")

# SET(MYCOMPILE_FLAGS "-Ofast -g -no-pie")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${MYCOMPILE_FLAGS}")

set(PROJECT_SOURCES
	src/main.cpp
)

set(LIB3_SOURCES
  /home/ivan/LiteLighting/lib/libola.a
  /home/ivan/LiteLighting/lib/libolaartnet.a
  /home/ivan/LiteLighting/lib/libolaartnetconf.a
  /home/ivan/LiteLighting/lib/libolacommon.a
  /home/ivan/LiteLighting/lib/liboladummy.a
  /home/ivan/LiteLighting/lib/libolae131.a
  /home/ivan/LiteLighting/lib/libolae131conf.a
  /home/ivan/LiteLighting/lib/libolaespnet.a
  /home/ivan/LiteLighting/lib/libolaftdidmx.a
  /home/ivan/LiteLighting/lib/libolagpio.a
  /home/ivan/LiteLighting/lib/libolagpiocore.a
  /home/ivan/LiteLighting/lib/libolakarate.a
  /home/ivan/LiteLighting/lib/libolakinet.a
  /home/ivan/LiteLighting/lib/libolamilinst.a
  /home/ivan/LiteLighting/lib/libolaopendmx.a
  /home/ivan/LiteLighting/lib/libolaopenpixelcontrol.a
  /home/ivan/LiteLighting/lib/libolaosc.a
  /home/ivan/LiteLighting/lib/libolapathport.a
  /home/ivan/LiteLighting/lib/libolarenard.a
  /home/ivan/LiteLighting/lib/libolasandnet.a
  /home/ivan/LiteLighting/lib/libolaserver.a
  /home/ivan/LiteLighting/lib/libolaserverplugininterface.a
  /home/ivan/LiteLighting/lib/libolashownet.a
  /home/ivan/LiteLighting/lib/libolaspi.a
  /home/ivan/LiteLighting/lib/libolaspicore.a
  /home/ivan/LiteLighting/lib/libolastageprofi.a
  /home/ivan/LiteLighting/lib/libolatrigger.a
  /home/ivan/LiteLighting/lib/libolauartdmx.a
  /home/ivan/LiteLighting/lib/libolausbdmx.a
  /home/ivan/LiteLighting/lib/libolausbpro.a
  /home/ivan/LiteLighting/lib/libolausbproconf.a
  -lprotobuf) # Setup the list of sources here.

include_directories(/home/ivan/LiteLighting/include/)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(LiteLighting
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

        include/light_headers/DmxGateway.h
        include/light_headers/FixtureArray.h
        include/light_headers/CustomTypeEnum.h
        include/light_headers/Fixture.h

        include/styles/main/main_palette.h
        include/styles/main/main_style.qss
        include/styles/color_constants.h
        include/forms/mainwindow.ui

        src/light_src/Fixture.cpp
        src/light_src/FixtureArray.cpp
        src/light_src/DmxGateway.cpp
        src/light_src/CustomTypeEnum.cpp
        src/light_src/programming_command/AbstractCommand.cpp
        src/light_src/FixtureGroup.cpp

        include/qt_headers/mainwindow.h include/qt_headers/mainwindow.cpp
        include/qt_headers/pages_panel/pagespanel.h include/qt_headers/pages_panel/pagespanel.cpp
        include/qt_headers/settings_panel/settingspanel.h include/qt_headers/settings_panel/settingspanel.cpp
        include/qt_headers/control_panel/controlpanel.h include/qt_headers/control_panel/controlpanel.cpp
        include/qt_headers/middle_panel/middlepanel.h include/qt_headers/middle_panel/middlepanel.cpp

        include/qt_headers/middle_panel/patch_sheet/patchsheetwindow.h include/qt_headers/middle_panel/patch_sheet/patchsheetwindow.cpp

        include/qt_headers/middle_panel/busking/buskingwindow.h include/qt_headers/middle_panel/busking/buskingwindow.cpp
        include/qt_headers/middle_panel/programming/programmingwindow.h include/qt_headers/middle_panel/programming/programmingwindow.cpp
        include/qt_headers/middle_panel/settings/settingswindow.h include/qt_headers/middle_panel/settings/settingswindow.cpp


        include/qt_headers/middle_panel/patch_sheet/patching_modal_window/qdialogpatching.h include/qt_headers/middle_panel/patch_sheet/patching_modal_window/qdialogpatching.cpp
        include/light_headers/fixture_array_delegates/universeaddressdelegate.h src/light_src/fixture_array_delegates/universeaddressdelegate.cpp
        include/qt_headers/middle_panel/programming/scroll_area_widget/scrollareawidget.h include/qt_headers/middle_panel/programming/scroll_area_widget/scrollareawidget.cpp
        include/qt_headers/middle_panel/programming/scroll_area_widget/buttons/programmingbutton.h include/qt_headers/middle_panel/programming/scroll_area_widget/buttons/programmingbutton.cpp

        include/qt_headers/control_panel/stacked_widget_properties/fixture_property/fixtureproperty.h include/qt_headers/control_panel/stacked_widget_properties/fixture_property/fixtureproperty.cpp
        include/qt_headers/control_panel/stacked_widget_properties/fixture_property/button_widget/buttonvalue.h include/qt_headers/control_panel/stacked_widget_properties/fixture_property/button_widget/buttonvalue.cpp
        include/qt_headers/control_panel/stacked_widget_properties/fixture_property/scroll_bar_widget/scrollbarvalue.h include/qt_headers/control_panel/stacked_widget_properties/fixture_property/scroll_bar_widget/scrollbarvalue.cpp
        include/qt_headers/control_panel/stacked_widget_properties/stackedwidgetproperty.h include/qt_headers/control_panel/stacked_widget_properties/stackedwidgetproperty.cpp
        include/qt_headers/middle_panel/programming/scroll_area_widget/buttons/typebutton.h include/qt_headers/middle_panel/programming/scroll_area_widget/buttons/typebutton.cpp
        include/light_headers/programming_command/AbstractCommand.h
        include/qt_headers/middle_panel/programming/scroll_area_widget/buttons/modal_windows/qdialogcommand.h include/qt_headers/middle_panel/programming/scroll_area_widget/buttons/modal_windows/qdialogcommand.cpp
        include/light_headers/FixtureGroup.h
        include/qt_headers/middle_panel/programming/scroll_area_widget/buttons/groupbutton.h include/qt_headers/middle_panel/programming/scroll_area_widget/buttons/groupbutton.cpp
        include/qt_headers/middle_panel/programming/scroll_area_widget/buttons/modal_windows/qdialoggrouping.h include/qt_headers/middle_panel/programming/scroll_area_widget/buttons/modal_windows/qdialoggrouping.cpp
        include/qt_headers/control_panel/btn_property_type/buttonpropertytype.h include/qt_headers/control_panel/btn_property_type/buttonpropertytype.cpp
        include/qt_headers/control_panel/stacked_widget_properties/fixture_property/button_widget/name_property/labelnameproperty.h include/qt_headers/control_panel/stacked_widget_properties/fixture_property/button_widget/name_property/labelnameproperty.cpp
        include/qt_headers/control_panel/stacked_widget_properties/fixture_property/button_widget/value_property/buttonvalueproperty.h include/qt_headers/control_panel/stacked_widget_properties/fixture_property/button_widget/value_property/buttonvalueproperty.cpp
        include/light_headers/Mediator.h
        include/light_headers/programming_command/CommandArray.h
        src/light_src/programming_command/CommandArray.cpp
        include/qt_headers/control_panel/stacked_widget_properties/fixture_property/button_widget/modal_window/qdialogsetter.h include/qt_headers/control_panel/stacked_widget_properties/fixture_property/button_widget/modal_window/qdialogsetter.cpp
        include/qt_headers/middle_panel/programming/scroll_area_widget/buttons/modal_windows/qdialogeditor.h include/qt_headers/middle_panel/programming/scroll_area_widget/buttons/modal_windows/qdialogeditor.cpp
        include/qt_headers/middle_panel/busking/busking_view/buskingview.h include/qt_headers/middle_panel/busking/busking_view/buskingview.cpp
        include/qt_headers/middle_panel/busking/busking_view/fixture_display_button/fixturebutton.cpp include/qt_headers/middle_panel/busking/busking_view/fixture_display_button/fixturebutton.h
        include/qt_headers/pages_panel/pages_button/pagesbutton.h include/qt_headers/pages_panel/pages_button/pagesbutton.cpp
        res/photos.qrc
        include/light_headers/CircuitBreaker.h src/light_src/CircuitBreaker.cpp
        include/qt_headers/middle_panel/busking/busking_view/fixture_display_button/socketbutton.h include/qt_headers/middle_panel/busking/busking_view/fixture_display_button/socketbutton.cpp
        include/qt_headers/middle_panel/busking/busking_view/fixture_display_button/breakerbutton.h include/qt_headers/middle_panel/busking/busking_view/fixture_display_button/breakerbutton.cpp
        include/qt_headers/middle_panel/busking/busking_view/fixture_display_button/modal_window/qdialogsocket.cpp include/qt_headers/middle_panel/busking/busking_view/fixture_display_button/modal_window/qdialogsocket.h
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET LiteLighting APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(LiteLighting SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(LiteLighting
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(LiteLighting PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${LIB3_SOURCES})

# target_compile_options(LiteLighting PUBLIC ${MYCOMPILE_FLAGS})

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.LiteLighting)
endif()

set_target_properties(LiteLighting PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS LiteLighting
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(LiteLighting)
endif()
