#include <iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	cout << "Enter Number Of Elements" << endl;
	int N;
	cin >> N;
	int* ptr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> ptr[i];
	}
	insertionSort(ptr, N);
	printArray(ptr, N);

	return 0;
}

