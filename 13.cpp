#include<iostream>
#include<cmath>
using namespace std;
int isPrime( int n )
{
    int flag = 1;
    for( int i=2; i<=sqrt(n); i++ )
    if( n%i==0 ){
        flag = 0; break;
    }
    return flag;
}

int main()
{
    int a[10086];
    int m,n,cnt,j;
    cin>>m>>n;
    cnt = j = 0;
    for( int i=2; cnt<=n; i++ ){
        if( isPrime(i) )
            a[++cnt] = i;
    }
    for( int i=m; i<=n; i++ )
    {
        if( j ) cout<<" ";
        cout<<a[i];
        j = (j+1)%10;
        if( j==0 ) cout<<endl;
    }
    return 0;
}
