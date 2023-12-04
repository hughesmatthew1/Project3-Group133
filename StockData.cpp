#include "StockData.h"

bool StockData::openGT(const StockData& rhs) const {
    return open > rhs.open;
}

bool StockData::closeGT(const StockData& rhs) const {
    return close > rhs.close;
}

bool StockData::incGT(const StockData& rhs) const {
    return increase > rhs.increase;
}

bool StockData::openLT(const StockData& rhs) const {
    return open < rhs.open;
}

bool StockData::closeLT(const StockData& rhs) const {
    return close < rhs.close;
}

bool StockData::incLT(const StockData& rhs) const {
    return increase < rhs.increase;
}

std::string StockData::getString() {
    std::string string = symbol + " [" + date + "]:";
    string += " (Open: " + std::to_string(open) + ", Close: " + std::to_string(close) + ", Increase: " + std::to_string(increase) + "%)\n";
    return string;
}