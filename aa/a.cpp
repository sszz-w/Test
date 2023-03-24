#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg{"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    int a;

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cin >> a;
    return 0;
}