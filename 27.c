#include <stdio.h>
#include <math.h>
//每一行可以放置符号的最大数目可以通过数学公式推导出来:
//每一行末尾的空格不要打印出来 否则会判格式错误
int main()
{
    int i,j,k,n,maxcnt,cnt;
    char c;
    cnt = maxcnt = 0;
    scanf("%d %c",&n,&c);
    maxcnt = (int)(sqrt((n+1)*2*1.0))-1;
    if( maxcnt%2==0 )
        maxcnt--;
    for( i=maxcnt; i>0; i-=2 ){
        for( j=1; j<=(maxcnt-i)/2; j++ )
            printf(" ");
        for( j=1; j<=i; j++ )
            printf("%c",c);
        cnt += i;
        printf("\n");
    }
    for( i=3; i<=maxcnt; i+=2 )
    {
        for( j=1; j<=(maxcnt-i)/2; j++ )
            printf(" ");
        for( j=1; j<=i; j++ )
            printf("%c",c);
        cnt += i;
        printf("\n");
    }
    printf("%d\n",n-cnt);
    return 0;
}
