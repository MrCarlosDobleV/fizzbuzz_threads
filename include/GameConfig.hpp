// include/GameConfig.hpp
#pragma once
#include <string>
#include <vector>
#include <map>

struct GameConfig {
    std::vector<std::string> players; // Player names in turn order
    std::map<int, std::string> rules; // Divisor -> Word
    int maxNumber = 30;               // Max number to count to

    // Default configuration
    static GameConfig Default() {
        GameConfig c;
        c.players = {"Abdul","Bart","Claudia","Divya"};
        c.rules = {{3,"fizz"},{5,"buzz"}};
        c.maxNumber = 30;
        return c;
    }
};
