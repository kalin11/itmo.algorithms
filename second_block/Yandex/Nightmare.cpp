#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    std::map<char, int32_t> char_weight;
    std::map<char, std::pair<int32_t, int32_t>> char_weight_count;
    std::string s;
    std::string ans;
    std::cin >> s;
    ans = s;
    std::vector<char> vector;
    int32_t power = 26;
    char letter = 'a';
    for (int i = 0; i < power; i++) {
        std::cin >> char_weight[letter];
        letter++;
    }
    for (const char &i: s) {
        char_weight_count[i].first = char_weight[i];
        char_weight_count[i].second++;
    }

    std::sort(ans.begin(), ans.end(), [char_weight_count](const char &x, const char &y) -> bool {
        if (char_weight_count.at(x).second == 1 && char_weight_count.at(y).second == 1) {
            return char_weight_count.at(x).first > char_weight_count.at(y).first;
        } else if (char_weight_count.at(x).second > 1 && char_weight_count.at(y).second > 1) {
            return char_weight_count.at(x).first > char_weight_count.at(y).first;
        } else {
            return char_weight_count.at(x).second > char_weight_count.at(y).second;
        }
    });


    for (char &an: ans) {
        if (!std::count(vector.begin(), vector.end(), an)) {
            vector.push_back(an);
        }
    }
    int a = 0;
    int b = ans.length() - 1;
    for (char &i: vector) {
        if (char_weight_count[i].second > 1) {
            s.at(a) = i;
            s.at(b) = i;
            a++;
            b--;
            char_weight_count[i].second -= 2;
        }
    }

    for (char &i: vector) {
        for (int j = 0; j < char_weight_count[i].second; j++) {
            s.at(a) = i;
            a++;
        }
    }

    std::cout << s << std::endl;


    return 0;
}