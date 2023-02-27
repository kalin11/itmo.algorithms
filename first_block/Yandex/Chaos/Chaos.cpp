#include <iostream>

int main(){
    int a,b,c,d;
    long k;
    int prevValue;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> d;
    std::cin >> k;

    long currentDay = 0;
    int currentCount = 0;
    while (b != 0 && currentDay != k){
        currentCount = a * b;
        prevValue = a;
        if (currentCount >= c){
            currentCount -= c;
        }
        else {
            currentCount = 0;
            break;
        }
        if (currentCount >= d){
            currentCount = d;
            break;
        }
        else {
            if (currentCount <= 0){
                a = 0;
            }
            else {
                a = currentCount;
                if (a == prevValue){
                    break;
                }
            }
        }
        currentDay++;
    }

    std::cout << currentCount;
    return 0;

}