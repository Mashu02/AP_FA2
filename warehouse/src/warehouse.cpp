#include "include/warehouse.hpp"
#include <algorithm>

Warehouse::Warehouse() {}

void Warehouse::addEmployee(const Employee& employee) {
    employees.push_back(employee);
}

// Employee* Warehouse::getEmployee(const std::string& employeeName) {
//     for (auto& employee : employees) {
//         if (employee.getName() == employeeName) {
//             return &employee;
//         }
//     }
//     return nullptr;  // Employee not found
// }

void Warehouse::addShelf(const Shelf& shelf) {
    shelves.push_back(shelf);
}

bool Warehouse::rearrangeShelf(Shelf& shelf)
{
    bool employeeAvailable = false;
    for (const auto& employee : employees)
    {
        if (employee.getForkliftCertificate() && !employee.getBusy())
        {
            employeeAvailable = true;
            break;
        }
    }

    if (!employeeAvailable)
    {
        return false; // No employee with a forklift certificate available
    }

    bool swapped = false;
    for (size_t i = 0; i < shelf.pallets.size() - 1; ++i)
    {
        swapped = false;
        for (size_t j = 0; j < shelf.pallets.size() - i - 1; ++j)
        {
            if (shelf.pallets[j].getItemCount() > shelf.pallets[j + 1].getItemCount())
            {
                shelf.swapPallet(j, j + 1);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break; 
        }
    }
    return true;
}


bool Warehouse::pickItems(const std::string& itemName, int itemCount) {
    // Iterate over all shelves and pallets to pick items
    for (auto& shelf : shelves) {
        for (auto& pallet : shelf.pallets) {
            if (pallet.getItemName() == itemName) {
                for (int i = 0; i < itemCount; i++) {
                    if (pallet.getItemCount() > 0) {
                        pallet.takeOne();
                    } else {
                        return false;
                    }
                }
                // All items have been successfully picked
                return true;
            }
        }
    }    
    // Item not found in any pallets
    return false;
}
