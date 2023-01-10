#include"header.h"
//order is not important
//sort o(nlogn)
//2 pointer O(n)
// use dnf algo also O(n)

void rearrange(vector<int>& arr){
	int n = arr.size();
	int i=0,j=0;
	while(i<n){
		if(arr[i]<0){
			swap(arr[i],arr[j]);j++;
		}
		i++;
	}
}
//dnf
void rearrangednf(vector<int>& arr){
	int n = arr.size();
	int low = 0,mid =0 ,high = n-1;
	while(mid<=high){
		if(arr[mid]==0){
			mid++;
		}else if(arr[mid]<0){
			swap(arr[low++],arr[mid++]);
		}else if(arr[mid]>0){
			swap(arr[mid],arr[high--]);
		}
	}
}
//order is important
//make +ve and -ve array and place them in original array
//USING rotation of array concept
//approach 1
void rotate(vector<int>& arr,int l,int r){
	int temp = arr[r];
	for(int i=r;i>l-1;i--){
		arr[i] = arr[i-1];
	}
	arr[l] = temp; 
}
void rearrangearr(vector<int>& arr){
	int n = arr.size();
	int idx = -1;
	for(int i=0;i<n;i++){
		if(arr[i]<0){
			idx+=1;
			swap(arr[i],arr[idx]);
			if(i-idx>=2){
				rotate(arr,idx+1,i);
			}
		}
	}
}
//approach 2
void insertionsort(vector<int>& arr){
	int n = arr.size();
	for(int i=1;i<n;i++){
		int key = arr[i];
		int j = i-1;
		if(key>0)continue;
		while(j>=0&&arr[j]>0){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}
//approach 3
void merge(vector<int>& arr,int si,int mid,int ei){
	int n1 = mid-si+1;
	int n2 = ei-mid;
	int left[n1],right[n2];
	for(int i=0;i<n1;i++)left[i] = arr[si+i];
	for(int i=0;i<n2;i++)right[i] = arr[mid+i+1];
	int i=0,j=0,k=si;
	while(i<n1&&left[i]<0)arr[k++] = left[i++];
	while(j<n2&&right[j]<0)arr[k++] = right[j++];
	while(i<n1)arr[k++] = left[i++];
	while(j<n2)arr[k++] = right[j++];
}
void solve(vector<int>& arr,int si,int ei){
	if(si>=ei)return;
	int mid = si + (ei-si)/2;
	solve(arr,si,mid);
	solve(arr,mid+1,ei);
	merge(arr,si,mid,ei);
}
void mergesort(vector<int>& arr){
	int si=0,ei = arr.size()-1;
	return solve(arr,si,ei);
}
//approach 4-> sliding window but worst case o(n^2) in [3,4,5,6,7,8,-3]
void rearrangePosNegWithOrder(vector<int>& arr)
{
   int i = 0, j = 0;
   int size = arr.size();
   while (j < size) {
       if (arr[j] >= 0) {
           j++;
       }
       else {
           for (int k = j; k > i; k--) {
               swap(arr[k],arr[k-1]);
           }
           i++;
           j++;
       }
   }
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);// -1, 2, -3, 4, 5, 6, -7, 8, 9
	for(int i=0;i<n;i++)cin>>arr[i];
	mergesort(arr);
	for(int i=0;i<n;i++)cout<<arr[i]<<" ";
	return 0;
}
// 5, 5, -3, 4, -8, 0, -7, 3, -9, -3, 9, -2, 1 };
//13
// 5 5 -3 4 -8 0 -7 3 -9 -3 9 -2 1