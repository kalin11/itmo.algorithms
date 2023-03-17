#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::string s;
    std::vector<std::string> vector;
    freopen ("C:\\Users\\kal1n\\CLionProjects\\FirstProject\\input.in", "r", stdin);
    freopen ("C:\\Users\\kal1n\\CLionProjects\\FirstProject\\output.txt", "w", stdout);
    while (std::cin >> s) {
        vector.push_back(s);
    }
    std::sort(vector.begin(), vector.end(), [] (const std::string& x, const std::string& y) -> bool { return x + y > y + x; });
    for (std::string& i : vector){
        std::cout << i;
    }
    return 0;
}