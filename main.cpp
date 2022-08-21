// maman14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "minHeap.h"
#include "randomizeSelectQuickSort.cpp"
#include <iterator>
#include <algorithm>


void Execute_random_quickSort(int* arr, int p, int r, int k, int* cmp) {
	randomizeSelect(arr, p, r, k, cmp);
	quickSort(arr, 0, k - 1, cmp);
	
	std::cout << "Using randomize selectand quick sort, let's print the " << k <<  " smallest elements from " << r+1 << " elements" << std::endl;
	for (int i = 0; i < k; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Lets print the number of comparetions we done: " << (*cmp) << std::endl;
	(*cmp) = 0;
	std::cout << std::endl;
	std::cout << std::endl;
}


void Execute_heap(int* arr, int n, int k) {
	minHeap<int> heap(arr, 100);
	heap.buildMinHeap();
	std::cout << "Lets print the result for A array with n=" << n <<  " and k=" << k << std::endl;
	for (int i = 0; i < k; i++) {
		std::cout << heap.heapExtractMin() << " ";
	}
	std::cout << std::endl;
	heap.printCmpSize();
	std::cout << std::endl;
	std::cout << std::endl;
}






int main()
{
	int n, k, tmp_number, num_of_comp_random_quick = 0;
	char random_bool;
	srand(time(0));
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
	std::cout << std::endl;
	std::cout << std::endl;
	/*Randomize select && quicksort part*/
	Execute_random_quickSort(arr_to_quicksort, 0, n-1 , k , &num_of_comp_random_quick);
	
	/*Heap part*/
	minHeap<int> heap(arr_to_heap, n);
	heap.buildMinHeap();
	std::cout << "We can now print the " << k << " smallest elements we found with the Min Heap structure : " << std::endl;
	for (int i = 0; i < k; i++) {
		std::cout << heap.heapExtractMin() << " ";
	}
	std::cout << std::endl;
	heap.printCmpSize();


	delete[] arr_to_heap;
	delete[] arr_to_quicksort;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "SECTION B: " << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	/*Allocate araays for the randomize select, quicksort, heap and random integers elements for them*/
	int k1 = 8, k2 = 50, k3 = 100;
	int* A_rand_quick_k1 = new int[100];
	int* A_rand_quick_k2 = new int[100];
	int* A_rand_quick_k3 = new int[100];
	int* B_rand_quick_k1 = new int[200];
	int* B_rand_quick_k2 = new int[200];
	int* B_rand_quick_k3 = new int[200];
	int* C_rand_quick_k1 = new int[500];
	int* C_rand_quick_k2 = new int[500];
	int* C_rand_quick_k3 = new int[500];
	int* D_rand_quick_k1 = new int[1000];
	int* D_rand_quick_k2 = new int[1000];
	int* D_rand_quick_k3 = new int[1000];
	int cmpNumA = 0;
	int cmpNumB = 0;
	int cmpNumC = 0;
	int cmpNumD = 0;
	int* A_heap_k1 = new int[100];
	int* A_heap_k2 = new int[100];
	int* A_heap_k3 = new int[100];
	int* B_heap_k1 = new int[200];
	int* B_heap_k2 = new int[200];
	int* B_heap_k3 = new int[200];
	int* C_heap_k1 = new int[500];
	int* C_heap_k2 = new int[500];
	int* C_heap_k3 = new int[500];
	int* D_heap_k1 = new int[1000];
	int* D_heap_k2 = new int[1000];
	int* D_heap_k3 = new int[1000];

	for (int i = 0; i < 100; i++) {
		A_rand_quick_k1[i] = rand() % 100;
		A_rand_quick_k2[i] = rand() % 100;
		A_rand_quick_k3[i] = rand() % 100;
	}
	for (int i = 0; i < 200; i++) {
		B_rand_quick_k1[i] = rand() % 200;
		B_rand_quick_k2[i] = rand() % 200;
		B_rand_quick_k3[i] = rand() % 200;
	}
	for (int i = 0; i < 500; i++) {
		C_rand_quick_k1[i] = rand() % 500;
		C_rand_quick_k2[i] = rand() % 500;
		C_rand_quick_k3[i] = rand() % 500;
	}
	for (int i = 0; i < 1000; i++) {
		D_rand_quick_k1[i] = rand() % 1000;
		D_rand_quick_k2[i] = rand() % 1000;
		D_rand_quick_k3[i] = rand() % 1000;
	}

	/*Copy the array for the heap section*/

	for (int i = 0; i < 100; i++) {
		A_heap_k1[i] = A_rand_quick_k1[i];
	}
	for (int i = 0; i < 200; i++) {
		B_heap_k1[i] = B_rand_quick_k1[i];
	}
	for (int i = 0; i < 500; i++) {
		C_heap_k1[i] = C_rand_quick_k1[i];
	}
	for (int i = 0; i < 1000; i++) {
		D_heap_k1[i] = D_rand_quick_k1[i];
	}

	/*Copy the array for the heap section*/

	for (int i = 0; i < 100; i++) {
		A_heap_k2[i] = A_rand_quick_k2[i];
	}
	for (int i = 0; i < 200; i++) {
		B_heap_k2[i] = B_rand_quick_k2[i];
	}
	for (int i = 0; i < 500; i++) {
		C_heap_k2[i] = C_rand_quick_k2[i];
	}
	for (int i = 0; i < 1000; i++) {
		D_heap_k2[i] = D_rand_quick_k2[i];
	}

	/*Copy the array for the heap section*/

	for (int i = 0; i < 100; i++) {
		A_heap_k3[i] = A_rand_quick_k3[i];
	}
	for (int i = 0; i < 200; i++) {
		B_heap_k3[i] = B_rand_quick_k3[i];
	}
	for (int i = 0; i < 500; i++) {
		C_heap_k3[i] = C_rand_quick_k3[i];
	}
	for (int i = 0; i < 1000; i++) {
		D_heap_k3[i] = D_rand_quick_k3[i];
	}


	std::cout << "Part of randomize select and quicksort" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	/*Execute with A as input, n=100 k=8*/
	Execute_random_quickSort(A_rand_quick_k1, 0, 99, k1, &cmpNumA);

	/*Execute with A as input, n=100 k=50*/
	Execute_random_quickSort(A_rand_quick_k2, 0, 99, k2, &cmpNumA);

	/*Execute with A as input, n=100 k=100*/
	Execute_random_quickSort(A_rand_quick_k3, 0, 99, k3, &cmpNumA);

	/*Execute with B as input, n=200 k=8*/
	Execute_random_quickSort(B_rand_quick_k1, 0, 199, k1, &cmpNumB);

	/*Execute with B as input, n=200 k=50*/
	Execute_random_quickSort(B_rand_quick_k2, 0, 199, k2, &cmpNumB);

	/*Execute with B as input, n=200 k=100*/
	Execute_random_quickSort(B_rand_quick_k3, 0, 199, k3, &cmpNumB);

	/*Execute with C as input, n=500 k=8*/
	Execute_random_quickSort(C_rand_quick_k1, 0, 499, k1, &cmpNumC);

	/*Execute with C as input, n=500 k=50*/
	Execute_random_quickSort(C_rand_quick_k2, 0, 499, k2, &cmpNumC);

	/*Execute with C as input, n=500 k=100*/
	Execute_random_quickSort(C_rand_quick_k3, 0, 499, k3, &cmpNumC);

	/*Execute with D as input, n=1000 k=8*/
	Execute_random_quickSort(D_rand_quick_k1, 0, 999, k1, &cmpNumD);

	/*Execute with D as input, n=1000 k=50*/
	Execute_random_quickSort(D_rand_quick_k2, 0, 999, k2, &cmpNumD);

	/*Execute with D as input, n=1000 k=100*/
	Execute_random_quickSort(D_rand_quick_k3, 0, 999, k3, &cmpNumD);

	std::cout << "Part of Heap" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	/*Execute with A input, n=100 k=8*/
	Execute_heap(A_heap_k1, 100, k1);

	/*Execute with A input, n=100 k=50*/
	Execute_heap(A_heap_k2, 100, k2);

	/*Execute with A input, n=100 k=100*/
	Execute_heap(A_heap_k3, 100, k3);

	/*Execute with B input, n=200 k=8*/
	Execute_heap(B_heap_k1, 200, k1);

	/*Execute with B input, n=200 k=50*/
	Execute_heap(B_heap_k2, 200, k2);

	/*Execute with B input, n=200 k=100*/
	Execute_heap(B_heap_k3, 200, k3);

	/*Execute with C input, n=500 k=8*/
	Execute_heap(C_heap_k1, 500, k1);

	/*Execute with C input, n=500 k=50*/
	Execute_heap(C_heap_k2, 500, k2);

	/*Execute with C input, n=500 k=100*/
	Execute_heap(C_heap_k3, 500, k3);

	/*Execute with D input, n=1000 k=8*/
	Execute_heap(D_heap_k1, 1000, k1);

	/*Execute with D input, n=1000 k=50*/
	Execute_heap(D_heap_k2, 1000, k2);

	/*Execute with D input, n=1000 k=100*/
	Execute_heap(D_heap_k3, 1000, k3);

	delete[] A_heap_k1;
	delete[] A_heap_k2;
	delete[] A_heap_k3;
	delete[] B_heap_k1;
	delete[] B_heap_k2;
	delete[] B_heap_k3;
	delete[] C_heap_k1;
	delete[] C_heap_k2;
	delete[] C_heap_k3;
	delete[] D_heap_k1;
	delete[] D_heap_k2;
	delete[] D_heap_k3;
	delete[] A_rand_quick_k1;
	delete[] B_rand_quick_k1;
	delete[] C_rand_quick_k1;
	delete[] D_rand_quick_k1;
	delete[] A_rand_quick_k2;
	delete[] B_rand_quick_k2;
	delete[] C_rand_quick_k2;
	delete[] D_rand_quick_k2;
	delete[] A_rand_quick_k3;
	delete[] B_rand_quick_k3;
	delete[] C_rand_quick_k3;
	delete[] D_rand_quick_k3;

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
