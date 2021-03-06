# FAQ

## Какво е опашката като структура от данни?
Крайна редица от хомогенни елементи. Операция за включване в края и операция за излючване от началото от вида FIFO (first in first out).

![](https://miro.medium.com/max/1400/1*RFztQ8ATdev1d0MaFwhDFQ.png)

## Да си я напишем сами?
Две физически представяния. Свързано и последователно. При последователното се пази блок памет, в който опашката расте и се съкращава. Обикновено той е цикличен, т.е. когато когато краят на опашката достигне края на блока, но има свободно място в началото му елементите продължават да се пишат там. При свързаното представяне парчетата са разпръснати из оперативната памет и с тях боравим чрез указатели. Необходими са ни указатели към началото и края на опашката.

## А да я ползвам на готово?
Естествено, има я в stl.

```c++
#include <queue>
// ...
std::queue<int> q;

q.push(5);
q.push(6);
q.push(7);

while(!q.empty()) {
    std::cout << q.front();
    q.pop();
}
```

# Задача 1
## Stack using Queues

Имплементирайте структурата от данни стек използвайки само две опашки. Стекът трябва да поддържа всички функционалности на нормален стек (`push`, `top`, `pop`, and `empty`).

Имплементация на класа `MyStack`:


- `void push(int x)` Слага елементът х на върха на стека.
- `int pop()` Премахва елемент от върха на стека и го връща.
- `int top()` Връща елемента на върха на стеак.
- `bool empty()` Проверява дали стекът е празен и връща `true` ако е.

**Бележки:**

Трябва да използвате само стандартните операции на една опашка - push to back, peek/pop from front, size and is empty са валидни.
 

**Example 1:**

```c++
Explanation
MyStack* myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
```

**Constraints:**

- `1 <= x <= 9`
- At most `100` calls will be made to `push`, `pop`, `top`, and `empty`.
- All the calls to `pop` and `top` are valid.

**Follow-up:** Can you implement the stack using only one queue?


# Задача 2
## Queue using Stacks

Имплементирайте структурата от данни опашка използвайки два стека. Опашката трябва да поддържа всички функционалности на нормална опашка (`push`, `peek`, `pop`, and `empty`).

Имплементирайте класа `MyQueue`:

- `void push(int x)` Добавя елемент на края на опашката.
- int pop() Премахва елемент от началото на опашката и го връща.
- `int peek()` Връща елемента в началото на опашката.
- `bool empty()` Проверява дали опашката е празна и връща `true` ако е.
 

**Example 1:**

```c++
MyQueue* myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
 ```

**Constraints:**

- `1 <= x <= 9`
- At most `100` calls will be made to `push`, `pop`, `peek`, and `empty`.
- All the calls to `pop` and `peek` are valid.
 
# Задача 3
## Какви други видове опашки има?

Реализирайте структурата `deque`. **D**ouble-**e**nded **q**ueue е вид опашка, която поддържа операциите `push` и `pop` както в началото така и в края.

![](https://media.geeksforgeeks.org/wp-content/uploads/anod.png)

Използвайте я за да реализирате класа `FrontMiddleBack`, който представлява опашка със следните свойства:

- `FrontMiddleBack()` Инициализира класа.
- `void pushFront(int val)` Добавя `val` в началото на опашката.
- `void pushMiddle(int val)` Добавя `val` в средата на опашката.
- `void pushBack(int val)` Добавя `val` в края на опашката.
- `int popFront()` Премахва елемента в началото на опашката и го връща. Ако опашката е празна връща -1.
- `int popMiddle()` Премахва елемента в средата на опашката и го връща. Ако опашката е празна връща -1.
- `int popBack()` Премахва елемента в края на опашката и го връща. Ако опашката е празна връща -1.

**Example 1:**

```c++
FrontMiddleBackQueue* q = new FrontMiddleBackQueue();
q.pushFront(1);   // [1]
q.pushBack(2);    // [1, 2]
q.pushMiddle(3);  // [1, 3, 2]
q.pushMiddle(4);  // [1, 4, 3, 2]
q.popFront();     // return 1 -> [4, 3, 2]
q.popMiddle();    // return 3 -> [4, 2]
q.popMiddle();    // return 4 -> [2]
q.popBack();      // return 2 -> []
q.popFront();     // return -1 -> [] (The queue is empty)
```

# Задача 4
## Генериране на всички числа в двоична бройна система използвайки опашка

По дадено положително число `n`, генерирайте числата в двоична бройна система между 1 и `n` използвайки структрата от данни опашка.

Изисква се решение в линейно време.

**Example 1:**

```c++
Input: n = 16
Outout: 1 10 11 100 101 110 111 1000 1001 1010 1011 1100 1101 1110 1111 10000
 ```


# Задача 5
Имаме n на брой приятели, които играят игра. Стоейки в кръг те се номерират от 1 до n по часовниковата стрелка. 

Правилата на играта:

1. Започваме от първия приятел.
2. Броим k приятели по часовниковата стрелка включително този, от който започваме. Можем да броим някои хора по повече от веднъж, тъй като са подредени в кръг.
3. Последния преброен човек излиза от кръга и губи играта.
4. Отиваме на стъпка 2, ако има повече от 1 човек останал в кръга.
5. Последният приятел останал в кръга печели играта.

По даден броят на приятелите, n, и цяло число k, намерете победителят в играта.


**Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/25/ic234-q2-ex11.png)

```c++
Input: n = 5, k = 2
Output: 3
Explanation: Here are the steps of the game:
1) Start at friend 1.
2) Count 2 friends clockwise, which are friends 1 and 2.
3) Friend 2 leaves the circle. Next start is friend 3.
4) Count 2 friends clockwise, which are friends 3 and 4.
5) Friend 4 leaves the circle. Next start is friend 5.
6) Count 2 friends clockwise, which are friends 5 and 1.
7) Friend 1 leaves the circle. Next start is friend 3.
8) Count 2 friends clockwise, which are friends 3 and 5.
9) Friend 5 leaves the circle. Only friend 3 is left, so they are the winner.
```
**Example 2:**
```c++
Input: n = 6, k = 5
Output: 1
Explanation: The friends leave in this order: 5, 4, 6, 2, 3. The winner is friend 1.
 ```

**Constraints:**

- 1 <= k <= n <= 500


 
# Задача 6
Даден е масив от цели числа и sliding window с големина `k`, който се движи от първия елемент до последния. В него можете да виждате само по `k` числа. Придвижва се на дясно с по една позиция.

Какво е sliding window?

![](https://i.stack.imgur.com/2Dneo.png)

Принтирайте максимума на елементите в sliding window-а на всяка итерация.

**Example 1**:
```c++
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```
**Example 2**:
```c++
Input: nums = [1], k = 1
Output: [1]
```
**Example 3**:
```c++
Input: nums = [1,-1], k = 1
Output: [1,-1]
```
**Example 4**:
```c++
Input: nums = [9,11], k = 2
Output: [11]
```
**Example 5**:
```c++
Input: nums = [4,-2], k = 2
Output: [4]
 ```

**Constraints:**

- 1 <= nums.length <= 10<sup>5</sup>
- -10<sup>4</sup> <= nums[i] <= 10<sup>4</sup>
- 1 <= k <= nums.length

# Задача 7
## Най-къс път в лабиринт

Даден е лабиринт под формата на двоична правоъгълна матрица. Намерете най-късия път от дадена начална точка до дадена дестинация.

Пътят може да бъде само от клетки със стойност 1. Можем да се движим с по една стъпка в някоя от четирите посоки.
```
Go Top: (x, y) ——> (x – 1, y)
Go Left: (x, y) ——> (x, y – 1)
Go Down: (x, y) ——> (x + 1, y)
Go Right: (x, y) ——> (x, y + 1)
```

**Example 1**:

**Input:** source = `(0, 0)`, destination = `(7, 5)`

 [ 
<span style="color:blue">1</span>  <span style="color:blue">1</span>  <span style="color:blue">1</span>  1  1  0  0  1  1  1 ]

 [ 0  1  <span style="color:blue">1</span>  1  1  1  0  1  0  1 ]

 [ 0  0  <span style="color:blue">1</span>  0  1  1  1  0  0  1 ]

 [ 1  0  <span style="color:blue">1</span>  <span style="color:blue">1</span>  1  0  1  1  0  1 ]

 [ 0  0  0  <span style="color:blue">1</span>  0  0  0  1  0  1 ]

 [ 1  0  1  <span style="color:blue">1</span>  <span style="color:blue">1</span>  0  0  1  1  0 ]

 [ 0  0  0  0  <span style="color:blue">1</span>  0  0  1  0  1 ]

 [ 0  1  1  1  <span style="color:blue">1</span>  <span style="color:blue">1</span>  <span style="color:blue">1</span>  <span style="color:blue">1</span>  0  0 ]

 [ 1  1  1  1  1  0  0  <span style="color:blue">1</span>  <span style="color:blue">1</span>  <span style="color:blue">1</span> ]

 [ 0  0  1  0  0  1  1  0  0  <span style="color:blue">1</span> ]


**Output:** 12
# Задача 8
## Chess Knight Problem
Дадена е дъска за шах, начално поле и цел. Намерете най-малкия брой ходове, които трябва да направи един кон (фигурата кон), за да достигне до целта, започвайки от началото.

**Example 1**:
```c++
Input: 
N = 8 (8 × 8 board)
Source = (7, 0)
Destination = (0, 7)
 
Output: Minimum number of steps required is 6
```
Explanation: 

![](https://www.techiedelight.com/wp-content/uploads/2016/11/Chess-Board.png)
