#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
    int titleToNumber(string s) 
    {
        if (s.length() == 0)
            return 0;

        long x = 1, sol = 0, i = 0;
        for (auto iter = --s.end(); iter >= s.begin(); iter--)
        {
            if (*iter == 'A') 
                i = 1;
            else if (*iter == 'B')
                i = 2;
            else if (*iter == 'C')
                i = 3;
            else if (*iter == 'D')
                i = 4;
            else if (*iter == 'E')
                i = 5;
            else if (*iter == 'F')
                i = 6;
            else if (*iter == 'G')
                i = 7;
            else if (*iter == 'H')
                i = 8;
            else if (*iter == 'I')
                i = 9;
            else if (*iter == 'J')
                i = 10;
            else if (*iter == 'K')
                i = 11;
            else if (*iter == 'L')
                i = 12;
            else if (*iter == 'M')
                i = 13;
            else if (*iter == 'N')
                i = 14;
            else if (*iter == 'O')
                i = 15;
            else if (*iter == 'P')
                i = 16;
            else if (*iter == 'Q')
                i = 17;
            else if (*iter == 'R')
                i = 18;
            else if (*iter == 'S')
                i = 19;
            else if (*iter == 'T')
                i = 20;
            else if (*iter == 'U')
                i = 21;
            else if (*iter == 'V')
                i = 22;
            else if (*iter == 'W')
                i = 23;
            else if (*iter == 'X')
                i = 24;
            else if (*iter == 'Y')
                i = 25;
            else
                i = 26;

            sol += i * x;
            x *= 26;
        }

        return sol;
    }
};

int main() 
{
    string s = "AAA";
    Solution sol;
    
    cout << sol.titleToNumber(s) << endl;

    return 0;
}