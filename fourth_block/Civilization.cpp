#include <bits/stdc++.h>

constexpr int water = -100;
constexpr int field = 1;
constexpr int wood = 2;

class Point {
public:
    int price;
    int id;

};

struct PointComparator {
    bool operator () (const Point &v1, const Point &v2) {
        return v1.price > v2.price;
    }
};

Point remove_top(std::priority_queue<Point, std::vector<Point>, PointComparator> &queue) {
    auto curr = queue.top();
    queue.pop();
    return curr;
}


int main() {
    std::ostream::sync_with_stdio(false);
    int n, m, x1, y1, x2, y2;
    std::cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    std::vector<std::vector<int>> map(n);
    std::vector<Point> visited(n * m);
    std::vector<std::vector<Point>> neighbours(n * m);
    std::vector<char> way_back;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char val;
            std::cin >> val;
            if (val == '.') {
                map[i].push_back(field);
            } else if (val == 'W') {
                map[i].push_back(wood);
            } else {
                map[i].push_back(water);
            }
        }
    }
    int start = (x1 - 1) * m + (y1 - 1);
    int end = (x2 - 1) * m + (y2 - 1);

    std::priority_queue<Point, std::vector<Point>, PointComparator> queue;
    queue.push({0, start});

    for (int i = 0; i < n * m; i++) {
        visited[i] = {-1, -1};
    }

    while (!queue.empty()) {
        auto curr = remove_top(queue);
        if (curr.id == end) break;

        int x = curr.id / m;
        int y = curr.id % m;
        if (map[x][y] == water) continue;
        if (y - 1 >= 0 && map[x][y - 1] != water) {
            neighbours[curr.id].push_back({map[x][y - 1], curr.id - 1});
        }
        if (x + 1 < n && map[x + 1][y] != water) {
            neighbours[curr.id].push_back({map[x + 1][y], curr.id + m});
        }
        if (y + 1 < m && map[x][y + 1] != water) {
            neighbours[curr.id].push_back({map[x][y + 1], curr.id + 1});
        }
        if (x - 1 >= 0 && map[x - 1][y] != water) {
            neighbours[curr.id].push_back({map[x - 1][y], curr.id - m});
        }

        for (auto next: neighbours[curr.id]) {
            int new_cost = curr.price + next.price;
            if (visited[next.id].price == -1 || new_cost < visited[next.id].price) {
                queue.push({new_cost, next.id});
                visited[next.id] = {new_cost, curr.id};
            }
        }
    }

    std::cout << visited[end].price << std::endl;


    if (visited[end].price == -1) {
        return 0;
    }
    int curr = end;
    while (curr != start) {
        int diff = curr - visited[curr].id;
        if (diff == 1) {
            way_back.push_back('E');
        }
        else if (diff == -1) {
            way_back.push_back('W');
        }
        else if (diff == m) {
            way_back.push_back('S');
        }
        else if (diff == -m) {
            way_back.push_back('N');
        }
        curr = visited[curr].id;
    }
    for (int i = way_back.size() - 1; i >= 0; i--) {
        std::cout << way_back[i];
    }
    return 0;
}