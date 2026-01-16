// include/FizzBuzzGame.hpp
#pragma once
#include "GameConfig.hpp"
#include <vector>
#include <memory>

class Player;

class FizzBuzzGame {
public:
    // Constructor with game configuration
    explicit FizzBuzzGame(GameConfig config);
    // Runs the game
    void run();

private:
    // Game configuration
    GameConfig config_;
};
