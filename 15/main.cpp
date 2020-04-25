#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

template <class T>
void printVec(T &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i) << " ";
    }
    cout << endl;
}

template <class T>
void printVecOfVec(vector<vector<T>> &vec)
{
    cout << "Size: " << vec.size() << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        printVec(vec.at(i));
        //cout << endl;
    }
}

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> vec_sol;
        unordered_map<int, int> hash_table;

        if (nums.size() == 0)
            return vec_sol;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++)
        {
            hash_table.insert({nums.at(i), i});
        }

        for (int i = 0; i < (nums.size() - 1); i++)
        {
            int num;

            for (int j = i + 1; j < nums.size(); j++)
            {
                // cout << nums.at(i) << " " << nums.at(j) << endl;
                num = nums.at(i) + nums.at(j);
                auto it = hash_table.find(-num);
                if (it != hash_table.end() && i != j && it->second != i && it->second != j)
                {
                    vector<int> vec = {nums.at(i), nums.at(j), it->first};
                    sort(vec.begin(), vec.end());
                    vec_sol.push_back(vec);
                    // cout << "true" << endl;
                }
                // else
                // cout << "false" << endl;
            }
            cout << endl;
        }
        sort(vec_sol.begin(), vec_sol.end());
        vec_sol.erase(unique(vec_sol.begin(), vec_sol.end()), vec_sol.end());

        return vec_sol;
    }
};

int main()
{
    Solution sol;
    vector<int> vec = {-1, 0, 1, 2, -1, -4};
    vector<int> empty_vec = {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
    vector<vector<int>> vec_sol = sol.threeSum(vec);
    printVecOfVec(vec_sol);
}