#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int k;
    int n;
    int currNum = 1;
    int sum = 0;
    std::cin >> k;
    std::vector<std::pair<int, int>> numbers;
    std::vector<int> ans;
    std::vector<int> counts;
    for (int i = 0; i < k; i++) {
        std::cin >> n;
        sum += n;
        std::pair<int, int> pair;
        pair.first = n;
        pair.second = currNum;
        numbers.push_back(pair);
        counts.push_back(numbers.at(i).first);
        for (int j = 0; j < n; j++) {
            ans.push_back(currNum);
        }
        currNum++;
    }

    // в итоге алгоритмическая сложность O(n^2) кажется
    // todo подумать над тем, как пихнуть сюда сортировку

    int maxPointer = counts.size() - 1;
    int pos = 0;
    while (counts.at(maxPointer) > 0) { // тут сумма
        int max = INT_MIN;
        int min = INT_MAX;
        std::pair<int, int> maxPair;
        std::pair<int, int> minPair;
        for (int i = 0; i < counts.size(); i++) { // k
            if (counts.at(i) > max) {
                max = counts.at(i);
                maxPointer = i;
                maxPair.first = i;
                maxPair.second = numbers.at(i).second;
            }
            if (counts.at(i) < min && counts.at(i) > 0) {
                min = counts.at(i);
                minPair.first = i;
                minPair.second = numbers.at(i).second;
            }

        }
        if (maxPair.first == minPair.first) {
            if (counts.at(maxPair.first) > 1) {
                ans.at(pos++) = maxPair.second;
            } else if (counts.at(maxPair.first) == 1) {
                ans.at(pos) = maxPair.second;
            }
            counts.at(maxPair.first)--;
        } else {
            ans.at(pos++) = maxPair.second;
            ans.at(pos++) = minPair.second;
            counts.at(maxPair.first)--;
            counts.at(minPair.first)--;
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans.at(i) << " ";
    }

    return 0;
}