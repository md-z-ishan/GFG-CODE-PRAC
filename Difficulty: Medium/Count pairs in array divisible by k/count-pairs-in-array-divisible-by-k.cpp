class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        
        vector<int> freq(k, 0);
        long long count = 0;
        
        for(int num : arr) {
            
            int rem = num % k;
            int complement = (k - rem) % k;
            
            count += freq[complement];
            freq[rem]++;
        }
        
        return count;
    }
};