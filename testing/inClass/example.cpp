#include <iostream>
#include "cashRegister.h"

using namespace std;

int main()
{
	CashResgister reg;
	reg.addItem(2.00);
	reg.addItem(2.35);
	reg.clear();
	cout << "Total Price: " << reg.getTotalPrice() << endl;
	cout << "Total Items: " << reg.getNumberOfItems() << endl;
}