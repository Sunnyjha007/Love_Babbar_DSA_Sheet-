class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int j = n-1;
        while(j>0&&nums[j]<=nums[j-1])j--;
        if(j==0){reverse(nums.begin(),nums.end());return;}
        //[1,5,8,4,7,6,5,3,1]
        int i=n-1;
        while(i>0&&nums[j-1]>=nums[i])i--;
        swap(nums[j-1],nums[i]);
        reverse(nums.begin()+j,nums.end());

    }
};

