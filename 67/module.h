#include <string>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string c;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        const char *a_c = a.c_str();
        const char *b_c = b.c_str();

        int temp = 0;
        int curr = 0;

        while (true)
        {
            if (*a_c != '\0')
            {
                if (*b_c != '\0')
                {
                    const char a_temp[2] = {*a_c, '\0'};
                    const char b_temp[2] = {*b_c, '\0'};

                    curr = atoi(a_temp) + atoi(b_temp) + temp;
                    cout << curr << endl;

                    if (curr % 2 == 1)
                    {
                        if (curr == 3)
                            temp = 1;
                        else
                            temp = 0;

                        c = "1" + c;
                    }
                    else
                    {
                        if (curr == 2)
                            temp = 1;
                        else
                            temp = 0;

                        c = "0" + c;
                    }
                    b_c++;
                }
                else
                {
                    const char a_temp[2] = {*a_c, '\0'};

                    curr = atoi(a_temp) + temp;
                    cout << curr << endl;

                    if (curr % 2 == 1)
                    {
                        temp = 0;
                        c = "1" + c;
                    }
                    else
                    {
                        if (curr == 2)
                            temp = 1;
                        else
                            temp = 0;

                        c = "0" + c;
                    }
                }
                a_c++;
            }
            else if (*b_c != '\0')
            {
                const char b_temp[2] = {*b_c, '\0'};

                curr = atoi(b_temp) + temp;
                cout << curr << endl;

                if (curr % 2 == 1)
                {
                    temp = 0;
                    c = "1" + c;
                }
                else
                {
                    if (curr == 2)
                        temp = 1;
                    else
                        temp = 0;

                    c = "0" + c;
                }
                b_c++;
            }
            else
            {
                if (temp == 1)
                    c = "1" + c;

                return c;
            }
        }
    }
};