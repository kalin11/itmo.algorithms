#include "bits/stdc++.h"

int ans = 0;

void dfs(int v, std::vector<std::pair<int, std::vector<int>>> & graph){
    graph[v].first = 1;
    for(int next : graph[v].second){
        if (!graph[next].first) dfs(next, graph);
        else if (graph[next].first == 1) ans++;
    }
    graph[v].first = 2;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, std::vector<int>>> graph(n);
    for (int i = 0; i < n; i++) {
        int key;
        std::cin >> key;
        graph[key - 1].second.push_back(i);
    }

    for (int i = 0; i < n; i++)
        if (!graph[i].first) {
            dfs(i, graph);
        }
    std::cout << ans;
    return 0;
}