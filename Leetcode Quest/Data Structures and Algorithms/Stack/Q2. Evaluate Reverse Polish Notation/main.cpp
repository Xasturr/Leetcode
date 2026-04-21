class Solution {
private:
    bool isOperator(const string& token)
    {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> s;

        for (int i = 0; i < tokens.size(); ++i)
        {
            if (isOperator(tokens[i]))
            {
                const int x1 = s.top();
                s.pop();
                const int x2 = s.top();
                s.pop();

                int x3 = 0;

                const char* token = tokens[i].c_str();
                switch (*token)
                {
                    case '+':
                        x3 = x2 + x1;
                        break;
                    case '-':
                        x3 = x2 - x1;
                        break;
                    case '*':
                        x3 = x2 * x1;
                        break;
                    case '/':
                        x3 = x2 / x1;
                        break;
                    default:
                        break;
                }

                s.push(x3);
            }
            else
            {
                s.push(stoi(tokens[i]));
            }
        }

        return s.top();
    }
};