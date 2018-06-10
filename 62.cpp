#include<iostream>
#include<cstdio>
using namespace std;
//用浮点数做除法会损失精度的，应换成整数运算
//题目并没有给定两个分数的大小所以要先判断
int gcd( int n, int m )
{
    if( m==0 ) return n;
    return gcd(m,n%m);
}
int main()
{
    int flag,i,n1,m1,n2,m2,k,temp1,temp2;
    scanf("%d/%d %d/%d %d",&n1,&m1,&n2,&m2,&k);
    if( n1*m2>n2*m1 ){//确保n1/m1<n2/m2
        temp1 = n1; temp2 = m1;
        n1 = n2; m1 = m2;
        n2 = temp1; m2 = temp2;
    }
    i = 0; flag = 0;
    while( i*m1<=n1*k ) i++;
    while( i*m2<n2*k ){
        if( gcd(i,k)==1 )
        {
            if( flag ) printf(" ");
            printf("%d/%d",i,k);
            flag = 1;
        }
        i++;
    }

}
