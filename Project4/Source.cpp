#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
template <class T>
void InsertionSort(T arr[], int n)
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
void PrintArray(T arr[], int n)
{
	cout << "----- Print Array -----" << endl;
	for (int i  = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
template <class T>
void PrintArray(vector<T> arr)
{
	cout << "----- Print Vector -----" << endl;
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}
template <class T>
void BubbleSort(T arr[],int n) {
	cout << "----- Bubble Sort -----" << endl;
	for (int i = 0; i < n-1; i++)
		for (int j = 0; j < n; j++) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
				
			}
				
		}
		
}
void AveragePrefix(int arr[],int n) {
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

	long* fib = new long[number ];
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= number ; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	return fib[number];
}
long Fibonacci(int number){
	if (number == 1)
		return 1;
	if (number == 0)
		return 0;
	else
		return Fibonacci(number - 1) + Fibonacci(number - 2);
}
//Fibonacci with a twist , Fibonacci count to reset
/*
* Test Cases 
* number=16,reset=5 output=1
* number=16,reset=6 output=5
* number=17,reset=6 output=8
* number=1506,reset=10 output=1
*/
int ResetFibonacci(int number, int reset) {
	if (number == reset)
		return DpFibonacci(number);
	int* fib = new int[reset];
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= reset; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	return fib[(number%reset)+1];
}
int main()
{
	while (true) {
	int choice;
	cout << "Press 1 For Mathimatical Algorithms" << endl;
	cout << "Press 2 For Sorting Algorithms" << endl;
	cout << "Press 3 For Binary Search Algorithms" << endl;
	cout << "Press 4 For Fibonacci" << endl;
	cout << "Press 9 To exit" << endl;
	cin >> choice;
	if (choice == 1) {
		while (true) {
			int choice2;
			cout << "Press 1 For Average Prefix " << endl;
			cout << "Press 2 For Smart Multiply " << endl;
			cout << "Press 9 Back To Main Menu" << endl;
			cin >> choice2;
			if (choice2 == 1) {
				cout << "Enter Number Of Elements" << endl;
				int N;
				cin >> N;
				int* ptr = new int[N];
				cout << "Enter Array Elements" << endl;
				for (int i = 0; i < N; i++) {
					cin >> ptr[i];
				}
				AveragePrefix(ptr, N);
			}
			else if (choice == 2) {
				int num1, num2;
				cout << "Enter Num 1" << endl;
				cin >> num1;
				cout << "Enter Num 2" << endl;
				cin >> num2;
				cout << SmartMultiply(num1, num2);

			}
			else if (choice2 == 9)
				break;
		}
	}
	else if (choice == 2) {
		while (true) {
			int choice2;
			cout << "Press 1 For Insertion Sort " << endl;
			cout << "Press 2 For Bubble Sort " << endl;
			cout << "Press 3 For Merge Sort " << endl;
			cout << "Press 9 Back To Main Menu" << endl;
			cin >> choice2;
			if (choice2 == 1) {
				cout << "Enter Number Of Elements" << endl;
				int N;
				cin >> N;
				int* ptr = new int[N];
				cout << "Enter Array Elements" << endl;
				for (int i = 0; i < N; i++) {
					cin >> ptr[i];
				}
				InsertionSort(ptr, N);
			    PrintArray(ptr, N);

			}
			else if (choice2 == 2) {
				cout << "Enter Number Of Elements" << endl;
				int N;
				cin >> N;
				int* ptr = new int[N];
				cout << "Enter Array Elements" << endl;
				for (int i = 0; i < N; i++) {
					cin >> ptr[i];
				}
				BubbleSort(ptr, N);
				PrintArray(ptr, N);
			}
			else if (choice2 == 3) {
				cout << "Enter Number Of Elements" << endl;
				int N;
				cin >> N;
				vector <int> arr;
				int* arr1 = new int[N];
				cout << "Enter Array Elements" << endl;
				for (int i = 0; i < N; i++) {
					cin >> arr1[i];
					arr.push_back(arr1[i]);
				}
				MergeSort(arr);
				PrintArray(arr);
			}
			else if (choice2 == 9)
				break;

		}
		
	}
	else if (choice == 3) {
		while (true) {
			int choice2;
			cout << "Press 1 For Find Peak Algorithm " << endl;
			cout << "Press 2 For Find Drop Algorithm " << endl;
			cout << "Press 3 For Binary Search " << endl;
			cout << "Press 9 Back To Main Menu" << endl;
			cin >> choice2;
			if (choice2 == 1) {
				vector<int> arr = { 1, 3, 5, 7, 9, 11, 10, 8, 6, 4, 2 };
				PrintArray(arr);
				cout << "Peak " << FindPeak(arr) << endl;
				vector<int> arr2 = { 1, 7, 6, 2 };
				PrintArray(arr);
				cout << "Peak " << FindPeak(arr2) << endl;
				vector<int> arr3 = { 1, 2,3,4,5,6,7,11,10,9,8,7,5,6,4,3 };
				PrintArray(arr);
				cout << "Peak " << FindPeak(arr3) << endl;
			}
			else if (choice2 == 2)
			{
				int arr7[8] = { 10, 9, 4,  2, 6, 10, 100 };
				PrintArray(arr7, 8);
				cout << "Drop " << FindDrop(arr7, 7) << endl;
			}
			else if (choice2 == 3) {
				cout << "Enter Number Of Integers" << endl;
				int N;
				int val;
				cin >> N;
				vector <int> arr;
				int* arr1 = new int[N];
				cout << "Enter Array Elements" << endl;
				for (int i = 0; i < N; i++) {
					cin >> arr1[i];
					arr.push_back(arr1[i]);
				}
				cout << "Enter Value to Search For" << endl;
				cin >> val;
				int index = 0;
				if (BinarySearch(arr, val, index))
					cout << "Element Found At index " << index + 1 << endl;
				else
					cout << "Element Not Found " << endl;
			}
			else if (choice == 9)
				break;
		}
	}
	else if (choice == 4) {
		while (true) {
			int choice2;
			cout << "Press 1 For Recursive Fibonacci " << endl;
			cout << "Press 2 For Dynamic Programming Fibonacci " << endl;
			cout << "Press 3 For Reset Fibonnaci " << endl;
			cout << "Press 9 Back To Main Menu" << endl;
			cin >> choice2;
			if (choice2 == 1)
			{
				int num;
				cout << "Enter Number to Calculate Fibonnaci"<<endl;
				cout << "Complexity O(2^n)" << endl;
				cin >> num;
				if (num>46)
					cout << "Fibonnaci of " << num << " is more than Long Limit " << LONG_MAX << endl;
				else cout << "Fibonnaci " <<Fibonacci(num) << endl;
			}
			else if (choice2 == 2) {
				int num;
				cout << "Enter Number to Calculate Fibonnaci by Dynamic Programming" << endl;
				cout << "Complexity O(n)" << endl;
				cin >> num;
				if (num > 46)
					cout << "Fibonnaci of " << num << " is more than Long Limit " << LONG_MAX << endl;
				else cout << "Fibonnaci " << DpFibonacci(num) << endl;
			}
			else if (choice2 == 3) {
				int num, reset;
				cout << "Enter Number to Calculate Reset Fibonnaci" << endl;
				cin >> num;
				cout << "Enter Number to Reset Fibonacci Count" << endl;
				cin >> reset;
				cout << ResetFibonacci(num, reset) << endl;
			}
		}
	}
	else if(choice==9)
		break;
	}
	return 0;
}

