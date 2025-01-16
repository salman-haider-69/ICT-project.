#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip> // For formatting

using namespace std;

// Structure to represent a menu item
struct MenuItem {
    string name;
    double price;
};

// Function to display the menu
void displayMenu(const vector<MenuItem>& menu) {
    cout << "\n===== Welcome, Hope you were doing well.. =====\n";
    cout << "Please have a look at our exquisite menu:\n\n";
    cout << left << setw(5) << "No." << setw(30) << "Dish" << "Price ($)" << endl;
    cout << string(40, '-') << endl;
    for (int i = 0; i < menu.size(); i++) {
        cout << setw(5) << i + 1 << setw(30) << menu[i].name
            << fixed << setprecision(2) << menu[i].price << endl;
    }
    cout << endl;
}

// Function to get user input for order
map<int, int> getOrder() {
    map<int, int> order;
    int choice;
    do {
        cout << "Enter the item number to order (or 0 to finish): ";
        cin >> choice;
        if (choice != 0) {
            if (cin.fail() || choice < 1 || choice > 15) {
                cout << "Invalid choice. Please select a valid item number.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
            cout << "Enter quantity: ";
            int quantity;
            cin >> quantity;
            if (cin.fail() || quantity <= 0) {
                cout << "Invalid quantity. Please enter a positive number.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
            order[choice] += quantity; // Accumulate quantities if the item is selected again
        }
    } while (choice != 0);
    return order;
}

// Function to calculate the total cost
double calculateTotal(const vector<MenuItem>& menu, const map<int, int>& order) {
    double total = 0;
    for (const auto& item : order) {
        total += menu[item.first - 1].price * item.second;
    }
    return total;
}

int main() {
    // Define the menu items
    vector<MenuItem> menu = {
        {"Grilled Salmon", 12.50},
        {"Steak with Mushroom Sauce", 15.00},
        {"Caesar Salad", 8.00},
        {"Margherita Pizza", 10.00},
        {"Cheeseburger Deluxe", 9.00},
        {"Pasta Alfredo", 11.50},
        {"Chicken Tikka", 7.50},
        {"Lamb Chops", 14.00},
        {"Seafood Paella", 16.00},
        {"Vegetable Stir Fry", 6.50},
        {"Beef Tacos", 7.00},
        {"Chicken Wings (Spicy)", 8.50},
        {"Shrimp Tempura", 10.50},
        {"Chocolate Lava Cake", 6.00},
        {"Ice Cream Sundae", 5.50}
    };

    // Display the menu
    displayMenu(menu);

    // Get the order from the user
    map<int, int> order = getOrder();

    // Check if the order is empty
    if (order.empty()) {
        cout << "\nNo items ordered. Thank you for visiting Gourmet Bistro!\n";
        return 0;
    }

    // Calculate the total cost
    double total = calculateTotal(menu, order);

    // Print the order summary
    cout << "\n========== Order Summary ==========\n";
    cout << left << setw(30) << "Dish" << setw(10) << "Quantity"
        << "Price ($)" << endl;
    cout << string(50, '-') << endl;
    for (const auto& item : order) {
        cout << setw(30) << menu[item.first - 1].name
            << setw(10) << item.second
            << fixed << setprecision(2)
            << menu[item.first - 1].price * item.second << endl;
    }
    cout << string(50, '-') << endl;
    cout << setw(40) << "Total" << "$" << fixed << setprecision(2) << total << endl;

    cout << "\nThank you for dining with us. Enjoy your meal!\n";

    return 0;
}
