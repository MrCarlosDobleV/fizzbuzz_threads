// include/RuleEngine.hpp
#pragma once
#include <string>
#include <map>

class RuleEngine {
public:
    /// Constructor for RuleEngine
    explicit RuleEngine(std::map<int,std::string> rules);
    /// Evaluates the rules for a given number n
    std::string evaluate(int n) const;
private:
    // Map of rules: divisor -> word
    std::map<int,std::string> rules_;
};
