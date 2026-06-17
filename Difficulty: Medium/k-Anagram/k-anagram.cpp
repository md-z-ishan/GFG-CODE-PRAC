class Solution {
  public:
    bool areKAnagrams(string &s1, string &s2, int k) {
        
        if(s1.size() != s2.size()) return false;
        
        vector<int> freq(26, 0);
        
        for(char ch : s1) {
            freq[ch - 'a']++;
        }
        
        for(char ch : s2) {
            freq[ch - 'a']--;
        }
        
        int changes = 0;
        
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) {
                changes += freq[i];
            }
        }
        
        return changes <= k;
    }
};