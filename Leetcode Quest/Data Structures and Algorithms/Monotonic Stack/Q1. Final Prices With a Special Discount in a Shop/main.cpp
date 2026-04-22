class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) 
    {
        vector<int> result = prices;
        stack<int> s;

        for (int i = 0; i < prices.size(); ++i)
        {
            while (!s.empty() && prices[s.top()] >= prices[i])
            {
                const int index = s.top();
                s.pop();
                result[index] = prices[index] - prices[i];
            }

            s.push(i);
        }

        return result;
    }
};