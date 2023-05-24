#include "include/pallet.hpp"

Pallet::Pallet(const std::string& itemName, int itemCapacity, int itemCount)
    : itemName(itemName), itemCapacity(itemCapacity), itemCount(itemCount) {}

Pallet::Pallet()
    : itemCapacity(0), itemCount(0), itemName("")  {}

std::string Pallet::getItemName() const {
    return itemName;
}

int Pallet::getItemCount() const {
    return itemCount;
}

int Pallet::getRemainingSpace() const {
    return itemCapacity - itemCount;
}

bool Pallet::reallocateEmptyPallet(const std::string& newItemName, int newItemCapacity) {
    if (itemCount == 0) {
        itemName = newItemName;
        itemCapacity = newItemCapacity;
        return true;
    }
    return false;
    
}

bool Pallet::takeOne() {
    if (itemCount > 0) {
        itemCount--;
        return true;
    }
    return false;
}

bool Pallet::putOne() {
    if (itemCount < itemCapacity) {
        itemCount++;
        return true;
    }
    return false;
}

bool Pallet::isEmpty()
{
    if (itemCount == 0)
    {
        return true;
    }
    return false;

}

bool Pallet::isFull()
{
    if (itemCount == itemCapacity)
    {
        return true;
    }
    return false;
}