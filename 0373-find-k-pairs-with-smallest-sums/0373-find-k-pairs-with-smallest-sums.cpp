class Solution {
    typedef pair<int,pair<int,int>> pi;
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        int n=nums1.size();
        int m=nums2.size();
        for(int i=0;i<n && i<k;i++){
            int sum=nums1[i]+nums2[0];
            pq.push({sum,{i,0}});
        }
        vector<vector<int>> ans;
        while(k-- && !pq.empty()){
            auto data=pq.top();
            pq.pop();
            int i=data.second.first;
            int j=data.second.second;
            ans.push_back({nums1[i],nums2[j]});
            if(j+1<m){
                int sum=nums1[i]+nums2[j+1];
                pq.push({sum,{i,j+1}});
            }
        }
        return ans;
    }
};