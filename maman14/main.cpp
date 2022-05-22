// maman14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "minHeap.h"
#include "randomizeSelectQuickSort.cpp"





int main()
{
	int arr[] = { 8,7,6,5,4,3,2,1 };
	int arr2[] = { 8,7,6,5,4,3,2,1 };
	minHeap<int> heap(arr, 8);
	heap.printHeap();
	heap.buildMinHeap();
	heap.printHeap();
	std::cout << "The 5 smallest elements are:" << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << heap.heapExtractMin() << std::endl;
	}
	heap.printCmpSize();

	std::cout << randomizeSelect(arr2,0, 7, 5) << std::endl;
	quickSort(arr2, 0, 4);
	std::cout << "/n";
	std::cout << "The 5 smallest elements sorted by the randomize select and quick sort algorithem are:" << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << arr2[i] << std::endl;
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
