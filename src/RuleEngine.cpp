// src/RuleEngine.cpp
#include "RuleEngine.hpp"
#include <sstream>

RuleEngine::RuleEngine(std::map<int,std::string> rules) : rules_(std::move(rules)) {}

std::string RuleEngine::evaluate(int n) const {
    std::string out;
    for (const auto& [div, word] : rules_) {
        if (div != 0 && n % div == 0) out += word;
    }
    if (out.empty()) return std::to_string(n);
    return out;
}
