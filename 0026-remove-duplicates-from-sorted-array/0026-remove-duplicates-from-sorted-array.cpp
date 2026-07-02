class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int k=1;
        int i=0,j=1;
        while(j<n){
            if(nums[j]!=nums[i]){
                nums[k]=nums[j];
                i=j;
                k++;
            }
            j++;
        }
        return k;
    }
};