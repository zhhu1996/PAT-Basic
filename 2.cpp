#include<iostream>
using namespace std;
char *str[10] = {"ling","yi","er","san","si","wu",
               "liu","qi","ba","jiu"};
//用字符串数组会方便点
int main()
{
    int i,j,sum;
    int n[108];
    i = sum = j =0;
    char s[128];
    cin>>s;
    while( s[i] ){
        sum += s[i]-'0';
        i++;
    }
    while( sum ){
        n[j] = sum%10;
        sum /= 10;
        j++;
    }
    for( i=j-1; i>=0; i-- ){
        cout<<str[n[i]];
        if( i ) cout<<" ";
    }
}
