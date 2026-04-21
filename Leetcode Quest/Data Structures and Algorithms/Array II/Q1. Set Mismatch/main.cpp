class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        unordered_map<int, int> hashtable;

        for (int i = 0; i < nums.size(); ++i)
        {
            hashtable[nums[i]]++;
        }

        int n1 = 0;
        int n2 = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (hashtable[i + 1] > 1)
            {
                n1 = i + 1;

                if (n2 != 0)
                {
                    break;
                }
            }
            else if (hashtable[i + 1] == 0)
            {
                n2 = i + 1;

                if (n1 != 0)
                {
                    break;
                }
            }
        }

        return {n1, n2};
    }
};