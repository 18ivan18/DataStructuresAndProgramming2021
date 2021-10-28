#include <string>
#include <cwctype>
#include <cassert>
#include <stack>

// Time: O(n)
// Space: O(n)
int calculate(std::string s)
{
    int len = s.length();
    if (len == 0)
    {
        return 0;
    }
    std::stack<int> stack;
    int currentNumber = 0;
    char operation = '+';
    for (int i = 0; i < len; i++)
    {
        char currentChar = s[i];
        if (isdigit(currentChar))
        {
            currentNumber = (currentNumber * 10) + (currentChar - '0');
        }
        if (!isdigit(currentChar) && !iswspace(currentChar) || i == len - 1)
        {
            if (operation == '-')
            {
                stack.push(-currentNumber);
            }
            else if (operation == '+')
            {
                stack.push(currentNumber);
            }
            else if (operation == '*')
            {
                int stackTop = stack.top();
                stack.pop();
                stack.push(stackTop * currentNumber);
            }
            else if (operation == '/')
            {
                int stackTop = stack.top();
                stack.pop();
                stack.push(stackTop / currentNumber);
            }
            operation = currentChar;
            currentNumber = 0;
        }
    }
    int result = 0;
    while (stack.size() != 0)
    {
        result += stack.top();
        stack.pop();
    }
    return result;
}

// Time: O(n)
// Space: O(1)
// int calculate(std::string s)
// {
//     int length = s.length();
//     if (length == 0)
//     {
//         return 0;
//     }
//     int currentNumber = 0, lastNumber = 0, result = 0;
//     char sign = '+';
//     for (int i = 0; i < length; i++)
//     {
//         char currentChar = s[i];
//         if (isdigit(currentChar))
//         {
//             currentNumber = (currentNumber * 10) + (currentChar - '0');
//         }
//         if (!isdigit(currentChar) && !iswspace(currentChar) || i == length - 1)
//         {
//             if (sign == '+' || sign == '-')
//             {
//                 result += lastNumber;
//                 lastNumber = (sign == '+') ? currentNumber : -currentNumber;
//             }
//             else if (sign == '*')
//             {
//                 lastNumber = lastNumber * currentNumber;
//             }
//             else if (sign == '/')
//             {
//                 lastNumber = lastNumber / currentNumber;
//             }
//             sign = currentChar;
//             currentNumber = 0;
//         }
//     }
//     result += lastNumber;
//     return result;
// }

int main()
{
    assert(calculate("3+2*2") == 7);
    assert(calculate(" 3/2 ") == 1);
    assert(calculate(" 3+5 / 2 ") == 5);
}