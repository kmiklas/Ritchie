//
// Ritchie Stock Exchange
// http:://www.ritchiestockexchange.org/
//
// Generates an order number in the format
//
// [exchange in reverse-dot notation]-[instrument]-[days since epoch]-[number for day]
//
// Example:
// ORDER NUMBER:     com.ritchie.exchange-GOLD-17280-5694372
//
// SERVER:           com.ritchie.exchange
// INSTRUMENT:       GOLD
// DAYS SINCE EPOCH: 17280
// NUMBER FOR DAY:   5694372q
//

#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

class Order_number {
public:
    Order_number(const std::string exchange, const std::string instrument):exchange_(exchange),instrument_(instrument) {
        // To get the day stamp, we take the time now and divide by 24, with some type casting
        auto hour_stamp = std::chrono::system_clock::now();
        day_stamp_ = (static_cast<long int>(std::chrono::duration_cast<std::chrono::hours>(hour_stamp.time_since_epoch()).count()))/24;
        intraday_ = 0;
    }
    ~Order_number() {}
    std::string exchange() {
        // Returns name of server
        return exchange_;
    }
    std::string instrument() {
        // Returns name of server
        return instrument_;
    }
    long int dayStamp() {
        // Returns name of server
        return day_stamp_;
    }
    std::string generate() {
        auto hour_stamp = std::chrono::system_clock::now();
        long int today = (static_cast<long int>(std::chrono::duration_cast<std::chrono::hours>(hour_stamp.time_since_epoch()).count()))/24;
        // If the day has turned over, increment it, and reset the
        if (day_stamp_ < today) {
            day_stamp_ = today;
            intraday_ = 1;
        } else {
            ++intraday_;
        }
        return (exchange_ + '-' + instrument_ + '-' + std::to_string(day_stamp_) + '-' + std::to_string(intraday_));
    }
private:
    long int day_stamp_;
    long int intraday_;
    std::string exchange_;
    std::string instrument_;
};

class Pit {
public:
private:
};

class Ladder {
public:
private:
};
class Book {
public:
private:
};

class Order {
public:
private:
};

int main(int argc, const char * argv[]) {
    Order_number order_number("com.ritchie.exchange", "GOLD");
    std::cout << "SERVER:            " << order_number.exchange() << std::endl;
    std::cout << "INSTRUMENTS:       " << order_number.instrument() << std::endl;
    std::cout << "DAYS SINCE EPOCH:  " << order_number.dayStamp() << std::endl;
    std::cout << "FULL ORDER NUMBER: " << order_number.generate() << std::endl;

    std::cout << "\n";
    return 0;
}