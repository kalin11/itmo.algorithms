#include <iostream>
#include <stack>
#include <map>

#define DIFFERENCE 32


int main() {

    int big = 0;
    int small = 0;

    std::string s;

    std::cin >> s;

    std::stack<char> stack;
    std::stack<int> lower;
    std::stack<int> upper;
    std::map<int, int> map;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 65 && s[i] <= 92) { // большие
            big++;
            upper.push(big);
            if (!stack.empty()) {
                if (std::abs(stack.top() - s[i]) == DIFFERENCE) {
                    map[upper.top()] = lower.top();
                    stack.pop();
                    lower.pop();
                    upper.pop();
                } else {
                    stack.push(s[i]);
                }
            } else {
                stack.push(s[i]);
            }

        } else if (s[i] >= 97 && s[i] <= 122) { // мелкие
            small++;
            lower.push(small);
            if (!stack.empty()) {
                if (std::abs(stack.top() - s[i]) == DIFFERENCE) {
                    map[upper.top()] = lower.top();
                    stack.pop();
                    lower.pop();
                    upper.pop();
                } else {
                    stack.push(s[i]);
                }
            } else {
                stack.push(s[i]);

            }
        }

    }

    if (stack.empty()) {
        std::cout << "Possible\n";
        for (auto& i : map) {
            std::cout << i.second << " ";
        }
    } else {
        std::cout << "Impossible";
    }

    return 0;
}


























