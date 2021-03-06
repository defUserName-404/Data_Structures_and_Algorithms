#include <stack>
#include <string>
#include <vector>

class Solution
{
  public:
    std::vector<int> en;
    int go(int lo, int hi)
    {
        if (lo + 1 == hi)
            return 1;
        int mid = en[lo];
        if (mid == hi)
            return 2 * go(lo + 1, hi - 1);
        return go(lo, mid) + go(mid + 1, hi);
    }

    //calculates the score of string S
    //This is solution of my YouTube video "The Recursive Stack Problem on Strings"
    int scoreOfParentheses(std::string &S)
    {
        int i, n = (int)S.size();
        n = std::max(n, 1);
        en.resize(n, 0);
        std::stack<int> s;
        for (i = 0; i < n; i++)
        {
            if (S[i] == ')')
            {
                int t = s.top();
                en[t] = i;
                s.pop();
            }
            else
                s.push(i);
        }
        return go(0, n - 1);
    }
};
