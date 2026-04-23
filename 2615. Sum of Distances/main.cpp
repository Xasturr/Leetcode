class Solution {
public:
    vector<long long> distance(vector<int>& nums) 
    {
        unordered_map<int, vector<long long>> map;
        vector<long long> result(nums.size(), 0);

        for (int i = 0; i < nums.size(); ++i)
        {
            map[nums[i]].push_back(i);
        }

        for (auto iter = map.begin(); iter != map.end(); ++iter)
        {
            const vector<long long>& indexVector = iter->second;
            long long sum = 0;
            long long leftSum = 0;

            for (const int index : indexVector)
            {
                sum += index;
            }

            for (int i = 0; i < indexVector.size(); ++i)
            {
                const long long rightSum = sum - leftSum - indexVector[i];
                result[indexVector[i]] = i * indexVector[i] - leftSum + rightSum - (indexVector.size() - i - 1) * indexVector[i];

                leftSum += indexVector[i];
            }

        }

        return result;
    }
};