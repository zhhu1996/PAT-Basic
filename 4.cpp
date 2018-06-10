#include<iostream>
#include<algorithm>
//排序
using namespace std;
struct data{
    char name[12],num[12];
    int score;
}Stu[100];
bool cmp( const struct data a, const struct data b )
{//降序，bool类型的返回值
    return a.score>b.score;
}

int main()
{
    int n;
    cin>>n;
    for( int i=0; i<n; i++ ){
        cin>>Stu[i].name>>Stu[i].num>>Stu[i].score;
    }
    sort(Stu,Stu+n,cmp);
    cout<<Stu[0].name<<" "<<Stu[0].num<<endl;
    cout<<Stu[n-1].name<<" "<<Stu[n-1].num;
}
