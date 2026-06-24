class Solution {
	public:
	long long count = 0;
	void merge(vector<int> &arr, int left, int mid, int right) {
		int i = left;
		int j = mid + 1;
		vector<int>ans;
		while (i<=mid && j<=right) {
			if (arr[i] <= arr[j]) {
				ans.push_back(arr[i++]);
			} else {
				// yahi count karenge
				count += (mid - i + 1);
				ans.push_back(arr[j++]);
			}
		}
		while (i<=mid) {
			ans.push_back(arr[i++]);
		}
		while (j<=right) {
			ans.push_back(arr[j++]);
		}
		for(int k=0;k<ans.size();k++){
		    arr[left+k]=ans[k];
		}
	}
	void divide(vector<int> &arr, int left, int right) {
		int mid = left + (right - left)/2;
		if (left<right) {
			divide(arr, left, mid);
			divide(arr, mid + 1, right);
			merge(arr, left, mid, right);
		}
	}
	int inversionCount(vector<int> &arr) {
		// Code Here
		count=0;
		divide(arr, 0, arr.size() - 1);
		return count;
		
	}
};
//brute force method 
// class Solution{
//     public:
//     int inversionCount(vector<int> &arr){
//         int n=arr.size();
//         int count=0;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(arr[i]>arr[j]){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
    
// };



































