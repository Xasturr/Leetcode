class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums)
    {
        vector<int> result(nums.size());
        int leftSum = 0;
        int sum = 0;

        for (const int num : nums)
        {
            sum += num;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            const int rightSum = sum - nums[i] - leftSum; 
            result[i] = i * nums[i] - leftSum + rightSum - (nums.size() - i - 1) * nums[i];
            leftSum += nums[i];
        }

        return result;   
    }
};