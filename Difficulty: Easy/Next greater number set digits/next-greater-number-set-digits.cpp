class Solution {
  public:
    int findNext(int N) {
        string s = to_string(N);
        int n = s.length();

        int i = n - 2;
        while(i >= 0 && s[i] >= s[i + 1]) {
            i--;
        }

        if(i < 0) return -1;

        int j = n - 1;
        while(s[j] <= s[i]) {
            j--;
        }

        swap(s[i], s[j]);

        reverse(s.begin() + i + 1, s.end());

        long long ans = stoll(s);

        if(ans > INT_MAX) return -1;
        return ans;
    }
};