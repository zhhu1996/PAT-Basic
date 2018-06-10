#include<iostream>
#include<cstdlib>
using namespace std;
/*指数需要根据+-分情况讨论
将+-与E之间的数字保存起来    根据指数的大小确定小数点的位置和有效位数
*/
int main()
{
    char s[10086],zs[10086];
    int i,j,expon;
    j = 0;
    cin>>s;
    //将+-与E之间的数字保存起来
    for( i=0; s[i]!='E'; i++ ){
        if( s[i]!='+'&&s[i]!='-'&&s[i]!='.' )
            zs[j++] = s[i];
    }
    expon = atoi(s+i+1);
    if( s[0]=='-' ) cout<<"-";
    if( expon>=0 )
    {
        for( i=0; i<j; i++ ){
            cout<<zs[i];
            //当i=j-1的时候不需要输出小数点，否则是需要输出的
            if( i==expon&&i!=j-1 ) cout<<".";
        }
        while( i<=expon ){
            cout<<"0"; i++;
        }
    }
    else{
        expon = -expon;
        cout<<"0.";
        //expon-1个0
        for( i=1; i<expon; i++ ) cout<<"0";
        for( i=0; i<j; i++ ) cout<<zs[i];
    }
}
