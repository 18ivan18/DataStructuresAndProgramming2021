#include <iostream>
#include <string>
#include <stack>
int main() {
    std::string logs = "d1/,d2/,../,d30/,./,d34,../,../,../,../";
	std::stack<char> stack;
	for (int i = 0; i < logs.length(); i++) {
		switch (logs[i]) {
		case 'd':
			stack.push(logs[i]);
			break;
		case '.':
			if (logs[i + 1] == '.') {
				if(!stack.empty())
					stack.pop();
			}
			break;
		default:
			break;
		}
	}
	int output = 0;
	while (!stack.empty()) {
		output++;
		stack.pop();
	}
	std::cout << output;
    return 0;	
}