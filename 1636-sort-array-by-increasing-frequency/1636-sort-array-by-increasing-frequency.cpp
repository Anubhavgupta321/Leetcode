class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        for(int n:nums){
            mpp[n]++;
        }
        sort(nums.begin(),nums.end(),[&](int a,int b){
            if(mpp[a]==mpp[b]) return a>b;
            return mpp[a]<mpp[b];
        });
        return nums;
    }
};