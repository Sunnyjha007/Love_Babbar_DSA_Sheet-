#include"header.h"
 vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==0)return{};
        if(n==1)return intervals;
        int j=0;
        sort(intervals.begin(),intervals.end());
        for(int i=1;i<n;i++){
            if(intervals[j][1]>=intervals[i][0]){
                intervals[j][1] = max(intervals[j][1],intervals[i][1]);
            }else{
                j++;
                intervals[j] = intervals[i];
            }
        }
       intervals.resize(j+1);
        return intervals;
}
//part-2
//insert interval
//same approach as above
 vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end()); // O(nlogn)
	int j=0,i=1,n=intervals.size();
	for(i=1;i<n;i++){
		if(intervals[j][1]>=intervals[i][0]){
			intervals[j][1] = max(intervals[j][1],intervals[i][1]);
		}else{
			j++;
			intervals[j] = intervals[i];
		}
	}
	intervals.resize(j+1);
	return intervals;
}
//new approach
 vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	int n = intervals.size();
	vector<vector<int>> v;
	for(int i=0;i<n;i++){
		if(intervals[i][1]<newInterval[0]){
			v.push_back(intervals[i]);
		}else if(intervals[i][0]>newInterval[1]){
			v.push_back(newInterval);
			newInterval = intervals[i];
		}else if(intervals[i][0]<=newInterval[1]||intervals[i][1]>=newInterval[0]){
			int mini = min(newInterval[0],intervals[i][0]);
			int maxi = max(newInterval[1],intervals[i][1]);
			v.push_back({mini,maxi});
		}
	} 
	return v;     
}