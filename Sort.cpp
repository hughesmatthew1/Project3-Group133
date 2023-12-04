#include "Sort.h"

void heapify(std::vector<StockData>& vector, int root, int size, int comp){
    // Assign the indexes of the subtree's root, left child, and right child
    int min = root;
    int left = 2*root + 1;
    int right = 2*root + 2;

    // When comp == 1, we are sorting based on open value
    // Checks if left child exists, if left open is less than current minimum close
    if (comp == 1 && left < size && vector[left].openLT(vector[min])) {
        min = left;
    }
    // Checks if right child exists, if right open is less than current minimum close
    if (comp == 1 && right < size && vector[right].openLT(vector[min])) {
        min = right;
    }

    // When comp == 2, we are sorting based on close value
    // Checks if left child exists, if left close is less than current minimum close
    if (comp == 2 && left < size && vector[left].closeLT(vector[min])) {
        min = left;
    }
    // Checks if right child exists, if right open is less than current minimum close
    if (comp == 2 && right < size && vector[right].closeLT(vector[min])) {
        min = right;
    }

    // When comp == 3, we are sorting based on increase value
    // Checks if left child exists, if left open is less than current minimum inc
    if (comp == 3 && left < size && vector[left].incLT(vector[min])) {
        min = left;
    }
    // Checks if right child exists, if right open is less than current minimum inc
    if (comp == 3 && right < size && vector[right].incLT(vector[min])) {
        min = right;
    }

    // If a child is less than root
    if (min != root){
        // Swamp with lesser child
        std::swap(vector[min], vector[root]);
        // Recursively call heapify on the child you swap with
        heapify(vector, min, size, comp);
    }
}

std::vector<StockData> heap_sort(std::vector<StockData>& vector, int comp){
    // Create Copy of input vector so it doesnt get modified
    auto sorted = vector;
    
    int size = sorted.size();

    // Make the vector into a heap
    // Heapifies all non-leaf nodes
    for (int i = size / 2; i >= 0; i--) {
        heapify(sorted, i, size, comp);
    }

    // Reorder the heap using heapify (min heap)
    // Heapifies all nodes
    for (int i = size - 1; i >= 0; i--) {
        // Move root to end
        std::swap(sorted[0], sorted[i]);
        // Heapify from root of tree
        heapify(sorted, 0, i, comp);
    }
    // Returns sorted copy of vector
    return sorted;
}

int partition(std::vector<StockData>& vector, int low, int high, int comp) {
    // change to struct instead of int
    // test
    int i;
    if (comp == 1) {
        // open

        // pick pivot
        float pivot = vector[high].open;
        // index of smaller element
        i = low - 1;

        for (int j = low; j < high; j++) {
            // if element is smaller than pivot
            if (vector[j].open < pivot) {
                // increment index of smaller element
                i++;
                std::swap(vector[i], vector[j]);
            }
        }
    }
    else if (comp == 2) {
        // close

        // pick pivot
        float pivot = vector[high].close;
        // index of smaller element
        i = low - 1;

        for (int j = low; j < high; j++) {
            // if element is smaller than pivot
            if (vector[j].close < pivot) {
                // increment index of smaller element
                i++;
                std::swap(vector[i], vector[j]);
            }
        }
    }
    else if (comp == 3) {
        // percent increase

        // pick pivot
        int pivot = vector[high].increase;
        // index of smaller element
        i = low - 1;

        for (int j = low; j < high; j++) {
            // if element is smaller than pivot
            if (vector[j].increase < pivot) {
                // increment index of smaller element
                i++;
                std::swap(vector[i], vector[j]);
            }
        }
    }

    std::swap(vector[i+1], vector[high]);
    return i + 1;
}

void quick_sort(std::vector<StockData>& vector, int low, int high, int comp) {
    // change to struct instead of int
    // test

    if (low < high) {
        int index = partition(vector, low, high, comp);

        quick_sort(vector, low, index - 1, comp);
        quick_sort(vector, index + 1, high, comp);
    }
}

std::vector<StockData> quick_sort(std::vector<StockData>& vector, int comp) {
    // change to struct instead of int
    // test

    // create new vector to store the sorted vector
    std::vector<StockData> sorted = vector;
    int size = sorted.size();
    quick_sort(sorted, 0, size - 1, comp);
    return sorted;
}