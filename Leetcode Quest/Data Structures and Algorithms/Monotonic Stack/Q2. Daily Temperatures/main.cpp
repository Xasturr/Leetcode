class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        vector<int> result(temperatures.size(), 0);
        stack<int> s;

        for (int i = 0; i < temperatures.size(); ++i)
        {
            while (!s.empty() && temperatures[s.top()] < temperatures[i])
            {
                int index = s.top();
                s.pop();
                result[index] = i - index;
            }

            s.push(i);
        }

        return result;
    }
};