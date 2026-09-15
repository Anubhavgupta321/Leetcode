class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int eidx=0;
        int oidx=1;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                ans[eidx]=nums[i];
                eidx+=2;
            }
            else{
                ans[oidx]=nums[i];
                oidx+=2;
            }
        }
        return ans;
    }
};