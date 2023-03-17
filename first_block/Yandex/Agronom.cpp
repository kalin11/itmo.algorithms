#include <iostream>

using namespace std;


int main() {
    int firstPointer = 0;
    int pointer = 0;
    int secondPointer = 0;
    int max = -1;
    int count = 1;
    int currentLength = 1;
    bool prevTwoAreSame = false;

    int n;

    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++){
        if (a[i] == a[i - 1]){
            count++;
        }
        else if (a[i] != a[i - 1]){
            count = 1;
        }
        else if (a[i] == a[i - 1] && prevTwoAreSame){
            count = 3;
        }

        if (count == 3){
            currentLength = 1;
            prevTwoAreSame = true;
            pointer = i - 1;
            count = 2;
        }

        currentLength++;
        if (currentLength > max){
            max = currentLength;
            secondPointer = i;
            firstPointer = pointer;
        }
    }

    cout << firstPointer + 1 << " " << secondPointer + 1;

    return 0;
}



