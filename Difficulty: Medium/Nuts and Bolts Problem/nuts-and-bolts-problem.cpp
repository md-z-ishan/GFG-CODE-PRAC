class Solution {
  public:
  
    void matchPairs(vector<char>& nuts, vector<char>& bolts) {
        
        vector<char> order = {'!', '#', '$', '%', '&', '*', '?', '@', '^'};
        
        unordered_set<char> st(nuts.begin(), nuts.end());
        
        int index = 0;
        
        for(char ch : order) {
            
            if(st.find(ch) != st.end()) {
                
                nuts[index] = ch;
                bolts[index] = ch;
                
                index++;
            }
        }
    }
};