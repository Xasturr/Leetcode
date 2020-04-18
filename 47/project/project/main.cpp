#include "class.h"

int main()
{
	Solution solution;

	vector<int> vec;
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(3);

	vector<vector<int>> vec2 = solution.permuteUnique(vec);

	for (int i = 0; i < vec2.size(); i++)
	{
		for (int j = 0; j < vec2.at(i).size(); j++)
		{
			cout << vec2.at(i).at(j);
		}
		cout << endl;
	}

	return 0;
}