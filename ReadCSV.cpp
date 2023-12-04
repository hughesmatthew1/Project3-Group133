#include "ReadCSV.h"

void read_csv(std::string filename, std::vector<StockData>& vector){
    // Open indicated file
    std::fstream file(filename, std::ios::in);

    if (!file.is_open()) {
        std::cout << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    // Skip header
    getline(file, line);

    while (getline(file, line)) {
        StockData data;
        // Assign symbol from file name
        data.symbol = filename.substr(0, filename.find("."));
        // Assign symbol from file
        data.date = line.substr(0, line.find(","));
        line.erase(0, line.find(",")+1);
        // Assign open from file
        data.open = stof(line.substr(0, line.find(",")));
        line.erase(0, line.find(",")+1);
        line.erase(0, line.find(",")+1);
        line.erase(0, line.find(",")+1);
        // Assign close from file
        data.close = stof(line.substr(0, line.find(",")));

        // Calculate percent increase
        data.increase = (data.close - data.open)*100.0f / (data.open);

        // Store new StockData struct in the vector
        vector.push_back(data);
    }
    file.close();
}
