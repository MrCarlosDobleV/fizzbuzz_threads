// src/FizzBuzzGame.cpp
#include "FizzBuzzGame.hpp"
#include "TurnManager.hpp"
#include "RuleEngine.hpp"
#include "Player.hpp"

// Constructor with game configuration
FizzBuzzGame::FizzBuzzGame(GameConfig config) : config_(std::move(config)) {}

void FizzBuzzGame::run() {

    // Create shared TurnManager
    auto turn = std::make_shared<TurnManager>((int)config_.players.size(), config_.maxNumber);
    // Create shared RuleEngine
    auto rules = std::make_shared<RuleEngine>(config_.rules);

    // Players container
    std::vector<std::unique_ptr<Player>> players;
    players.reserve(config_.players.size());

    // Create players   
    for (int i = 0; i < (int)config_.players.size(); ++i) {
        players.push_back(std::make_unique<Player>(i, config_.players[i], turn, rules));
    }
    // Start players threads
    for (auto& p : players) p->start();
    // Wait for all players to finish
    for (auto& p : players) p->join();
}
