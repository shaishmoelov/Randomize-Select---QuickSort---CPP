#include <iostream>
#pragma once
template<class T>
class minHeap{
	T* arr;
	int arrSize;
	int heapSize;
	int cmpCount;

public:

	minHeap(T* arr, int n) {
		this->arr = arr;
		this->arrSize = n;
		this->cmpCount = 0;
		this->heapSize = n;
	}
	

	void buildMinHeap() {
		for (int i = arrSize / 2 ; i >= 0; i--) {
			minHeapify(i);
		}
	}

	void minHeapify(int i) {
		int l = getLeft(i);
		int r = getRight(i);
		int smallest = -1;
		if (l < heapSize && arr[l] < arr[i]) {
			smallest = l;
			cmpCount++;
		}
		else {
			smallest = i;
			cmpCount++;
		}
		if (r < heapSize && arr[r] < arr[smallest]) {
			smallest = r;
			cmpCount++;
		}
		if (smallest != i) {
			swap(smallest, i);
			minHeapify(smallest);
		}
	}

	void swap(int idx1, int idx2) {
		T tmp = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = tmp;
	}

	/*Get the parent of index i like we learned in book*/
	int getParent(int i) {
		return i >> 1;
	}

	/*Get the left child of index i like we learned in book*/
	int getLeft(int i) {
		return (i << 1) + 1;
	}

	/*Get the right child of index i like we learned in book*/
	int getRight(int i) {
		return (i << 1) + 2;
	}

	void printHeap() {
		for (int i = 0; i < heapSize; i++) {
			printf("%d ", arr[i]);
		}
	}

	int heapExtractMin() {
		if (heapSize < 1) {
			std::cout << "heap underflow" << std::endl;
		}
		int min = arr[0];
		arr[0] = arr[heapSize - 1];
		heapSize--;
		minHeapify(0);
		return min;
	}

	void printCmpSize() {
		std::cout << "The number of compares in the past algorithem between array elemnts was: " <<
			cmpCount << std::endl;
	}

};

