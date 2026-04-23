class Solution {
public:
    void relativeSort(vector<int>& a1, vector<int>& a2) {
        
        unordered_map<int, int> freq;
        for(int i = 0; i < a1.size(); i++) {
            freq[a1[i]]++;
        }
        
        int index = 0;
        for(int i = 0; i < a2.size(); i++) {
            int val = a2[i];
            
            while(freq[val] > 0) {
                a1[index++] = val;
                freq[val]--;
            }
        }
        
        vector<int> remaining;
        
        for(auto it : freq) {
            while(it.second > 0) {
                remaining.push_back(it.first);
                it.second--;
            }
        }
        
        sort(remaining.begin(), remaining.end());
        
        for(int i = 0; i < remaining.size(); i++) {
            a1[index++] = remaining[i];
        }
    }
};