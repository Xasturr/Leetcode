class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums)
    {
        std::unordered_map<int, int> map;
        int distance = -1;

        for (int i = 0; i < nums.size(); ++i)
        {
            std::string numString = std::to_string(nums[i]);
            std::reverse(numString.begin(), numString.end());
            const int numReversed = std::stoi(numString);

            if (map.contains(nums[i]))
            {
                distance = distance == - 1 ? i - map[nums[i]] : std::min(i - map[nums[i]], distance);

                if (distance == 1)
                {
                    return distance;
                }
            }

            map[numReversed] = i;
        }

        return distance;
    }
};