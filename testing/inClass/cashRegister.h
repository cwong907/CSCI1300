#ifndef CASHREGISTER_H
#define CASHREGISTER_H

class CashResgister
{
	private:
	double totalPrice; 
	int numberOfItems;
	
	public:
	double getTotalPrice();		//accessor 
	int getNumberOfItems();		//accessor
	void addItem(double price);	//mutator
	void clear();				//mutator
};

#endif