#include "bits/stdc++.h"

constexpr short RED = 1;
constexpr short BLACK = 2;

short inverse_color(short color) {
    if (color == RED) return BLACK;
    return RED;
}

void dfs(std::vector<std::vector<int>> &graph, short color, int v, std::vector<short> &colors) {
    colors[v] = color;

    for (int u : graph[v]) {
        if (colors[u] == color) {
            std::cout << "NO";
            exit(0);
        }
        else if (!colors[u]){
            dfs(graph, inverse_color(color), u, colors);
        }
    }

}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n + 1);
    std::vector<short> colors(n + 1);
    for (int i = 0; i < m; i++) {
        int first_num, second_num;
        std::cin >> first_num >> second_num;
        graph[first_num].push_back(second_num);
        graph[second_num].push_back(first_num);
    }

    for (int i = 1; i < n + 1; i++) {
        if (!colors[i]) dfs(graph, RED, i, colors);
    }

    std::cout << "YES";
    return 0;

}