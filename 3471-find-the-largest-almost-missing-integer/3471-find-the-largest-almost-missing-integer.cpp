class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=-1;
        if(k==1){
            unordered_map<int,int> mpp;
            for(int i=0;i<n;i++) mpp[nums[i]]++;
            for(auto x:mpp){
                if(x.second<=1) maxi=max(maxi,x.first);
            }
            return maxi;
        }
        if(k==n){
            return *max_element(nums.begin(),nums.end());
        }
        unordered_map<int,int> mpp;
        for(int i=0;i+k<=n;i++){
            int j=i;
            while(j<i+k){
                mpp[nums[j]]++;
                j++;
            }
        }
        for(auto x:mpp){
            if(x.second<=1){
                maxi=max(maxi,x.first);
            }
        }
        return maxi;
    }
};