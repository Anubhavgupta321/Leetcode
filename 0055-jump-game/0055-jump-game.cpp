class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool> v(n,false);
        v[0]=true;
        for(int i=0;i<n;i++){
            if(v[i]==true){
                int j=i;
                int last=nums[i]+i;
                while(j<=last && j<n){
                    v[j]=true;
                    j++;
                }
            }
            else break;
        }
        return v[n-1];
    }
};