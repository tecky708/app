#include <iostream>
#include <map>
using namespace std;

int method1(int *arr, int n)
{
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > (n / 2))
        {
            ans = arr[i];
            break;
        }
    }
    return ans;
}

int method2(int *arr, int n)
{
    map<int, int> m;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    for (auto it : m)
    {
        if (it.second > (n / 2))
        {
            ans = it.first;
            break;
        }
    }
    return ans;
}

int method3(int *arr, int n)
{
    int m = arr[0];
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (cnt == 0)
        {
            m = arr[i];
            cnt = 1;
        }
        else if (m == arr[i])
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == m)
        {
            cnt++;
        }
    }
    if (cnt > (n / 2))
    {
        return m;
    }
    return -1;
}

int main()
{
    // int arr[] = {2, 8, 7, 2, 2, 1, 2};
    int arr[] = {2, 8, 7, 2, 1};
    int n = sizeof(arr) / sizeof(int);
    cout << method1(arr, n) << endl;
    cout << method2(arr, n) << endl;
    cout << method3(arr, n) << endl;
    return 0;
}