class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string all="123456789";
        vector<int> ans;
        int minlen=(to_string(low).size());
        int maxlen=(to_string(high).size());
        for(int len=minlen;len<=maxlen;len++){
            for(int i=0;i+len<=all.size();i++){
                string s=all.substr(i,len);
                int num=stoi(s);
                if(num>=low && num<=high){
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};