cmake_minimum_required(VERSION 3.21)

project(colloquium)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключаем GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        9706f75b8f91c52a3840cf5d878a7f37ea10ef00
)

if(MSVC)
    set(gtest_disable_pthreads ON CACHE BOOL "" FORCE)
     add_compile_definitions(_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING)
endif()
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Основная программа
add_executable(Colloquium colloquium.cpp colloquium_methods.cpp colloquium.h "Utils.cpp")

# Тесты 
add_executable(Testing test.cpp colloquium_methods.cpp "Utils.cpp")
target_link_libraries(Testing PRIVATE gtest gtest_main) 

# Включаем тестирование
enable_testing()
include(GoogleTest)
gtest_discover_tests(Testing)

add_custom_command(TARGET Testing POST_BUILD
    COMMAND Testing
    COMMENT "Запуск тестов и вывод результатов..."
)
