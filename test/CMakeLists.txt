cmake_minimum_required(VERSION 3.2)

add_executable(test_version test_version.cpp)

# включаем 14 стандарт для наших целей
set_target_properties(test_version PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

set_target_properties(test_version PROPERTIES
    COMPILE_DEFINITIONS
    BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

# подключим инклуды из основного каталога проекта
target_include_directories(test_version
    PRIVATE "${PROJECT_SOURCE_DIR}/src"
)

target_link_libraries(test_version
    ${Boost_LIBRARIES}
    helloworld
)

# максимально строгие настройки компилятора
if (MSVC)
    target_compile_options(test_version PRIVATE
        /W4
    )
else ()
    target_compile_options(test_version PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

add_test(test_version test_version)
