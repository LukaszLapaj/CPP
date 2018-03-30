#include <iostream>
using namespace std;

void print(int t[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << t[i] << "\t";
	}
	cout << endl;
}

void merge(int t[], int lo, int pivot, int hi) {
	int i = lo, j = pivot + 1, k = 0;
	int tmp[hi - lo + 1];
	while (i <= pivot && j <= hi) {
		if (t[i] < t[j]) {
			tmp[k] = t[i];
			++i;
		}
		else {
			tmp[k] = t[j];
			++j;
		}
		++k;
	}
	while (i <= pivot) {
		tmp[k] = t[i];
		++i;
		++k;
	}
	while (j <= hi) {
		tmp[k] = t[j];
		++j;
		++k;
	}
	for (int i = lo; i <= hi; ++i) {
		t[i] = tmp[i - lo];
	}
}

void mergeSortRecursive(int t[], int lo, int hi) {
	int mid = lo + (hi - lo) / 2;
	mergeSortRecursive(t, lo, mid);
	mergeSortRecursive(t, mid + 1, hi);
	merge(t, lo, mid, hi);
}

int main() {
	int array[] = { 3, 1, 2, 5, 4, 9, 8, 7, 0, 6 };
	int arraySize = sizeof(array) / sizeof(array[0]);

	print(array, arraySize);
	mergeSortRecursive(array, 0, arraySize - 1);
	print(array, arraySize);
	return 0;
}