cmake_minimum_required(VERSION 3.2)

# устанавливаем имя проекта и его версию
if(DEFINED ENV{TRAVIS_BUILD_NUMBER})
    message("TRAVIS_BUILD_NUMBER IS DEFINED:" $ENV{TRAVIS_BUILD_NUMBER})
    project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
    message("TRAVIS_BUILD_NUMBER IS NOT DEFINED")
    project(helloworld VERSION 0.0.1)
endif()

# поиск тестового фреймворка из состава буста
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

# включаем тесты
enable_testing()

# подключаем тесты
add_subdirectory(src)
add_subdirectory(test)
