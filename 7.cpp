#include<iostream>
#include<cmath>
using namespace std;
//先找出所有小于n的素数 然后求相邻的素数之差
int isPrime( int n )
{
    int flag = 1;
    for( int i=2; i<=sqrt(n); i++ )
        if( n%i==0 )
        {
            flag = 0; break;
        }
    return flag;
}
int main()
{
    int prime[100000];
    int i,j,n,cnt,t;
    cin>>n;
    cnt = 0;
    for( i=1; i<=n; i++ )
    {
        if( isPrime(i) )
            prime[cnt++] = i;
    }
    t = 0;
    for( i=1; i<cnt; i++ )
    {
        int d = prime[i]-prime[i-1];
        if( d==2 ) t++;
    }
    cout<<t;

}
