/*cout<<setiosflags(ios::fixed)<<setprecision(2);//需要头文件#include <iomanip>
然后再输出实数类型变量即可以保留2位小数输出了，当然你要保留三位小数，setprecision(3)就行。
setprecision是指设置输出精度，当没有
cout<<setiosflags(ios::fixed)时，输出格式是数据的有效位数，例如
float a = 123.666;
cout<<setprecision(5)<<a;
将输出123.67（注意这里，它会四舍五入）。如果setprecision里的参数小于整数位数，将以指数形式输出，例如
float a = 123.666;
cout<<setprecision(2)<<a;
将输出1.2e+002。
setiosflags(ios::fixed)是指以固定的浮点显示，当setiosflags(ios::fixed)和serprecision(n)两个一起用时就表示保留n位小数输出。
这里还要注意，每次输出只要设置一次就行了(同一次cout)，因为这两个的作用范围是后续对象，而不是仅对后一个对象起作用。
*/
/*
FLOAT/DOUBLE同类型数的大小比较不能直接用==  >,<最方便
*/
/*
a2有可能结果为0但是是存在该类数字的
*/
#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int main()
{
    int a1,a2,a3,a5,n,ta2,cnta2,cnta4;
    int a[1024];
    float a4;
    a1 = a2 = a3 = a5 = cnta2 = cnta4 = 0; a4 = 0.0;
    ta2 = 1;
    cin>>n;
    for( int i=0; i<n; i++ ){
        cin>>a[i];
        if( a[i]%5==0&&a[i]%2==0 ) a1 += a[i];
        if( a[i]%5==1 ) { a2 += ta2*a[i]; ta2 = -ta2; cnta2++; }
        if( a[i]%5==2 )  a3++;
        if( a[i]%5==3 ) { cnta4++; a4 += 1.0*a[i]; }
        if( a[i]%5==4 ) { a5 = max(a5,a[i]); }
    }
    a4 = a4/cnta4;
    if( a1!=0 ) cout<<a1;
    else cout<<"N";
    cout<<" ";
    if( a2!=0||cnta2 ) cout<<a2;
    else cout<<"N";
    cout<<" ";
    if( a3!=0 ) cout<<a3;
    else cout<<"N";
    cout<<" ";
    if( a4>0.0 ) cout<<setiosflags(ios::fixed)<<setprecision(1)<<a4;
    else cout<<"N";
    cout<<" ";
    if( a5!=0 ) cout<<a5;
    else cout<<"N";
}
