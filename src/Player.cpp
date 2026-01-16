// src/Player.cpp
#include "Player.hpp"
#include "TurnManager.hpp"
#include "RuleEngine.hpp"
#include <iostream>

Player::Player(int id, std::string name,
               std::shared_ptr<TurnManager> turn,
               std::shared_ptr<RuleEngine> rules)
    : id_(id), name_(std::move(name)), turn_(std::move(turn)), rules_(std::move(rules)) {}

// Starts the player's thread
void Player::start() { th_ = std::thread(&Player::run, this); }
// Joins the player's thread
void Player::join()  { if (th_.joinable()) th_.join(); }

// Main loop of the player
void Player::run() {
    while (turn_->waitTurn(id_)) { // Wait until it's this player's turn or the game is finished
        int n = turn_->currentNumber(); // Get the current number to process
        std::string said = rules_->evaluate(n); // Evaluate the rules for the number

        // Requiered format output
        // If said is the number itself, print without exclamation
        if (said == std::to_string(n)) {
            std::cout << name_ << " says " << said << "\n";
        } else { // Otherwise, print the corresponding word with exclamation 
            std::cout << name_ << " says " << said << "!\n";
        }

        turn_->advance(); // Advance to the next number and update turn
    }
}
