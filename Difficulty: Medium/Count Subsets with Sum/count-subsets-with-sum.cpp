class Solution {
	public:
	int perfectSum(vector<int>& nums, int target) {
		// code here
		int n = nums.size();
		vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
		for (int i = 0; i <= n ; i++) {
			dp[i][0] = 1;
		}
		for (int i = 1; i <= n ; i++) {
			for (int j = 0; j <= target; j++) {
				if (nums[i - 1] <= j) {
					dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
				} else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		return dp[n][target];
		
	}
};
