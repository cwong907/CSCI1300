#include "cashRegister.h"

double CashResgister::getTotalPrice()
{
	return totalPrice;
}

int CashResgister::getNumberOfItems()
{
	return numberOfItems;
}

void CashResgister::addItem(double price)
{
	totalPrice +=price;
	numberOfItems++;
}

void CashResgister::clear()
{
	totalPrice = 0;
	numberOfItems = 0;
}