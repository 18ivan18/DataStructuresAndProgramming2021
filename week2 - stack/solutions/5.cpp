#include <vector>
#include <stack>
#include <string>

int minOperations(std::vector<std::string> &logs)
{
    std::stack<std::string> st;
    for (int i = 0; i < logs.size(); i++)
    {
        if (logs[i] == "./" || (logs[i] == "../" && st.empty()))
        {
            continue;
        }
        if (logs[i] == "../")
        {
            st.pop();
            continue;
        }
        st.push(logs[i]);
    }
    return st.size();
}