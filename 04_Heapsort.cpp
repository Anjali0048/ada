#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i){
	int largest = i;
	int left = 2*i + 1;    
	int right = 2*i + 2;  
	
	if(left < n && arr[left]>arr[largest]){
		largest = left;
	}
	if(right < n && arr[right]>arr[largest]){
		largest = right;
	}
	if(largest != i){
		swap(arr[i], arr[largest]);
		heapify(arr,n, largest);
	}
}

void heapSort(int arr[], int n){
	
	// building heap
	for(int i=n/2-1; i>=0; i--){
		heapify(arr,n,i);
	}
	// extract ele from heap one by one
	for(int i=n-1; i>=0; i--){
		// swap the root node and the last leaf node
		swap(arr[0],arr[i]);
		// call heapify on reduced heap
		heapify(arr,i,0);
	}
}

void print(int arr[], int n){
	for(int i=0; i<n; i++){
		cout << arr[i] << " " ;
	}
	cout << endl;
}

int main(){
	int arr[] = { 60 ,20 ,40 ,70, 30, 10};
	int n= 6;
	cout << "unsorted array : " ;
	print(arr,n);
	cout << "Sorted array : ";
	heapSort(arr,n);
	print(arr,n);
	
	return 0;
}
