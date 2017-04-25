//
// Ritchie Stock Exchange
// http:://www.ritchiestockexchange.org/license
// 
// book.h
// Creates an order book
//
// [exchange in reverse-dot notation]-[instrument]-[days since epoch]-[number for day]
// Example: com.ritchie.exchange-GOLD-17280-5694372
#include <iostream>
#include <queue>
#include <map>
#include <memory>
#include "globals.h"
#include "order.h"
#include "orderNumber.h"

#ifndef _RITCHIE_BOOK_
#define _RITCHIE_BOOK_

namespace ritchie {
	class Book {
	public:
		// The book method "books" an order; e.g., pushes the order onto the priority queue/heap
		void book(std::shared_ptr<ritchie::Order> o) {
			bid_[MARKET_PRICE].push(o);
		}
		void unloadMarketHeap() {
			std::shared_ptr<ritchie::Order> o_ptr;
			while (!bid_[MARKET_PRICE].empty()) {
				o_ptr = bid_[MARKET_PRICE].top();
				std::cout << o_ptr->getOrderNumber() << std::endl;
				bid_[MARKET_PRICE].pop();
			}
		}
	private:
		std::map<double, std::priority_queue<std::shared_ptr<ritchie::Order>>> bid_, ask_;
	};
}
#endif


/**********************************
OUTPUT 

com.ritchie.exchange-gold-17281-5
com.ritchie.exchange-gold-17281-4
com.ritchie.exchange-gold-17281-3
com.ritchie.exchange-gold-17281-2
com.ritchie.exchange-gold-17281-1
Press enter to quit.

*/