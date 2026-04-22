class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int result = 0;

        stack<int> s;
        vector<int> lElements(heights.size());
        vector<int> rElements(heights.size());

        for (int i = 0; i < heights.size(); i++)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }

            lElements[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        s = {};

        for (int i = heights.size() - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }

            rElements[i] = s.empty() ? heights.size() : s.top();
            s.push(i);
        }

        for (int i = 0; i < heights.size(); i++)
        {
            int width = rElements[i] - lElements[i] - 1;
            result = max(result, heights[i] * width);
        }

        return result;
    }
};