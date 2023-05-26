#include <iostream>
#include "src/include/Warehouse.hpp"
#include "src/include/Shelf.hpp"
#include "src/include/Pallet.hpp"
#include "src/include/Employee.hpp"


int main() {
    // Create an employee
    Employee employee("Mark", true);

    // Create a shelf
    Shelf shelf;
    shelf.pallets = {
        Pallet("Books", 100, 20),
        Pallet("Boxes", 100, 30),
        Pallet("Toys", 100, 10),
        Pallet("Lamps", 100, 40)
    };

    // Create a warehouse
    Warehouse warehouse;
    warehouse.addEmployee(employee);
    warehouse.addShelf(shelf);

    // Print the initial state of Shelf 1
    std::cout << "Shelf 1:" << std::endl;
    for (const auto& pallet : warehouse.shelves[0].pallets) {
        std::cout << pallet.getItemCount() << " " << pallet.getItemName() << " remaining in the warehouse." << std::endl;
    }
    std::cout << std::endl;

    // Pick items from the warehouse
    bool itemsPicked = warehouse.pickItems("Books", 5);
    if (itemsPicked) {
        std::cout << "Picking 5 Books from the warehouse." << std::endl;
    } else {
        std::cout << "Failed to pick books from the warehouse." << std::endl;
    }

    // Print Shelf 1 after picking
    std::cout << "Shelf 1:" << std::endl;
    for (const auto& pallet : warehouse.shelves[0].pallets) {
        std::cout << pallet.getItemCount() << " " << pallet.getItemName() << " remaining in the warehouse." << std::endl;
    }
    std::cout << std::endl;

    // Pick more items from the warehouse
    bool itemsPicked2 = warehouse.pickItems("Boxes", 20);
    if (itemsPicked2) {
        std::cout << "Picking 20 Boxes from the warehouse." << std::endl;
    } else {
        std::cout << "Failed to pick boxes from the warehouse." << std::endl;
    }

    // Print Shelf 1 after picking more items
    std::cout << "Shelf 1:" << std::endl;
    for (const auto& pallet : warehouse.shelves[0].pallets) {
        std::cout << pallet.getItemCount() << " " << pallet.getItemName() << " remaining in the warehouse." << std::endl;
    }
    std::cout << std::endl;

    // Put one item back to the warehouse
    bool putOne = warehouse.shelves[0].pallets[0].putOne();
    if (putOne) {
        std::cout << "Putting 1 Book back to the warehouse." << std::endl;
    } else {
        std::cout << "Failed to put 1 Book back to the warehouse." << std::endl;
    }

    // Print Shelf 1 after picking more items
    std::cout << "Shelf 1:" << std::endl;
    for (const auto& pallet : warehouse.shelves[0].pallets) {
        std::cout << pallet.getItemCount() << " " << pallet.getItemName() << " remaining in the warehouse." << std::endl;
    }
    std::cout << std::endl;

    // Make a copy of the shelf for rearranging
    Shelf copyShelf = warehouse.shelves[0];

    // Rearrange the shelf
    bool rearrange = warehouse.rearrangeShelf(copyShelf);
    if (rearrange) {
        std::cout << "Rearranged the shelf." << std::endl;
    } else {
        std::cout << "Failed to rearrange the shelf." << std::endl;
    }

    // Print Shelf 1 after rearranging
    std::cout << "Shelf 1:" << std::endl;
    for (const auto& pallet : copyShelf.pallets) {
        std::cout << pallet.getItemCount() << " " << pallet.getItemName() << " remaining in the warehouse." << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
