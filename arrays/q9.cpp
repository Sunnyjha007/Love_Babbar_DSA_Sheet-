#include"header.h"
//leetcode - 910
int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
        int result = arr[n-1] - arr[0];
        int max_ele,min_ele;
        for(int i=0;i<n;i++){
            max_ele = max(arr[i]+k , arr[n-1]-k);
            min_ele = min(arr[0]+k,arr[i+1]-k);
            result = min(result,max_ele-min_ele);
        }
        return result;       
}