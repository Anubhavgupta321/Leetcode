class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int maxxor=0;
        bool hasnonzero=false;
        for(int n:nums){
            maxxor^=n;
            if(n!=0) hasnonzero=true;
        }
        if(maxxor>0) return n;
        else{
            if(hasnonzero) return n-1;
            return 0;
        }
    }
};