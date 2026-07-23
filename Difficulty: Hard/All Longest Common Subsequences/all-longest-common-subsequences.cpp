class Solution {
	public:
	int dp[55][55];
	map<pair<int, int>, set<string>> memo;
	int lcs(string a, string b, int n, int m) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (a[i - 1] == b[j - 1])
					dp[i][j] = 1 + dp[i - 1][j - 1];
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return dp[n][m];
	}
	
	set<string> printAll(string &s1, string &s2, int i, int j) {
		if (i == 0 || j == 0)
			return {""};
		if (memo.count({i, j}))
			return memo[{i, j}];
		set<string> ans;
		if (s1[i - 1] == s2[j - 1]) {
			set<string> temp = printAll(s1, s2, i - 1, j - 1);
			for (auto str : temp)
				ans.insert(str + s1[i - 1]);
		}
		else {
			if (dp[i - 1][j] >= dp[i][j - 1]) {
				set<string> temp = printAll(s1, s2, i - 1, j);
				ans.insert(temp.begin(), temp.end());
			}
			    if (dp[i][j - 1] >= dp[i - 1][j]) {
				set<string> temp = printAll(s1, s2, i, j - 1);
				ans.insert(temp.begin(), temp.end());
			}
		}
		return memo[{i, j}] = ans;
	}
	
	vector<string> allLCS(string &s1, string &s2) {
		memset(dp, 0, sizeof(dp));
		memo.clear();
		int n = s1.size();
		int m = s2.size();
		lcs(s1, s2, n, m);
		set<string> st = printAll(s1, s2, n, m);
		vector<string> ans(st.begin(), st.end());
		return ans;
	}
};
