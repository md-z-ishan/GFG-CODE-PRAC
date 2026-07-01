class Solution {

  public:
  int dp[1001][1002];
    int lcs(string a, string b, int n, int m) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
    int minOperations(string &s1, string &s2) {
        // Your code goes here
        int n=s1.size();
        int m=s2.size();
    int l=lcs(s1,s2,n,m);
    return (n-l)+(m-l);
        
    }
};