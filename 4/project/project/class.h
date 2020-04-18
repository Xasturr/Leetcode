#pragma once

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size;
        if ((nums1.size() + nums2.size()) % 2 == 1)
            size = floor((double(nums1.size() + nums2.size()) / 2));
        else 
            size = (nums1.size() + nums2.size()) / 2;
        double median = 0;
        int index1 = 0, index2 = 0;
        vector<int> vec;

        for (int i = 0; i < nums2.size() + nums1.size(); i++)
        {
            if (index1 < nums1.size() && index2 < nums2.size())
            {
                if (nums1.at(index1) < nums2.at(index2))
                {
                    vec.push_back(nums1.at(index1++));
                }
                else
                {
                    vec.push_back(nums2.at(index2++));
                }
            }
            else if (index1 >= nums1.size() && index2 < nums2.size())
            {
                vec.push_back(nums2.at(index2++));
            }
            else if (index2 >= nums2.size() && index1 < nums1.size())
            {
                vec.push_back(nums1.at(index1++));
            }
        }
        
        if (vec.size() % 2 == 1)
        {
            if (vec.size() == 1)
                return vec.at(0);
            int mid = vec.size() / 2;
            return vec.at(mid);
        }
        else
        {
            if (vec.size() == 2)
            {
                return double(vec.at(0) + vec.at(1)) / 2;
            }
            else
            {
                for (int i = vec.size() / 2 - 1; i < vec.size() / 2 + 1; i++)
                {
                    median += vec.at(i);
                }
                return double(median / 2);
            }
        }
    }
};