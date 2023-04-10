#include <iostream>
#include <cmath>
#include <vector>

void build_tree(std::vector<int> *tree, int first_index) {
    int i = first_index;
    int size = tree->size();
    while (i > 0) {
        tree->at((i - 1) / 2) = std::min(tree->at(i), tree->at(i + 1));
        if (i + 2 >= size) {
            i = (first_index - 1) / 2;
            first_index = i;
            size /= 2;
        } else {
            i = i + 2;
        }
    }
}

int get_min(std::vector<int> *tree, int l, int r, int node, int lx, int rx) {
    if (lx >= l && rx <= r) {
        return tree->at(node);
    }
    if (l > rx || lx > r) {
        return 2147483647;
    }
    int mid = (lx + rx) / 2;
    int minL = get_min(tree, l, r, 2 * node + 1, lx, mid);
    int minR = get_min(tree, l, r, 2 * node + 2, mid + 1, rx);
    return (minL >= minR) ? minR : minL;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> list;
    int val;
    for (int i = 0; i < n; i++) {
        std::cin >> val;
        list.push_back(val);
    }
    int size_row = pow(2, ceil(std::log2(n)));
    int arr_size = 0;
    int copy = size_row;
    while (copy >= 1){
        arr_size += copy;
        copy /= 2;
    }
    int first_index = arr_size - size_row;
    std::vector<int> tree(arr_size);
    int j = 0;
    for (int i = first_index; i < arr_size; i++) {
        if (j >= n) {
            tree.at(i) = 2147483647;
        } else {
            tree.at(i) = list.at(j++);
        }
    }
    build_tree(&tree, first_index);

    int lPtr = 0;
    int rPtr = k;
    for (int i = 0; i < n - k + 1; i++) {
        std::cout << get_min(&tree, first_index + lPtr, first_index + rPtr - 1, 0, first_index, arr_size - 1) << " ";
        lPtr++;
        rPtr++;
    }
    return 0;
}