class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int len=1;
        unordered_set<int> st;
        for(int n:nums) st.insert(n);
        for(auto it:st){
            if(!st.count(it-1)){
                int cnt=1;
                while(st.count(it+1)){
                    cnt++;
                    it++;
                }
                len=max(len,cnt);
            }
        }
        return len;
    }
};