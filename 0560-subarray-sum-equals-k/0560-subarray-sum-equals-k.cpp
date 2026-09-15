class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int> mpp;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k) ans++;
            int rem=sum-k;
            ans+=mpp[rem];
            mpp[sum]++;
        }
        return ans;
    }
};