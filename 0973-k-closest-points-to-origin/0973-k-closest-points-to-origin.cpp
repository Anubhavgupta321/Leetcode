class Solution {
    typedef pair<int,vector<int>> pi;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        priority_queue<pi> pq;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            int dis=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            pq.push({dis,{points[i][0],points[i][1]}});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};