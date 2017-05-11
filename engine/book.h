// book.h - an order book object
// Copyright (C) 2017  by Keith Miklas

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

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