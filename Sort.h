#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "StockData.h"

// Should probably take in by reference;
std::vector<StockData> heap_sort(std::vector<StockData>&, int);
std::vector<StockData> quick_sort(std::vector<StockData>&, int);

// Helper function
void heapify(std::vector<StockData>&, int, int, int);
int partition(std::vector<StockData>&, int, int, int);
void quick_sort(std::vector<StockData>&, int, int, int);