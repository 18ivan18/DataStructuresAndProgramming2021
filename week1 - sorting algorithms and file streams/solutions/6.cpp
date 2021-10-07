#include <iostream>
#include <fstream>

int main()
{
    std::ifstream is("i.input");
    std::ofstream os("o.output");
    char c;
    while (is.get(c))
    {
        os.put(c);
    }
}