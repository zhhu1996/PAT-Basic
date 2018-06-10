#include <stdio.h>
#include <string.h>
//(P左边的A的个数)*(PT中间A的个数) = T右边的A的个数
int JudgeIsPat( char s[] )
{
    int i,j,len,cntpre,cntin,cntpost,cntP,cntA,cntT;
    int flag = 1;
    len = strlen(s);
    cntin = cntpost = cntpre = 0;
    cntA = cntP = cntT = 0;
    for( i=0; i<len; i++ )
    {
        if( s[i]!='A' && s[i]!='P' && s[i]!='T' )
        {
            flag = 0; break;
        }
        if( s[i]=='A' )
            cntA++;
        else if( s[i]=='P' )
            cntP++;
        else if( s[i]=='T' )
            cntT++;
    }
    if( cntA==0 || cntP==0 || cntT==0 )
        flag = 0;

    if( flag ){
        for( i=0; i<len; i++ )
        {
            if( s[i]=='A' )
                cntpre++;
            else if( s[i]=='P' )
                break;
            else
            {
                flag = 0; break;
            }
        }
        if( flag )
        {
            for( i++; i<len; i++ )
            {
                if( s[i]=='A' )
                    cntin++;
                else if( s[i]=='T' )
                    break;
                else{
                     flag = 0; break;
                }
            }
            if( flag )
            {
                for( i++; i<len; i++ ){
                    if( s[i]=='A' )
                        cntpost++;
                    else{
                        flag = 0; break;
                    }
                }
            }
        }
    }
    if( (cntpost != cntin*cntpre) || (cntin == 0) )
                    flag = 0;
    return flag;

}
int main()
{
    int n,i;
    int s[110];
    scanf("%d",&n);
    for( i=0; i<n; i++ )
    {
        scanf("%s",s);
        if( JudgeIsPat(s) )
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
