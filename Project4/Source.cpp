#include <iostream>
#include <vector>
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
int FindPeak(vector<int> arr) {
	int start = 0;
	int end = arr.size()-1;
	int mid = 0;
		cout << "start " << start << endl;
	cout << "end " << end << endl;
	while (start < end) {
		mid = start + (end -start) / 2;
		if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1])
			return arr[mid];
		else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1]) {
			end = mid-1;

		}
		else {
			start = mid+1;

		}
	}
	return arr[end];
	
}
int main()
{
	//int num1, num2;
	/*cout << "Enter Number Of Elements" << endl;
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
	cout << "Enter Num 1" << endl;
	cin >> num1;
	cout << "Enter Num 2" << endl;
	cin >> num2;
	cout<<SmartMultiply(num1, num2);*/
	vector<int> arr = { 1, 3, 5, 7, 9, 11, 10, 8, 6, 4, 2 };
	cout <<"Peak "<< FindPeak(arr) << endl;
	vector<int> arr2 = { 1, 7, 6, 2 };
	cout << "Peak " << FindPeak(arr2) << endl;
	vector<int> arr3 = { 1, 2,3,4,5,6,7,11,10,9,8,7,5,6,4,3 };
	cout << "Peak " << FindPeak(arr3) << endl;
	return 0;
}

