cmake_minimum_required(VERSION 3.2)

# конфигурим шаблонный заголовочник в настоящий
configure_file(lib/version.h.in lib/version.h)

add_executable(helloworld_cli main.cpp)
add_library(helloworld lib/lib.cpp)

# включаем 14 стандарт для наших целей
set_target_properties(helloworld_cli helloworld PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

# кидаем нашей библиотеке helloworld в инклуды путь к сгенерированному
# version.h из version.h.in
target_include_directories(helloworld
    PRIVATE "${CMAKE_BINARY_DIR}/src/lib"
)

target_link_libraries(helloworld_cli
    helloworld
)

# максимально строгие настройки компилятора
if (MSVC)
    target_compile_options(helloworld_cli PRIVATE
        /W4
    )
    target_compile_options(helloworld PRIVATE
        /W4
    )
else ()
    target_compile_options(helloworld_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(helloworld PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

# бинарник кладем в каталог bin
install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

# генерить будем deb пакет
set(CPACK_GENERATOR DEB)

# конфигурируем deb пакет
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_CONTACT oshuev.valery@yandex.ru)

# подключем генератор пакетов
include(CPack)
