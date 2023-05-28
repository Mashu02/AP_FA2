#define CATCH_CONFIG_MAIN
#include "include/catch.hpp"

#include "../src/warehouse.cpp"
#include "../src/shelf.cpp"
#include "../src/pallet.cpp"
#include "../src/employee.cpp"

#include <iostream>

//Employee
TEST_CASE("Employee construction", "[Employee]") {
    SECTION("Valid employee creation") {
        Employee employee("Mark", true);
        REQUIRE(employee.getName() == "Mark");
        REQUIRE(employee.getForkliftCertificate() == true);
        REQUIRE(employee.getBusy() == false);
    }
}

TEST_CASE("Employee forklift certificate", "[Employee]") {
    Employee employee("Mark", false);

    SECTION("Set forklift certificate") {
        employee.setForkliftCertificate(true);
        REQUIRE(employee.getForkliftCertificate() == true);
        
    }
    SECTION("Unset forklift certificate") {
        employee.setForkliftCertificate(false);
        REQUIRE(employee.getForkliftCertificate() == false);
    }
}


TEST_CASE("Employee busy status", "[Employee]") {
    Employee employee("Mark", true);

    SECTION("Set busy status") {
        employee.setBusy(true);
        REQUIRE(employee.getBusy() == true);
    }

    SECTION("Unset busy status") {
        employee.setBusy(false);
        REQUIRE(employee.getBusy() == false);
    }
}


//Pallet
TEST_CASE("Pallet construction", "[Pallet]") {
    SECTION("Valid pallet creation") {
        Pallet pallet("Books", 100, 20);
        REQUIRE(pallet.getItemName() == "Books");
        REQUIRE(pallet.getItemCount() == 20);
        REQUIRE(pallet.getRemainingSpace() == 80);
    }
}

TEST_CASE("Pallet item count manipulation", "[Pallet]") {
    Pallet pallet("Books", 100, 20);
    Pallet pallet2("Lamps", 50, 5);

    SECTION("Increase item count") {
        pallet.putOne();
        REQUIRE(pallet.getItemCount() == 21);
    }

    SECTION("Decrease item count") {
        pallet2.takeOne();
        pallet2.takeOne();
        REQUIRE(pallet2.getItemCount() == 3);
    }
}

TEST_CASE("Pallet reallocate", "[Pallet]") {
    //shouldnt work on pallet with items
    //should work on pallet without items
    Pallet pallet("Books", 100, 20);
    Pallet pallet2("Lamps", 50, 0);

    REQUIRE(pallet.reallocateEmptyPallet("Bikes", 100) == 0);
    REQUIRE(pallet2.reallocateEmptyPallet("Rocks", 50) == 1);
}

TEST_CASE("Pallet override", "[Pallet]")
{
    Pallet pallet("Books", 100, 40);
    Pallet pallet2("Lamps", 100, 0);
    Pallet pallet3("Boxes", 100, 100);

    REQUIRE(pallet.isEmpty() == 0);
    REQUIRE(pallet.isFull() == 0);

    REQUIRE(pallet2.isFull() == 0);
    REQUIRE(pallet2.isEmpty() == 1);

    REQUIRE(pallet3.isFull() == 1);
    REQUIRE(pallet3.isEmpty() == 0);
}


//Shelf
TEST_CASE("Shelf construction", "[Shelf]") {
    SECTION("Default shelf creation") {
        Shelf shelf;
        REQUIRE(shelf.isEmpty() == true);
    }

    SECTION("Shelf creation with pallets") {
        Shelf shelf;
        shelf.pallets = {
            Pallet("Books", 100, 20),
            Pallet("Boxes", 100, 30),
            Pallet("Toys", 100, 10),
            Pallet("Lamps", 100, 40)
        };

        Shelf shelf2;
        shelf.pallets = {
            Pallet("Books", 100, 100),
            Pallet("Boxes", 100, 100),
            Pallet("Toys", 100, 100),
            Pallet("Lamps", 100, 100)
        };

        REQUIRE(shelf.isEmpty() == false);
        REQUIRE(shelf.isFull() == false);
    }
}

TEST_CASE("Shelf swap", "[Shelf]")
{
    Shelf shelf;
    shelf.pallets = {
        Pallet("Books", 100, 20),
        Pallet("Boxes", 100, 30),
        Pallet("Toys", 100, 10),
        Pallet("Lamps", 100, 40)
    };
    
    shelf.swapPallet(0, 1);
    
    REQUIRE(shelf.pallets[0].getItemName() == "Boxes");
    REQUIRE(shelf.pallets[1].getItemName() == "Books");

    //shouldnt work so false
    REQUIRE(shelf.swapPallet(5, -1) == false);
}


//Warehouse
TEST_CASE("Warehouse creation", "[Warehouse]") {
    Employee employee("Mark", true);
    Warehouse warehouse;
    Shelf shelf;
    shelf.pallets = {
        Pallet("Books", 100, 20),
        Pallet("Boxes", 100, 30),
        Pallet("Toys", 100, 10),
        Pallet("Lamps", 100, 40)
    };

    warehouse.addShelf(shelf);
    warehouse.addEmployee(employee);

    REQUIRE(warehouse.pickItems("Books", 10) == true);
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 10);
}

TEST_CASE("Warehouse pickitems", "[Warehouse]") {
    Employee employee("Mark", true);
    Warehouse warehouse;
    Shelf shelf;
    shelf.pallets = {
        Pallet("Books", 100, 20),
        Pallet("Boxes", 100, 30),
        Pallet("Toys", 100, 10),
        Pallet("Lamps", 100, 40)
    };
    Shelf shelf2;
    shelf2.pallets = {
        Pallet("Books", 100, 50),
        Pallet("Books", 100, 10),
        Pallet("Books", 100, 40),
        Pallet("Lamps", 100, 40)
    };

    warehouse.addShelf(shelf);
    warehouse.addShelf(shelf2);
    warehouse.addEmployee(employee);

    REQUIRE(warehouse.pickItems("Books", 10) == true);
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 10);

    REQUIRE(warehouse.pickItems("Boxes", 30) == true);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 0);

    REQUIRE(warehouse.pickItems("Toys", 50) == false);

}

TEST_CASE("Warehouse employee", "[Warehouse]") {
    Warehouse warehouse;
    Employee employee1("Bob", true);
    Employee employee2("Alice", false);
    warehouse.addEmployee(employee1);
    warehouse.addEmployee(employee2);

    //moet overload
    // SECTION("Get employee by index") {
    //     REQUIRE(warehouse.getEmployee("Bob") == employee1);
    //     REQUIRE(warehouse.getEmployee("Alice") == employee2);
    // }
}