#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "StockData.h"
#include "read_csv.h"
#include "heap_sort.h"
#include "quick_sort.h"


using namespace std;

void read_csv(string filename, vector<StockData>& vec);
vector<StockData> heap_sort(vector<StockData> vec, int comp);

int main(){
    // Vector including filename strings
    vector<string> filenames;
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
    vector<StockData> stockVec;

    // Populate stockVec from dataset
    for (string filename : filenames){
        read_csv(filename, stockVec);
    }

    // UI

    // Call Sorts & track time taken

    // Templates for sort calls:
    // heap_sort(stockVec, 0 1 or 2)
    // vecQuickSort(stockVec, 0 1 or 2)

    // Output

}
