class Solution {
public:
    struct Log
    {
        int functionId;
        string state;
        int timestamp;
    };

    vector<int> exclusiveTime(int n, vector<string>& logs)
    {
        vector<int> result(n, 0);
        stack<Log> s;
        Log lastLog;

        for (const string& logString : logs)
        {
            stringstream ss(logString);
            string functionId, state, timestamp;

            getline(ss, functionId, ':');
            getline(ss, state, ':');
            getline(ss, timestamp, ':');

            Log currLog = {stoi(functionId), state, stoi(timestamp)};

            if (currLog.state == "start")
            {
                if (!s.empty())
                {
                    result[s.top().functionId] += currLog.timestamp - lastLog.timestamp;

                    if (lastLog.state == "end")
                    {
                        result[s.top().functionId] -= 1;
                    }
                }

                s.push(currLog);
            }
            else
            {
                s.pop();

                result[currLog.functionId] += currLog.timestamp - lastLog.timestamp;

                if (lastLog.state == "start")
                {
                    result[currLog.functionId] += 1;
                }
            }

            lastLog = currLog;
        }

        return result;
    }
};