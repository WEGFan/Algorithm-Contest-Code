#include <iostream>
#include <algorithm>
using namespace std;

int arr[107][107];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cin >> arr[i][j];
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                arr[i][j] += max(arr[i + 1][j], arr[i + 1][j + 1]);
            }
        }
        cout << arr[0][0] << endl;
    }
    return 0;
}