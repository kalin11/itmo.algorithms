#include "iostream"

int main() {
    int a, b, c, d, e, f, g, h;
    std::cin >> a >> b >> c >> d >> e >> f >> g >> h;
    if ((a + c + h + f) != (e + d + g + b)) {
        std::cout << "IMPOSSIBLE";
    } else {
        while (e + d + g + b > 0) {
            if (d > 0) {
                if (a > 0) {
                    a--;
                    std::cout << "DA-" << std::endl;
                } else if (c > 0) {
                    c--;
                    std::cout << "DC-" << std::endl;
                } else if (h > 0) {
                    h--;
                    std::cout << "DH-" << std::endl;
                } else if (f > 0) {
                    f--;
                    std::cout << "AB+" << std::endl << "AD-" << std::endl << "BF-" << std::endl;
                }
                d--;
            }
            else if (b > 0) {
                if (a > 0) {
                    a--;
                    std::cout << "BA-" << std::endl;
                } else if (f > 0) {
                    f--;
                    std::cout << "BF-" << std::endl;
                } else if (c > 0) {
                    c--;
                    std::cout << "BC-" << std::endl;
                } else if (h > 0) {
                    h--;
                    std::cout << "AE+" << std::endl << "AB-" << std::endl << "EH-" << std::endl;
                }
                b--;
            }
            else if (g > 0) {
                if (h > 0) {
                    h--;
                    std::cout << "GH-" << std::endl;
                } else if (f > 0) {
                    f--;
                    std::cout << "GF-" << std::endl;
                } else if (c > 0) {
                    c--;
                    std::cout << "GC-" << std::endl;
                } else if (a > 0) {
                    a--;
                    std::cout << "BC+" << std::endl << "CG-" << std::endl << "AB-" << std::endl;
                }
                g--;
            }
            else if (e > 0) {
                if (f > 0) {
                    f--;
                    std::cout << "EF-" << std::endl;
                } else if (a > 0) {
                    a--;
                    std::cout << "EA-" << std::endl;
                } else if (h > 0) {
                    h--;
                    std::cout << "EH-" << std::endl;
                } else if (c > 0) {
                    c--;
                    std::cout << "AD+" << std::endl << "AE-" << std::endl << "DC-" << std::endl;
                }
                e--;
            }


        }
    }
    return 0;
}
