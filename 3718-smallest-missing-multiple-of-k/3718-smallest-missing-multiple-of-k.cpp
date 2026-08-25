class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(int n:nums){
            st.insert(n);
        }
        int i=k;
        while(i<=*max_element(nums.begin(),nums.end())){
            if(!st.count(i)) return i;
            i+=k;
        }
        return i;
    }
};