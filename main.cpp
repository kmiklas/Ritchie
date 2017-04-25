//
// Ritchie Stock Exchange
// http:://www.ritchiestockexchange.org/license
// 
// This sample:
// 1. Creates an order book for gold
// 2. Creates five market buy orders at 1275.00
// 3. Pushes smart pointers to said orders onto the heap at this price
// 4. Pops off the heap and prints
//
#include <iostream>
#include <memory>
#include "globals.h"
#include "orderNumber.h"
#include "book.h"
#include "order.h"


int main() {
	// Create an order book for gold
	ritchie::OrderNumber orderNumber;
	ritchie::Book gold;

	// Create five new order single basic orders at market
	std::shared_ptr<ritchie::Order> a(new ritchie::Order(orderNumber.generate(), "mkt", "buy"));
	std::shared_ptr<ritchie::Order> b(new ritchie::Order(orderNumber.generate(), "mkt", "buy"));
	std::shared_ptr<ritchie::Order> c(new ritchie::Order(orderNumber.generate(), "mkt", "buy"));
	std::shared_ptr<ritchie::Order> d(new ritchie::Order(orderNumber.generate(), "mkt", "buy"));
	std::shared_ptr<ritchie::Order> e(new ritchie::Order(orderNumber.generate(), "mkt", "buy"));

	// Book the five orders
	gold.book(a);
	gold.book(b);
	gold.book(c);
	gold.book(d);
	gold.book(e);

	// Pop and print orders
	gold.unloadMarketHeap();

	std::cout << "Press enter to quit.";
	std::cin.get();
	std::cout << std::endl;
	return 0;
}