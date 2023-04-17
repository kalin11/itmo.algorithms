#include <iostream>
#include <set>
#include <list>
#include <queue>

int main() {
    int n;
    int k;
    int p;
    int ans = 0;
    std::cin >> n >> k >> p;

    std::vector<std::list<int>> car_positions(n);
    std::vector<int> task;
    std::set<int> cars_on_the_floor;
    std::priority_queue<std::pair<int, int>> next_car_pos;
    for (int i = 0; i < p; i++){
        int val;
        std::cin >> val;
        task.push_back(val);
        car_positions[--task.at(i)].push_back(i);
    }


    for (int i = 0; i < p; i++){
        car_positions[task.at(i)].pop_front();

        // we didn't find needed car on the floor, so we have to take it from the shelf
        if (cars_on_the_floor.find(task.at(i)) == cars_on_the_floor.end()){
            if (cars_on_the_floor.size() >= k){
                cars_on_the_floor.erase(next_car_pos.top().second);
                next_car_pos.pop();
            }
            ans++;
            cars_on_the_floor.insert(task.at(i));
        }

        if (car_positions[task.at(i)].empty()) {
            std::pair<int, int> big_car_number;
            big_car_number.first = 2147483647;
            big_car_number.second = task.at(i);
            next_car_pos.push(big_car_number);
        }
        else {
            std::pair<int, int> car_number;
            car_number.first = car_positions[task.at(i)].front();
            car_number.second = task.at(i);
            next_car_pos.push(car_number);
        }

    }

    std::cout << ans;

    return 0;
}