#include<stdio.h>
#include<string.h>
/*这道题目枚举算法肯定超时*/
/*
下面这种做法  只有O(N)复杂度 用的是动态规划的思想
从末尾开始遍历，每遇到一个T就cntT++
遇到A就让cntAt就加上此时具有的cntT
遇到P就让cntPat加上此时具有的cntAt
*/
int main()
{
    char s[100008];
    int i,cntPat,cntAt,cntT,n;
    cntPat = cntAt = cntT = 0;
    scanf("%s",s);
    n = strlen(s);

    for( i=n-1; i>=0; i-- ){
        if( s[i]=='T' )
            cntT = (cntT+1)%1000000007;
        if( s[i]=='A' )
            cntAt = (cntAt+cntT)%1000000007;
        if( s[i]=='P' )
            cntPat = (cntPat+cntAt)%1000000007;
    }
    printf("%d\n",cntPat);
    /*枚举算法
    for( i=0; i<n; i++ )
    {
        if( s[i]=='P' )
            for( j=i+1; j<n; j++ )
            {
                if( s[j]=='A' )
                    for( k=j+1; k<n; k++ )
                    {
                        if( s[k]=='T' )
                            cnt = (cnt+1)%1000000007;
                    }
            }
    }
    */
    //printf("%d\n",cnt);
}
