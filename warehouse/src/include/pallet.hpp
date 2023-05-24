#pragma once
#include <string>
#include "icontainer.hpp"

class Pallet : public Icontainer {
private:
    std::string itemName;
    int itemCapacity;
    int itemCount;

public:
    Pallet(const std::string& itemName, int itemCapacity, int itemCount);
    Pallet();

    std::string getItemName() const;
    int getItemCount() const;
    int getRemainingSpace() const;

    bool reallocateEmptyPallet(const std::string& newItemName, int newItemCapacity);
    bool takeOne();
    bool putOne();
    bool isEmpty() override;
    bool isFull() override;
};