class Solution {
    int lb(vector<int>& nums, int target,int n){
        int i=0,j=n-1;
        int ans=n;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]>=target){
                ans=mid;
                j=mid-1;
            }
            else i=mid+1;
        }
        return ans;
    }
    int ub(vector<int>& nums, int target,int n){
        int i=0,j=n-1;
        int ans=n;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]>target){
                ans=mid;
                j=mid-1;
            }
            else i=mid+1;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int firocc=lb(nums,target,n);
        if(firocc==n || nums[firocc]!=target) return {-1,-1};
        return {firocc,ub(nums,target,n)-1};
    }
};