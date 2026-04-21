class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
        vector<string> result;
        auto it = target.begin();
        int currTarget = *it;

        for (int i = 1; i <= n; ++i)
        {
            result.push_back("Push");

            if (i == currTarget)
            {
                if (it + 1 == target.end())
                {
                    return result;
                }

                currTarget = *(++it);
            }
            else if (i != currTarget)
            {
                result.push_back("Pop");
            }
        }

        return result;
    }
};