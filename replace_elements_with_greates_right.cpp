#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> method1(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int max = -1;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] > max)
            {
                max = arr[j];
            }
        }
        arr[i] = max;
    }
    return arr;
}

vector<int> method2(vector<int> arr)
{
    int max;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (i == arr.size() - 1)
        {
            max = arr[i];
            arr[i] = -1;
        }
        else
        {
            int temp = arr[i];
            arr[i] = max;
            if (temp > max)
            {
                max = temp;
            }
        }
    }
    return arr;
}

int main()
{
    vector<int> arr;
    arr.push_back(17);
    arr.push_back(18);
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(1);
    print(arr);
    print(method1(arr));
    print(method2(arr));
    return 0;
}