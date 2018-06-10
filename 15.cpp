#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct student{
    int num,de,cai,total;
}Stu[100008],Stu1[100008],Stu2[100008],Stu3[100008],Stu4[100008];

//排序函数
//输入输出必须用scanf printf    cin cout会超时
//还有种更方便的方法是不用开四个数组，直接在结构体中新建一个类别的属性，将类别也写进sort函数
//注意 结构体之间可以直接赋值
bool cmp( struct student s1, struct student s2 )
{
    bool ret;
    if( s1.total!=s2.total ) ret = s1.total>s2.total;
    else{
        if( s1.de!=s2.de ) ret = s1.de>s2.de;
        else ret = s1.num<s2.num;
    }
    return ret;
}
int main()
{
    int n,l,h,q,w,e,r,cnt;
    //cin>>n>>l>>h;
    scanf("%d %d %d",&n,&l,&h);
    q = w =e = r = cnt = 0;
    for( int i=0; i<n; i++ )
    {
        //cin>>Stu[i].num>>Stu[i].de>>Stu[i].cai;
        scanf("%d %d %d",&Stu[i].num,&Stu[i].de,&Stu[i].cai);
        Stu[i].total = Stu[i].de + Stu[i].cai;
    }
    for( int i=0; i<n; i++ )
    {
        if( Stu[i].de>=l && Stu[i].cai>=l ){
            cnt++;
            if( Stu[i].de>=h && Stu[i].cai>=h )
                Stu1[q++] = Stu[i];
            else if( Stu[i].de>=h && Stu1[i].cai<h )
                Stu2[w++] = Stu[i];
            else if( Stu[i].de<h && Stu[i].cai<h && Stu[i].de>=Stu[i].cai )
                Stu3[e++] = Stu[i];
            else
                Stu4[r++] = Stu[i];
        }
    }
    sort(Stu1,Stu1+q,cmp);
    sort(Stu2,Stu2+w,cmp);
    sort(Stu3,Stu3+e,cmp);
    sort(Stu4,Stu4+r,cmp);
    cout<<cnt<<endl;
    for( int i=0; i<q; i++ )
        printf("%d %d %d\n",Stu1[i].num,Stu1[i].de,Stu1[i].cai);
        //cout<<Stu1[i].num<<" "<<Stu1[i].de<<" "<<Stu1[i].cai<<endl;
    for( int i=0; i<w; i++ )
        printf("%d %d %d\n",Stu2[i].num,Stu2[i].de,Stu2[i].cai);
        //cout<<Stu2[i].num<<" "<<Stu2[i].de<<" "<<Stu2[i].cai<<endl;
    for( int i=0; i<e; i++ )
        printf("%d %d %d\n",Stu3[i].num,Stu3[i].de,Stu3[i].cai);
        //cout<<Stu3[i].num<<" "<<Stu3[i].de<<" "<<Stu3[i].cai<<endl;
    for( int i=0; i<r; i++ )
        printf("%d %d %d\n",Stu4[i].num,Stu4[i].de,Stu4[i].cai);
        //cout<<Stu4[i].num<<" "<<Stu4[i].de<<" "<<Stu4[i].cai<<endl;

}
