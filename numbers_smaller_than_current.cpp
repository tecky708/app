#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int *method1(int *arr, int n)
{
    int *ans = new int[n];
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (j != i && arr[j] < arr[i])
            {
                cnt++;
            }
        }
        ans[i] = cnt;
    }
    return ans;
}

int *method2(int *arr, int n)
{
    int *temp = new int[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[i];
    }
    sort(temp, temp + n);
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        if (m.find(temp[i]) == m.end())
        {
            m[temp[i]] = i;
        }
    }
    int *ans = new int[n];
    for (int i = 0; i < n; i++)
    {
        ans[i] = m[arr[i]];
    }
    return ans;
}

int *method3(int *arr, int n)
{
    int *temp = new int[100];
    for (int i = 0; i < 100; i++)
    {
        temp[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        temp[arr[i]]++;
    }
    for (int i = 0; i < 100; i++)
    {
        if (i != 0)
        {
            temp[i] = temp[i - 1] + temp[i];
        }
    }
    int *ans = new int[n];
    for (int i = 0; i < n; i++)
    {
        ans[i] = temp[arr[i] - 1];
    }
    return ans;
}

int main()
{
    int arr[] = {8, 1, 2, 2, 3};
    int n = sizeof(arr) / sizeof(int);
    print(arr, n);
    // int *ans = method1(arr, n);
    // int *ans = method2(arr, n);
    int *ans = method3(arr, n);
    print(ans, n);
    return 0;
}