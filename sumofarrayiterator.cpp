#include<iostream>
using namespace std;
int sum(int* a,int n,int i){
    if(i==n){
        return 0;
    }
    return a[i]+sum(a,n,i+1);

}
int main(){
    int a[]={1,4,5,8};
    int n=sizeof(a)/sizeof(int);
    cout<<sum(a,n,0);
}