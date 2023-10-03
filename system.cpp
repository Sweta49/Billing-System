#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

// Define a structure to represent an item
struct Item {
    std::string name;
    double price;
    int quantity;
};

// Function to calculate the total cost of items in the cart
double calculateTotal(const std::vector<Item>& cart) {
    double total = 0.0;
    for (const Item& item : cart) {
        total += item.price * item.quantity;
    }
    return total;
}

int main() {
    std::vector<Item> cart;
    char choice;

    do {
        Item item;
        std::cout << "Enter item name: ";
        std::cin >> item.name;
        std::cout << "Enter item price: $";
        std::cin >> item.price;
        std::cout << "Enter item quantity: ";
        std::cin >> item.quantity;

        cart.push_back(item);

        std::cout << "Do you want to add another item? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Print the bill
    std::cout << "\n********** Invoice **********\n";
    std::cout << std::left << std::setw(20) << "Item Name" << std::setw(10) << "Price" << std::setw(10) << "Quantity" << std::setw(10) << "Total" << std::endl;
    std::cout << "------------------------------\n";
    for (const Item& item : cart) {
        std::cout << std::left << std::setw(20) << item.name << std::setw(10) << "$" << item.price << std::setw(10) << item.quantity << std::setw(10) << "$" << item.price * item.quantity << std::endl;
    }
    std::cout << "------------------------------\n";
    std::cout << "Total: $" << calculateTotal(cart) << std::endl;

    return 0;
}
