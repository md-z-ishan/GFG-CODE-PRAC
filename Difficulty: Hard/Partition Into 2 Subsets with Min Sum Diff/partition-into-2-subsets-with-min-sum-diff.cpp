class Solution {
	public:
	int minDifference(vector<int>& nums) {
		// code here
		int sum = accumulate(begin(nums), end(nums), 0);
		int n = nums.size();
		int target = sum/2;
		vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
		for (int i = 0; i <= n ; i++) {
			dp[i][0] = true;
		}
		for (int i = 1; i <= n ; i++) {
			for (int j = 1; j <= target; j++) {
				if (nums[i - 1] <= j) {
					dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
				} else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		int ans = INT_MAX;
		for (int i = 0; i <= target; i++) {
			if (dp[n][i]) {
				ans = min(ans, sum - 2*i);
			}
		}
		return ans;
		
	}
};
