if (WIN32)
    set(BOOST_ROOT "C:\\Program Files\\Boost\\boost_1_79_0")
    set(Boost_USE_STATIC_LIBS        ON)
    set(Boost_USE_MULTITHREADED      ON)
    set(Boost_USE_STATIC_RUNTIME    OFF)
    SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "C:\\Program Files\\Boost\\boost_1_79_0")
    SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "C:\\Program Files\\Boost\\boost_1_79_0\\stage\\lib")
    find_package(Boost 1.79.0 COMPONENTS thread serialization QUIET)
    if (Boost_FOUND)
        include_directories(${Boost_INCLUDE_DIRS})
    endif (Boost_FOUND)
    find_package(raylib 4.0.0 QUIET)
    if (NOT raylib_FOUND)
        include(FetchContent)
        FetchContent_Declare(
                raylib
                URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz
        )
        FetchContent_GetProperties(raylib)
        if (NOT raylib_POPULATED)
            set(FETCHCONTENT_QUIET NO)
            FetchContent_Populate(raylib)
            set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
            add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
        endif()
    endif()
else()
    find_package(raylib REQUIRED)
    find_package(Boost COMPONENTS system serialization REQUIRED)
endif()

include_directories(${Boost_INCLUDE_DIRS})
# include sources
file(GLOB SOURCES
    #raylib
    "raylib/camera/*.cpp"
    "raylib/color/*.cpp"
    "raylib/gamepad/*.cpp"
    "raylib/keyboard/*.cpp"
    "raylib/rectangle/*.cpp"
    "raylib/model/*.cpp"
    "raylib/mouse/*.cpp"
    "raylib/music/*.cpp"
    "raylib/sound/*.cpp"
    "raylib/text/*.cpp"
    "raylib/texture/*.cpp"
    "raylib/vector/*.cpp"
    "raylib/window/*.cpp"
    "raylib/error/*.cpp"
    #objects
    "objects/button/*.cpp"
    #network
    #"network/*.cpp"
    #"network/error/*.cpp"
    #"network/protocol/*.cpp"
    #gameEngine
    "gameEngine/entity/interface/*.cpp"
    "gameEngine/entity/*.cpp"
    "gameEngine/movement/*.cpp"
    "gameEngine/*.cpp"
    "gameEngine/ia/*.cpp"
    #game
    "game/saver/*.cpp"
    "game/sceneHandler/*.cpp"
    "game/sceneHandler/OptionScenes/*.cpp"
    "game/sceneHandler/SceneSplash.cpp"
    "game/sceneHandler/SceneGame.cpp"
    "game/sceneHandler/SceneLoad.cpp"
    "game/inputHandler/*.cpp"
    "game/Button/*.cpp"
    "game/Models/*.cpp"
    "InputBox/*.cpp"
    )
add_executable(bomberman ${SOURCES})
target_link_libraries(bomberman ${Boost_LIBRARIES})
target_link_libraries(bomberman raylib)