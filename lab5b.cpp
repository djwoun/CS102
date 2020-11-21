// lab5b.cpp
// The program prompts the user for their name and date. After they can freely add, remove, change, and print for shopping.
// Dong Jun Woun
// 10/30/2020
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>
using namespace std;
class Item {
public:
	// initializer list for Item Variables
	Item()
		: iName("none"), Description("none"), Price(0), Quantity(0) {}
	// public mutators and accessors for item class
	void SetName(string itemName);
	void SetDescription(string itemDescription);
	void SetPrice(double itemPrice);
	void SetQuantity(int itemQuantity);
	string GetName() const;
	string GetDescription() const;
	double GetPrice() const;
	int GetQuantity() const;
private:
	// private member variables store an item's name, a real-number to store the price, and an integeter to store the quantity of the item.
	// initializer list
	string iName, Description;
	double Price;
	int Quantity;
};

class ShoppingCart {
public:
	// initializer list for ShoppingCart Variables
	ShoppingCart()
		: CustomerName("none"), date("April 1, 2020") {}
	// public mutators and accessors for ShoppingCart class
	void SetCustomerName(string sName);
	void SetDate(string sdate);
	void AddItem(const Item&); 
	void RemoveItem(const string&);
	void ChangeQuantity(const string&, int);
	string GetCustomerName() const;
	string GetDate() const;
	int GetTotalQuantity() const;
	double GetTotalCost() const;
	void PrintTotal() const;
	void PrintDescription() const;
	vector<string> shoppingListItem;
	vector<string> shoppingListDescription;
	vector<double> shoppingListPrice;
	vector<int> shoppingListQuantity;
	// using vectors to store all items the user specifies
private:
	string CustomerName, date;
	int FindItemIndex(const string&) const;
};
char PrintMenu();

int main()
{
	// variable customerName and date 
	Item Shop;
	ShoppingCart Customer;
	string customerName;
	string date;

	while (cout << "Enter customer name: ") {

		// asks the user for their name
		if (!(getline(cin, customerName))) {
			if ((cin.eof())) {
				break;
			}

			// error checking
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter customer name: ";

		}

		// customerName is not none, the program sets the cumstomer name to the name inputed
		if (customerName != "none") {

			Customer.SetCustomerName(customerName);

			// asks the user for the date
			while (cout << "Enter today's date: ", !(getline(cin, date))) {

				if ((cin.eof())) {
					break;
				}

				// error checking
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter today's date: ";

			}
			if ((cin.eof())) {
				break;
			}

			//  the program sets the cumstomer date to the date inputed 
			Customer.SetDate(date);

			// outputs the Customer's name and today's date
			cout << endl;
			cout << "Customer name: " << Customer.GetCustomerName() << endl;
			cout << "Today's date: " << Customer.GetDate() << endl;
			cout << endl;
		}
		char option;

		do {
			// call PrintMenu for option
			option = PrintMenu();

		

			if (option == 'a') {
				// initiates AddItem if a is typed
				Customer.AddItem(Shop);

			}
			else if (option == 'd') {
				// id d is typed, the user is asked which item to remove after it initiates RemoveItem
				string PossibleRemoval;
				cout << "REMOVE ITEM FROM CART" << endl;
				cout << "Enter the item name to remove: ";
				getline(cin, PossibleRemoval);

				Customer.RemoveItem(PossibleRemoval);
				cout << endl;
			}
			else if (option == 'c') {
				// id c is typed, the user is asked the item and the item quantity the program should change.
				string changeQuantityName;
				int changeQuantity;
				cout << endl;
				cout << "CHANGE ITEM QUANTITY" << endl;
				cout << "Enter the item name: ";
				getline(cin, changeQuantityName);
				cout << "Enter the item quantity : ";

				while (!(cin >> changeQuantity) || (changeQuantity <= -1)) {
					if ((cin.eof())) {
						break;

					}
					// error checking
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Enter the item quantity : ";

				}
				if ((cin.eof())) {
					break;

				}
				cin.ignore(100, '\n');
				// after it initiates ChangeQuantity
				Customer.ChangeQuantity(changeQuantityName, changeQuantity);
				cout << endl;

			}
			else if (option == 'i') {
				// if i is typed the item's descriptions are output
				Customer.PrintDescription();

			}
			else if (option == 'o') {
				// if i is typed the item's total costs and quantity are output
				Customer.PrintTotal();
			}
			else if (option == 'q') {
				// if q is typed the program ends
				break;
			}

			// if EOF signal is recieved the program ends
		} while (!(cin.eof()));
		break;
	}

}
//public mutators  called SetName, SetPrice, SetDescription, and SetQuantity which return the value of the corresponding member variables.
void Item::SetName(string itemName) {
	iName = itemName;
}
void Item::SetDescription(string itemDescription) {
	Description = itemDescription;
}
void Item::SetPrice(double itemPrice) {
	Price = itemPrice;
}
void Item::SetQuantity(int itemQuantity) {
	Quantity = itemQuantity;
}

//public accessors called GetName, GetPrice, GetDescription, and GetQuantity which return the value of the corresponding member variables.
string Item::GetName() const {
	return iName;
}
string Item::GetDescription() const {
	return Description;
}
double Item::GetPrice() const {
	return Price;
}
int Item::GetQuantity() const {
	return Quantity;
}


void ShoppingCart::SetCustomerName(string sName) {
	CustomerName = sName;
}
void ShoppingCart::SetDate(string sdate) {
	date = sdate;
}
void ShoppingCart::AddItem(const Item& ) {

	Item Shop;
	string iName = "none";
	string description = "none";
	double Price = 0;
	int Quantity = 0;
	do {

		cout << "ADD ITEM TO CART " << endl;
		cout << "Enter the item name : " << flush;
		while (!(getline(cin, iName))) {

			if ((cin.eof())) {
				break;
			}

			// error checking
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter the item name: ";

		}
		if ((cin.eof())) {
			break;

		}

		if (iName != "none") {
			Shop.SetName(iName);

			// asks for item description
			cout << "Enter the item description: ";
			while (!(getline(cin, description))) {

				if ((cin.eof())) {
					break;

				}

				// error checking
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter the item description: ";

			}
			if ((cin.eof())) {
				break;

			}

			// if Name is not none, the public accessor SetName sets itemname to Name
			if (description != "none") {
				Shop.SetDescription(description);

				// asks for item quantity
				cout << "Enter the item price : $";
				while (!(cin >> Price) || (Price <= 0)) {

					if ((cin.eof())) {
						break;

					}

					// error checking
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Enter the item price : $";

				}
				if ((cin.eof())) {
					break;

				}
				cin.ignore(100, '\n');

				// if Price is above 0, the public accessor SetPrice sets itemPrice to Price
				if (Price > 0) {
					Shop.SetPrice(Price);

					// asks for item quantity
					cout << "Enter the item quantity : ";
					while (!(cin >> Quantity) || (Quantity <= 0)) {
						if ((cin.eof())) {
							break;

						}
						// error checking
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Enter the item quantity : ";

					}
					if ((cin.eof())) {
						break;

					}
					cin.ignore(100, '\n');

					// if Quantity is above 0, the public accessor SetQuantity sets itemQuantity to Price
					if (Quantity > 0) {
						// information is not stored if EOF is signaled before the Quantity gets a valid input
						// information about the items are stored into the vector
						Shop.SetQuantity(Quantity);
						shoppingListItem.push_back(Shop.GetName());
						shoppingListPrice.push_back(Shop.GetPrice());
						shoppingListQuantity.push_back(Shop.GetQuantity());
						shoppingListDescription.push_back(Shop.GetDescription());

						cout << endl;

					}
				}
			}
		}
		break;
	} while (iName == "none");
}
void ShoppingCart::RemoveItem(const string& PossibleRemoval) {

	int itemNumber = FindItemIndex(PossibleRemoval);

	if (itemNumber != -1) {
		shoppingListItem.erase(shoppingListItem.begin() + itemNumber);
		shoppingListPrice.erase(shoppingListPrice.begin() + itemNumber);
		shoppingListQuantity.erase(shoppingListQuantity.begin() + itemNumber);
		shoppingListDescription.erase(shoppingListDescription.begin() + itemNumber);
	}

}
void ShoppingCart::ChangeQuantity(const string& changeQuantityName, int changeQuantity) {

	int itemNumber = FindItemIndex(changeQuantityName);

	if (itemNumber != -1) {
		shoppingListQuantity.at(itemNumber) = changeQuantity;

		if (shoppingListQuantity.at(itemNumber) == 0) {
			shoppingListItem.erase(shoppingListItem.begin() + itemNumber);
			shoppingListPrice.erase(shoppingListPrice.begin() + itemNumber);
			shoppingListQuantity.erase(shoppingListQuantity.begin() + itemNumber);
			shoppingListDescription.erase(shoppingListDescription.begin() + itemNumber);

		}
	}

}
int  ShoppingCart::FindItemIndex(const string& Item) const {
	// private and returns index if found or -1 if not found
	string FindItemIndex = "Item not found in cart.";
	int itemNUmber = -1;
	for (unsigned int i = 0; i < shoppingListItem.size(); i++) {

		if (Item == shoppingListItem.at(i)) {

			FindItemIndex = shoppingListItem.at(i);
			itemNUmber = i;

		}

	}
	if (FindItemIndex == "Item not found in cart.") {
		cout << FindItemIndex << endl;
	}

	return itemNUmber;
} //This function should search for an Item in the vector of Item objects whose name matches the string passed to the function. If an Item is found, return its index in the vector. Otherwise, return -1.

string ShoppingCart::GetCustomerName() const {
	return CustomerName;
}
string ShoppingCart::GetDate() const {
	return date;
}
int ShoppingCart::GetTotalQuantity() const {

	int totalQuantity = 0;

	for (unsigned int i = 0; i < shoppingListItem.size(); i++) {

		totalQuantity = totalQuantity + shoppingListQuantity.at(i);

	}

	return totalQuantity;
}
double ShoppingCart::GetTotalCost() const {
	double totalCost = 0;
	for (unsigned int i = 0; i < shoppingListItem.size(); i++) {

		// I/O manipulators to display prices to two decimal points
		totalCost = totalCost + shoppingListPrice.at(i) * shoppingListQuantity.at(i);
	}
	return totalCost;
}
void ShoppingCart::PrintTotal() const {

	cout << endl;

	if (GetTotalCost() == 0) {
		cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() << endl;
		cout << "Number of Items: 0" << endl;
		cout << endl;
		cout << "Total: $0.00" << endl;
	}
	else if (GetTotalCost() > 0) {
		cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() << endl;
		cout << "Number of Items: " << GetTotalQuantity() << endl;
		cout << endl;
		for (unsigned int i = 0; i < shoppingListItem.size(); i++) {

			// I/O manipulators to display prices to two decimal points
			cout << shoppingListItem.at(i) << ": " << shoppingListQuantity.at(i) << " at $" << setprecision(2) << fixed << shoppingListPrice.at(i) << " = $" << shoppingListPrice.at(i) * shoppingListQuantity.at(i) << endl;

		}
		cout << endl;
		cout << "Total: $" << GetTotalCost() << endl;
	}

	cout << endl;

}
void ShoppingCart::PrintDescription() const {
	cout << endl;
	cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() << endl;
	cout << endl;

	cout << "Item Descriptions" << endl;

	if (shoppingListItem.size() != 0) {
		for (unsigned int i = 0; i < shoppingListItem.size(); i++) {

			// I/O manipulators to display prices to two decimal points
			cout << shoppingListItem.at(i) << ": " << shoppingListDescription.at(i) << endl;
		}
	}
	else if (shoppingListItem.size() == 0) {

		cout << "Shopping cart is empty." << endl;
	}

	cout << endl;
}
char PrintMenu() {
	char option = ' ';
	cout << "Menu" << endl;
	cout << "a - Add item to cart" << endl;
	cout << "d - Remove item from cart" << endl;
	cout << "c - Change item quantity" << endl;
	cout << "i - Output item descriptions" << endl;
	cout << "o - Output shopping cart" << endl;
	cout << "q - Quit" << endl;
	cout << endl;

	while (cout << "Choose an option: ", !(cin >> option)) {

		if ((cin.eof())) {
			break;

		}

		// error checking
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Choose an option: ";

	}
	cin.ignore(100, '\n');
	cout << endl;
	return option;

}
