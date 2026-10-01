class Solution {
    int mindays(vector<int>& bloomDay,int k,int days){
        int n=bloomDay.size();
        int cnt=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=days) cnt++;
            else{
                ans+=cnt/k;
                cnt=0;
            }
        }
        ans+=cnt/k;
        return ans;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long val=1LL*m*1LL*k;
        if(val>n) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end()),high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mindays(bloomDay,k,mid)>=m){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};