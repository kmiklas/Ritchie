// order.h - order object
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

#ifndef _RITCHIE_ORDER_
#define _RITCHIE_ORDER_

#include <iostream>
#include <string>
#include "globals.h"

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