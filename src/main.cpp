// src/main.cpp
#include "FizzBuzzGame.hpp"
#include <iostream>

int main() {
    // Modo 1: default (names y 3/5)
    {
        auto config = GameConfig::Default();
        config.maxNumber = 30;
        FizzBuzzGame game(config);
        game.run();
    }

    std::cout << "----\n";

    // Modo 2: custom
    {
        GameConfig config;
        config.players = {"Ana","Luis","Sofi"};
        config.rules = {{2,"foo"},{7,"bar"}};
        config.maxNumber = 25;

        FizzBuzzGame game(config);
        game.run();
    }

    return 0;
}
