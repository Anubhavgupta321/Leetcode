class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(),reservedSeats.end());
        int i=1,j=0;
        int ans=0;
        while(i<=n){
            // No more reserved seats.
            // Every remaining row can fit 2 families.
            if(j == reservedSeats.size()) {
                ans += 2 * (n - i + 1);
                break;
            }

            if(reservedSeats[j][0]!=i){
                ans+=2;
                i++;
                continue;
            }
            unordered_set<int> st;
            while(j<reservedSeats.size() && reservedSeats[j][0]==i){
                st.insert(reservedSeats[j][1]);
                j++;
            }
            bool left=true;
            for(int k=2;k<=5;k++){
                if(st.count(k)){
                    left=false;
                    break;
                }
            }
            bool right=true;
            for(int k=6;k<=9;k++){
                if(st.count(k)){
                    right=false;
                    break;
                }
            }
            if(left && right) ans+=2;
            else if(left || right) ans+=1;
            else{
                bool middle=true;
                for(int i=4;i<=7;i++){
                    if(st.count(i)){
                        middle=false;
                        break;
                    }
                }
                if(middle) ans+=1;
            }
            i++;
        }
        return ans;
    }
};