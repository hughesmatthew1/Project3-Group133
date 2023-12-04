#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "StockData.h"

void read_csv(string filename, vector<StockData>& vec){
    // Open indicated file
    fstream file(filename, ios::in);

    if (!file.is_open()) {
        cout << "Error opening file: " << filename << std::endl;
        return;
    }

    string line;
    // Skip header
    getline(file, line);

    while (getline(file, line)) {
        StockData sd;
        // Assign symbol from file name
        sd.symbol = filename.substr(0, line.find("."));
        // Assign symbol from file
        sd.date = line.substr(0, filename.find(","));
        line.erase(0, line.find(",")+1);
        // Assign open from file
        sd.open = stof(line.substr(0, line.find(",")));
        line.erase(0, line.find(",")+1);
        line.erase(0, line.find(",")+1);
        line.erase(0, line.find(",")+1);
        // Assign close from file
        sd.close = stof(line.substr(0, line.find(",")));

        // Calculate percent increase
        sd.pIncrease = (sd.close - sd.open)*100.0f / (sd.open);

        // Store new StockData struct in the vector
        vec.push_back(sd);
    }
    file.close();
}
