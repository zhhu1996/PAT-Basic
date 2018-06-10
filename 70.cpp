#include<iostream>
#include<algorithm>
using namespace std;
/*
每次都会将两段绳子之和除2，第i段绳子会除以n-i次
要想最后的和最大，必须是升序排列
*/
bool cmp( int a, int b )
{
    return a<b;
}
int main()
{
    int n,result,a[10008];
    cin>>n;
    for( int i=0; i<n; i++ )
        cin>>a[i];
    sort(a,a+n,cmp);
    result = a[0];
    for( int i=1; i<n; i++ )
        result = (result+a[i])/2;
    cout<<result;
}
