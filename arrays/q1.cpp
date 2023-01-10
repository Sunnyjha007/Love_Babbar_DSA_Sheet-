//reverse an array
#include"Header.h"
void reverse(vector<int> arr){
	int n = arr.size(),i=0,j=n-1;
	while(i<j){
		swap(arr[i],arr[j]);
		i++;j--;
	}
}
//direct reverse function call 