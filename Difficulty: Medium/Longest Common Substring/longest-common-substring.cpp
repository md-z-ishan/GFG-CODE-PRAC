class Solution {
	public:
	int dp[1001][1002];
	int lcs(string a, string b, int n, int m) {
		int ans = 0;
		for (int i = 1; i <= n ; i++) {
			for (int j = 1; j <= m; j++) {
				// i!=j only the change is needed
				if (a[i - 1] == b[j - 1] ) {
					dp[i][j] = 1 + dp[i - 1][j - 1];
					ans = max(ans, dp[i][j]);
				} else {
					dp[i][j] = 0;
				}
			}
		}
		return ans;
	}
	int longCommSubstr(string& s1, string& s2) {
		// code here
		memset(dp, 0, sizeof(dp));
		return lcs(s1, s2, s1.size(), s2.size());
		
	}
};
