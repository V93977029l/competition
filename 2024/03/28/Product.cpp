// Product.cpp
#include "Product.h"

int Product::totalSold = 0;
double Product::totalRevenue = 0;

void Product::sell(int quantity)
{
	totalSold += quantity;
	totalRevenue += price * quantity;
}

double Product::average_price()
{
	if (totalSold == 0)
		return 0.0;
	else
		return totalRevenue / totalSold;
}
