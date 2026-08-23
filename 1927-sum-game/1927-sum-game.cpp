class Solution {
public:
    bool sumGame(string num) {
        int n=num.length();
        int q1=0,q2=0;
        int sum1=0,sum2=0;
        for(int i=0;i<n/2;i++){
            if(num[i]=='?') q1++;
            else sum1+=num[i]-'0';
        }
        for(int i=n/2;i<n;i++){
            if(num[i]=='?') q2++;
            else sum2+=num[i]-'0';
        }
        int qdiff = q1 - q2;
        int sumdiff = sum1 - sum2;

        // Same number of ? on both sides.
        // Bob can mirror Alice's moves.
        if(qdiff == 0)
            return sumdiff != 0;

        // Bob can force equality only when the number
        // of unmatched ? is even and the sum difference
        // exactly compensates for them.
        if(qdiff % 2 != 0)
            return true;

        return 2 * sumdiff + 9 * qdiff != 0;
    }
};