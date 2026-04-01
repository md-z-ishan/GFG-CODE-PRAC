class Solution {
  public:

    long long int product(vector<int> &arr) {
        
        long long mod=1000000007;
        
        long long result=1;
        
        for(int i=0;i<arr.size();i++){
            result=(result * arr[i])% mod;
        }
        
        return result;
    }
};