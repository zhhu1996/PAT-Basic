#include<stdio.h>
//得分只有101种情况  把每种得分的人数记录下来就好
int main()
{
    int choose[100000]={0},score[101]={0};
    int n,k,tmp;
    scanf("%d",&n);
    for( int i=0; i<n; i++ )
    {
        scanf("%d",&tmp);
        score[tmp]++;
    }
    scanf("%d",&k);
    for( int i=0; i<k; i++ )
        scanf("%d",&choose[i]);
    for( int i=0; i<k; i++ )
    {
        if( !i ) printf("%d",score[choose[i]]);
        else printf(" %d",score[choose[i]]);
    }
    return 0;
}
