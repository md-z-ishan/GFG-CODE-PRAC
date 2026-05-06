class Solution {
public:

    void solve(int index,
               vector<int> &arr,
               string current,
               vector<string> &ans,
               vector<string> &mapping) {

        if(index == arr.size()) {

            if(current.length() > 0)
                ans.push_back(current);

            return;
        }

        if(arr[index] == 0 || arr[index] == 1) {
            solve(index + 1, arr, current, ans, mapping);
            return;
        }

        string letters = mapping[arr[index]];

        for(int i = 0; i < letters.size(); i++) {

            current.push_back(letters[i]);

            solve(index + 1, arr, current, ans, mapping);

            current.pop_back();
        }
    }

    vector<string> possibleWords(vector<int> &arr) {

        vector<string> mapping = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };

        vector<string> ans;

        string current = "";

        solve(0, arr, current, ans, mapping);

        return ans;
    }
};