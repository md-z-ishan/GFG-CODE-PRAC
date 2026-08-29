class Solution {
public:
    int divisibleByDigits(string& s) {
        int count = 0;
        int rem[10] = {};

        for(char c : s) {
            int x = c - '0';

            for(int d = 1; d <= 9; d++)
                rem[d] = (rem[d] * 10 + x) % d;
        }

        for(char c : s) {
            int d = c - '0';

            if(d != 0 && rem[d] == 0)
                count++;
        }

        return count;
    }
};