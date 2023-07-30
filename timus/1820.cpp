#include <iostream>

int main()
{
    auto steaks = 0;
    auto pan_capacity = 0;

    std::cin >> steaks >> pan_capacity;

    if (pan_capacity >= steaks)
        std::cout << 2 << std::endl;
    else {
        if ((2 * steaks) % pan_capacity == 0) {
            std::cout << ((steaks * 2) / pan_capacity + 1) << std::endl;
        }
    }
    return 0;
}
