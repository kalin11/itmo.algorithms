#include <bits/stdc++.h>

class node {
public:
    std::vector<std::pair<int, int>> edges;
    int distance;
    int neighbours; 

    node() : neighbours(0), distance(-2e9) {}
};


int main() {
    int n, m, s, f;
    std::cin >> n >> m;
    node nodes[501];
    std::queue<node *> q;

    for (int i = 0; i < m; i++) {
        int v1, v2, price;
        std::cin >> v1 >> v2 >> price;
        nodes[v1].edges.emplace_back(v2, price);
        nodes[v2].neighbours++;
    }

    std::cin >> s >> f;
    nodes[s].distance = 0;

    for (int i = 1; i <= n; i++) {
        if (!nodes[i].neighbours) {
            q.push(nodes + i);
        }
    }

    while (!q.empty()) {
        auto nod = q.front();
        q.pop();
        for (auto it = nod->edges.begin(); it < nod->edges.end(); it++) {
            nodes[it->first].distance = std::max(nodes[it->first].distance, nod->distance + it->second);
            nodes[it->first].neighbours--;
            if (!nodes[it->first].neighbours) {
                q.push(nodes + it->first);
            }
        }
    }
    if (nodes[f].distance >= 0) {
        std::cout << nodes[f].distance;
    }
    else {
        std::cout << "No solution";
    }
    return 0;
}