class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();

        vector<int> freq(26, 0);

        for(char c : s) {
            freq[c - 'a']++;
        }

        string prefix = "";

        for(int i = 0; i < n; i++) {

            int x = target[i] - 'a';

            // Match target[i]
            if(freq[x] > 0) {
                prefix += target[i];
                freq[x]--;
            }
            else {

                // Try making current position greater
                for(int c = x + 1; c < 26; c++) {

                    if(freq[c] > 0) {

                        string ans = prefix;
                        ans += char(c + 'a');

                        freq[c]--;

                        // Smallest possible suffix
                        for(int d = 0; d < 26; d++) {
                            while(freq[d] > 0) {
                                ans += char(d + 'a');
                                freq[d]--;
                            }
                        }

                        return ans;
                    }
                }

                // Can't match or increase at i.
                // Backtrack only over positions [0, i-1].
                for(int j = i - 1; j >= 0; j--) {

                    int x = target[j] - 'a';

                    // Restore the character used at j
                    freq[x]++;

                    // Try a bigger character
                    for(int c = x + 1; c < 26; c++) {

                        if(freq[c] > 0) {

                            string ans = target.substr(0, j);
                            ans += char(c + 'a');

                            freq[c]--;

                            // Fill remaining characters
                            for(int d = 0; d < 26; d++) {
                                while(freq[d] > 0) {
                                    ans += char(d + 'a');
                                    freq[d]--;
                                }
                            }

                            return ans;
                        }
                    }
                }

                return "";
            }
        }

        // target was matched exactly.
        // Need a strictly greater permutation,
        // so backtrack from the last position.
        for(int i = n - 1; i >= 0; i--) {

            int x = target[i] - 'a';

            // Restore target[i]
            freq[x]++;

            for(int c = x + 1; c < 26; c++) {

                if(freq[c] > 0) {

                    string ans = target.substr(0, i);
                    ans += char(c + 'a');

                    freq[c]--;

                    for(int d = 0; d < 26; d++) {
                        while(freq[d] > 0) {
                            ans += char(d + 'a');
                            freq[d]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};