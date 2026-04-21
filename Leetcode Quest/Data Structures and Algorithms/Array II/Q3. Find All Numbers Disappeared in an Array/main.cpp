class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        vector<int> result;
        vector<int> numsCopy(nums.size());

        for (int i = 0; i < nums.size(); ++i)
        {
            if (numsCopy[nums[i] - 1] == nums[i])
            {
                continue;
            }

            numsCopy[nums[i] - 1] = nums[i];
        }

        for (int i = 0; i < numsCopy.size(); ++i)
        {
            if (numsCopy[i] == 0)
            {
                result.push_back(i + 1);
            }
        }

        return result;
    }
};