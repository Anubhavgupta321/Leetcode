class Solution {
    typedef pair<int,pair<int,int>> pi;
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            pq.push({nums[i][0],{i,0}});
            maxi=max(maxi,nums[i][0]);
        }
        int left=pq.top().first;
        int right=maxi;
        while(true){
            int ele=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(col==nums[row].size()-1) break;
            maxi=max(maxi,nums[row][col+1]);
            pq.push({nums[row][col+1],{row,col+1}});
            if(right-left>maxi-pq.top().first){
                left=pq.top().first;
                right=maxi;
            }
        }
        return {left,right};
    }
};