#include "StockData.h"
#include <vector>
#include <iostream>

using namespace std;

void heapify(vector<StockData>& vec, int root, int size, int comp){
    // Assign the indexes of the subtree's root, left child, and right child
    int min = root;
    int left = 2*root + 1;
    int right = 2*root + 2;

    // When comp == 0, we are sorting based on open value
    // Checks if left child exists, if left open is less than current minimum close
    if (comp == 0 && left < size && vec[left].openLT(vec[min])){
        min = left;
    }
    // Checks if right child exists, if right open is less than current minimum close
    if (comp == 0 && right < size && vec[right].openLT(vec[min])){
        min = right;
    }

    // When comp == 1, we are sorting based on close value
    // Checks if left child exists, if left close is less than current minimum close
    if (comp == 1 && left < size && vec[left].closeLT(vec[min])){
        min = left;
    }
    // Checks if right child exists, if right open is less than current minimum close
    if (comp == 1 && right < size && vec[right].closeLT(vec[min])){
        min = right;
    }

    // When comp == 2, we are sorting based on pIncrease value
    // Checks if left child exists, if left open is less than current minimum inc
    if (comp == 2 && left < size && vec[left].incLT(vec[min])){
        min = left;
    }
    // Checks if right child exists, if right open is less than current minimum inc
    if (comp == 2 && right < size && vec[right].incLT(vec[min])){
        min = right;
    }

    // If a child is less than root
    if (min != root){
        // Swamp with lesser child
        swap(vec[min], vec[root]);
        // Recursively call heapify on the child you swap with
        heapify(vec, min, size, comp);
    }
}

vector<StockData> heap_sort(vector<StockData> vec, int comp){
    // Create Copy of input vector so it doesnt get modified
    int size = vec.size();

    // Make the vector into a heap
    // Heapifies all non-leaf nodes
    for (int i = size/2; i >= 0; i--){
        heapify(vec, i, size, comp);
    }

    // Reorder the heap using heapify (min heap)
    // Heapifies all nodes
    for (int i = size-1; i>=0; i--){
        // Move root to end
        swap(vec[0], vec[i]);
        // Heapify from root of tree
        heapify(vec, 0, i, comp);
    }
    // Returns sorted copy of vector
    return vec;
}
