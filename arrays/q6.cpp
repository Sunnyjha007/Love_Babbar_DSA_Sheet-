#include"header.h"
int doUnion(int a[], int n, int b[], int m)  {
        //code here
        int *arr = new int[n+m];
        int i;
        int count=0;
        for( i=0;i<n;i++){
            arr[i] = a[i];
        }
        int k=0;
        for(int j=i;j<m+n;j++){
            arr[j]=b[k];
            k++;
        }
        sort(arr,arr+n+m);
        for(int i=0;i<m+n;i++){
            if(arr[i]!=arr[i+1]){
                count++;
            }
        }
      return count;  
    }
//o(n)&& O(1)
 int doUnion(int a[], int n, int b[], int m) {
	vector<int> v;
	int i=0,j=0;
	while(i<n&&j<m){
		if(a[i]>b[j]){
			v.push_back(b[j++]);
		}else if(a[i]<b[j]){
			v.push_back(a[i++]);
		}else{
			v.push_back(b[j++]);
			i++;
		}
	}
	while(i<n)v.push_back(a[i++]);
	while(j<m)v.push_back(b[j++]);
	return v.size();
 }
 /*
     public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[a[i]]++;
        }
        for(int i=0;i<m;i++){
            mp[b[i]]++;
        }
        return mp.size();
    }*/