#include<iostream>
#include<cstring>
using namespace std;
struct stu{
    char num[15];
    int Rposition;
}Student[1001];
int main()
{
    int n,m,p1,p2,f[1001];
    char tnum[15];
    cin>>n;
    for( int i=1; i<=n; i++ )
    {
        cin>>tnum>>p1>>p2;
        Student[p1].Rposition = p2;
        strcpy(Student[p1].num,tnum);
    }
    cin>>m;
    for( int i=0; i<m; i++ ){
        cin>>p1;
        cout<<Student[p1].num<<" "<<Student[p1].Rposition<<endl;
    }
}
