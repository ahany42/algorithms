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
template <class T>
void printArray(T arr[], int n)
{

	for (int i  = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
template <class T>
void bubbleSort(T arr[],int n) {
	for (int i = 0; i < n-1; i++)
		for (int j = 0; j < n; j++) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
				
			}
				
		}
		
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
	//insertionSort(ptr, N);
	bubbleSort(ptr, N);
	printArray(ptr, N);
	return 0;
}

