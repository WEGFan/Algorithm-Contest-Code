#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << min({a - b - c, a * b - c, a - b * c, a * b * c, a + b + c, a * b + c, a + b * c, a + b - c, a - b + c}) << endl;
    return 0;
}