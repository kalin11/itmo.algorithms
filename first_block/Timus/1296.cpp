#include "iostream"

int main(){
    int currentSum = 0;
    int maxSum = 0;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++){
        int p;
        std::cin >> p;
        currentSum += p;
        if (currentSum > maxSum){
            maxSum = currentSum;
        }
        if (currentSum < 0){
            currentSum = 0;
        }
    }

    std::cout << maxSum;
    return 0;
}