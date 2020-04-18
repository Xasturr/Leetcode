#pragma once

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
    void swapDigits(vector<int>& vec, int i, int j)
    {
        int temp = vec.at(i);
        vec.at(i) = vec.at(j);
        vec.at(j) = temp;
    }
    void helper(vector<int>& vec_inner, vector<vector<int>>& vec_solution, int index)
    {
        for (int i = index; i < vec_inner.size(); i++)
        {
            swapDigits(vec_inner, i, index);
            helper(vec_inner, vec_solution, index + 1);
            if (index == vec_inner.size() - 1)
                vec_solution.push_back(vec_inner);
            swapDigits(vec_inner, i, index);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>vec_solution;
        helper(nums, vec_solution, 0);
        return vec_solution;
    }
};