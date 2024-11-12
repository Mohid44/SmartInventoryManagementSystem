// InventoryItem.h
#ifndef INVENTORY_ITEM_H
#define INVENTORY_ITEM_H

#include <string>

struct InventoryItem {
    std::string name;
    int stockLevel;
    int reorderThreshold;
    std::string supplier;
    int dailyUsage;
};

#endif // INVENTORY_ITEM_H
