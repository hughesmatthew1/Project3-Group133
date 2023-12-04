#pragma once
#include <string>

using namespace std;

struct StockData{
    string symbol;
    string date;
    float open;
    float close;
    float pIncrease;

    // Comparison operators for each numerical member data

    bool openGT(const StockData& rhs) const
    {
        return this->open > rhs.open;
    }

    bool closeGT(const StockData& rhs) const
    {
        return this->close > rhs.close;
    }

    bool incGT(const StockData& rhs) const
    {
        return this->pIncrease > rhs.pIncrease;
    }

    bool openLT(const StockData& rhs) const
    {
        return this->open < rhs.open;
    }

    bool closeLT(const StockData& rhs) const
    {
        return this->close < rhs.close;
    }

    bool incLT(const StockData& rhs) const
    {
        return this->pIncrease < rhs.pIncrease;
    }
    
};
