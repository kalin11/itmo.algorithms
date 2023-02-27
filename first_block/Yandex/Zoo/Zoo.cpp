#include <iostream>
#include <stack>
#include <map>

#define DIFFERENCE 32


int main() {

    int big = 0;
    int small = 0;

    std::string s;

    std::cin >> s;

    std::stack<char> stack;
    std::stack<int> lower;
    std::stack<int> upper;
    std::map<int, int> map;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 65 && s[i] <= 92) { // большие
            big++;
            upper.push(big);
            if (!stack.empty()) {
                if (std::abs(stack.top() - s[i]) == DIFFERENCE) {
                    map[upper.top()] = lower.top();
                    stack.pop();
                    lower.pop();
                    upper.pop();
                } else {
                    stack.push(s[i]);
                }
            } else {
                stack.push(s[i]);
            }

        } else if (s[i] >= 97 && s[i] <= 122) { // мелкие
            small++;
            lower.push(small);
            if (!stack.empty()) {
                if (std::abs(stack.top() - s[i]) == DIFFERENCE) {
                    map[upper.top()] = lower.top();
                    stack.pop();
                    lower.pop();
                    upper.pop();
                } else {
                    stack.push(s[i]);
                }
            } else {
                stack.push(s[i]);

            }
        }

    }

    if (stack.empty()) {
        std::cout << "Possible\n";
        for (auto& i : map) {
            std::cout << i.second << " ";
        }
    } else {
        std::cout << "Impossible";
    }

    return 0;
}


//#include <cstdint>
//#include <vector>
//#include <memory>
//#include <stack>
//#include <map>
//#include <iostream>
//
//class Placeable {
//private:
//    uint32_t _number;
//    char _letter;
//public:
//    Placeable(uint32_t number, char letter) :
//            _number(number),
//            _letter(std::tolower(letter, std::locale::classic())) {}
//
//    virtual ~Placeable() = default;
//
//    inline uint32_t getNumber() const { return _number; }
//
//    inline char getLetter() const { return _letter; }
//
//    virtual bool match(const Placeable &placeable) = 0;
//};
//
//class Animal : public Placeable {
//public:
//    inline Animal(uint32_t number, char letter) : Placeable(number, letter) {}
//
//    bool match(const Placeable &placeable) override;
//};
//
//class Cell : public Placeable {
//public:
//    inline Cell(uint32_t number, char letter) : Placeable(number, letter) {}
//
//    bool match(const Placeable &placeable) override;
//};
//
//bool Cell::match(const Placeable &placeable) {
//    if (auto cell = dynamic_cast<const Animal *>(&placeable)) {
//        if (cell->getLetter() == this->getLetter()) {
//            return true;
//        } else return false;
//    } else return false;
//}
//
//bool Animal::match(const Placeable &placeable) {
//    if (auto cell = dynamic_cast<const Cell *>(&placeable)) {
//        if (cell->getLetter() == this->getLetter()) {
//            return true;
//        } else return false;
//    } else return false;
//}
//
//auto createPlaceablesVector(const std::string &problem) {
//    std::vector<std::shared_ptr<Placeable>> placeables;
//    uint32_t lastCell = 1;
//    uint32_t lastAnimal = 1;
//    for (auto c: problem) {
//        if (std::isupper(c, std::locale::classic())) {
//            placeables.push_back(std::make_shared<Cell>(lastCell++, c));
//        } else {
//            placeables.push_back(std::make_shared<Animal>(lastAnimal++, c));
//        }
//    }
//    return placeables;
//}
//
//
//std::vector<uint32_t> solve(const std::vector<std::shared_ptr<Placeable>> &placeables) {
//    std::stack<std::shared_ptr<Placeable>> state;
//    class CellByNumberComparator {
//    public:
//        bool operator()(const std::shared_ptr<Cell> &lhs, const std::shared_ptr<Cell> &rhs) const {
//            return lhs->getNumber() < rhs->getNumber();
//        }
//    };
//    std::map<std::shared_ptr<Cell>, std::shared_ptr<Animal>, CellByNumberComparator> mappings;
//    for (const auto &p: placeables) {
//        if (!state.empty() && state.top()->match(*p)) {
//            std::shared_ptr<Animal> animal = std::dynamic_pointer_cast<Animal>(state.top());;
//            std::shared_ptr<Cell> cell = std::dynamic_pointer_cast<Cell>(state.top());
//            animal = animal ? animal : std::dynamic_pointer_cast<Animal>(p);
//            cell = cell ? cell : std::dynamic_pointer_cast<Cell>(p);
//            mappings.insert(std::make_pair(cell, animal));
//            state.pop();
//        } else {
//            state.push(p);
//        }
//    }
//
//    std::vector<uint32_t> result;
//    for (auto &m: mappings) {
//        result.push_back(m.second->getNumber());
//    }
//    return result;
//}
//
//int main() {
//    std::string input;
//    std::getline(std::cin, input);
//
//    auto result = solve(createPlaceablesVector(input));
//    if (result.empty()) {
//        std::cout << "Impossible\n";
//    } else {
//        std::cout << "Possible\n";
//        for (auto n: result) {
//            std::cout << n << " ";
//        }
//    }
//    return 0;
//}

























