class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int totalsum=0;
        for(int n:nums) totalsum+=n;
        int maxlen=0;
        int sum=0;
        int target=totalsum-x;

        if(target==0) return n;
        
        unordered_map<int,int> mpp;
        mpp[0]=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum-target;
            if(mpp.count(rem)){
                maxlen=max(maxlen,i-mpp[rem]);
            }
            if(!mpp.count(sum)){
                mpp[sum]=i;
            }
        }
        return maxlen==0?-1:n-maxlen;
    }
};