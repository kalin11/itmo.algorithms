#include <bits/stdc++.h>

bool dfs(int v, int direction, std::vector<bool> &visited, std::vector<std::vector<bool>> &G, int n) {
    visited[v] = true;
    for (int i = 0; i < n; i++) {
        bool e;
        if (direction) e = G[i][v];
        else e = G[v][i];
        if (!visited[i] && e) {
            dfs(i, direction, visited, G, n);
        }
    }

    return std::all_of(visited.begin(), visited.end(), [](bool value) { return value; });
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> graph(n);
    std::vector<bool> visited(n);
    std::vector<std::vector<bool>> G(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            std::cin >> val;
            graph[i].push_back(val);
        }
    }
    int l = 0;
    int r = 2e9;
    while (l < r) {
        int mid = (l + r) / 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (G[i].size() == n) G[i].clear();
                G[i].push_back((graph[i][j] <= mid));
            }
        }
        std::fill(visited.begin(), visited.end(), false);
        dfs(0, 0, visited, G, n);
        bool change_right_boundary = true;
        if (dfs(0, 0, visited, G, n)) {
            std::fill(visited.begin(), visited.end(), false);
            if (!dfs(0, 1, visited, G, n)) {
                change_right_boundary = false;
            }
        } else {
            change_right_boundary = false;
        }
        if (change_right_boundary) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    std::cout << l;
    return 0;
}