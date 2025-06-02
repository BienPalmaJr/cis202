/*
    File: main.cpp
    Description: This program takes a list of pizza orders and outputs various sorted pizza order lists. First, it outputs the original pizza list. Then, it outputs sorted pizza order lists by ascending pizza sizes, alphabetical order by name, and ascending price.
    Author: Bienvenido Palma Jr
    Email: bienvep8368@student.vvc.edu
    Course#: CIS-202-30001-2025SP-OL
    Section#: 30001
    Date: June 1, 2025
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct PizzaOrder {
    std::string name;
    int size;
};

struct PizzaOrderWithPrice {
    std::string name;
    int size;
    double price;
};


int main() {
    std::vector<PizzaOrder> orders = {
        {"Alice", 12}, {"Bob", 16}, {"Charlie", 10}, {"Diana", 14}
    };

    std::vector<PizzaOrderWithPrice> ordersWithPrice{
        {"Alice", 12, 11.99}, {"Bob", 16, 15.49}, {"Charlie", 10, 9.99}, {"Diana", 14, 13.75}
    };

    //output original pizza orders list
    std::cout << std::endl << "Original Pizza Orders:\n";
    for (const auto order : orders)
        std::cout << order.name << " " << order.size << " inches\n";


    //sort list by ascending pizza sizes
    std::sort(orders.begin(), orders.end(), [](const PizzaOrder& a, const PizzaOrder& b) {
        return a.size < b.size;
        });

    //output list by ascending pizza sizes
    std::cout << std::endl << "Sorted by Size (Ascending):\n";
    for (const auto& order : orders)
        std::cout << order.name << " " << order.size << " inches\n";



    //sort list by alphabetical names
    std::sort(orders.begin(), orders.end(), [](const PizzaOrder& a, const PizzaOrder& b) {
        return a.name < b.name;
        });

    //output list alphabetical names 
    std::cout << std::endl << "Sorted by Name (Alphabetical):\n";
    for (const auto& order : orders)
        std::cout << order.name << " " << order.size << " inches\n";



    //sort list by ascending price
    std::sort(ordersWithPrice.begin(), ordersWithPrice.end(), [](const PizzaOrderWithPrice& a, const PizzaOrderWithPrice& b) {
        return a.price < b.price;
        });


    //output list ascending price
    std::cout << endl << "Sorted by Price (Ascending):\n";
    for (int i = 0; i < ordersWithPrice.size(); i++) {
        std::cout << ordersWithPrice[i].name << " " << ordersWithPrice[i].size << " inches $" << ordersWithPrice[i].price;
        //if not at the end of the list, then output a newline character
        //prevents newline character from being output at the last iteration of the for loop
        if (i < ordersWithPrice.size() - 1) {
            std::cout << '\n';
        }
    }



    return 0;
}