#include<iostream>
#include<cstdio>
#include<iomanip>
/*
公式不难归纳  a[i]*(i+1)*(n-i)
主要是精度损失问题， 三个系数必须都是double类型，不然会造成精度损失
*/
using namespace std;
int main()
{
    double sum,a[100008];
    int n;
    cin>>n;
    sum = 0.0;
    for( int i=0; i<n; i++ ){
        //scanf("%lf",&a[i]);
        cin>>a[i];
    }
    for( int i=0; i<n; i++ ){
    sum += a[i]*(double(i+1))*(double(n-i));
    }
    //printf("%.2f",sum);
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<sum;

}
