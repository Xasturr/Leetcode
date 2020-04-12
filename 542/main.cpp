#include <vector>
#include <iostream>

using namespace std;

void print(vector<vector<int>> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.at(i).size(); j++)
        {
            cout << vec.at(i).at(j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

class Solution
{

    int search(vector<vector<int>> &matrix, int &i, int &j, int &iSize, int &jSize)
    {
        int iIncrease = 0, jIncrease = 0;
        int iDecrease = 0, jDecrease = 0;
        int ans = iSize + jSize;
        bool flag = false;

        while (true)
        {
            if (i + (++iIncrease) >= iSize)
                --iIncrease;
            if (i + (--iDecrease) < 0)
                ++iDecrease;
            if (j + (++jIncrease) >= jSize)
                --jIncrease;
            if (j + (--jDecrease) < 0)
                ++jDecrease;

            for (int k = i + iDecrease; k <= i + iIncrease; k++)
            {
                for (int h = j + jDecrease; h <= j + jIncrease; h++)
                {
                    if (matrix[k][h] == 0 &&
                        ans > abs(k - i) + abs(h - j))
                    {
                        flag = false;
                        if (k == i + iDecrease && h == j + jDecrease ||
                            k == i + iDecrease && h == j + jIncrease ||
                            k == i + iIncrease && h == j + jDecrease ||
                            k == i + iIncrease && h == j + jIncrease) {
                                flag = true;
                            }
                        ans = abs(k - i) + abs(h - j);
                    }
                }
            }
            if (ans < iSize + jSize)
            {
                if (flag) {
                    if (i + (++iIncrease) >= iSize)
                        --iIncrease;
                    if (i + (--iDecrease) < 0)
                        ++iDecrease;
                    if (j + (++jIncrease) >= jSize)
                        --jIncrease;
                    if (j + (--jDecrease) < 0)
                        ++jDecrease;

                    for (int k = i + iDecrease; k <= i + iIncrease; k++)
                    {
                        for (int h = j + jDecrease; h <= j + jIncrease; h++)
                        {
                            if (matrix[k][h] == 0 &&
                                ans > abs(k - i) + abs(h - j))
                            {
                                return abs(k - i) + abs(h - j);
                            }
                        }
                    }
                }
                return ans;
            }
        }
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
        int I = 0, J = 0;
        int iSize = matrix.size();
        int jSize = matrix.at(0).size();

        vector<vector<int>> vec_sol = matrix;

        while (true)
        {
            if (matrix[I][J] == 0)
                vec_sol[I][J] = 0;
            else
                vec_sol[I][J] = search(matrix, I, J, iSize, jSize);

            if (++J == jSize)
            {
                if (++I == iSize)
                    return vec_sol;
                J = 0;
            }
        }

        return vec_sol;
    }
};

int main()
{
    vector<vector<int>> vec = {
        {1, 1, 0, 0, 1, 0, 0, 1, 1, 0},
        {1, 0, 0, 1, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 1, 1, 1, 1, 0},
        {0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
        {0, 1, 1, 1, 1, 1, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
        {0, 1, 0, 1, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 0, 1, 1, 1, 1}};

    print(vec);
    Solution sol;

    auto newVec = sol.updateMatrix(vec);

    print(newVec);

    return 0;
}