#include<iostream>


/**
 * @brief - Swap between two elements by indexes
 * @tparam T - Parameter for generic functions
 * @param arr - Pointer to the start of the array
 * @param idx1 - Index of the first element to swap
 * @param idx2 - Index of the second element to swap
*/
template<class T>
void swapT(T* arr, int idx1, int idx2) {
	T tmp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = tmp;
}

/**
 * @brief 
 * @tparam T 
 * @param arr 
 * @param p 
 * @param r 
 * @return 
*/
template<class T>
int partition(T* arr, int p, int r,int *cmp) {
	T x = arr[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++) {
		(*cmp)++;
		if (arr[j] <= x) {
			i++;
			swapT(arr,i, j);
		}
	}
	swapT(arr, i + 1, r);
	return i + 1;
}


/**
 * @brief 
 * @tparam T 
 * @param arr 
 * @param p 
 * @param r 
 * @return 
*/
template<class  T>
int randomizePartition(T* arr, int p, int r,int *cmp) {
	int i = (rand() % r) + 1;
	swapT(arr, r, i);
	return partition(arr, p, r,cmp);
}


/**
 * @brief 
 * @tparam T 
 * @param arr 
 * @param p 
 * @param r 
*/
template<class T>
void quickSort(T* arr, int p, int r,int *cmp) {
	if (p < r) {
		int q = randomizePartition(arr, p, r,cmp);
		quickSort(arr, p, q - 1,cmp);
		quickSort(arr, q + 1, r,cmp);
	}
}


/**
 * @brief 
 * @tparam T 
 * @param arr 
 * @param p 
 * @param r 
 * @param i 
 * @return 
*/
template<class T>
T randomizeSelect(T* arr, int p, int r, int i,int *cmp) {
	if (p == r) return arr[p];
	int q = randomizePartition(arr, p, r,cmp);
	int k = q - p + 1;
	if (i == k) {
		return arr[q];
	}
	else if(i < k) {
		return randomizeSelect(arr, p, q - 1, i,cmp);
	}
	else {
		return randomizeSelect(arr, q + 1, r, i - k,cmp);
	}

}