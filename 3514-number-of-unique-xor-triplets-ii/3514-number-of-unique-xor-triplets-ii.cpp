class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        const int max_xor=2048;
        vector<bool> twop(max_xor,false);
        vector<bool> threep(max_xor,false);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                twop[nums[i]^nums[j]]=true;
            }
        }
        for(int i=0;i<max_xor;i++){
            if(!twop[i]) continue;
            for(int x:nums){
                threep[i^x]=true;
            }
        }
        int ans=0;
        for(int i=0;i<max_xor;i++){
            if(threep[i]) ans++;
        }
        return ans;
    }
};