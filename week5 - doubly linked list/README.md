# FAQ

## Какви разновидности на свързан списък има?

Освен свързания списък с една връзка се срещат още и двойно свързан списък (doubly linked list), цикличен свързан списък с една/две връзки (circular linked list), както и някои по екзотични варианти като skip list. От тях произлиза и известната структура **дек** (**deque**). Произнася се дек и произлиза от **d**ouble **e**nded **que**ue. Това е списък, който поддържа бързите операции поставяне в началото, премахване от началото, добавяне в края и премахване от края.

### Свързан списък с една/две връзки.

![](https://raw.githubusercontent.com/ivanahristova/data-structures-fmi/main/media/sem05-linked-lists.png)

### Двоен цикличен свързан списък.
![](https://www.alphacodingskills.com/imgfiles/circular-doubly-linked-list.PNG)

### Skip list

![](https://www.cdn.geeksforgeeks.org/wp-content/uploads/SkipList1.png)

### Deque

![](https://media.geeksforgeeks.org/wp-content/uploads/anod.png)



# Задача 1
## Design Circular Deque

Реализирайте ваша имплементация на цикличен дек (circular double-ended queue (deque)).

Имплементирайте класа `MyCircularDeque`:


- `MyCircularDeque(int k)` Инициализира дек-а с максимален размер `k`.
- `bool insertFront()` Добавя елемент в началото на дек-а. Връща `true` ако операцията е успешна или `false` иначе.
- `bool insertLast()` Добавя елемент в края на дек-а. Връща `true` ако операцията е успешна или `false` иначе.
- `bool deleteFront()` Изтрива елемент от началото на дек-а. Връща `true` ако операцията е успешна или `false` иначе.
- `bool deleteLast()` Изтрива елемент от края на дек-а. Връща `true` ако операцията е успешна или `false` иначе.
- `int getFront()` Връща първия елемент на дек-а. Връща `-1` ако дек-а е пълен.
- `int getRear()` Връща последния елемент на дек-а. Връща `-1` ако дек-а е празен.
- `bool isEmpty()` Връща `true` ако дек-а е празен или `false` иначе.
- `bool isFull()` Връща `true` ако дек-а е пълен или `false` иначе.


**Example 1:**
```c++
MyCircularDeque* myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return true
myCircularDeque.insertLast(2);  // return true
myCircularDeque.insertFront(3); // return true
myCircularDeque.insertFront(4); // return false, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return true
myCircularDeque.deleteLast();   // return true
myCircularDeque.insertFront(4); // return true
myCircularDeque.getFront();     // return 4
 ```

**Constraints:**

- `1 <= k <= 1000`
- `0 <= value <= 1000`
- At most 2000 calls will be made to `insertFront`, `insertLast`, `deleteFront`, `deleteLast`, `getFront`, `getRear`, `isEmpty`, `isFull`.


# Задача 2
## Design Browser History

Имате даден браузър, който винаги отваря даден `homepage` в началото. Можете да посещавате други url-и, да се връщате в историята даден брой стъпки или да се предвижвате напред в историята даден брой стъпки.

Имплементирайте класът `BrowserHistory`:


- `BrowserHistory(string homepage)` Initializes the object with the homepage of the browser.
- `void visit(string url)` Visits url from the current page. It clears up all the forward history.
- `string back(int steps)` Move steps back in history. If you can only return `x` steps in the history and `steps > x`, you will return only `x` steps. Return the current url after moving back in history at most steps.
- `string forward(int steps)` Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.
 

**Example:**
```c++

BrowserHistory* browserHistory = new BrowserHistory("ivanarabadzhiyski.com");
browserHistory.visit("google.com");       // You are in "ivanarabadzhiyski.com". Visit "google.com"
browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
browserHistory.back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
browserHistory.back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
browserHistory.forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
browserHistory.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
browserHistory.back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
browserHistory.back(7);                   // You are in "google.com", you can move back only one step to "ivanarabadzhiyski.com". return "ivanarabadzhiyski.com"
 ```

**Constraints:**

- `1 <= homepage.length <= 20`
- `1 <= url.length <= 20`
- `1 <= steps <= 100`
- `homepage` and `url` consist of  '.' or lower case English letters.
- At most 5000 calls will be made to visit, back, and forward.


# Задача 3
## Design Skiplist

Реализирайте структурата `Skiplist` без използване на вградените библиотеки.

Skiplist е структура от данни, която отнема `O(log(n))` време за добавяне, изтриване и търсене. 

Например, ако имаме `Skiplist` с елементите [30,40,50,60,70,90] и искаме да добавим 80 и 45 в него.


![](https://assets.leetcode.com/uploads/2019/09/27/1506_skiplist.gif)

Забелязваме, че има много нива в `Skiplist`-a. Всяко ниво представлява сортиран свързан списък. С помощта на горните нива операциите добавяне, триене и търсене могат да се реализират по-бързо от O(n). Може да се докаже, че средната сложност по време на всяка операция е `O(log(n))`, а средната сложност по памет е `O(n)`.


Имплементирайте класът `Skiplist`:

- `Skiplist()` Инициализира обект.
- `bool search(int target)`
- `void add(int num)` Добавя num в листа
- `bool erase(int num)` Премахва стойността от листа и връща `true`. Ако такъв елемент не се намери, връща `false` и не прави нищо. Ако има няколко елемента с една и съща стойност изтрива кой да е от тях.


**Example 1:**

```c++
Skiplist* skiplist = new Skiplist();
skiplist.add(1);
skiplist.add(2);
skiplist.add(3);
skiplist.search(0); // return false
skiplist.add(4);
skiplist.search(1); // return true
skiplist.erase(0);  // return false, 0 is not in skiplist.
skiplist.erase(1);  // return true
skiplist.search(1); // return false, 1 has already been erased.
```
 

**Constraints:**

- 0 <= num, target <= 2 * 10<sup>4
- At most 5 * 10<sup>4</sup> calls will be made to `search`, `add`, and `erase`.

# Задача 4
## Reverse specified portion of a linked list

Обрънете реда на оказана част от свързан списък.

**Example 1:**
```c++
Input:
1 —> 2 —> 3 —> 4 —> 5 —> 6 —> 7 —> Ø
start: 2, end: 5
 
Output: 1 —> 5 —> 4 —> 3 —> 2 —> 6 —> 7 —> Ø
```

# Задача 5
Даден е свързан списък, в който всеки Node има един допълнителен указател наречен `random`. В началото той сочи към призволен елемент от списъка или към *nullptr*. Напишете функция, която пренарежда указателите `random` така че да сочат към елемента с най-голяма стойност намиращ се след дадения.

**Example 1:**
```c++
Input: 5(Ø) -> 10(Ø) -> 7(Ø) -> 9(Ø) -> 4(Ø) -> 3(Ø) -> Ø
Output: 5(10) -> 10(9) -> 7(9) -> 9(4) -> 4(3) -> 3(Ø) -> Ø
```

# Задача 6
## XOR Linked List

Знаем, че всеки `Node` на двойно свързан списък има две променливи, в които пази адреса на следващия и предишния елемент. Сега ще разгледаме структура наречена `XOR Linked List`. Всеки негов `Node` съдържа само един указател, който не пази адреса на следващия елемент, ами вместо това пази резултата от операцията побитово изключващо или (xor) на адресите на предишния и следващия елемент.

Да разгледаме произволна картинка на двоен свързан списък.

![](https://www.techiedelight.com/wp-content/uploads/Doubly-Linked-List-1.png)

Ето и еквивалентиния му XOR лист.
```c++
link(A) = nullptr ^ addr(B)        // bitwise XOR of nullptr with address of node B
link(B) = addr(A) ^ addr(C)     // bitwise XOR between the address of node A and C
link(C) = addr(B) ^ addr(D)     // bitwise XOR between the address of node B and D
link(D) = addr(C) ^ nullptr        // bitwise XOR of the address of node A with nullptr
```

## Как ни помага това?
Знаем следните свойства:
```
X ^ X = 0
X ^ 0 = X
X ^ Y = Y ^ X
```
Използвайки ги можем лесно да се предвижваме по листа в коя да е посока.

Вашата задача е да имплементирате такъв XOR list и да посочите предимства и недостатъци спрямо стандартен свързан списък.

**Reference:** https://en.wikipedia.org/wiki/XOR_linked_list


# Задачи за едносвързан списък
## Задача 1
Да се напише функция, която обръща всяка група от k елемента в свързан списък.

Ако k не е делител на броя на елементите в списъка, последната група от елементи да остане непроменена. 

Не трябва да променяте стойностите на елементите, можете да работите само с указатели.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/10/03/reverse_ex1.jpg)
```c++
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
```
**Example 2:**

![](https://assets.leetcode.com/uploads/2020/10/03/reverse_ex2.jpg)
```c++
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
```
**Example 3:**
```c++
Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]
```
**Example 4:**
```c++
Input: head = [1], k = 1
Output: [1]
 ```

**Constraints:**

- The number of nodes in the list is in the range sz.
- `1 <= sz <= 5000`
- `0 <= Node.val <= 1000`
- `1 <= k <= sz`
 

**Follow-up:** Can you solve the problem in O(1) extra memory space?

## Задача 2
### Palindrome Linked List
Да се напише функция, която проверява дали свързан списък е палиндром.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg)
```c++
Input: head = [1,2,2,1]
Output: true
```
**Example 2:**

![](https://assets.leetcode.com/uploads/2021/03/03/pal2linked-list.jpg)
```c++
Input: head = [1,2]
Output: false
 ```

**Constraints:**

- The number of nodes in the list is in the range [1, 105].
- 0 <= Node.val <= 9
 

**Follow up:** Could you do it in O(n) time and O(1) space?

## Задача 3
### Remove Zero Sum Consecutive Nodes from Linked List

Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

 

(Note that in the examples below, all sequences are serializations of ListNode objects.)

**Example 1:**
```c++
Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.
```
**Example 2:**
```c++
Input: head = [1,2,3,-3,4]
Output: [1,2,4]
```
**Example 3:**
```c++
Input: head = [1,2,3,-3,-2]
Output: [1]
 ```

**Constraints:**

- The given linked list will contain between `1` and `1000` nodes.
- Each node in the linked list has `-1000 <= node.val <= 1000`.

## Задача 4
### Reorder List
Напишете функция, която пренарежда свързан списък по зададен начин в линейно време.

Представяме листа като:

`L0 → L1 → … → Ln - 1 → Ln`

Пренареждаме елементите му по следния начин:

`L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …`

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/04/reorder1linked-list.jpg)
```c++
Input: head = [1,2,3,4]
Output: [1,4,2,3]
```
**Example 2:**

![](https://assets.leetcode.com/uploads/2021/03/09/reorder2-linked-list.jpg)
```c++
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 ```

**Constraints:**

- The number of nodes in the list is in the range [1, 5 * 10<sup>4</sup>].
- 1 <= Node.val <= 1000

## Задача 5
### Insert into a Cyclic Sorted List

По даден произволен елемент от цикличен свързан списък, сортиран възходящо, напишете функция, която добавя елемент в списъка така че той да остане сортиран. 

Ако има няколко подходящи места вие изберете къде да вмъкнете новия елемент.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/01/19/example_1_before_65p.jpg)

```c++
Input: head = [3,4,1], insertVal = 2
Output: [3,4,1,2]
Explanation: In the figure above, there is a sorted circular list of three elements. You are given a reference to the node with value 3, and we need to insert 2 into the list. The new node should be inserted between node 1 and node 3. After the insertion, the list should look like this, and we should still return node 3.
```
![](https://assets.leetcode.com/uploads/2019/01/19/example_1_after_65p.jpg)

**Constraints:**

- 0 <= Number of Nodes <= 5 * 10<sup>4
- 10^<sup>6</sup> <= Node.val <= 10<sup>6</sup>
- 10^<sup>6</sup> <= insertVal <= 10<sup>6</sup>



## Задача 6
### Odd Even Linked List

Даден е едносвързан списък. Пренаредете листа така че всички елементи с нечетни индекси да са първи, последвани от елементите с четни индекси и върнете пренаредения лист. 

За да е по-интересно първия елемент се смята за елемент с нечетен индекс, втория - четен и тн.

Използвайте `O(1)` място и `O(n)` време.

**Example 1:**

```c++
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
```
**Example 2:**

```c++
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
 ```

**Constraints:**

- n == number of nodes in the linked list
- 0 <= n <= 10<sup>4</sup>
- -10<sup>6</sup> <= Node.val <= 10<sup>6</sup>