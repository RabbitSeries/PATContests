#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
    string a = "1234";
    string b = a.substr(0,2);
    string c = a.substr(2,2);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    return 0;
}
