#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
//最后一个测试点卡的是动态数组
int cmp( const void *pa, const void *pb )
{
    int a = *(int*)pa;
    int b = *(int*)pb;
    return b-a;
}
int main()
{
    int N,m,n,minn,i,j,k;
    scanf("%d",&N);
    int a[N];
    minn = N;
    for(int i=1;i<=(int)(sqrt(N*1.0));i++){
        for(int j=i;j<=N;j++){
            if(i*j==N&&(j-i)<minn){//在符合条件的数中寻找差最小的数，并记录下来
                minn=j-i;
                m=j;
                n=i;
            }
        }
    }
    for( i=0; i<N; i++ )
        scanf("%d",&a[i]);
    int **b;
    b = (int**)malloc(sizeof(int*)*m);
    for( i=0; i<m; i++ )
        b[i] = (int*)malloc(sizeof(int)*n);

    for( i=0; i<m; i++)
        for( j=0; j<n; j++ )
            b[i][j] = 0;

    //memset(b,0,N);
    //int b[108][108] = {0};
    qsort(a,N,sizeof(a[0]),cmp);
    i=0;j=0;k=0;
    b[0][0] = a[k]; k++;
    while( k<N ){//当k<n的时候说明循环还要继续
        while( j+1<n&&!b[i][j+1] ) { b[i][j+1]=a[k]; k++; j++; }
        while( i+1<m&&!b[i+1][j] ) { b[i+1][j]=a[k]; k++; i++; }
        while( j-1>=0&&!b[i][j-1] ) { b[i][j-1]=a[k]; k++; j--; }
        while( i-1>=0&&!b[i-1][j] ) { b[i-1][j]=a[k]; k++; i--; }
    }
    for( i=0; i<m; i++ ){
        for( j=0; j<n; j++ ){
            if( j==0 ) printf("%d",b[i][j]);
            else printf(" %d",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}
