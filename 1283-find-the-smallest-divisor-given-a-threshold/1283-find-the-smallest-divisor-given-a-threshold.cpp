class Solution {
    int solve(vector<int>& nums,int divi){
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=ceil(double(nums[i])/double(divi));
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(nums,mid)<=threshold) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};