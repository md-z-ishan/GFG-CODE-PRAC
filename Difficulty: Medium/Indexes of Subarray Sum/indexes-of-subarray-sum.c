int subarraySum(int* arr, int n, int target, int* res) {
    int start = 0;
    long long sum = 0;

    for (int end = 0; end < n; end++) {
        sum += arr[end];

        while (sum > target && start <= end) {
            sum -= arr[start];
            start++;
        }

        if (sum == target) {
            res[0] = start + 1;
            res[1] = end + 1;
            return 1;
        }
    }

    return 0;
    
}