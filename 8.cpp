#include<iostream>
using namespace std;
//偷啦个懒，另开了个数组哈哈
int main()
{
    int n,m;
    int a[128],b[128];
    cin>>n>>m;
    for( int i=0; i<n; i++ )
    {
         cin>>a[i];
         b[(i+m)%n] = a[i];
    }
    for( int i=0; i<n; i++ )
    {
        if( i ) cout<<" ";
        cout<<b[i];
    }
    return 0;
}
