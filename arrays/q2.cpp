#include"header.h"
//my approach
// int findSum(int A[], int N)
//     {
//     	//code here.
//     	int maxi = INT_MIN,mini = INT_MAX;
//     	for(int i=0;i<N;i++){
//     	    maxi = max(maxi,A[i]);
//     	    mini = min(mini,A[i]);
//     	}
//     	return (maxi+mini);
//     }
    // n comparisions 
class Difference{
	public:
	int max;
	int min;
};
int findSum(int arr[],int n){
	Difference d;
	int i = 0;
	if(n%2==0){
		if(arr[0]>arr[1]){
			d.max = arr[0];
			d.min = arr[1];
		}else{
			d.max = arr[1];
			d.min = arr[0];
		}
		i+=2;
	}else{
		d.min = d.max = arr[0];
		i+=1;
	}
	while(i<n-1){
		if(arr[i]>arr[i+1]){
			if(arr[i]>d.max)d.max = arr[i];
			if(arr[i+1]<d.min)d.min = arr[i+1];
		}else{
			if(arr[i+1]>d.max)d.max = arr[i+1];
			if(arr[i]<d.min)d.min = arr[i];
		}
		i+=2;
	}
	return d.max+d.min;
}
//-2, 1, -4, 5, 3
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	cout<<"sunny jha"<<endl;
	cout<<findSum(arr,n);
	return 0;
}