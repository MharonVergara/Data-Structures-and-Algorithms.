#include <iostream>
#include <vector>

using namespace std;

void displayInventory(const vector<const char*>& inventory) {
    cout << "[";
    for (size_t i = 0; i < inventory.size(); i++) {
        cout << "\"" << inventory[i] << "\"";
        if (i < inventory.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    
    vector<const char*> currentInventory = {"apples", "bananas", "oranges", "pears"};


    vector<const char*> shipment = {"kiwis", "bananas", "grapes"};

    vector<const char*> soldItems;

    cout << "Current Inventory: ";
    displayInventory(currentInventory);

    cout << "Shipment: ";
    displayInventory(shipment);

    vector<const char*> updatedInventory;

    bool Banana = false;

    for (const char* item : currentInventory) {
        if (item == "apples" || item == "oranges") {
            soldItems.push_back(item);
        } else {
            updatedInventory.push_back(item);
            if (item == "bananas") {
                Banana = true; 
            }
        }
    }

    for (const char* item : shipment) {
        if (item == "bananas") {
            if (!Banana) {
                updatedInventory.push_back(item);
                Banana = true;
            }
        } else {
            updatedInventory.push_back(item);
        }
    }

    cout << "Sold-out items: ";
    displayInventory(soldItems);

    cout << "Updated Inventory: ";
    displayInventory(updatedInventory);

    return 0;
}