#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    /*
    string line;
    line = "1" + "abc" + "2" + "asd";
    cout << line << endl;
    */

    auto v = vector<int>{1, 2, 3};
    std::copy(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "));

    vector<string> v1{"abc", "sad", "ASD"};
    vector<int> v2{1, 2, 3};

    cout << v1 << endl;
    cout << v2;
    return 0;
}
