class Solution {
public:
    string removeDuplicates(string &s) {
        
        vector<int> vis(256, 0);
        string ans = "";
        
        for(char ch : s) {
            
            if(vis[ch] == 0) {
                
                ans += ch;
                vis[ch] = 1;
            }
        }
        
        return ans;
    }
};