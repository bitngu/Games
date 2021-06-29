cmake_minimum_required(VERSION 3.12)
project(NCursesConnectN C)

set(CMAKE_C_STANDARD 11)
set(CURSES_USE_NCURSES_TRUE)
find_package(Curses REQUIRED)

add_executable(NCursesConnectN main.c Board.c Board.h win.c win.h trackWinCursor.c trackWinCursor.h Move.c Move.h)
target_compile_options(NCursesConnectN PRIVATE -Wall -Werror)
target_link_libraries(NCursesConnectN PRIVATE ${CURSES_LIBRARIES})
target_include_directories(NCursesConnectN PRIVATE ${CURSES_INCLUDE_DIRS})

