#pragma once

#include <string>

struct StockData {
    std::string symbol;
    std::string date;
    float open;
    float close;
    float increase;

    // Comparison operators for each numerical member data
    bool openGT(const StockData& rhs) const;
    bool closeGT(const StockData& rhs) const;
    bool incGT(const StockData& rhs) const;
    bool openLT(const StockData& rhs) const;
    bool closeLT(const StockData& rhs) const;
    bool incLT(const StockData& rhs) const;
    std::string getString();
};