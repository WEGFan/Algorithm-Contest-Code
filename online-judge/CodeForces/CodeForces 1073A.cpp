#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    if (n == 1)
    {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
        {
            cout << "YES" << endl;
            cout << s[i - 1] << s[i] << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}