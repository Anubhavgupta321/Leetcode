class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st;
        for(int n:nums) st.insert(n);
        int longest=0;
        for(auto it:st){
            if(!st.count(it-1)){
                int cnt=1;
                while(st.count(it+1)){
                    cnt++;
                    it++;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }
};