class Solution {
public:
    long long ValidPair(int a[], int n) {
        
        sort(a, a + n);
        
        int i = 0, j = n - 1;
        long long count = 0;
        
        while (i < j) {
            
            if (a[i] + a[j] > 0) {
                count += (j - i); 
                j--;
            } 
            else {
                i++;
            }
        }
        
        return count;
    }
};