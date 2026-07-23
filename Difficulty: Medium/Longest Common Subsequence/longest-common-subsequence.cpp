class Solution {
	public:
	int dp[1001][1002];
	int lcs(string a, string b, int n, int m) {
		for (int i = 1; i <= n ; i++) {
			for (int j = 1; j <= m ; j++) {
				if (a[i - 1] == b[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1]+1;
				} else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[n][m];
		
	}
	int lcs(string &s1, string &s2) {
		// code here
		memset(dp, 0, sizeof(dp));
		return lcs(s1, s2, s1.size(), s2.size());
		
	}
};
