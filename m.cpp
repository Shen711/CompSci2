#include <string>
#include <iostream>
#include <limits.h>
#include <limits>
#include <vector>
using namespace std;
int main()
{
    int x = 25;
    int *p;
    p = &x;
    *p = 46;
    cout << x << endl;
}