class Solution {
public:
    string removeUtil(string &s) {
        
        string result = "";
        int i = 0;
        
        while(i < s.length()) {
            
            int j = i;
            
            while(j < s.length() && s[i] == s[j]) {
                j++;
            }
            
            if(j - i == 1) {
                result += s[i];
            }
            
            i = j;
        }
        
        if(result.length() == s.length()) {
            return result;
        }
        
        return removeUtil(result);
    }
};