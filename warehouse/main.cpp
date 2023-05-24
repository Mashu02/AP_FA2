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

    // Pick some items from the shelf
    bool itemsPicked = warehouse.pickItems("Books", 5);
    if (itemsPicked) {
        std::cout << "Successfully picked 5 books from the warehouse." << std::endl;
    } else {
        std::cout << "Failed to pick books from the warehouse." << std::endl;
    }

    bool rearrange = warehouse.rearrangeShelf(shelf);
    if (rearrange) {
        std::cout << "Successfully rearranged the shelf." << std::endl;
    } else {
        std::cout << "Failed to rearrange the shelf." << std::endl;
    }
    return 0;
}
