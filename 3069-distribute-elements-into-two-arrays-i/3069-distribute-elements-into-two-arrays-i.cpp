class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr1,arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        if(n<2) return nums;
        int i=2;
        while(i<n){
            int ele1=arr1.back();
            int ele2=arr2.back();
            if(ele1>ele2){
                arr1.push_back(nums[i]);
            }
            else arr2.push_back(nums[i]);
            i++;
        }
        arr1.insert(arr1.end(),arr2.begin(),arr2.end());
        return arr1;
    }
};