string makeGood(string s)
{
    bool erased = false;
    do
    {
        erased = false;
        for (int i = 0; i < s.length() - 1 && !s.empty(); ++i)
        {
            if (s[i] != s[i + 1] && std::tolower(s[i]) == std::tolower(s[i + 1]))
            {
                s.erase(i, 2);
                erased = true;

                break;
            }
        }
    } while (erased);

    return s;
}