class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        int start=*min_element(nums.begin(),nums.end());
        int end=*max_element(nums.begin(),nums.end());
        vector<int> ans;
        unordered_set<int> st;
        for(int x:nums) st.insert(x);
        for(int i=start;i<=end;i++){
            if(!st.count(i)) ans.push_back(i);
        }
        return ans;
    }
};