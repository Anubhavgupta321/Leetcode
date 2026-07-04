class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int balance=0;
        int dificit=0;
        int start=0;
        for(int i=0;i<n;i++){
            balance=balance+gas[i]-cost[i];
            if(balance<0){
                dificit+=balance;
                start=i+1;
                balance=0;
            }
        }
        if(balance+dificit>=0) return start;
        return -1;
    }
};