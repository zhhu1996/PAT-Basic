#include<iostream>
using namespace std;
//1000位正整数肯定要用字符串了~
//需要考虑A为1位正整数并且<=B的情况
int main()
{
    char a[1024],q[1024];
    int b,r,j,t,i;
    cin>>a>>b;
    i = j = t = 0;
    for( i=0; a[i]; i++ ){
        t = t*10 + a[i]-'0';
        if( i==0&&t/b==0 ) continue;//循环处理的时候第一位需要单独处理
        q[j++] = t/b + '0';
        t = t%b;
    }
    if( i==1 ) cout<<(a[0]-'0')/b<<" "<<(a[0]-'0')%b;
    else{
        q[j] = '\0';
        cout<<q<<" "<<t;
    }
}
