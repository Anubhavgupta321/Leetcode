class Solution {
    int solve(vector<int>& weights,int limit){
        int n=weights.size();
        int ans=1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=weights[i];
            if(sum>limit){
                ans++;
                sum=weights[i];
            }
        }
        return ans;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
        for(int i=0;i<weights.size();i++){
            high+=weights[i];
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(weights,mid)<=days) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};