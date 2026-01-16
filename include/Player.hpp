// include/Player.hpp
#pragma once
#include <string>
#include <thread>
#include <memory>

class TurnManager;
class RuleEngine;

class Player {
public:
    Player(int id, // Unique identifier for the player (starts from 0)
            std::string name, // Name of the player
            std::shared_ptr<TurnManager> turn, // Each player has shared access to the TurnManager
            std::shared_ptr<RuleEngine> rules);  // Each player has shared access to the RuleEngine

    // Starts the player's thread
    void start();
    // Joins the player's thread
    void join();

private:
    // Main loop of the player
    void run();
    
    // Unique identifier for the player
    int id_; 
    // Name of the player
    std::string name_; 
    // Shared pointer to the TurnManager 
    std::shared_ptr<TurnManager> turn_; 
    // Shared pointer to the RuleEngine
    std::shared_ptr<RuleEngine> rules_;
    // Thread object for the player 
    std::thread th_; 
};
