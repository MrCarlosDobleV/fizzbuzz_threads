// include/TurnManager.hpp
#pragma once
#include <mutex>
#include <condition_variable>

class TurnManager {
public:
    // Constructor for TurnManager
    TurnManager(int playerCount, int maxNumber);

    // Waits until it's the player's turn or the game is finished
    bool waitTurn(int playerId);

    // Returns the current number to be processed    
    int currentNumber() const;

    // Returns the id of the current player
    int currentPlayer() const;

    // Advances to the next number and updates turn
    void advance();

private:
    int playerCount_; // Total number of players
    int maxNumber_; // Maximum number to be said
    int number_ = 1; // Current number to be said
    int turn_ = 0; // playerId in current turn
    bool finished_ = false; // Indicates if the game is finished, starts as false

    mutable std::mutex mtx_; // Mutex for synchronizing access
    std::condition_variable cv_; // Condition variable for managing turns
};
