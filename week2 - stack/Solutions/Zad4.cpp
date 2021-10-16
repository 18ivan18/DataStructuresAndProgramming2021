#include <iostream>
#include <string>
#include <stack>

int func1(std::string input, int& i) {
	std::string temp;
	while (input[i] != ',') {
		temp += input[i++];
	}
	return atoi(temp.c_str());
}

int main() {
	std::string tokens = "10,6,9,3,+,-11,*,/,17,+,5,+";
	std::stack<int> numbers;
	int result = 0;
	
	for (int i = 0; i < tokens.length(); i++) {
		switch (tokens[i]) {
		case '+':
			result = numbers.top();
			numbers.pop();
			result += numbers.top();
			numbers.pop();
			numbers.push(result);
			break;
		case '*' :
			result = numbers.top();
			numbers.pop();
			result *= numbers.top();
			numbers.pop();
			numbers.push(result);
			break;
		case'/':
			result = numbers.top();
			numbers.pop();
			result = numbers.top() / result;
			numbers.pop();
			numbers.push(result);
			break;
		case '-':
			if (tokens[i + 1] != ',') {
				numbers.push(func1(tokens, i));
			}
			result = numbers.top();
			numbers.pop();
			result -= numbers.top();
			numbers.pop();
			numbers.push(result);
			break;
		case ',':
			break;
		default:
			numbers.push(func1(tokens, i));
			break;
		}
	}
	std::cout << numbers.top();

	return 0;
}
