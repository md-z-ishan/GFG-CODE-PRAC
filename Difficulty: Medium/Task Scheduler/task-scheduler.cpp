class Solution {
public:
    
    int leastInterval(int N, int K, vector<char> &tasks) {
        
        vector<int> freq(26, 0);
        
        for(char ch : tasks) {
            freq[ch - 'A']++;
        }
        
        int maxFreq = 0;
        
        for(int i = 0; i < 26; i++) {
            maxFreq = max(maxFreq, freq[i]);
        }
        
        int maxCount = 0;
        
        for(int i = 0; i < 26; i++) {
            if(freq[i] == maxFreq) {
                maxCount++;
            }
        }
        
        int partCount = maxFreq - 1;
        
        int partLength = K - (maxCount - 1);
        
        int emptySlots = partCount * partLength;
        
        int availableTasks = N - (maxFreq * maxCount);
        
        int idleSlots = max(0, emptySlots - availableTasks);
        
        return N + idleSlots;
    }
};