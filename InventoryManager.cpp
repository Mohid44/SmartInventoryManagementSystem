// InventoryManager.cpp
#include <iostream>
#include <fstream>
#include "InventoryManager.h"

void InventoryManager::addItem(const InventoryItem &item) {
    inventory.push_back(item);
}

void InventoryManager::updateStock(const std::string &name, int stockChange) {
    for (auto &item : inventory) {
        if (item.name == name) {
            item.stockLevel += stockChange;
            break;
        }
    }
}

void InventoryManager::checkReorderLevels() {
    for (const auto &item : inventory) {
        if (item.stockLevel < item.reorderThreshold) {
            std::cout << "Reorder needed for: " << item.name << "\n";
        }
    }
}

void InventoryManager::saveToFile() {
    std::ofstream file("inventory_data.txt");
    for (const auto &item : inventory) {
        file << item.name << " " << item.stockLevel << " " << item.reorderThreshold << " " << item.supplier << " " << item.dailyUsage << "\n";
    }
}

void InventoryManager::loadFromFile() {
    std::ifstream file("inventory_data.txt");
    if (file.is_open()) {
        InventoryItem item;
        while (file >> item.name >> item.stockLevel >> item.reorderThreshold >> item.supplier >> item.dailyUsage) {
            inventory.push_back(item);
        }
    }
}

void InventoryManager::predictRestockDate() {
    for (const auto &item : inventory) {
        int daysUntilOut = item.stockLevel / item.dailyUsage;
        std::cout << "Item: " << item.name << " will need restocking in approx. " << daysUntilOut << " days.\n";
    }
}
