class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> ran;
        unordered_map<char,int> mag;
        for(char c:ransomNote){
            ran[c]++;
        }
        for(char c:magazine){
            mag[c]++;
        }
        for(auto &it:ran){
            if(mag.find(it.first)==mag.end()) return false;
            if(mag[it.first]<it.second) return false;
        }
        return true;
    }
};