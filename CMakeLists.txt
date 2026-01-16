cmake_minimum_required(VERSION 3.16)
project(fizzbuzz_threads LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(fizzbuzz
  src/main.cpp
  src/RuleEngine.cpp
  src/TurnManager.cpp
  src/Player.cpp
  src/FizzBuzzGame.cpp
)

# Threads
find_package(Threads REQUIRED)
target_link_libraries(fizzbuzz PRIVATE Threads::Threads)
