// main.cpp
#include <iostream>
#include "InventoryManager.h"

void displayMenu() {
    std::cout << "1. Add Item\n";
    std::cout << "2. Update Stock\n";
    std::cout << "3. Check Reorder Levels\n";
    std::cout << "4. Save Data\n";
    std::cout << "5. Load Data\n";
    std::cout << "6. Predict Restock Date\n";
    std::cout << "7. Exit\n";
}

int main() {
    InventoryManager manager;
    manager.loadFromFile();
    int choice;
    
    while (true) {
        displayMenu();
        std::cin >> choice;
        
        if (choice == 1) {
            InventoryItem item;
            std::cout << "Enter item name: ";
            std::cin >> item.name;
            std::cout << "Enter stock level: ";
            std::cin >> item.stockLevel;
            std::cout << "Enter reorder threshold: ";
            std::cin >> item.reorderThreshold;
            std::cout << "Enter supplier: ";
            std::cin >> item.supplier;
            std::cout << "Enter daily usage: ";
            std::cin >> item.dailyUsage;
            manager.addItem(item);
        } else if (choice == 2) {
            std::string name;
            int stockChange;
            std::cout << "Enter item name: ";
            std::cin >> name;
            std::cout << "Enter stock change (positive or negative): ";
            std::cin >> stockChange;
            manager.updateStock(name, stockChange);
        } else if (choice == 3) {
            manager.checkReorderLevels();
        } else if (choice == 4) {
            manager.saveToFile();
        } else if (choice == 5) {
            manager.loadFromFile();
        } else if (choice == 6) {
            manager.predictRestockDate();
        } else if (choice == 7) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
