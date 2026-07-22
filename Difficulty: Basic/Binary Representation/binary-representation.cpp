class Solution {
  public:
    string getBinaryRep(int n) {
        // Code here
        string ans="";
        for(int i =31;i>=0;i--){
           ans=ans+char(((n>>i)&1)+'0');
        
        
    }
    return ans;
    }
};