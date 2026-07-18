class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int n:nums){
            mini=min(mini,n);
            maxi=max(maxi,n);
        }
        return gcd(mini,maxi);
    }
};