#pragma once
#include <vector>
#include "employee.hpp"
#include "shelf.hpp"

class Warehouse {
private:
    std::vector<Employee> employees;
    

public:
    std::vector<Shelf> shelves;
    Warehouse();
    
    void addEmployee(const Employee& employee);
    // Employee* getEmployee(int employeeID);
    void addShelf(const Shelf& shelf);
    bool rearrangeShelf(Shelf& shelf);
    bool pickItems(const std::string& itemName, int itemCount);

};