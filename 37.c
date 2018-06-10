#include<stdio.h>

//比较大小   减法的借位不能忽略
void Excute( int g1, int s1, int k1, int g2, int s2, int k2 )//2大的
{
    int carrysg=0,carryks=0;
    if( k2<k1 )
    {
        k2 = k2+29-k1;
        carryks = -1;
    }else{
        k2 -= k1;
        carryks = 0;
    }
    if( s2+carryks<s1 ){
        s2 = s2+17+carryks-s1;
        carrysg = -1;
    }else{
        s2 = s2+carryks-s1;
        carrysg = 0;
    }
    g2 = g2+carrysg-g1;
    printf("%d.%d.%d",g2,s2,k2);
}
int main()
{
    int g1,s1,k1,g2,s2,k2;
    scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
    if( (g1<g2) || (g1==g2&&s1<s2) || (g1==g2&&s1==s2&&k1<k2) ){//P<A
        Excute(g1,s1,k1,g2,s2,k2);
    }
    else{//P>=A
        if( g1!=g2 || s1!=s2 || k1!=k2 )//P!=A
            printf("-");
        Excute(g2,s2,k2,g1,s1,k1);
    }
}
