#include<iostream>
#include<algorithm>
using namespace std;
/*
乱序数组与升序数组相同下标i的对应元素相等并且是0~i子串中的最大值即能保证是主元
最后要输出换行
*/
bool cmp( int a, int b )
{
    return a<b;
}
int main()
{
    int n,j,maxnum,a[100008],b[100008],c[100008];
    cin>>n;
    j = maxnum = 0;
    for( int i=0; i<n; i++ ){
        cin>>a[i];
        b[i] = a[i];
    }
    sort(b,b+n,cmp);
    for( int i=0; i<n; i++ ){
        if( a[i]==b[i]&&a[i]>maxnum )
            c[j++] = a[i];
        if( maxnum<a[i] ) maxnum = a[i];
    }
    cout<<j<<endl;
    for( int i=0; i<j; i++ ){
        if( i ) cout<<" ";
        cout<<c[i];
    }
    cout<<endl;
}
