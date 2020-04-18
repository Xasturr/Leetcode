#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> vec_solution = { -1, -1 };
        if (!nums.size())
            return vec_solution;
        int index = nums.size() / 2;
        int num = index / 2;
        if (!num)
            num = 1;
        bool a = false;
        bool b = false;
        while (true)
        {
            if (nums.at(index) < target)
            {
                if (num == 1)
                {
                    if (b)
                        return vec_solution;
                    a = true;
                }

                index += num;

                if (num > 1)
                    num /= 2;

                if (index >= nums.size())
                    return vec_solution;
            }
            else if (nums.at(index) > target)
            {
                if (num == 1)
                {
                    if (a)
                        return vec_solution;
                    b = true;
                }

                index -= num;

                if (num > 1)
                    num /= 2;

                if (index < 0)
                    return vec_solution;
            }
            else
            {
                vec_solution.clear();

                int start = index;
                int end = index;

                for (int j = index - 1; j >= 0; j--)
                {
                    if (nums.at(j) == target)
                        start = j;
                }
                for (int j = index + 1; j < nums.size(); j++)
                {
                    if (nums.at(j) == target)
                        end = j;
                }

                vec_solution.push_back(start);
                vec_solution.push_back(end);

                return vec_solution;
            }
        } 
     }
};