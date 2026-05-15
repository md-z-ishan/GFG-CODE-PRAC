class Solution {
  public:
    
    int longestSubarrayDivK(vector<int>& arr, int k) {
        
        unordered_map<long long, int> mp;
        
        long long sum = 0;
        int maxi = 0;
        
        for(int i = 0; i < arr.size(); i++) {
            
            sum += arr[i];
            
            int rem = ((sum % k) + k) % k;
            
            if(rem == 0) {
                maxi = i + 1;
            }
            
            if(mp.find(rem) != mp.end()) {
                maxi = max(maxi, i - mp[rem]);
            }
            else {
                mp[rem] = i;
            }
        }
        
        return maxi;
    }
};