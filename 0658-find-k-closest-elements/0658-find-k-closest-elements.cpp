class Solution {
    typedef pair<int,int> pi;
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        priority_queue<pi> pq;
        vector<int> ans;
        for(int n:arr){
            pq.push({abs(n-x),n});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};