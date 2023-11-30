cmake_minimum_required(VERSION 3.26)
project(Artify)

set(CMAKE_CXX_STANDARD 17)

add_executable(Artify main.cpp
        API.cpp
        API.h
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
        Label.h
        DropdownMenu.cpp
        DropdownMenu.h
        InputBox.cpp
        InputBox.h
        ItemList.cpp
        ItemList.h
        Item.cpp
        Item.h
        Menu.cpp
        Menu.h
        MenuBar.cpp
        MenuBar.h
        FileItem.cpp
        FileItem.h
        FileNode.h
        FileTree.cpp
        FileTree.h
        Images.cpp
        Images.h
        ImageEnum.h
        FileNode.cpp
        Artify.cpp
        Artify.h
        Logo.cpp
        Logo.h
        Files.cpp
        Files.h
        PromptScreen.cpp
        PromptScreen.h
        EditScreen.cpp
        EditScreen.h)
include_directories(/usr/local/include)

find_package(SFML 2.6 COMPONENTS system window graphics network audio REQUIRED)
find_package(nlohmann_json 3.2.0 REQUIRED)
find_package(CURL REQUIRED)
target_link_libraries(Artify CURL::libcurl)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Artify sfml-system sfml-window sfml-network sfml-graphics sfml-audio)