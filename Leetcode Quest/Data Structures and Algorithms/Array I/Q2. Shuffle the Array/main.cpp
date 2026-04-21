class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector <int> result(2 * n);
        int* xPtr = &nums[0];
        int* yPtr = &nums[n];

        for (int i = 0; i < nums.size(); i++)
        {
            result[i] = i % 2 ? *yPtr++ : *xPtr++;
        }

        return result;
    }
};