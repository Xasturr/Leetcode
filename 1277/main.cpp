#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    int oneCount(vector<vector<int>> &matrix)
    {
        int counter = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.at(i).size(); j++)
            {
                if (matrix[i][j] == 1)
                    counter += 1;
            }
        }
        return counter;
    }

    int searchSubmatrixLength(vector<vector<int>> &matrix, int &i, int &j)
    {
        int counter = 0;
        int size = 2;
        int k = i;
        int l = j;
        while (k + size <= matrix.size() && l + size <= matrix.at(0).size())
        {
            for (k = i; k < i + size; k++)
            {
                for (l = j; l < j + size; l++)
                {
                    if (matrix[k][l] == 0)
                        return counter;
                }
            }
            size += 1;
            counter += 1;
            k = i;
            l = j;
        }
        return counter;
    }

public:
    int
    countSquares(vector<vector<int>> &matrix)
    {
        int sum = 0;
        int sub = 0;
        for (int i = 0; i < matrix.size() - 1; i++)
        {
            for (int j = 0; j < matrix.at(i).size() - 1; j++)
            {
                if (matrix[i][j] == 1)
                {
                    sum += searchSubmatrixLength(matrix, i, j);
                }
            }
        }
        return sum += oneCount(matrix);
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> vec = {
        {1, 0, 1},
        {1, 1, 0},
        {1, 1, 0}
    };
    return 0;
}