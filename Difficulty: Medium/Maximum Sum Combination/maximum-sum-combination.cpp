class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        
        int n = a.size();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        priority_queue<pair<int, pair<int,int>>> pq;
        set<pair<int,int>> st;
        
        pq.push({a[n-1] + b[n-1], {n-1, n-1}});
        st.insert({n-1, n-1});
        
        vector<int> ans;
        
        while(k--) {
            auto top = pq.top();
            pq.pop();
            
            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;
            
            ans.push_back(sum);
            
            if(i-1 >= 0 && st.find({i-1, j}) == st.end()) {
                pq.push({a[i-1] + b[j], {i-1, j}});
                st.insert({i-1, j});
            }
            
            if(j-1 >= 0 && st.find({i, j-1}) == st.end()) {
                pq.push({a[i] + b[j-1], {i, j-1}});
                st.insert({i, j-1});
            }
        }
        
        return ans;
    }
};