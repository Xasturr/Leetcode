class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        vector<int> res(nums.size());
        map<int, int> map;

        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            for (auto iter : map)
            {
                if (iter.first >= nums[i])
                {
                    break;
                }

                res[i] += iter.second;
            }
        }


        return res;
    }
};