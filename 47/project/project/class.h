#pragma once

#include <vector>
#include <iostream>

using namespace std;

class Solution {
    bool searchSame(vector<int> &inner_vec, vector<vector<int>> &vec_solution)
    {
        //if (vec_solution.size() >= inner_vec.size())
        //{
            for (int i = vec_solution.size() - 1; i >= vec_solution.size() - inner_vec.size() && i >= 0; i--)
            {
                bool same = true;
                for (int j = 0; j < vec_solution.at(i).size(); j++)
                {
                    if (vec_solution.at(i).at(j) != inner_vec.at(j))
                    {
                        same = false;
                        break;
                    }
                }
                if (same)
                    return true;
            }
        //}

        for (int i = 0; i < vec_solution.size(); i++)
        {
            bool same = true;
            for (int j = 0; j < vec_solution.at(i).size(); j++)
            {
                if (vec_solution.at(i).at(j) != inner_vec.at(j))
                {
                    same = false;
                    break;
                }
            }
            if (same)
                return true;
        }
        return false;
    }

    void swap(vector<int>& vec, int i, int j)
    {
        int temp = vec.at(i);
        vec.at(i) = vec.at(j);
        vec.at(j) = temp;
    }

    void helper(vector<int>&inner_vec, vector<vector<int>>&vec_solution, int index)
    {
        for (int i = index; i < inner_vec.size(); i++)
        {
            swap(inner_vec, i, index);
            helper(inner_vec, vec_solution, index + 1);
            if (index == inner_vec.size() - 1)
            {
                if (!searchSame(inner_vec, vec_solution))
                    vec_solution.push_back(inner_vec);
            }
            swap(inner_vec, i, index);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>vec;
        helper(nums, vec, 0);
        return vec;
;    }
};