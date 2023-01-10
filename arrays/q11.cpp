#include"header.h"
//o(nlogn)
//O(n)&o(n)
//o(n)&O(1)
int findDuplicate(vector<int>& nums){
int n = nums.size();
        for(int i=0;i<n;i++){
            int idx = abs(nums[i])-1;
            nums[idx]*=-1;
            if(nums[idx]>0)return abs(nums[i]);
        }
        return -1;
}
//O(n)
 int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int hare = nums[0],tor = nums[0];
        hare = nums[nums[hare]];
        tor = nums[tor];
        while(hare!=tor){
            hare = nums[nums[hare]];
            tor = nums[tor];
        }
        
        hare = nums[0];
        while(hare!=tor){
            hare = nums[hare];
            tor = nums[tor];
        }
        return tor;
}
//o(logn)
