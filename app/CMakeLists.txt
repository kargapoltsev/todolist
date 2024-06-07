set(NAME todolist)

set (SOURCES_LIST
    main.cpp
)

add_executable(${NAME} ${SOURCES_LIST})

find_package(gtest REQUIRED)
find_package(ftxui REQUIRED)

target_link_libraries(${NAME} PRIVATE gtest::gtest ftxui::ftxui)
 