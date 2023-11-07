cmake_minimum_required(VERSION 3.26)
project(TextInput)

set(CMAKE_CXX_STANDARD 17)

add_executable(TextInput main.cpp
        FontEnum.h
        Fonts.h
        Fonts.cpp
        Letter.h
        Letter.cpp
        MultiText.h
        MultiText.cpp
        Typing.h
        Typing.cpp
        States.cpp
        States.h
        ObjectState.h
        Snapshot.h
        Box.cpp
        Box.h
        SnapshotInterface.cpp
        SnapshotInterface.h
        Application.cpp
        Application.h
        GUIComponent.cpp
        GUIComponent.h
        MouseEvents.cpp
        MouseEvents.h
        History.cpp
        History.h
        HistoryNode.h
        TextInput.cpp
        TextInput.h
        Snapshot.cpp
        EventHandler.h
        KeyShortcuts.h
        KeyShortcuts.cpp
        TextBox.h
        TextBox.cpp
        Cursor.cpp
        Cursor.h
        Label.cpp
        Label.h)
include_directories(/usr/local/include)

find_package(SFML 2.6 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(TextInput sfml-system sfml-window sfml-network sfml-graphics sfml-audio)