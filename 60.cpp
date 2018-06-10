#include<iostream>
#include<algorithm>
using namespace std;
bool cmp( int a, int b )
{
    return a>b;
}
int main()
{
    int n,maxnum,l,r,m,cnt,a[100008];
    cin>>n;
    for( int i=0; i<n; i++ )
        cin>>a[i];
    sort(a,a+n,cmp);
    maxnum = 0;
    for( int i=0; i<n; i++ ){//降序排列
        //a[i]是0到i子序列中的最小值,i+1是大于a[i]的天数
        //a[i]>i+1 就能保证有E天超过E，遍历一遍就能找到最大的E
        if( a[i]>i+1 ) maxnum = i+1;
    }

    cout<<maxnum;
}
