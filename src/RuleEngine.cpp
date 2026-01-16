// src/RuleEngine.cpp
#include "RuleEngine.hpp"
#include <sstream>

/// Constructor for RuleEngine
RuleEngine::RuleEngine(std::map<int,std::string> rules) : rules_(std::move(rules)) {}

//Evaluates the rules for a given number n
std::string RuleEngine::evaluate(int n) const {
    std::string out;
    for (const auto& [div, word] : rules_) {
        if (div != 0 && n % div == 0) out += word; // Append word if n is divisible by div
    }
    if (out.empty()) return std::to_string(n);  // Return the number as string if no rules matched
    return out; // Return the concatenated words or number as string
}
