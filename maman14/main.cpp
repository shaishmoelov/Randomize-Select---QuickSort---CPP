// maman14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "minHeap.h"
#include "randomizeSelectQuickSort.cpp"
#include <iterator>
#include <algorithm>





int main()
{
	int n, k,tmp_number,num_of_comp_random_quick=0;
	char random_bool;
	std::cout << "HELLO! Please provide the lenght of the array as an integer: ";
	std::cin >> n;
	std::cout << "Please let me know how many smallest numbers you would like as an integer: ";
	std::cin >> k;
	std::cout << "Please press 'y' if you want me to randomize the numbers in the array, otherwise press 'n': ";
	std::cin >> random_bool;
	int* arr_to_heap = new int[n];
	int* arr_to_quicksort = new int[n];
	if (random_bool == 'y') {/*An array of n integers is randomly generated here*/
		for (int i = 0; i < n; i++) {
			arr_to_heap[i] = rand() % 1000;
		}
	}
	else if (random_bool == 'n') {/*The user is asked to provide the array elements here*/
		for (int i = 0; i < n; i++) {
			std::cout << "Enter number" << i + 1 << " : ";
			std::cin >> tmp_number;
			arr_to_heap[i] = tmp_number;
		}
	}
	else { /*The user entered incorrect parameters*/
		std::cout << "Not Vaid Input - Abort" << std::endl;
		return 0;
	}

	/*Here's a copy of the array for observing the results later*/
	for (int i = 0; i < n; i++) {
		arr_to_quicksort[i] = arr_to_heap[i];
	}

	/*Randomize select && quicksort part*/
	std::cout << randomizeSelect(arr_to_quicksort,0, n-1, k-1,&num_of_comp_random_quick) << std::endl;
	quickSort(arr_to_quicksort, 0, k-1,&num_of_comp_random_quick);
	std::cout << std::endl;

	/*Using randomize select and quick sort, let's print the k smallest elements*/
	std::cout << "According to the randomize select and quick sort algorithms, the " << k <<
		"smallest elements are: "<< std::endl;
	for (int i = 0; i < k; i++) {
		std::cout << arr_to_quicksort[i] << " ";
	}
	std::cout << std::endl;
	
	std::cout << "Let's print the number of comparisons we made: " ;
	std::cout << num_of_comp_random_quick << std::endl;

	/*Heap part*/
	minHeap<int> heap(arr_to_heap, n);
	heap.buildMinHeap();
	std::cout << "We can now print the k smallest elements we found with the Min Heap structure: " << std::endl;
	for (int i = 0; i < k; i++) {
		std::cout << heap.heapExtractMin() << " ";
	}
	std::cout << std::endl;
	heap.printCmpSize();
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
