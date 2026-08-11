class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int pref=0;
        pref=nums[0];
        int i=1;
        int num=pref;
        while(i<n){
            if(nums[i]!=nums[i-1]+1) break;
            pref+=nums[i];
            num=pref;
            i++;
        }
        unordered_set<int> st;
        int j=0;
        while(j<n){
            st.insert(nums[j]);
            j++;
        }
        int maxi=*max_element(nums.begin(),nums.end());
        maxi=max(maxi,num);
        for(int i=num;i<=maxi;i++){
            if(!st.count(i)) return i;
        }
        return maxi+1;
    }
};