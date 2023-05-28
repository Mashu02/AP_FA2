#include "include/shelf.hpp"
#include "include/pallet.hpp"

Shelf::Shelf() {}

bool Shelf::swapPallet(int slot, int slot2) {
    if (slot < 0 || slot >= 4 || slot2 < 0 || slot2 >= 4) {
        return false; // Invalid slot
    }

    Pallet temp = pallets[slot];
    pallets[slot] = pallets[slot2];
    pallets[slot2] = temp;

    return true;
}

bool Shelf::isEmpty() {
    for (const auto& pallet : pallets) {
        if (pallet.getItemCount() > 0) {
            return false;
        }
    }
    return true;
}

bool Shelf::isFull() {
    for (const auto& pallet : pallets) {
        if (pallet.getRemainingSpace() == 0) {
            return false;
        }
    }
    return true;
}
