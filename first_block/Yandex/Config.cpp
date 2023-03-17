#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <stack>
#include <list>
#include "vector"

#define DELIMITER "="
#define START_BLOCK "{"
#define END_BLOCK "}"

bool isNumber(const std::string &s) {
    try {
        std::stol(s);
    } catch (const std::invalid_argument &) {
        return false;
    }
    return true;
}

std::pair<std::string, std::string> parse_by_delimiter(const std::string &s, const std::string &delimiter) {
    std::string first;
    std::string second;
    first = s.substr(0, s.find(delimiter));
    second = s.substr(s.find(delimiter) + 1);
    std::pair<std::string, std::string> pair;
    pair.first = first;
    pair.second = second;
    return pair;
}

int main() {
    std::ostream::sync_with_stdio(false);
    constexpr int default_value = 0;
    std::string s;
    std::string delimiter = DELIMITER;
    std::map<std::string, std::stack<long>> stack_for_variable;
    std::unordered_map<int, std::vector<std::string>> block_changes;
    int scopeNum = 0;
    std::pair<std::string, std::string> pair;
    while (std::getline(std::cin, s) && !std::equal(s.begin(), s.end(), "\0")) {
        if (std::equal(s.begin(), s.end(),START_BLOCK)){
            scopeNum++;
        }
        else if (std::equal(s.begin(), s.end(),END_BLOCK)){
            for (auto const& element : block_changes[scopeNum]){
                stack_for_variable[element].pop();
            }
            block_changes[scopeNum].clear();
            scopeNum--;
        }

        else{
            pair = parse_by_delimiter(s, DELIMITER);
            if (!isNumber(pair.second)) {
                if (stack_for_variable[pair.second].empty()){
                    stack_for_variable[pair.second].push(default_value);
                    stack_for_variable[pair.first].push(default_value);
                    block_changes[scopeNum].push_back(pair.first);
                    block_changes[scopeNum].push_back(pair.second);
                }
                else {
                    stack_for_variable[pair.first].push(stack_for_variable[pair.second].top());
                    block_changes[scopeNum].push_back(pair.first);
                }

                std::cout << stack_for_variable[pair.second].top() << std::endl;

            }
            else {
                stack_for_variable[pair.first].push(std::stol(pair.second));
                block_changes[scopeNum].push_back(pair.first);
            }
        }

    }
    return 0;
}