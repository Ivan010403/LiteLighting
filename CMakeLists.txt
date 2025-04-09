cmake_minimum_required(VERSION 3.5)

project(LiteLighting VERSION 0.1 LANGUAGES CXX)

# set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# SET(MYCOMPILE_FLAGS "-Ofast -g -no-pie")
# SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${MYCOMPILE_FLAGS}")

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
        include/light_headers/ChannelTypeEnum.h
        include/light_headers/Fixture.h

        include/styles/main/main_palette.h
        include/styles/main/main_style.qss
        include/styles/color_constants.h
        # include/forms/mainwindow.ui

        src/light_src/Fixture.cpp
        src/light_src/FixtureArray.cpp
        src/light_src/DmxGateway.cpp


        include/qt_headers/mainwindow.h include/qt_headers/mainwindow.cpp
        include/qt_headers/pages_panel/pagespanel.h include/qt_headers/pages_panel/pagespanel.cpp
        include/qt_headers/settings_panel/settingspanel.h include/qt_headers/settings_panel/settingspanel.cpp
        include/qt_headers/control_panel/controlpanel.h include/qt_headers/control_panel/controlpanel.cpp
        include/qt_headers/middle_panel/middlepanel.h include/qt_headers/middle_panel/middlepanel.cpp

        include/qt_headers/middle_panel/patch_sheet/patchsheetwindow.h include/qt_headers/middle_panel/patch_sheet/patchsheetwindow.cpp
        include/qt_headers/middle_panel/busking/fixture_display/fixtureproperties.h
        include/qt_headers/middle_panel/busking/buskingwindow.h include/qt_headers/middle_panel/busking/buskingwindow.cpp
        include/qt_headers/middle_panel/programming/programmingwindow.h include/qt_headers/middle_panel/programming/programmingwindow.cpp
        include/qt_headers/middle_panel/settings/settingswindow.h include/qt_headers/middle_panel/settings/settingswindow.cpp
        include/qt_headers/middle_panel/executors&buttons/execbuttonswindow.h include/qt_headers/middle_panel/executors&buttons/execbuttonswindow.cpp

        include/qt_headers/middle_panel/patch_sheet/patching_modal_window/qdialogpatching.h include/qt_headers/middle_panel/patch_sheet/patching_modal_window/qdialogpatching.cpp

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
