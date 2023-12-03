#include "StockData.h"
#include <vector>
#include <iostream>

using namespace std;

void heapify(vector<int>& vec, int root, int size){
    // Assign the indexes of the subtree's root, left child, and right child
    int min = root;
    int left = 2*root + 1;
    int right = 2*root + 2;

    // Checks if left child exists, if left is less than current minimum
    if (left < size && vec[left] < vec[min]){
        min = left;
    }
    // Checks if right child exists, if right is less than current minimum
    if (right < size && vec[right] < vec[min]){
        min = right;
    }
    // If a child is less than root
    if (min != root){
        // Swamp with lesser child
        swap(vec[min], vec[root]);
        // Recursively call heapify on the child you swap with
        heapify(vec, min, size);
    }
}

vector<int> heap_sort(vector<int> vec){
    // Create Copy of input vector so it doesnt get modified
    int size = vec.size();

    // Make the vector into a heap
    // Heapifies all non-leaf nodes
    for (int i = size/2; i >= 0; i--){
        heapify(vec, i, size);
    }

    // Reorder the heap using heapify (min heap)
    // Heapifies all nodes
    for (int i = size-1; i>=0; i--){
        // Move root to end
        swap(vec[0], vec[i]);
        // Heapify from root of tree
        heapify(vec, 0, i);
    }
    // Returns sorted copy of vector
    return vec;
}


int main(){
    vector<int> test;

    test.push_back(17);
    test.push_back(7);
    test.push_back(13);
    test.push_back(6);
    test.push_back(9);
    test.push_back(8);
    test.push_back(2);
    test.push_back(19);
    test.push_back(20);

    vector<int> sorted_test = heap_sort(test);

    for (auto& i : test){
        cout << i << ", ";
    }
    cout << endl;

    for (auto& i : sorted_test){
        cout << i << ", ";
    }


    string buffer;
    cin >> buffer;

}