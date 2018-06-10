#include<iostream>
#include<algorithm>
/*
先排序再比较
如果使用暴力算法的话必定会超时
样例：
10 8
2 3 20 4 5 1 6 7 8 9
排序过后
1 2  3 4 5 6 7 8 9 20
第一轮循环 i=0 j=8 cnt=8
开始第二轮的时候 i=1 j=i+cnt=8
前一轮的迭代使得这cnt个数一定能保证M<=m*p
*/
/*注意两个数相乘可能会超出int范围  需要用更大精度的类型*/
using namespace std;
bool cmp( long long a, long long b )
{
    return a<b;
}
int main()
{
    int n,p,cnt;
    long long a[100086];
    cin>>n>>p;
    for( int i=0; i<n; i++ )
        cin>>a[i];
    sort(a,a+n,cmp);
    cnt = 0;
    for( int i=0; i<n; i++ )
        for( int j=i+cnt; j<n; j++ )
        {
            if( a[j]-a[i]*p>0 ) break;
            if( cnt<j-i+1 ) cnt = j-i+1;
        }
    cout<<cnt;
}
