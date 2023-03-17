#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    long long n;
    std::cin >> n;
    long long divisor = (n - 1) * n;
    long long xSum = 0;
    long long ySum = 0;
    std::vector<std::pair<int, int>> people;
    std::vector<int> x;
    std::vector<int> y;
    for (int i = 0; i < n; i++) {
        int currX;
        int currY;
        std::cin >> currX;
        std::cin >> currY;
        x.push_back(currX);
        y.push_back(currY);
    }

    std::sort(x.begin(), x.end());
    std::sort(y.begin(), y.end());

    for (int i = 1; i < n; i++) {
        xSum += (abs(x.at(i) - x.at(i - 1))) * (n - i) * 2 * i;
        ySum += (abs(y.at(i) - y.at(i - 1))) * (n - i) * 2 * i;
    }

    std::cout << (xSum + ySum) / divisor;
    return 0;
}