#include <iostream>
#include <cassert>
#include <cstring>
#include "./Sorts/BubbleSort.cpp"

bool isAnagram(char *s, char *t)
{
    BubbleSort<char> bs;
    bs(s, strlen(s));
    bs(t, strlen(t));
    for (size_t i = 0; i < strlen(s); i++)
    {
        if (s[i] != t[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char s[] = "anagram", t[] = "nagaram";
    assert(isAnagram(s, t) == true);
    char s1[] = "rat", t1[] = "car";
    assert(isAnagram(s1, t1) == false);
}