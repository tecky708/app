#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int i,t,a,b,c,flag,cut;
    cin>>t;
    int arr[3];
    for(i=0;i<t;i++)
    {
        cin>>arr[0]>>arr[1]>>arr[2];
        sort(arr,arr+3);
        if (arr[1]% arr[0]==0 && arr[2] % arr[0] == 0 && (arr[1] / arr[0]) + (arr[2] / arr[0]) - 2 <= 3)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    return 0;
}