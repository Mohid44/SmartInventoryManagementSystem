// InventoryManager.h
#ifndef INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H

#include <vector>
#include <string>
#include "InventoryItem.h"

class InventoryManager {
    std::vector<InventoryItem> inventory;

public:
    void addItem(const InventoryItem &item);
    void updateStock(const std::string &name, int stockChange);
    void checkReorderLevels();
    void saveToFile();
    void loadFromFile();
    void predictRestockDate();
};

#endif // INVENTORY_MANAGER_H
