#include"header.h"
//lc-55  jump game 1
//greedy
bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reachable=0;
        for(int i=0;i<n;i++){
            if(reachable<i)return false;
            reachable = max(reachable,i+nums[i]);
        }
        return true;
}
//dp - solution -> Tle
bool solve(vector<int>& nums,int i,vector<int>& dp){
        if(i>=nums.size()-1)return true;
        if(dp[i]!=-1)return dp[i];
        if(nums[i]==0)return dp[i] =  false;
        for(int j=1;j<=nums[i];j++){
            if(solve(nums,i+j,dp))return dp[i] = true;
        }
        return dp[i] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return solve(nums,0,dp);
}
//lc - 45 jump game 2
//top-down
   int solve1(vector<int>& nums,int i,vector<int>& dp){
        if(i>=nums.size()-1)return 0;
        if(dp[i]!=-1)return dp[i];
        if(nums[i]==0)return dp[i] = 1e9;
        int mini = 1E9;
        for(int j=1;j<=nums[i];j++){
            mini = min(mini,1+solve(nums,i+j,dp));
        }
        return dp[i] = mini ;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return 0;
        vector<int> dp(n+1,-1);
        cout<<1e9<<" "<< INT_MAX;
        return solve1(nums,0,dp);
}
//bottom up
 int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,INT_MAX-1);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<=nums[i]&&i+j<n;j++){
                dp[i+j] = min(dp[i+j],dp[i]+1);
            }
        }
        return dp[n-1];
}
//greedy
int jump(vector<int>& nums) {
        int n = nums.size();
       int jumps=0,current=0,reachable=0;
        for(int i=0;i<n-1;i++){
            reachable = max(reachable,i+nums[i]);
            if(current==i){
                //we cover every nums[i] -> for i;
                jumps++;
                current = reachable;
            }
        }
        return jumps;
    }
//jump start 3
//bfs approach
bool canReach(vector<int>& arr, int start) {
        queue<int> pn;
        vector<int> visited(arr.size(),false);
        pn.push(start);
        while(!pn.empty()){
            int front = pn.front();
            pn.pop();
            if(arr[front]==0)return true;
            if(!visited[front]){
                if(front+arr[front]<arr.size())pn.push(front+arr[front]);
                if(front-arr[front]>-1)pn.push(front-arr[front]);
                visited[front] = true;
            }
        }
        return false;
}
//dfs
 bool solve(vector<int>& arr, int start,vector<bool>& visited){
        if(start<0||start>=arr.size()||visited[start])return false;
        visited[start] = true;
        if(arr[start]==0)return true;
       return solve(arr,start+arr[start],visited)||solve(arr,start-arr[start],visited);
    }
    bool canReach(vector<int>& arr, int start) {
       int n = arr.size();
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(solve(arr,start,visited))return true;
            }
        }
        return false;
    }
  //jump game 4
  int minJumps(vector<int>& arr) {
       int n = arr.size();
        unordered_map<int,vector<int>> map;
        for(int i=0;i<n;i++){
           map[arr[i]].push_back(i);
        }
        vector<bool> visited(n,false);
        queue<int> pn;
        pn.push(0);
        visited[0] = true;
        int ans=0;
        while(!pn.empty()){
            int size = pn.size();
            while(size--){
                int front = pn.front();pn.pop();
                if(front==n-1)return ans;
                if(front-1>=0&&!visited[front-1]){
                    visited[front-1] = true;
                    pn.push(front-1);
                }
                 if(front+1<=n-1&&!visited[front+1]){
                    visited[front+1] = true;
                    pn.push(front+1);
                }
                if(map.count(arr[front])){
                    for(auto i:map[arr[front]]){
                        if(i!=front&&!visited[i]){
                            visited[i] = true;
                            pn.push(i);
                        }
                    }
                }map.erase(arr[front]);
            }
            ans++;
        }
        return -1;
    }
 //gfg submitted
 int minJumps(int arr[], int n){
        int curr=0,reach=0,jumps=0;
        for(int i=0;i<n-1;i++){
            reach = max(reach,i+arr[i]);
            if(curr==i){
                curr = reach;
                jumps++;
            }
        }
        if(curr>=n-1)return jumps;
        return -1;
}