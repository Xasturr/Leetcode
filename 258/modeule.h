#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        string s = to_string(num);
        int num_res = 0;
        int num_temp = 0;
        auto iter = s.begin();
        while (true)
        {
            const char s_res[2] = {*iter, '\0'};
            num_temp = atoi(s_res);
            num_res += num_temp;

            iter++;
            if (iter == s.end())
            {
                if (num_res < 10)
                    return num_res;
                else
                {
                    s = to_string(num_res);
                    iter = s.begin();
                    num_res = 0;
                }
            }
        }
    }
};