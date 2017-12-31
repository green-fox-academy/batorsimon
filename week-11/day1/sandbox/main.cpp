#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct
{
    string a;
    string b;
    string c;
}Mystruct;

Mystruct myfun();

int main()
{
    /*
    string line;
    line = "1" + "abc" + "2" + "asd";
    cout << line << endl;

    not working !
    */

    /*
    auto v = vector<int>{1, 2, 3};
    std::copy(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "));

    not working!!
    */

    /*
    vector<string> v1{"abc", "sad", "ASD"};
    vector<int> v2{1, 2, 3};

    cout << v1 << endl;
    cout << v2;

    not working !!
    */

    Mystruct ms2;
    ms2 = myfun();
    cout << "Name: " << ms2.a << " Year: " << ms2.b << " Length: " << ms2.c << endl;

    return 0;
}


Mystruct myfun()
{
    string a;
    string b;
    string c;
    Mystruct ms;

    a = "name";
    b = "year";
    c = "length";
    ms.a = a;
    ms.b = b;
    ms.c = c;

    return(ms);
}
