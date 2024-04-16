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

//Multiplying 2 numbers with only summation and with complexity less than O(n)
int SmartMultiply(int num1,int num2) {
	int mult;
	if (num1 == 0)
		return 0;
	 if (num1 == 1)
		return num2;
	 mult = SmartMultiply(num1 / 2, num2);
		if (num1 % 2 == 0)
			return mult + mult;
		else
			return mult + mult + num2;
	
	
}
int main()
{
	int num1, num2;
	/*cout << "Enter Number Of Elements" << endl;
	int N;
	cin >> N;
	int* ptr = new int[N];
	cout << "Enter Array Elements" << endl;
	for (int i = 0; i < N; i++) {
		cin >> ptr[i];
	}
	averageprefix(ptr, N);*/
	//insertionSort(ptr, N);
	//bubbleSort(ptr, N);
	//printArray(ptr, N);
	cout << "Enter Num 1" << endl;
	cin >> num1;
	cout << "Enter Num 2" << endl;
	cin >> num2;
	cout<<SmartMultiply(num1, num2);
	return 0;
}

