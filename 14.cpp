#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
char *day[] = { "zero","MON","TUE","WED","THU","FRI","SAT","SUN"};
//c++输出 不足补0: cout<<setw(2)<<setfill('0')<<i;
//输出秒的时候  必须是字母相等输出下标
using namespace std;

int main()
{
    char s1[66],s2[66],s3[66],s4[66];
    int len1,len2,len3,len4,i;
    cin>>s1>>s2>>s3>>s4;
    len1 = strlen(s1);
    len2 = strlen(s2);
    len3 = strlen(s3);
    len4 = strlen(s4);
    len1 = min(len1,len2);
    len3 = min(len3,len4);
    for( i=0; i<len1; i++ ){
        if( s1[i]==s2[i]&&s1[i]>='A'&&s1[i]<='G' ){
            cout<<day[s1[i]-'A'+1]<<" ";
            break;
        }
    }
    i++;
    for( ; i<len1; i++ ){
        if( s1[i]==s2[i] ){
            if( s1[i]>='0'&&s1[i]<='9' ){
                cout<<"0"<<s1[i]<<":";
                break;
            }
            else if( s1[i]>='A'&&s1[i]<='N' ){
                cout<<(s1[i]-'A'+10)<<":";
                break;
            }
        }
    }
    for( i=0; i<len3; i++ ){
        if( s3[i]==s4[i]&&((s3[i]>='a'&&s3[i]<='z')||(s3[i]>='A'&&s3[i]<='Z')) )
            cout<<setw(2)<<setfill('0')<<i;
    }
}
