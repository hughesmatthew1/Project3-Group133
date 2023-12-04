#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

#include "StockData.h"
#include "ReadCSV.h"
#include "Sort.h"

int user_input(int n) {
    std::string string;
	std::getline(std::cin, string);
    std::string value;
	for (int i = 1; i < n + 1; i++) {
		value = std::to_string(i);
		if (value == string) {
			return i;
		}
	}
	return 0;
}

void output(std::string string) {
    std::cout << string;
}

int main(){
    // Vector including filename strings
    std::vector<std::string> filenames;
    filenames.push_back("AAPL.csv");
    filenames.push_back("AMZN.csv");
    filenames.push_back("BA.csv");
    filenames.push_back("CVX.csv");
    filenames.push_back("DIS.csv");
    filenames.push_back("F.csv");
    filenames.push_back("GE.csv");
    filenames.push_back("GOOG.csv");
    filenames.push_back("HD.csv");
    filenames.push_back("JPM.csv");
    filenames.push_back("NVDA.csv");
    filenames.push_back("TSLA.csv");
    filenames.push_back("TTD.csv");
    filenames.push_back("V.csv");
    filenames.push_back("WMT.csv");
    filenames.push_back("XOM.csv");
    
    // Instantiate vector of Stock Data points
    std::vector<StockData> vector;

    // Populate stockVec from dataset
    for (std::string filename : filenames){
        read_csv(filename, vector);
    }

    std::string line;
    for (int i = 0; i < 5; i++) {
        line.append("----------------");
    }
    line.append("\n");

    // // Test
    // vector = heap_sort(vector, 1);
    // for (int i = 0; i < 1000; i++) {
    //     std::cout << vector[i].getString();
    // }

    while (true) {
        // Analyze a stock
        output(line);
        output("Which stock would you like to analyze?\n");
        output(line);
        output("(1)  AAPL | (2)  AMZN  | (3)  BA    | (4)  CVX\n");
        output("(5)  DIS  | (6)  F     | (7)  GOOG  | (8)  HD\n");
        output("(9)  JMP  | (10) NVDA  | (11) TSLA  | (12) TTD\n");
        output("(13) V    | (14) WHT   | (15) XOM   | (16) [ALL]\n");
        output(line);

        int stockIndex = user_input(16);
        output(line);
        if (stockIndex == 0) {
            output("Invalid Input\n");
            continue;
        }

        output("What would you like to sort based on?\n");
        output(line);
        output("(1) Opening Price\n(2) Closing Price\n(3) Percent Increase\n");
        output(line);

        int sortComp = user_input(3);
        output(line);
        if (sortComp == 0) {
            output("Invalid Input\n");
            continue;
        }

        std::vector<StockData> copy;
        if (stockIndex == 16) {
            // Sort entire array
            for (auto iter = vector.begin(); iter != vector.end(); iter++) {
                copy.push_back(*iter);
            }
        }
        else {
            int index = filenames[stockIndex - 1].find(".");
            std::string symbol = filenames[stockIndex - 1].substr(0, index);
            for (auto iter = vector.begin(); iter != vector.end(); iter++) {
                if (symbol == (*iter).symbol) {
                    copy.push_back(*iter);
                }
            }
        }

        auto start = std::chrono::high_resolution_clock::now();
        auto heapSorted = heap_sort(copy, sortComp);
        auto end = std::chrono::high_resolution_clock::now();

        double heapTime = std::chrono::duration_cast<std::chrono::duration<double>>(end- start).count();

        start = std::chrono::high_resolution_clock::now();
        auto quickSorted = quick_sort(copy, sortComp);
        end = std::chrono::high_resolution_clock::now();

        double quickTime = std::chrono::duration_cast<std::chrono::duration<double>>(end- start).count();

        output("Number of entries (max=" + std::to_string(heapSorted.size()) + "): ");
        std::string entries;
        std::getline(std::cin, entries);

        output("Ascending(A) or Descending(D): ");
        std::string string;
        std::getline(std::cin, string);
        output(line);

        bool flag = false;
        for (char c: entries) {
            if (!std::isdigit(c)) {
                flag = true;
                break;
            }
        }
        if (flag || !(string == "A" || string == "D")) {
            output("Invalid Input\n");
            continue;
        }
        int n = std::stoi(entries);
        if (n > heapSorted.size()) {
            output("Invalid Input\n");
            continue;
        }
        
        if (string == "A") {
            for (int i = 0; i < n; i++) {
                output("Heap Sort: " + heapSorted[heapSorted.size() - 1 - i].getString());
                output("Quick Sort: " + quickSorted[i].getString());
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                output("Heap Sort:  " + heapSorted[i].getString());
                output("Quick Sort: " + quickSorted[heapSorted.size() - 1 - i].getString());
            }
        }

        output("Heap Sort Time:  " + std::to_string(heapTime) + "\n");
        output("Quick Sort Time: " + std::to_string(quickTime) + "\n");
        output(line);
        output("Would you like to continue?\n");
        output(line);
        output("(1) yes\n(2) no\n");
        output(line);

        int input = user_input(2);
        if (input == 0) {
            output(line);
            output("Invalid Input\n");
            continue;
        }
        else if (input == 2) {
            break;
        }
    }
}