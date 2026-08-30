class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return n;
        int minidx=0,maxidx=0;
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]<mini){
                minidx=i;
                mini=nums[i];
            }
            if(nums[i]>maxi){
                maxidx=i;
                maxi=nums[i];
            }
        }
        if(minidx>maxidx) swap(minidx,maxidx);
        int x1=minidx+1+(n-maxidx);
        int x2=minidx+1+(maxidx-minidx);
        int x3=(n-maxidx)+(maxidx-minidx);
        x1=min(x1,x2);
        x1=min(x1,x3);
        return x1;
    }
};