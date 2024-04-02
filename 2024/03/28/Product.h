// Product.h
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using std::string;

class Product
{
public:
	Product(string name, double price) : name(name), price(price) {}

private:
	string name;				// 商品名
	double price;				// 单价
	static int totalSold;		// 销售商品的总数
	static double totalRevenue; // 总收入

public:
	void sell(int quantity);								// 销售商品
	static int total_sold() { return totalSold; }			// 获取销售总数
	static double total_revenue() { return totalRevenue; };	// 获取总收入
	static double average_price();							// 计算平均价格
};

#endif
