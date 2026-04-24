class Solution {
public:
    vector<double> getMedian(vector<int> &arr) {
        
        priority_queue<int> maxHeap; 
        priority_queue<int, vector<int>, greater<int>> minHeap; 
        
        vector<double> result;
        
        for(int i = 0; i < arr.size(); i++) {
            

            if(maxHeap.empty() || arr[i] <= maxHeap.top()) {
                maxHeap.push(arr[i]);
            } else {
                minHeap.push(arr[i]);
            }
            
            // Step 2: Balance heaps
            if(maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } 
            else if(minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            
            // Step 3: Find median
            if(maxHeap.size() == minHeap.size()) {
                double median = (maxHeap.top() + minHeap.top()) / 2.0;
                result.push_back(median);
            } else {
                result.push_back(maxHeap.top());
            }
        }
        
        return result;
    }
};