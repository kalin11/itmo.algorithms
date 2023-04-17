#include <iostream>
#include <map>
#include <vector>

std::multimap<int, int> multimap_size_index;
std::map<int, int> map_index_size;

void remove(const std::map<int, int>::iterator &it) {
    auto x = multimap_size_index.find(it->second);
    while (x->second != it->first) {
        x.operator++();
    }
    multimap_size_index.erase(x);
    map_index_size.erase(it);
}

void insert(const std::pair<int, int> &pair) {
    map_index_size.insert(pair);
    multimap_size_index.insert({pair.second, pair.first});
}

int main() {
    int n, m, k;
    int index, size;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> history(m);
    insert({1, n});
    for (int i = 0; i < m; history[i] = {k, index}, i++) {
        index = 0;
        std::cin >> k;
        if (k < 0) {
            int index_history = history.at(-k - 1).second;
            int size_history = history.at(-k - 1).first;
            if (index_history == -1) {
                continue;
            } else {
                auto right = map_index_size.lower_bound(index_history);
                auto left = right;
                if (right != map_index_size.begin()) {
                    left = std::prev(right);
                } else {
                    left = map_index_size.end();
                }

                if (right->first == index_history + size_history && right != map_index_size.end()) {
                    if (left->first + left->second == index_history && left != map_index_size.end()) {
                        size = left->second + right->second;
                        index = left->first;
                        remove(left);
                        remove(right);
                        insert({index, size + size_history});
                    } else {
                        size = right->second;
                        remove(right);
                        insert({index_history, size + size_history});
                    }
                } else {
                    if (left->first + left->second == index_history && left != map_index_size.end()) {
                        size = left->second;
                        index = left->first;
                        remove(left);
                        insert({index, size + size_history});
                    } else {
                        insert({index_history, size_history});
                    }
                }
            }
        } else {
            auto it = multimap_size_index.lower_bound(k);
            if (it == multimap_size_index.end()) {
                index = -1;
                std::cout << index << std::endl;
            } else {
                size = it->first - k;
                index = it->second;
                map_index_size.erase(it->second);
                multimap_size_index.erase(it);
                if (size > 0) {
                    insert({index + k, size});
                }
                std::cout << index << std::endl;
            }
        }
    }
    return 0;
}