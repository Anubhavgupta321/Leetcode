class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]<mini){
                mini=nums[i];
            }
        }
        if(mini%2==0){
            for(int i=0;i<n;i++){
                if(nums[i]%2!=0) return false;
            }
            return true;
        }
        else{
            for(int i=0;i<n;i++){
                if(nums[i]%2==0){
                    if(nums[i]-mini<1) return false;
                }
            }
            return true;
        }
    }
};