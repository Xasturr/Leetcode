#include "class.h"

int main()
{
	Solution solution;

	vector<int> vec = { 5, 7, 7, 8, 8, 10 };
		
	vector<int> vec2 = solution.searchRange(vec, 8);

	for (int i = 0; i < vec2.size(); i++)
	{
		cout << vec2.at(i);
	}

	return 0;
}