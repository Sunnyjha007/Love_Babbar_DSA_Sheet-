#include"header.h"
void sort012(int arr[], int n)
    {
        // code here
        //sorting o(nlogn)
        //maintain 0,1,2 - > counting and place in arr
        //use dutch national flag algo.
        int low = 0,mid=0,high=n-1;
        while(mid<=high){
            switch(arr[mid]){
                case 0:
                swap(arr[low++],arr[mid++]);break;
                case 1:
                mid++;break;
                case 2:
                swap(arr[mid],arr[high--]);break;
            }
        }
    }
// quick sort using dnf algo -> improtant
int partition(vector<int>& arr,int si,int ei,int& low,int& mid){
	int pivot = arr[ei];
	int high = ei;
	while(mid<=high){
		if(arr[mid]<pivot){
			swap(arr[low++],arr[mid++]);
		}else if(arr[mid]>pivot){
			swap(arr[mid],arr[high--]);
		}else mid++;
	}
}
void quicksort(vector<int>& arr,int si,int ei){
	if(si>=ei)return ;
	int start=0,mid=0;
	int par = partition(arr,si,ei,start,mid);
	quicksort(arr,si,par-1);
	quicksort(arr,par+1,ei);
}
vector<int> quickSortUsingDutchNationalFlag(vector<int> &arr){
	int n = arr.size();
	quicksort(arr,0,n-1);
}