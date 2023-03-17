#include <iostream>

bool possible(int mid, const int stall[], int k, int length){
    int left = stall[0];
    int cows = 1;
    for (int i = 0; i < length; i++){
        if (stall[i] - left >= mid){
            cows++;
            left = stall[i];
        }
    }
    return cows >= k;
}

int main(){
    int n, k;
    std::cin >> n >> k;
    int stall[n];
    for (int i = 0; i < n; i++){
        std::cin >> stall[i];
    }

    int l = 0;
    int r = stall[n - 1] - stall[0] + 1;
    int mid;
    while (r - l > 1){
        mid = (r + l) / 2;
        if (possible(mid, stall, k, n)){
            l = mid;
        }
        else {
            r = mid;
        }
    }

    std::cout << l;

}