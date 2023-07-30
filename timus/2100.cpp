#include <iostream>
#include <string>

int main()
{
    auto number_of_friends = 0;
    auto number_of_pairs = 0;

    std::cin >> number_of_friends;

    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.find("+") != std::string::npos) {
            number_of_pairs++;
        }
    }

    int guests = 2 + number_of_friends + number_of_pairs;

    if (guests == 13) {
        std::cout << (guests * 100 + 100) << std::endl;
    }
    else {
        std::cout << (guests * 100) << std::endl;
    }
}
