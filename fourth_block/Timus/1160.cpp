#include <bits/stdc++.h>

class node {
public:
    node *parent;
    int rank;
    int n;
    node() : parent(this), rank(0) {}
};

class edge {
public:
    node *a, *b;
    int weight;

    edge(node *a, node *b, int weight) : a(a), b(b), weight(weight) {}
};

void link(node *a, node *b) {
    if (a->rank > b->rank)
        b->parent = a;
    else {
        a->parent = b;
        if (a->rank == b->rank)
            b->rank++;
    }
}

node *find(node *s) {
    if (s != s->parent)
        s->parent = find(s->parent);
    return s->parent;
}

std::vector<node> points;
std::vector<edge> edges;
std::vector<edge*> ans;

int main() {
    int n, m;
    std::cin >> n >> m;
    points.reserve(n + 1);
    for (int i = 0; i < n + 1; i++) {
        points.emplace_back(node());
        points.back().parent = &points.back();
        points.back().n = i;
    }
    edges.reserve(m);
    ans.reserve(m);
    for (int i = 0; i < m; i++) {
        int v1, v2, w;
        std::cin >> v1 >> v2 >> w;
        edges.emplace_back(&points[v1], &points[v2], w);
    }
    std::sort(edges.begin(), edges.end(), [](edge &a, edge &b) { return a.weight < b.weight; });
    int max = 0;
    for (edge &e: edges) {
        if (find(e.a) != find(e.b)) {
            link(find(e.a), find(e.b));
            max = std::max(max, e.weight);
            ans.push_back(&e);
        }
    }
    std::cout << max << std::endl;
    std::cout << ans.size() << std::endl;
    for (auto e: ans) {
        std::cout << e->a->n << " " << e->b->n << std::endl;
    }
    return 0;
}