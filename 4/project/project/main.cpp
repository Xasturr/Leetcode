#include "class.h"

int main()
{
	Solution solution;
	vector<int> nums1;
	vector<int> nums2;
	nums1.push_back(1);
	nums1.push_back(2);
	nums1.push_back(3);
	nums1.push_back(4);
	nums2.push_back(6);
	nums2.push_back(7);
	nums2.push_back(8);
	nums2.push_back(9);

	//nums1.push_back(5);

	//nums2.push_back(2);
	//nums2.push_back(4);

	cout << endl << "median: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

	return 0;
}