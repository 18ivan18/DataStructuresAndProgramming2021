#include <iostream>
#include <string>
#include <stack>

int func2(std::string input, int& i) {
	std::string temp;
	if (input[i] == '-') {
		temp += input[i];
		i++;
	}
	while (input[i] >= '0' && input[i] <= '9' ) {
		temp += input[i++];
	}
	return atoi(temp.c_str());
}

int main() {
	std::string s = "3-7*4/2+5";
	std::stack<int> numbers;
	std::stack<char> operations;
	int result = 0;
	for (int i = 0; i < s.length(); i++) {
		switch (s[i]) {
		case '+':
			operations.push('+');
			break;
		case '*':
			result = func2(s, ++i);
			result *= numbers.top();
			numbers.pop();
			numbers.push(result);
			i--;
			break;
		case'/':
			result = func2(s, ++i);
			result = numbers.top() / result;
			numbers.pop();
			numbers.push(result);
			i--;
			break;
		case '-':
			numbers.push(func2(s, i));
			i--;
			operations.push('+');
			break;
		case ',':
			break;
		default:
			numbers.push(func2(s, i));
			i--;
			break;
		}
		std::cout << numbers.top() << std::endl;
	}
	result = 0;
	while (!operations.empty()) {
		result = numbers.top();
		numbers.pop();
		result += numbers.top();
		numbers.pop();
		numbers.push(result);
		operations.pop();
	}
	std::cout << numbers.top();
	return 0;
}