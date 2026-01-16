# Fizzbuzz_threads

## Carlos Mario Minu Quiroga
cm.minu10@uniandes.edu.co

A small C++17 FizzBuzz game that runs players on separate threads and coordinates turns so output stays in order.

## How it works
- A `TurnManager` serializes turns with a mutex/condition variable.
- A `RuleEngine` evaluates the number against divisor rules (e.g., 3 -> fizz, 5 -> buzz).
- Each `Player` runs in its own `std::thread` and prints on its turn.
- `FizzBuzzGame` wires everything together using a `GameConfig`.

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Run

```bash
./build/fizzbuzz
```

## Configuration
The game is configured via `GameConfig`
- `players`: list of player names in turn order.
- `rules`: map of divisor -> word.
- `maxNumber`: last number to play.

`main.cpp` shows two examples:
1. Default config with players and 3/5 rules.
2. Custom config with players and 2/7 rules.

## Example output

```text
Abdul says 1
Bart says 2
Claudia says fizz!
Divya says 4
Abdul says buzz!
```

## Project layout
- `include/` public headers
- `src/` implementation
- `CMakeLists.txt` build configuration

## Notes
- Output order is deterministic because turns are synchronized; threads only print when `TurnManager` grants their turn.
- The rule evaluation concatenates words in rule order (ascending divisor due to `std::map`).
- Each player has shared access to the `TurnManager` and the `RuleEngine`.
- Mutex ensures thread-safe turn management.
- Condition variable allows players to wait for their turn without busy-waiting.
- The game continues until the maximum number is reached, at which point all threads exit gracefully.


## Class Diagram

![Class Diagram](images/uml_fizzbuzz_threads.png)


## Sequence Diagram

![Sequence Diagram](images/sequence_diagram.png)