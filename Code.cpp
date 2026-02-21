#include <iostream>
#include <string>

using namespace std;



int main() {
 
  struct Product {
  int productCode;
  string name;
  double price;
};
  Product products[] = {
      {1, "Milk", 20.5},
      {2, "Bread", 1.95}, 
      {3, "Eggs", 10},
      {4, "Apples", 40.6},
      {5,"oragne", 20},
  };
   int numProducts = sizeof(products) / sizeof(products[0]);

  double subtotal = 0;
  bool continueBilling = true;
  int purchasedItems[numProducts] = {0}; 

  while (continueBilling) {
    cout << "\n** Supermarket Billing System **\n";
    cout << "1. Add Item\n";
    cout << "2. Display Bill\n";
    cout << "3. Exit\n";

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1: {
        int productCode, quantity;
        bool productFound = false;

        cout << "\nEnter product code: ";
        cin >> productCode;

        for (int i = 0; i < numProducts; ++i) {
          if (products[i].productCode == productCode) {
            cout << "Enter quantity: ";
            cin >> quantity;

            subtotal += products[i].price * quantity;
            purchasedItems[i] = quantity; 
            cout << "Item added to bill.\n";
            productFound = true;
            break;
          }
        }

        if (!productFound) {
          cout << "Invalid product code.\n";
        }
        break;
      }
      case 2: {
        if (subtotal > 0) {
          cout << "\n** Bill Details **\n";
          cout << "--------------------\n";

          
          for (int i = 0; i < numProducts; ++i) {
            if (purchasedItems[i] > 0) {
              cout << products[i].name << " x " << purchasedItems[i] << " - $" << products[i].price * purchasedItems[i] << endl;
            }
          }

          cout << "--------------------\n";
          cout << "Subtotal: $" << subtotal << endl;
          
          cout << "Total: $" << subtotal << endl; 
        } else {
          cout << "No items added to the bill yet.\n";
        }
        break;
      }
      case 3:
        continueBilling = false;
        break;
      default:
        cout << "Invalid choice.\n";
    }
  }

  cout << "\nThank you for shopping!\n";

  return 0;
}