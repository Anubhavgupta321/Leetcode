class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        int start=*min_element(nums.begin(),nums.end());
        int end=*max_element(nums.begin(),nums.end());
        vector<int> temp;
        for(int i=start;i<=end;i++){
            temp.push_back(i);
        }
        unordered_set<int> st;
        vector<int> ans;
        for(int x:nums) st.insert(x);
        for(int i=0;i<temp.size();i++){
            if(!st.count(temp[i])) ans.push_back(temp[i]);
        }
        return ans;
    }
};