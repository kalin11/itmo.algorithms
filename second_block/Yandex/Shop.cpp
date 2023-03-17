#include <iostream>
#include <algorithm>

int main(){
    int n,k;
    std::cin >> n >> k;
    int a[n];
    int ans = 0;
    for (int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    std::sort(a, a + n, std::greater_equal<>());

    for (int i = 0; i < n; i++){
        if ((i + 1) % k != 0) ans += a[i];
    }

    std::cout << ans;
    return 0;
}