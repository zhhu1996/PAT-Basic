#include<iostream>
#include<iomanip>
#include<cmath>
/*
setw(4)<<setfill('0')   只对下一项输出起作用
setiosflags(ios::fixed)<<setprecision(4)    对之后所有的输出都起作用
*/
using namespace std;
struct stu{
    int flag;
    int therank;
}Student[10000];
bool isPrime( int n )
{
    bool flag = true;
    for( int i=2; i<=sqrt(n); i++ )
    if( n%i==0 ){
        flag = false; break;
    }
    return flag;
}
int main()
{
    char *str[] = {"Mystery Award","Minion","Chocolate","Are you kidding?","Checked"};
    int n,k,query;
    cin>>n;
    for( int i=0; i<10000; i++ )
        Student[i].flag = Student[i].therank = -1;
    for( int i=0; i<n; i++ ){
        cin>>query;
        Student[query].flag = 0;
        Student[query].therank = i+1;
    }
    cin>>k;
    for( int i=0; i<k; i++ ){
        cin>>query;
        if( Student[query].flag==-1 ) cout<<setw(4)<<setfill('0')<<query<<": "<<str[3]<<endl;
        else if( Student[query].flag==0&&Student[query].therank==1 ){
            cout<<setw(4)<<setfill('0')<<query<<": "<<str[0]<<endl;
            Student[query].flag = 1;
        }
        else if( Student[query].flag==0&&isPrime(Student[query].therank) ){
            cout<<setw(4)<<setfill('0')<<query<<": "<<str[1]<<endl;
            Student[query].flag = 1;
        }
        else if( Student[query].flag==1 )
            cout<<setw(4)<<setfill('0')<<query<<": "<<str[4]<<endl;
        else{
            cout<<setw(4)<<setfill('0')<<query<<": "<<str[2]<<endl;
            Student[query].flag = 1;
        }
    }
}
