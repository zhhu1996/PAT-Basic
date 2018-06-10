#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int c1,c2,len;
    const int CLK_TCK = 100;
    cin>>c1>>c2;
    //四舍五入
    len = int(1.0*(c2-c1)/100+0.5);
    //注意输出宽度
    cout<<setw(2)<<setfill('0')<<len/3600<<":"<<setw(2)<<setfill('0')<<len%3600/60<<":"<<setw(2)<<setfill('0')<<len%60;
}
