#include <iostream>
using namespace std;

void swap(int t[], int i, int j) {
	int tmp = t[i];
	t[i] = t[j];
	t[j] = tmp;
}

void quickSort(int t[], int lo, int hi) {
	int i = lo, j = hi;
	int mid = t[lo + (hi - lo) / 2];
	while (i <= j) {
		while (t[i] < mid) ++i;
		while (mid < t[j]) --j;
		if (i <= j) {
			swap(t, i, j);
			++i;
			--j;
		}
	}
	if (lo < j) quickSort(t, lo, j);
	if (i < hi) quickSort(t, i, hi);
}

void print(int t[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << t[i] << "\t";
	}
	cout << endl;
}

int main() {
	int array[] = { 3, 1, 2, 5, 4, 9, 8, 7, 0, 6 };
	int arraySize = sizeof(array) / sizeof(array[0]);

	print(array, arraySize);
	quickSort(array, 0, arraySize - 1);
	print(array, arraySize);
	return 0;
}