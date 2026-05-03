class Solution {
public:
    string minWindow(string &s, string &p) {
        
        vector<int> freqP(256, 0), freqS(256, 0);
        
        for(char c : p) freqP[c]++;
        
        int start = 0, startIndex = -1;
        int minLen = INT_MAX;
        int count = 0;
        
        for(int end = 0; end < s.length(); end++) {
            
            freqS[s[end]]++;
            
            if(freqP[s[end]] != 0 && freqS[s[end]] <= freqP[s[end]]) {
                count++;
            }
            
            if(count == p.length()) {
                
                while(freqS[s[start]] > freqP[s[start]] || freqP[s[start]] == 0) {
                    
                    if(freqS[s[start]] > freqP[s[start]])
                        freqS[s[start]]--;
                    
                    start++;
                }
                
                int len = end - start + 1;
                
                if(len < minLen) {
                    minLen = len;
                    startIndex = start;
                }
            }
        }
        
        if(startIndex == -1) return "";
        
        return s.substr(startIndex, minLen);
    }
};