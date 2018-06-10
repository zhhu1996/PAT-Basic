#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
//循环不变式
//输出的每个数要求宽度为4
int num[4]={0};
int getNum()
{
    int n = 0;
    for( int i=0; i<4; i++ )
        n = n*10 + num[i];
    return n;
}
void getDigit( int c )
{
	for( int i=0; i<4; i++ ){
		num[i] = c%10;
		c /=10;
	}
}
bool cmpup( int a, int b )
{
    return a<b;
}
bool cmpdw( int a, int b )
{
    return a>b;
}

int main()
{
    int n,a,b,c;
    cin>>n;
    if( n%10==n/1000&&n%10==n%1000/100&&n%10==n%100/10 )
        cout<<n<<" - "<<n<<" = 0000";
    else{
    	c = n;
        do{
            getDigit(c);
            sort(num,num+4,cmpdw);
            a = getNum();
            sort(num,num+4,cmpup);
            b = getNum();
            c = a-b;
            cout<<setw(4)<<setfill('0')<<a<<" - "<<setw(4)<<setfill('0')<<b<<" = "<<setw(4)<<setfill('0')<<c<<endl;
        }while( c!=6174 );
    }
}
