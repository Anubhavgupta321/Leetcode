class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if(n<=0) return {};
        unordered_map<int,int> mpp;
        vector<int> v=arr;
        sort(arr.begin(),arr.end());
        int j=1;
        mpp[arr[0]]=1;
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]){
                mpp[arr[i]]=j;
            }
            else{
                j++;
                mpp[arr[i]]=j;
            }
        }
        for(int i=0;i<n;i++){
            v[i]=mpp[v[i]];
        }
        return v;
    }
};