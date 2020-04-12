#include <iostream>

using namespace std;

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long N = 0, i;
        cout << "1: S: " << S << " K: " << K << endl;
        for (i = 0; N < K; ++i) {
            N = isdigit(S[i]) ? N * (S[i] - '0') : N + 1;
            cout << "2: N: " << N << endl;
        }
        cout << "i: " << i << " K: " << K << endl;
        while (i--)
            if (isdigit(S[i])) {
                N /= S[i] - '0', K %= N;
                cout << "3: N: " << N << " K: " << K << endl;
            }
            else if (K % N-- == 0)
                return string(1, S[i]);
        return "";
    }
};

int main() {
    Solution sol;
    string s = "ha22";
    cout << s << endl;
    cout << sol.decodeAtIndex(s, 5) << endl;
    return 0;
}