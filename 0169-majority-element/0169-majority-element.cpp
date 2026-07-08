class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt=1;
        int ele=nums[0];
        for(int i=1;i<n;i++){
            if(cnt==0){
                ele=nums[i];
                cnt++;
            }
            else if(nums[i]==ele){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        cnt=0;
        for(int n:nums){
            if(n==ele) cnt++;
        }
        if(cnt>(n/2)) return ele;
        return -1;
    }
};