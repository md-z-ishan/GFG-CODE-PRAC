class Solution {
	public:
	
	bool zishan(int index, int sum, vector<int> &arr,
	vector<vector<int>> &dp)
	{
		if (sum == 0)
			return true;
		if (index == arr.size())
			return false;
		if (dp[index][sum] != -1)
			return dp[index][sum];
		bool notTake = zishan(index + 1, sum, arr, dp);
		bool take = false;
		if (arr[index] <= sum)
			{
			take = zishan(index + 1,
			sum - arr[index],
			arr,
			dp);
		}
		return dp[index][sum] = (take || notTake);
	}
		bool isSubsetSum(vector<int>& arr, int sum)
	{
		int n = arr.size();
		vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
		return zishan(0, sum, arr, dp);
	}
};
