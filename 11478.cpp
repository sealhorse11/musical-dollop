#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    string curr_substring;
    set<string> substring;

    for (int length = 1; length <= s.size(); length++)
    {
        for (int i = 0; i < s.size() - length + 1; i++)
        {
            curr_substring = s.substr(i, length);
            substring.insert(curr_substring);
        }
    }
    cout << substring.size();
    return 0;
}