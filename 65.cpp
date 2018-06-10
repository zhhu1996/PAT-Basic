#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
/*
设置一个结构体表示配对
flag初始化为-1，如果是夫妻的话双方都改成0，
在查询的时候对每个id对应的flag++，这样就能区分开三种数据：不属于任何夫妻对的id(flag=-1)，
单方出现而爱人未出现的id(flag不全为1)，双方都出现的id(flag全为1)
*/
struct stu{
    int nextid;
    int flag;
}Student[100000];
bool cmp( int a, int b )
{
    return a<b;
}
int main()
{
    int n,m,t1,t2,j,num[100000],rightnum[100000];
    cin>>n;
    for( int i=0; i<100000; i++ )
        Student[i].flag = -1;

    for( int i=0; i<n; i++ ){
        cin>>t1>>t2;
        Student[t1].flag++; Student[t1].nextid = t2;
        Student[t2].flag++; Student[t2].nextid = t1;
    }
    cin>>m;
    for( int i=0; i<m; i++ ){
        cin>>num[i];
        Student[num[i]].flag++;
    }
    j = 0;
    for( int i=0; i<m; i++ ){
        t1 = num[i];
        if( Student[t1].flag==1 && Student[Student[t1].nextid].flag==1 ) continue;
        else rightnum[j++] = num[i];
    }
    sort(rightnum,rightnum+j,cmp);
    cout<<j<<endl;
    for( int i=0; i<j; i++ )
    {
        if( i ) cout<<" ";
        cout<<setw(5)<<setfill('0')<<rightnum[i];
    }
}
