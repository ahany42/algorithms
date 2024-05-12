#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
template <class T>
void insertionSort(T arr[], int n)
{
	cout << "----- Insertion Sort -----" << endl;
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
	cout << "----- Print Array -----" << endl;
	for (int i  = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
template <class T>
void bubbleSort(T arr[],int n) {
	cout << "----- Bubble Sort -----" << endl;
	for (int i = 0; i < n-1; i++)
		for (int j = 0; j < n; j++) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
				
			}
				
		}
		
}
void averageprefix(int arr[],int n) {
	cout << "----- Average Prefix -----" << endl;
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + arr[i];
		cout << sum / (i + 1)<<" ";
	}
	
}

//Multiplying 2 numbers with only summation and with complexity less than O(n)
int SmartMultiply(int num1,int num2) {
	cout << "----- Smart Multiply -----" << endl;
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
	cout << "----- Find Peak -----" << endl;
	int start = 0;
	int end = arr.size()-1;
	int mid = 0;

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
//Binary Search,arr>>sorted array
template <class T>
bool BinarySearch(vector<T> arr,T element,int &index) {
	cout << "----- Binary Search -----" << endl;
	int start = 0;
	int end = arr.size() - 1;
	int mid = 0;
	while(start<=end){
		mid = start + (end - start) / 2;
		if (arr[mid] > element) {
			end = mid - 1;
		}
		else if (arr[mid] < element) {
			start = mid + 1;
		}
		else
		{
			index = mid;
			return true;
		}
	}
	

	index = -1;
	return false;

	
}
//Using Divide And Conquer Technique
void Combine(vector<int> &arr, vector<int> &leftHalf, vector<int> &rightHalf) {
	int leftSize = leftHalf.size();
	int rightSize = rightHalf.size();
	int i=0, j=0, k = 0;
	while (i < leftSize && j < rightSize) {
		if (leftHalf[i] <= rightHalf[j]) {
			arr[k] = leftHalf[i];
			i++;
		}
		else {
			arr[k] = rightHalf[j];
			j++;
		}
		k++;
	}
	while (i < leftSize) {
		arr[k] = leftHalf[i];
		k++;
		i++;
	}
	while (j < rightSize) {
		arr[k] = rightHalf[j];
		k++;
		j++;
	}
}
void MergeSort(vector<int> &arr) {
	int size = arr.size();
	int mid = size / 2;
	if (size < 2)
		return;
	//Divide
	vector<int> leftHalf(arr.begin(), arr.begin() + mid);
	vector<int> rightHalf(arr.begin() + mid, arr.end());
	MergeSort(leftHalf);
	MergeSort(rightHalf);
	//Combine
	Combine(arr, leftHalf, rightHalf);
}
//two sum problem
vector<int> twoSum(vector<int>& nums, int target) {
	vector <int> solution;
	int size = nums.size();
	int start = 0;
	int end = nums.size() - 1;
	int i = 0;
	while (abs(nums[start] + nums[end]) != abs(target) || i == size) {
		i++;
		if (abs(nums[start] + nums[end]) > abs(target)) {
			end--;
		}
		else if (abs(nums[start] + nums[end]) < abs(target)) {
			start++;
		}
	}
	if (i == size) {
		return solution;
	}
	else {

		solution.push_back(start);
		solution.push_back(end);
	}

	return solution;
}
int FindDrop(int arr[], int N) {
	int start = 0;
	int end = N - 1;
	int mid = 0;
	if (N < 2)
		return arr[0];
	while (end > start) {
	mid = (start + end) / 2;
	if (arr[mid] < arr[mid + 1] && arr[mid] < arr[mid - 1])
		return arr[mid];
	else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
	
		end = mid - 1;
	else if (arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1])

		start = mid + 1;
	

	}
}
long DpFibonacci(int number) {
/*if (number == 0)
		return 0;
	if (number == 1)
		return 1;*/
	long* fib = new long[number ];
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= number ; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	return fib[number];
}
int main()
{
	/*int num1, num2;
	cout << "Enter Number Of Elements" << endl;
	int N;
	cin >> N;
	int* ptr = new int[N];
	cout << "Enter Array Elements" << endl;
	for (int i = 0; i < N; i++) {
		cin >> ptr[i];
	}
	averageprefix(ptr, N);
	insertionSort(ptr, N);
	bubbleSort(ptr, N);
    printArray(ptr, N);
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
	int index = 0;
	vector<int> arr4 = {1,5,8,9,10,17,20};
	vector <char> arr5 = { 'a','b','c','d','e' };
	cout <<endl<< "Index is 1 based " << endl;
	if (BinarySearch(arr4, 3, index))
		cout << "Element Found At index " << index+1 << endl;
	else
		cout << "Element Not Found " << endl;
	if (BinarySearch(arr4, 17, index))
		cout << "Element Found At index " << index + 1 << endl;
	else
		cout << "Element Not Found " << endl;
	if (BinarySearch(arr4, 20, index))
		cout << "Element Found At index " << index + 1 << endl;
	else
		cout << "Element Not Found " << endl;
	if (BinarySearch(arr4, 1, index))
		cout << "Element Found At index " << index + 1 << endl;
	else
		cout << "Element Not Found " << endl;
	if (BinarySearch(arr5, 'a', index))
		cout << "Element Found At index " << index + 1 << endl;
	else
		cout << "Element Not Found " << endl;
	if (BinarySearch(arr5, 'e', index))
		cout << "Element Found At index " << index + 1 << endl;
	else
		cout << "Element Not Found " << endl;
	if (BinarySearch(arr5, 'd', index))
		cout << "Element Found At index " << index + 1 << endl;
	else
		cout << "Element Not Found " << endl;
	if (BinarySearch(arr5, 'w', index))
		cout << "Element Found At index " << index + 1 << endl;
	else
		cout << "Element Not Found " << endl;
	MergeSort(arr);
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << "  ";
	cout << endl;
	int arr7[8] = {10, 9, 4,  2, 6, 10, 100};
	cout << "Drop "<<FindDrop(arr7, 7) << endl;
	cout << DpFibonacci(15) << " " << DpFibonacci(50) << " " << endl;
	return 0;
}

