class Solution {
    typedef pair<int,int> pi;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(int n:nums) mpp[n]++;
        for(auto it:mpp){
            auto [ele,freq]=it;
            pq.push({freq,ele});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};