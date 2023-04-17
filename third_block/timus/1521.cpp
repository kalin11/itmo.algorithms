#include <iostream>
#include <vector>

int find_mth_max(std::vector<int> * tree, int m, int n_max) {
    int x = 1;

    while (2 * x < n_max) {
        if (tree->at(x * 2) >= m) {
            x *= 2;
        }
        else {
            m -= tree->at(x * 2);
            x = x * 2 + 1;
        }
    }
    if (tree->at(x) == 2)
        return tree->at(2 * x + m - 1);
    else if (tree->at(2 * x + 1) != 0) {
        return tree->at(2 * x + 1);
    }
    else {
        return tree->at(2 * x);
    }
}

void build_tree(std::vector<int> * tree, int n, int n_max) {
    for (int i = 0; i < n; i++)
        tree->at(n_max + i) = i + 1;
    for (int i = n_max - 1; i > 0; i--) {
        if (2 * i >= n_max) {
            tree->at(i) = 0;
            if (tree->at(2 * i) != 0)
                tree->at(i)++;
            if (tree->at(2 * i + 1) != 0)
                tree->at(i)++;
        }
        else
            tree->at(i) = tree->at(2 * i) + tree->at(2 * i + 1);
    }
}

int main() {
    int n, k;
    std::cin >> n >> k;

    if (n == 1) {
        std::cout << 1;
        return 0;
    }

    int n_max = 1;
    while (n_max < n)
        n_max <<= 1;
    std::vector<int> tree(2 * n_max);
    build_tree(&tree, n, n_max);
    int prev = 0;
    while (n > 0) {
        prev = (prev + k - 1) % n;
        n--;
        int index = find_mth_max(&tree, prev + 1, n_max);
        std::cout << index << " ";
        tree[n_max + index - 1] = 0;

        int j = n_max + index - 1;
        while (j > 1) {
            j /= 2;
            tree[j]--;
        }
    }

    return 0;
}