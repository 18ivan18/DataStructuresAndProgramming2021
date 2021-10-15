#include <string>
#include <stack>
#include <cassert>
#include <iostream>

// Time: O(n)
// Space: O(n)
int longestValidParentheses(std::string s)
{
    std::stack<int> st;
    st.push(-1);
    int longest = 0, current = 0, size = s.length();
    for (int i = 0; i < size; i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        if (s[i] == ')')
        {
            st.pop();
            if (st.empty())
            {
                st.push(i);
            }
            current = i - st.top();
            longest = std::max(longest, current);
        }
    }
    return longest;
}

// Time: O(n)
// Space: O(1)
int longestValidParenthesesLeftToRight(std::string s)
{
    int left = 0, right = 0, longest = 0, size = s.length();
    for (int i = 0; i < size; i++)
    {

        if (s.at(i) == '(')
        {
            left++;
        }
        else
        {
            right++;
        }
        if (left == right)
        {
            longest = std::max(longest, left + right);
        }
        if (right > left)
        {
            left = right = 0;
        }
    }
    left = right = 0;
    for (int i = size - 1; i >= 0; i--)
    {

        if (s.at(i) == '(')
        {
            left++;
        }
        else
        {
            right++;
        }
        if (left == right)
        {
            longest = std::max(longest, left + right);
        }
        if (left > right)
        {
            left = right = 0;
        }
    }

    return longest;
}

int main()
{
    assert(longestValidParentheses("(()") == 2);
    assert(longestValidParentheses(")()())") == 4);
    assert(longestValidParentheses("") == 0);
    assert(longestValidParentheses("()(()") == 2);
}