# F.A.Q.

## Какво беше това сложност?

Θ(g(n)) = { f(n) | ∃c<sub>1</sub>, c<sub>2</sub> > 0, ∃n<sub>0</sub> : ∀n ≥ n<sub>0</sub>, 0 ≤ c<sub>1</sub>.g(n) ≤ f(n) ≤ c<sub>2</sub>.g(n) }
	
f(n) ≈ g(n) ⇔ f(n) = Θ(g(n)) 

### Нестрога горна граница

O(g(n)) = { f(n) | ∃c > 0, ∃n<sub>0</sub> : ∀n ≥ n<sub>0</sub>, 0 ≤ f(n) ≤ c.g(n) }

f(n) <= g(n) ⇔ f(n) = O(g(n)) 
	
### Нестрога долна граница
Ω(g(n)) = { f(n) | ∃c > 0, ∃n<sub>0</sub> : ∀n ≥ n<sub>0</sub>, 0 ≤ c.g(n) ≤ f(n) }

f(n) ≺ g(n) ⇔ f(n) = o(g(n)) 
	

### Строга горна граница

o(g(n)) = { f(n) | ∀c > 0, ∃n<sub>0</sub> : ∀n ≥ n<sub>0</sub>, 0 ≤ f(n) < c.g(n) }

f(n) >= g(n) ⇔ f(n) = Ω(g(n)) 
	
### Строга долна граница

ω(g(n)) = { f(n) | ∀c > 0, ∃n<sub>0</sub> : ∀n ≥ n<sub>0</sub>, 0 ≤ c.g(n) < f(n) }
	
f(n) ≻ g(n) ⇔ f(n) = ω(g(n)) 

## Кои бяха основните сложности с примери?

Big O Notation | Name | Example(s)
------------ | ------------- | ---------
O(1) | Constant | **Odd or Even number** <br>**Look-up table (on average)**
O(log n) | Logarithmic | **Finding element on sorted array with binary search**
O(n) | Linear | **Find max element in unsorted array**
O(n log n) | Linearithmic | **Sorting elements in array with merge sort**
O($n^2$) | Quadratic | **Duplicate elements in array (naïve)**
O($n^3$) |	Cubic | **3 variables equation solver**
O($2^n$) |	Exponential	| **Find all subsets**
O(n!) | Factorial | **Find all permutations of a given set/string**

## Защо ме вълнува сложнстта?

| n | O(1) | O(log n) | O(n) | O(n log n) | O($n^2$) | O($2^n$) | O(n!)
| - | - | - | - | - | - | - | - 
| 1	        | < 1 sec |	< 1 sec |	< 1 sec	| < 1 sec	| < 1 sec	| < 1 sec	            | < 1 sec
| 10	        | < 1 sec |	< 1 sec |	< 1 sec	| < 1 sec	| < 1 sec	| < 1 sec	            | 4 sec
| 100	        | < 1 sec |	< 1 sec |	< 1 sec	| < 1 sec	| < 1 sec	| 40170 trillion years	| > vigintillion years
| 1,000	    | < 1 sec |	< 1 sec |	< 1 sec	| < 1 sec	| < 1 sec	| > vigintillion years	| > centillion years
| 10,000	    | < 1 sec |	< 1 sec |	< 1 sec	| < 1 sec	| 2 min	    | > centillion years	| > centillion years
| 100,000	    | < 1 sec |	< 1 sec |	< 1 sec	| 1 sec	    | 3 hours	| > centillion years	| > centillion years
| 1,000,000	| < 1 sec |	< 1 sec |	1 sec	| 20 sec	| 12 days	| > centillion years	| > centillion years

## Какво беше това потоци?

Йерархия на класовете за работа с потоци:

![](https://media.geeksforgeeks.org/wp-content/uploads/20190509103056/Heirarchy-of-Stream-Classess-in-iostream.h-1024x636.jpg)

## Как се отваря и затваря поток?

### Output stream
- ostream
- ofstream

### Input stream
- istream
- ifstream

Използваме метода:
```c++
void open(const char *filename, ios::openmode mode);
```
за отваряне на файл, или конструктора на обекта. По подразбиране файлът отворен чрез istream/ostream се отваря с вдигнат флаг за писане/четене. Ако файл за четене не съществува имаме грешка. Ако файл за писане не съществува такъв се създава. При работа с потоци добрата практика е да проверим дали потокът е в добро състояние след операция, която може да даде грашка.

### Кои бяха тези флагове за отваряне на файлове?

| № | Mode Flag & Description
| - | -
| 1 |	ios::app <br>Append mode. All output to that file to be appended to the end.
| 2 |	ios::ate<br>Open a file for output and move the read/write control to the end of the file.
| 3 |	ios::in<br>Open a file for reading.
| 4 |	ios::out<br>Open a file for writing.
| 5 |	ios::trunc<br>If the file already exists, its contents will be truncated before opening the file.
| 6 | ios::binary<br> This causes the file to be accessed as a binary file.   

Всеки поток трябва да се затвори след като приключи неговото използване. Използваме следния метод:

```c++
void close();
```

Можем да пишем или четем използвайки потоци с предефинираните оператори `>>` (shift right) и `<<` (shift left), както и с методите
```c++
ostream& put (char c);

// single character (1)	
int get();
istream& get (char& c);
// c-string (2)	
istream& get (char* s, streamsize n);
istream& get (char* s, streamsize n, char delim);
// stream buffer (3)	
istream& get (streambuf& sb);
istream& get (streambuf& sb, char delim);

istream& getline (char* s, streamsize n );
istream& getline (char* s, streamsize n, char delim );
```

```c++
#include <iostream> // input-output stream
#include <fstream> // file stream

int main() {
    ofstream os;
    os.open("file.dat", ios::out | ios::trunc);
    if(!os) {
        // handle error
    }
    
    fstream fs("file.dat", ios::out | ios::in);
    if(!fs) {
        // handle error
    }
    
    os.close();
    fs.close();
}
```

istream и ostream дават достъп до методи за позициониране на указателя за позицията във файл. Тези методи са seekg ("seek get") за istream и seekp ("seek put") за ostream.

Можем да използваме ios::beg (по подразбиране) за позициониране относно началото на потока, ios::cur за позициониране относно текущата позиция в потока или ios::end за позициониране относно края на потока.

```c++
// position to the nth byte of fileObject (assumes ios::beg)
fileObject.seekg(n);

// position n bytes forward in fileObject
fileObject.seekg(n, ios::cur);

// position n bytes back from end of fileObject
fileObject.seekg(n, ios::end);

// position at end of fileObject
fileObject.seekg(0, ios::end);
```

## Как се правеше това с двоичните файлове?
```c++
struct Person
{
  char name[50];
  int age;
  char phone[24];
};

Person me = {"Robert", 28, "364-2534"};
Person book[30];
int x = 123;
double fx = 34.54;
ofstream outfile;
outfile.open("junk.dat", ios::binary | ios::out);
outfile.write(&x, sizeof(int)); // sizeof can take a type
outfile.write(&fx, sizeof(fx)); // or it can take a variable name
outfile.write(&me, sizeof(me));
outfile.write(book, 30*sizeof(Person))
outfile.close();

// -------------------------

// It is the responsibility of the programmer to make sure that the buffer is large enough to hold all the data that is being read. The following code segment would probably result in a crash unless the size of a integer was 7 bytes (unlikely number):
int x;
ifstream infile;
infile.open("silly.dat", ios::binary | ios::in)
infile.read(&x, 7); // reads 7 bytes into a cell that is either 2 or 4

// ----------------------

int x;
streampos pos;
ifstream infile;
infile.open("silly.dat", ios::binary | ios::in);
infile.seekp(243, ios::beg); // move 243 bytes into the file
infile.read(&x, sizeof(x));
pos = infile.tellg();
cout << "The file pointer is now at location " << pos << endl;
infile.seekp(0,ios::end); // seek to the end of the file
infile.seekp(-10, ios::cur); // back up 10 bytes
infile.close();
```

## Как се четяха и пишеха класове в двоичен файл?
```c++
#include <iostream.h>
#include <stdlib.h>
#include <fstream.h>

class Student
{
  private:
    int number;
    char name[50];
    float gpa;
  public:
    Student(int n, const char *s, float g);
    void save(ofstream& of);
    void load(ifstream& inf);
};

void Student::save(ofstream& of)
{
  of.write(&number, sizeof(number));
  of.write(name, sizeof(name));
  of.write(&gpa, sizeof(gpa));
}

void Student::load(ifstream& inf)
{
  inf.read(&number, sizeof(number));
  inf.read(name, sizeof(name));
  inf.read(&gpa, sizeof(gpa));
}

main()
{
  Student me(11321, "Myself", 4.3);
  ofstream myfile;
  myfile.open("silly.dat", ios::binary | ios::out);
  me.save(myfile);
  myfile.close();
}
```

## Какво означава един сортиращ алгоритъм да е stable и in place?
An in-place sorting algorithm directly modifies the list that it receives as input instead of creating a new list that is then modified. An example of an in-place sorting algorithm is bubble sort that simply swaps the elements of the array received as input.

A stable sorting algorithm leaves elements in the list that have equal sorting keys at the same places that they were in the input. Bubble sort is a stable algorithm, whereas e.g. quick sort isn't.

![](https://qph.fs.quoracdn.net/main-qimg-8a1ad8261a2cabbfae5bf8d9f7a0732d)

# Задача 1
Декларирайте клас `Sort` и класове наследници имплементиращи 
- bubble sort
- insertion sort
- selection sort 
- merge sort 
- quick sort

и посочете техните сложности в средния и най-лошия случай. Определете дали те са in place и stable. За самото сортиране използвайте оператор `()`.


<details><summary><b>
Bubble Sort</b></summary>
<p>

![](https://www.programmingsimplified.com/images/c/bubble-sort.gif)
</p>
</details>

<details><summary><b>
Insertion Sort</b></summary>
<p>

![](
https://i.pinimg.com/originals/92/b0/34/92b034385c440e08bc8551c97df0a2e3.gif)
</p>
</details>

<details><summary><b>
Selection Sort</b></summary>
<p>

![](
https://i2.wp.com/algorithms.tutorialhorizon.com/files/2019/01/Selection-Sort-Gif.gif?ssl=1)
</p>
</details>

<details><summary><b>
Анализ</b></summary>
<p>

| \* | Merge sort | Quick sort | Counting sort | Bubble sort | Selection sort | Insertion sort |
| --- | --- | --- | --- | --- | --- | --- |
| BC | *O(nlogn)* | *O(nlogn)* | *O(n + k)* | *O(n)* | *O($n^2$)* | *O(n)* |
| AC | *O(nlogn)* | *O(nlogn)* | *O(n + k)* | *O($n^2$)* | *O($n^2$)* | *O($n^2$)* |
| WC | *O(nlogn)* | *O($n^2$)* | *O(n + k)* |*O($n^2$)*  | *O($n^2$)* | *O($n^2$)* |
| Memory | *O(n)* | *O(1)* | *O(n + k)* | *O(1)* | *O(1)* | *O(1)* |
| Stability | :heavy_check_mark: | ❌ | ❌ | :heavy_check_mark: | ❌ | :heavy_check_mark: |
</p>
</details>
 

# Задача 2
По дадени два символни низа `s` и `t`, върнете `true` ако `t` е анаграма на `s`, и `false` в противен случай.

 

**Example 1:**
```c++
Input: s = "anagram", t = "nagaram"
Output: true
```
**Example 2:**
```c++
Input: s = "rat", t = "car"
Output: false
 ```

**Constraints:**

- `1 <= s.length, t.length <= 5 * 10`<sup>`4`
- `s` and `t` consist of lowercase English letters.
 
# Задача 3
По даден масив от n различни числа в интервал [0, n], върнете единственото число в този интервал, което не се съдържа в масива.

 

**Example 1:**
```c++
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
```
**Example 2:**
```c++
Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
```
**Example 3:**
```c++
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
```
**Example 4:**
```c++
Input: nums = [0]
Output: 1
Explanation: n = 1 since there is 1 number, so all numbers are in the range [0,1]. 1 is the missing number in the range since it does not appear in nums.
 ```

**Constraints:**

- `n == nums.length`
- `1 <= n <= 10`<sup>`4`
- `0 <= nums[i] <= n`
- All the numbers of `nums` are **unique**.
 

# Задача 4
По даден символен низ `s`, сортирайте го на базата на честотата на срещане на всеки символ. Честотата на срещане на един символ е броят пъти, които той се среща в символния низ.

Върнете сортирания низ. Ако има няколко възможни отговора, върнете, който и да е от тях.

 

**Example 1:**
```c++
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
```
**Example 2:**
```c++
Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
```
**Example 3:**
```c++
Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 ```

**Constraints:**

- `1 <= s.length <= 5 * 10`<sup>`5`
- `s` consists of uppercase and lowercase English letters and digits.

# Задача 5
По даден масив с големина n, върнете елементът, който се среща повече от ⌊n / 2⌋ пъти. Нека предположим, че такъв елемент винаги съществува.


**Example 1:**
```c++
Input: nums = [3,2,3]
Output: 3
```
**Example 2:**
```c++
Input: nums = [2,2,1,1,1,2,2]
Output: 2
 ```

Constraints:

- n == nums.length
- 1 <= n <= 5 * 10<sup>4
- 2<sup>31</sup> <= nums[i] <= 2<sup>31</sup> - 1
 

# Задача 6
Отворете един файл за четене и един за писане. Запишете съдържанието на пръвия във втория.

# Задача 7

Имплементирайте следните функции и определете тяхната сложност.

- `bool isOdd(int);`
- `int findMax(int*, int)`;
- `bool hasDuplicates(int*, int)`
- Намерете всички решения на уравнението: 3x + 9y + 8z = 79, където x, y, z < n <br>
`void findXYZ(int);`
- `int indexOfInASortedArray(int*, int, int);`
- `void powerset(char*);`
- `void getPermutations(char*)`
