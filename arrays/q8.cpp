#include"header.h"
long long maxSubarraySum(int arr[], int n){
        // Your code here
        for(int i=1;i<n;i++){
            arr[i] = max(arr[i],arr[i]+arr[i-1]);
            arr[0]=max(arr[0],arr[i]);
        }
        return arr[0];       
}
long long maxSubarraySum(int arr[], int n){
int maxsum = INT_MIN;
    int cursum = 0;
    for(int i=0;i<n;i++){
        cursum = cursum + arr[i];
        if(cursum>maxsum){
            maxsum=cursum;
        }
        if(cursum<0){
            cursum=0;
        }
    }
    return maxsum;
}