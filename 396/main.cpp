#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxRotateFunction(vector<int> &A)
    {
        if (A.size() == 0)
            return 0;

        int num = 0, exp = 0, n = 0, j = 0, k = 0, max = 0;
        for (; j < A.size(); j++)
        {
            exp += j * A[j];
        }
        max = exp;
        exp = 0;
        n += 1;
        j = A.size() - n;
        for (int i = 1; i < A.size(); i++)
        {
            for (; j < A.size(); j++)
            {
                exp += k++ * A[j];
            }
            for (j = 0; j < A.size() - n; j++)
            {
                exp += k++ * A[j];
            }
            if (max < exp)
                max = exp;
            exp = k = 0;
            n += 1;
            j = A.size() - n;
        }
        return max;
    }
};
// A = [ 4, 3, 2, 6 ]

// F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
// F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
// F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
// F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26

// So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
int main()
{
    vector<int> vec = {4, 3, 2, 6};
    Solution sol;
    cout << sol.maxRotateFunction(vec);
    return 0;
}