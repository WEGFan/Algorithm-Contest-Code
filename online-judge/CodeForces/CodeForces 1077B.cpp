#include <iostream>

using namespace std;

int arr[107];

int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 2; i <= n - 1; i++)
    {
        if (arr[i - 1] == arr[i + 1] && arr[i - 1] == 1 && arr[i] == 0)
        {
            arr[i + 1] = 0;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}