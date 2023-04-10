#include <iostream>
#include <list>
int main(){
    int n;
    std::cin >> n;
    std::list<int> left_half;
    std::list<int> right_half;
    std::string cmd;
    int goblin_num;
    for (int i = 0; i < n; i++){
        std::cin >> cmd;
        if (cmd == "-"){
            std::cout << left_half.front() << std::endl;
            left_half.pop_front();
        }
        else {
            std::cin >> goblin_num;
            if (cmd == "*"){
                left_half.push_back(goblin_num);
            }
            else {
                right_half.push_back(goblin_num);
            }
        }

        if (left_half.size() > right_half.size() + 1){
            right_half.push_front(left_half.back());
            left_half.pop_back();
        }
        else if (right_half.size() > left_half.size()){
            left_half.push_back(right_half.front());
            right_half.pop_front();
        }

    }
    return 0;
}