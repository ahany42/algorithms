#include <iostream>
using namespace std;
template <class T>
void insertionSort(T arr[], int n)
{
	int i,  j;
	T key;
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
void averageprefix(int arr[],int n) {
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + arr[i];
		cout << sum / (i + 1)<<" ";
	}
	
}
int main()
{
	cout << "Enter Number Of Elements" << endl;
	int N;
	cin >> N;
	int* ptr = new int[N];
	cout << "Enter Array Elements" << endl;
	for (int i = 0; i < N; i++) {
		cin >> ptr[i];
	}
	averageprefix(ptr, N);
	//insertionSort(ptr, N);
	//bubbleSort(ptr, N);
	//printArray(ptr, N);
	return 0;
}

