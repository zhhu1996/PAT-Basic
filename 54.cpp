#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
bool isLegal( char s[], int n )
{//先判断第一位，只能是数字或者是-；第二位往后只能是数字或者小数点(小数点只能有一个)
 //完成以上输入后直接用atof将字符串转换为double变量与1000比较
 //在比较的时候还要确保小数位数不超过两位(如果输入字符串存在小数点那么一定要进行小数位数判断)
    bool flag = true;
    int pointcnt,pointit,rightnum;
    double num = 0.0;
    pointcnt = pointit = rightnum = 0;
    //base = 1;
    //判断第一位
    if( (s[0]<'0'||s[0]>'9')&&s[0]!='-' ) flag = false;
    for( int i=1; i<n; i++ ){
        if( (s[i]<'0'||s[i]>'9') ){
            if( s[i]=='.' ){
                pointcnt++;
                pointit = i;
                if( pointcnt>1 ){
                    flag = false; break;
                }
            }
            else{
                flag = false; break;
            }
        }
    }
    if( flag ){
        if( pointit>0 ){
            for( int j=pointit+1; j<n; j++ )
                rightnum++;
            if( rightnum>2 ) flag = false;
        }
        num = atof(s);
        if( abs(num)>1000 ) flag = false;
    }
    return flag;


}
int main()
{
    int n,k;
    double sum,avg;
    char s[110][110];
    cin>>n;
    k = 0;
    sum = avg = 0.0;
    for( int i=0; i<n; i++ )
    {
        cin>>s[i];
        if( isLegal(s[i],strlen(s[i])) ) { k++; sum+=atof(s[i]);}
        else{
            cout<<"ERROR: "<<s[i]<<" is not a legal number"<<endl;
        }
    }
    if( k==0 ) cout<<"The average of 0 numbers is Undefined"<<endl;
    else if( k==1 ) cout<<"The average of 1 number is "<<setiosflags(ios::fixed)<<setprecision(2)<<sum<<endl;
    else cout<<"The average of "<<k<<" numbers is "<<setiosflags(ios::fixed)<<setprecision(2)<<sum/k<<endl;
}
