cmake_minimum_required(VERSION 3.2)

add_executable(test_version_boost test_version_boost.cpp)

# включаем 14 стандарт для наших целей
set_target_properties(test_version_boost PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

set_target_properties(test_version_boost PROPERTIES
    COMPILE_DEFINITIONS
    BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

# подключим инклуды из основного каталога проекта
target_include_directories(test_version_boost
    PRIVATE "${PROJECT_SOURCE_DIR}/src"
)

target_link_libraries(test_version_boost
    ${Boost_LIBRARIES}
    helloworld
)

# максимально строгие настройки компилятора
if (MSVC)
    target_compile_options(test_version_boost PRIVATE
        /W4
    )
else ()
    target_compile_options(test_version_boost PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

add_test(test_version_boost test_version_boost)
