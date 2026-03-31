// User function template for C++
class Solution {
  public:
    // Function to return sum of elements
    int arraySum(vector<int>& arr) {
        // code here
        int s=0;
        for(int i=0;i<arr.size();i++){
            s=s+arr[i];
        }
        return s;
    }
};