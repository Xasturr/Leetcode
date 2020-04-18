#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template<class T>
void printVec(T& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << " ";
    }
    cout << endl;
}

template<class T>
void printVecOfVec(vector<vector<T>>& vec) {
    cout << "Size: " << vec.size() << endl;
    for (int i = 0; i < vec.size(); i++) {
        printVec(vec.at(i));
        //cout << endl;
    }
}

template<class T>
void pushElement(vector<vector<T>>& vec_sol, vector<T>& nums) {
    if (!vec_sol.size())
        vec_sol.push_back(nums);
    else {
        for (int i = 0; i < vec_sol.size(); i++) {
            if (vec_sol.at(i) == nums)
                return;
        }
        vec_sol.push_back(nums);
    }
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sol;
        if (nums.size() < 3)
            return sol;
        printVec(nums);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i + 1; j < nums.size() - 1; j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums.at(i) + nums.at(j) + nums.at(k) == 0) {
                        vector<int> temp = {nums.at(i), nums.at(j), nums.at(k)};
                            if (!sol.size())
                                sol.push_back(temp);
                            else {
                                if (sol.at(sol.size() - 1) != temp)
                                    sol.push_back(temp);
                            }
                    cout << i << j << k << endl;
                    }
                }
            }
        }
        return sol;
    }
};

int main() {
    Solution sol;
    vector<int> vec = {-1, 0, 1, 2, -1, -4};
    vector<int> empty_vec = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector<vector<int>> vec_sol = sol.threeSum(empty_vec); 
    printVecOfVec(vec_sol);
}