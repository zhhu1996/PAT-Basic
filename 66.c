#include<stdio.h>
int main()
{
    int row,col,a,b,ret,t;
    scanf("%d %d %d %d %d",&row,&col,&a,&b,&ret);
    for( int i=0; i<row; i++ ){
        for( int j=0; j<col; j++ ){
            scanf("%d",&t);
            if( j ) printf(" ");
            if( t>=a&&t<=b ) printf("%03d",ret);
            else printf("%03d",t);
        }
        printf("\n");
    }
    return 0;
}
