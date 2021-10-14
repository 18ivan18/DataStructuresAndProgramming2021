# FAQ

## Какво беше това стек?

Линейна динамична структура от данни. Крайна редица от хомогенни елементи. Операции за включване и изключване на елементи от вида LIFO (last in first out). 

![](https://cdn.programiz.com/sites/tutorial2program/files/stack.png)

![](https://cdn.programiz.com/sites/tutorial2program/files/stack-operations.png)



## Как сега го имплементирах този стек?

Две физически представяния - последователно и свързано. Последователното има ограничен капацитет. При свързаното парчетата памет са разпръснати из оперативната памет и връзката между отделните елементи става чрез указатели.

![](https://lh3.googleusercontent.com/proxy/B8FTgbSgpUvyHXAL-Hl21PXCrkxQfKwI9k14bxypgoi9koCiKMlA80lypSFDBTtVAGcgJxJIz3ruQ53MjWyVbtRzAzfPy9e1WS8yC22aX7ZXZDyHOLNA1MR0hcaPDzXpZ3U2vymPf7DhOGtfX-XyipAmJmuMmm1e4dOU)

## Добре де, ама ако не искам да си го пиша сам, нали хората вече са го измислили?

Ползвай stl реализацията в c++.

```c++
#include <stack>
// ...
std::stack<int> st;
st.push(5);
st.push(-42);
st.push(69);
st.push(77);

while (!st.empty()) {
    std::cout << st.top() << " ";
    st.pop();
}
```

## И кога каза, че го ползвам това чудо?

- Expression evaluation and syntax parsing
- Backtracking  
- Compile time memory management
- Efficient algorithms

# Задача 1
## Валидни скоби

Даден е низ `s` съдържащ символите `'(', ')'`, `'{', '}'`, `'['` и `']'`, опредеете дали входът е валиден.

Входният низ е валиед, ако:

1. Отварящите скоби се затварят от същия вид скоби.
2. Отварящите скоби са затворени в правилния ред.
 

**Example 1:**
```c++
Input: s = "()"
Output: true
```
**Example 2:**
```c++
Input: s = "()[]{}"
Output: true
```
**Example 3:**
```c++
Input: s = "(]"
Output: false
```
**Example 4:**
```c++
Input: s = "([)]"
Output: false
```
**Example 5:**
```c++
Input: s = "{[]}"
Output: true
```

**Constraints:**

* 1 <= s.length <= 10<sup>4
* `s` consists of parentheses only `'()[]{}'`.
# Задача 2
## Минимален стек

Напишете структура стек, която поддържа операциите `push`, `pop`, `top` и извеждане на минимален елемент в константно време.

Implement the `MinStack` class:

- `MinStack()` инициализира обекта стек.
- `void push(val)` поставя елемента `val` на върха на стека.
- `void pop()` премахва най-горния елемент от върха на стека.
- `int top()` връща стойността на елемента, който се намира на върха на стека.
- `int getMin()` взима минималния елемент в стека.
 

**Example 1:**
```c++
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
```

**Constraints:**

- -2<sup>31</sup> <= val <= 2<sup>31</sup> - 1
- Methods `pop`, `top` and `getMin` operations will always be - called on **non-empty** stacks.
- At most 3 * 10<sup>4</sup> calls will be made to `push`, `pop`, `top`, and `getMin`.

# Задача 3
## Пресметнете стойносттна на аритметичен израз записан в обратен полски запис (Reverse Polish Notation)

![](https://media.cheggcdn.com/media%2Fb3d%2Fb3d2eb31-5784-49be-895c-aef23651f0b2%2Fimage.png)

Валидни оператори са `+`, `-`, `*`, and `/`. Всеки операнд може да е число или друг валиден израз.

Използвайте floor division. 

Гарантираме, че даденият израз в обратен полски запис е винаги правилен. Той винаги се свежда до резултат и няма да има деление на нула.
 

**Example 1:**
```c++
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
```

**Example 2:**
```c++
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
```
**Example 3:**
```c++
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
```

**Constraints:**

- 1 <= tokens.length <= 10<sup>4
- `tokens[i]` is either an operator: `"+"`, `"-"`, `"*"`, or `"/"`, or an integer in the range `[-200, 200].`

# Задача 4
Нека пазим лог всеки път, когато сменяме директорията в нашата файлова система. 

По-долу са описани следните операции:

- `"../"` : Местим се в родителската директория на папката, в която се намираме в момента. (Ако вече сме в главната директория оставаме в нея).
- `"./"` : Оставаме в същата директория.
- `"x/"` : Местим се в подпапка с име `x` (Гарантирано е, че тази директория съществува).

Даден е лист от низове `logs`, където `logs[i]` е операцията, която е извършил потребителя на `i-тата `стъпка.

Файловата система започва с главната директория и след това операциите записани в `logs` се изпълняват.

Върнете минималният брой операции необходими да се върнем обратно в главната директория.
 
**Example 1:**
![](https://assets.leetcode.com/uploads/2020/09/09/sample_11_1957.png)

```c++
Input: logs = ["d1/","d2/","../","d21/","./"]
Output: 2
Explanation: Use this change folder operation "../" 2 times and go back to the main folder.
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/09/09/sample_22_1957.png)

```c++
Input: logs = ["d1/","d2/","./","d3/","../","d31/"]
Output: 3
```

**Example 3:**
```c++
Input: logs = ["d1/","../","../","../"]
Output: 0
 ```

Constraints:

- 1 <= logs.length <= 10<sup>3
- `2 <= logs[i].length <= 10`
- `logs[i]` contains lowercase English letters, digits, `'.'`, and `'/'`.
- `logs[i]` follows the format described in the statement.
- Folder names consist of lowercase English letters and digits.



# Задача 5
## Простичък калкулатор
Даден ни е низ `s` представляващ правилен алгебричен израз. Напишете обикновен калкулатор, който да пресметне стойността му и да я върне като резултат.
 
При деление на цели числа използвайте floor division.

Можем да предположим, че изразите са винаги верни.

**Example 1:**
```c++
Input: s = "3+2*2"
Output: 7
```
**Example 2:**
```c++
Input: s = " 3/2 "
Output: 1
```
**Example 3:**
```c++
Input: s = " 3+5 / 2 "
Output: 5
 ```

**Constraints:**

- 1 <= s.length <= 3 * 10<sup>5
- `s` consists of integers and operators (`'+'`, `'-'`, `'*'`, `'/'`) separated by some number of spaces.
- `s` represents **a valid expression**.
- All the integers in the expression are non-negative integers in the range [0, 2<sup>31</sup> - 1].
- The answer is **guaranteed** to fit in a **32-bit integer**.

# Задача 6
## Калкулатор 
Даден ни е низ `s` представляващ правилен алгебричен израз. Напишете калкулатор, който да пресметне стойността му и да я върне като резултат.
 

**Example 1:**
```c++
Input: s = "1 + 1"
Output: 2
```
**Example 2:**
```c++
Input: s = " 2-1 + 2 "
Output: 3
```
**Example 3:**
```c++
Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
 ```

**Constraints:**

- 1 <= s.length <= 3 * 10<sup>5
- `s` consists of digits, `'+'`, `'-'`, `'('`, `')'`, and `' '`.
- `s` represents a valid expression.
- `'+'` is not used as a unary operation.
- `'-'` could be used as a unary operation and in this case, it will not be used directly after a +ve or -ve signs (will be inside parentheses).
- There will be no two consecutive operators in the input.
- Every number and running calculation will fit in a signed 32-bit integer.

# Задача 7
## Най-дълга поредица от правилни скоби
Даден е низ състоящ се само от символите `'('` and `')'`, намерете дължината на най-дългия подниз от правилно поставени скоби.

**Example 1:**
```c++
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
```
**Example 2:**
```c++
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
```
**Example 3:**

```c++
Input: s = ""
Output: 0
 ```

**Constraints:**

* 0 <= s.length <= 3 * 10<sup>4
* `s[i]` is `'('`, or `')'`.

# Задача 8
## Пресичащи се интервали
Даден е вектор от интервали от време s. Всеки интервал се характеризира с начален час и краен час. Намерете всички непресичащи се интервали след като убедините всички пресичащи се.

**Example 1:**
```c++
Input:  {1, 5}, {2, 3}, {4, 6}, {7, 8}, {8, 10}, {12, 15}
Output: Intervals after merging overlapping intervals are {1, 6}, {7, 10}, {12, 15}.
```