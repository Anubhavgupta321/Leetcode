class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        bool one=false;
        if(nums[n-1]<nums[0]){
            for(int i=1;i<n;i++){
                if(nums[i]<nums[i-1]){
                    if(one) return false;
                    one=true;
                }
            }
            return true;
        }
        else{
            for(int i=1;i<n;i++){
                if(nums[i]<nums[i-1]) return false;
            }
            return true;
        }
    }
};