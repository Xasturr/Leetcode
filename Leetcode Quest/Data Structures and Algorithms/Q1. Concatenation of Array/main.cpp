class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) 
    {
        const int numsSize = nums.size();

        for (int i = 0; i < numsSize; i++)
        {
            nums.push_back(nums[i]);
        }

        return nums;
    }
};