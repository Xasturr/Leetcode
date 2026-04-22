class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) 
    {
        vector<string> result;
        unordered_map<string, int> hashmap;
        constexpr int allowedEdits = 2;

        for (const string& word : dictionary)
        {
            ++hashmap[word];
        }

        for (const string& queryWord : queries)
        {
            if (hashmap.contains(queryWord))
            {
                result.push_back(queryWord);
                continue;
            }

            for (const string& dictionaryWord : dictionary)
            {
                int currEdits = 0;
            
                for (int i = 0; i < queryWord.length(); ++i)
                {
                    if (queryWord[i] != dictionaryWord[i])
                    {
                        ++currEdits;

                        if (currEdits > allowedEdits)
                        {
                            break;
                        }
                    }
                }

                if (currEdits <= allowedEdits)
                {
                    result.push_back(queryWord);
                    break;
                }
            }
        }

        return result;
    }
};