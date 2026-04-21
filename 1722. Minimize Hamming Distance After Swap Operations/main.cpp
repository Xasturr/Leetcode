class Solution {
private:
    vector<int> root;

    int find(const int x)
    {
        if (root[x] != x)
        {
            root[x] = find(root[x]);
        }

        return root[x];
    }

    void Union(const int n1, const int n2)
    {
        int x = find(n1);
        int y = find(n2);

        root[x] = y;
    }

public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps)
    {
        int res = 0;
        const int n = source.size();
        root.resize(n);

        for (int i = 0; i < n; ++i)
        {
            root[i] = i;
        }

        for (auto pair : allowedSwaps)
        {
            Union(pair[0], pair[1]);
        }

        unordered_map<int, unordered_map<int, int>> unionMap;

        for (int i = 0; i < n; ++i)
        {
            const int x = find(i);
            unionMap[x][source[i]]++;
        }

        for (int i = 0; i < n; ++i)
        {
            const int x = find(i);
            if (unionMap[x][target[i]] > 0)
            {
                --unionMap[x][target[i]];
            }
            else
            {
                ++res;
            }
        }

        return res;
    }
};