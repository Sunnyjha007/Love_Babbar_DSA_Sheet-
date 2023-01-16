#include"header.h"
//brute force o(n^2) -> 2 loops and check the condition
//optimal o(nlogn)
 long long  mergetwo(long long *arr,long start,long end,long mid){
	long long   count=0;
	long n1 = mid-start+1;
	long n2 = end - mid;
	long left[n1];
	long right[n2];
	for(long i=0;i<n1;i++){
		left[i] = arr[start+i];
	}
	for(long j=0;j<n2;j++){
		right[j] = arr[mid+1+j];
	}
	int i=0,j=0,k=start;
	while(i<n1&&j<n2){
		if(left[i]<=right[j]){
			arr[k++] = left[i++];
		}else{
			arr[k++] = right[j++];
			count+= n1-i;
		}
	}
	while(i<n1){
		arr[k++] = left[i++];
	}
	while(j<n2){
		arr[k++] = right[j++];
	}
       return count;

}
long long  merge_sort(long long  *arr,long  start,long end){
	long long  count=0;
         if(start<end){
	int mid = (start+end)/2;
	count+= merge_sort(arr,start,mid);
	count+= merge_sort(arr,mid+1,end);
	count+= mergetwo(arr,start,end,mid);
	 }
	return count;

}

long long int inversionCount(long long arr[], long long n)
{
    // Your Code Here
    long long ans = merge_sort(arr,0,n-1);
     
}


