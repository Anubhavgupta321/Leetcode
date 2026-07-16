class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> pref(n);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            pref[i]=gcd(maxi,nums[i]);
        }
        sort(pref.begin(),pref.end());
        int i=0,j=n-1;
        long long sum=0;
        while(i<j){
            sum+=gcd(pref[i],pref[j]);
            i++;
            j--;
        }
        return sum;
    }
};