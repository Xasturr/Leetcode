class Solution {
public:
    int maxDistance(vector<int>& colors) 
    {
        int maxDistance = 1;

        for (int i = 0; i < colors.size(); ++i)
        {

            for (int j = colors.size() - 1; j >= 0; --j)
            {
                if (colors[i] != colors[j])
                {
                    maxDistance = max(maxDistance, abs(j - i));
                }
            }
        }

        return maxDistance;
    }
};