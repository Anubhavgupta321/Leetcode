class Solution {
    long long solve(vector<int>& piles,int num){
        int n=piles.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=ceil(double(piles[i])/double(num));
        }
        return ans;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            long long ban=solve(piles,mid);
            if(ban<=h){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};