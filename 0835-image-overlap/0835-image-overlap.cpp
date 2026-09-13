class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<pair<int,int>> a,b;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]){
                    a.push_back({i,j});
                }
                if(img2[i][j]){
                    b.push_back({i,j});
                }
            }
        }
        int ans=0;
        unordered_map<string,int> mpp;
        for(auto [r1,c1]:a){
            for(auto [r2,c2]:b){
                int dr=r1-r2;
                int dc=c1-c2;
                string key=to_string(dr)+","+to_string(dc);
                mpp[key]++;
                ans=max(ans,mpp[key]);
            }
        }
        return ans;
    }
};