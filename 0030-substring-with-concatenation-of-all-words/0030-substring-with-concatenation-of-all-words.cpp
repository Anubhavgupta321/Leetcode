class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(s.empty() || words.empty()) return ans;
        int wordlen=words[0].size();
        int totalwords=words.size();
        int totallen=wordlen*totalwords;
        int n=s.length();
        if(n<totallen) return ans;
        unordered_map<string,int> totalfreq;
        for(string w:words){
            totalfreq[w]++;
        }
        for(int offset=0;offset<wordlen;offset++){
            int left=offset;
            int cnt=0;
            unordered_map<string,int> freq;
            for(int right=offset;right+wordlen<=n;right+=wordlen){
                string word=s.substr(right,wordlen);
                if(!totalfreq.count(word)){
                    cnt=0;
                    freq.clear();
                    left=right+wordlen;
                    continue;
                }
                freq[word]++;
                cnt++;
                while(freq[word]>totalfreq[word]){
                    string leftword=s.substr(left,wordlen);
                    freq[leftword]--;
                    cnt--;
                    left+=wordlen;
                }
                if(cnt==totalwords){
                    ans.push_back(left);
                    string leftword=s.substr(left,wordlen);
                    freq[leftword]--;
                    cnt--;
                    left+=wordlen;
                }
            }
        }
        return ans;
    }
};