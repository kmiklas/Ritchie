//
// Ritchie Stock Exchange
// http:://www.ritchiestockexchange.org/license
// 
// orderNumber.h
// Generates an order number in the format
//
// [exchange in reverse-dot notation]-[instrument]-[days since epoch]-[number for day]
// Example: com.ritchie.exchange-GOLD-17280-5694372
//

#ifndef _RITCHIE_ORDER_NUMBER_
#define _RITCHIE_ORDER_NUMBER_

#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

namespace ritchie {
	class OrderNumber {
	public:
		OrderNumber() {
			auto hour_stamp = std::chrono::system_clock::now();
			day_stamp_ = day_stamp_ = (static_cast<long int>(std::chrono::duration_cast<std::chrono::hours>(hour_stamp.time_since_epoch()).count())) / 24;
			intraday_ = 0;
			exchange_ = "com.ritchie.exchange";
			instrument_ = "gold";
		}
		~OrderNumber() {}
		std::string exchange() { return exchange_; }
		std::string instrument() { return instrument_; }
		long int dayStamp() { return day_stamp_; }
		std::string generate() {
			auto hour_stamp = std::chrono::system_clock::now();
			long int today = (static_cast<long int>(std::chrono::duration_cast<std::chrono::hours>(hour_stamp.time_since_epoch()).count())) / 24;
			// If the day has turned over, increment it, and reset the intraday
			if (day_stamp_ < today) {
				day_stamp_ = today;
				intraday_ = 1;
			}
			else
				++intraday_;
			return (exchange_ + '-' + instrument_ + '-' + std::to_string(day_stamp_) + '-' + std::to_string(intraday_));
		}
	private:
		long int day_stamp_;
		long int intraday_;
		std::string exchange_;
		std::string instrument_;
	};
}
#endif