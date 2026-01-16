// src/TurnManager.cpp
#include "TurnManager.hpp"

TurnManager::TurnManager(int playerCount, int maxNumber)
    : playerCount_(playerCount), maxNumber_(maxNumber) {}

// Waits until it's the player's turn or the game is finished
bool TurnManager::waitTurn(int playerId) {
    std::unique_lock<std::mutex> lock(mtx_);
    cv_.wait(lock, [&]{ return finished_ || turn_ == playerId; });
    return !finished_; //Returns false if the game is finished, to exit the player loop; true if it's the player's turn
}

// Returns the current number to be processed
int TurnManager::currentNumber() const {
    // Lock for thread safety
    std::lock_guard<std::mutex> lock(mtx_);
    return number_;
}

// Returns the id of the current player
int TurnManager::currentPlayer() const {
    // Lock for thread safety
    std::lock_guard<std::mutex> lock(mtx_);
    return turn_;
}

// Advances to the next number and updates turn
void TurnManager::advance() {
    // Lock for thread safety
    std::lock_guard<std::mutex> lock(mtx_);

    // Advance number
    number_++;
    if (number_ > maxNumber_) {
        finished_ = true;
        cv_.notify_all();
        return;
    }

    // Advance turn
    turn_ = (turn_ + 1) % playerCount_; // Cycle through players (0 to playerCount_-1)
    cv_.notify_all(); // Notify all waiting players to verify if it's their turn
}
