#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        int alphabet_cnt_s[26] = {0};
        int alphabet_cnt_t[26] = {0};

        for(int i = 0; i < s.size(); ++i) {
            alphabet_cnt_s[(int)s[i] - 97]++;
            alphabet_cnt_t[(int)t[i] - 97]++;
        }

        for(int i = 0; i < 26; ++i)
            if(alphabet_cnt_s[i] != alphabet_cnt_t[i])
                return false;

        return true;
    }
};

int main()
{
    string s = "anagram", t = "nagaram";
    Solution sl;

    if(sl.isAnagram(s, t))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
