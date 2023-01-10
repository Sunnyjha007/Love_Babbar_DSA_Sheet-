#include"header.h"
//O(nlogk+klogk)
int kthSmallest(int arr[], int l, int r, int k) {
	//code here
        priority_queue<int,vector<int>, greater<int>> pq;
        for(int i=0;i<=r;i++){
            pq.push(arr[i]);
        }
        k=k-1;
        while(k--){
            pq.pop();
        }
        return pq.top();
}
//use sorting o(nlogn)
//using max heap priority queue
//o(nlogk)
int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue<int> pq;
        for(int i=l;i<k;i++){
            pq.push(arr[i]);
        }
	for(int i=k;i<=r;i++){
		if(arr[i]<pq.top()){
			pq.pop();
			pq.push(arr[i]);
		}
	}
        return pq.top();
}