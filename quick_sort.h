//
// Created by Morgan Evans on 12/3/23.
//

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int partition(vector<StockData>& vec, int low, int high, int comp) {
    // change to struct instead of int
    // test
    int i;
    if (comp == 0) {
        // open

        // pick pivot
        float pivot = vec[high].open;
        // index of smaller element
        i = low - 1;

        for (int j = low; j < high; j++) {
            // if element is smaller than pivot
            if (vec[j].open < pivot) {
                // increment index of smaller element
                i++;
                swap(vec[i], vec[j]);
            }
        }
    }
    else if (comp == 1) {
        // close

        // pick pivot
        float pivot = vec[high].close;
        // index of smaller element
        i = low - 1;

        for (int j = low; j < high; j++) {
            // if element is smaller than pivot
            if (vec[j].close < pivot) {
                // increment index of smaller element
                i++;
                swap(vec[i], vec[j]);
            }
        }
    }
    else if (comp == 2) {
        // percent increase

        // pick pivot
        int pivot = vec[high].pIncrease;
        // index of smaller element
        i = low - 1;

        for (int j = low; j < high; j++) {
            // if element is smaller than pivot
            if (vec[j].pIncrease < pivot) {
                // increment index of smaller element
                i++;
                swap(vec[i], vec[j]);
            }
        }
    }

    swap(vec[i+1], vec[high]);
    return i + 1;
}

void quickSort(vector<StockData>& vec, int low, int high, int comp) {
    // change to struct instead of int
    // test

    if (low < high) {
        int index = partition(vec, low, high, comp);

        quickSort(vec, low, index-1, comp);
        quickSort(vec, index + 1, high, comp);
    }
}

vector<StockData> vecQuickSort(vector<StockData>& vecStock, int comp) {
    // change to struct instead of int
    // test

    // create new vector to store the sorted vecStock
    vector<StockData> sortedVec = vecStock;
    int size = sortedVec.size();
    quickSort(sortedVec, 0, size - 1, comp);
    return sortedVec;
}
