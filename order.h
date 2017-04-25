//
// Ritchie Stock Exchange
// http:://www.ritchiestockexchange.org/license
// 
// order.h
// Creates an order
//

#ifndef _RITCHIE_ORDER_
#define _RITCHIE_ORDER_

#include <iostream>
#include <string>

namespace ritchie {
	class Order {
	public:
		Order(std::string orderNumber, std::string ordType, std::string side) {
			orderNumber_ = orderNumber;
			ordType_ = ordType;
			side_ = side;
			price_ = MARKET_PRICE;
		}
		double getPrice() {
			return price_;
		}
		std::string getOrderNumber() {
			return orderNumber_;
		}
	private:
		Order() {}
		std::string ordType_;
		std::string side_;
		double price_;
		std::string orderNumber_;
	};
}
#endif
