#include <iostream>
#include <map>
#include <sstream>
#include <string>

struct Directory {
    std::map<std::string , Directory*> sub_directories;
};

Directory root_directories[60000];

unsigned int root_dir_num = 1;

Directory* add_dir(Directory* root, const std::string& child_name) {
    auto& d = root->sub_directories[child_name];

    if (!d) {
        d = &root_directories[root_dir_num++];
    }
    return d;
}

void print_dirs(Directory* directory, const std::string& tabs = "") {
    for (const auto& root_dir : directory->sub_directories) {
        std::cout << tabs << root_dir.first << std::endl;
        print_dirs(root_dir.second, tabs + " ");
    }
}

int main(){
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string str, directory_name;
        std::cin >> str;
        std::stringstream ss(str);
        Directory* dir = &root_directories[0];

        while (getline(ss, directory_name, '\\')) {
            dir = add_dir(dir, directory_name);
        }
    }

    std::stringstream out;
    print_dirs(&root_directories[0]);
}