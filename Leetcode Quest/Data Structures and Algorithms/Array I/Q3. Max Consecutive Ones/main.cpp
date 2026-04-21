class Solution 
{
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int maxConsecutiveOnes = 0;
        int currentConsecutiveOnes = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                maxConsecutiveOnes = max(maxConsecutiveOnes, currentConsecutiveOnes);
                currentConsecutiveOnes = 0;
            }
            else
            {
                ++currentConsecutiveOnes;
            }
        }

        maxConsecutiveOnes = max(maxConsecutiveOnes, currentConsecutiveOnes);
        return maxConsecutiveOnes;
    }
};