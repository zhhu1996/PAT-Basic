#include<stdio.h>
int main()
{
    int src,n,k,temp;
    int data[100005],nextaddr[100005];
    scanf("%d %d %d",&src,&n,&k);
    for( int i=0; i<n; i++ ){
        scanf("%d",&temp);
        scanf("%d %d",&data[temp],&nextaddr[temp]);
    }
    int list[100005];
    int sum = 0;//是为啦防止多余结点
    while( src!=-1 ){
        list[sum++] = src;
        src = nextaddr[src];
    }
    int result[100005];
    for( int i=0; i<sum; i++ )
        result[i] = list[i];

    for( int i=0; i<(sum - sum%k); i++ )
        result[i] = list[i/k*k + k-1 -i%k];

    for( int i=0; i<sum-1; i++ ){
        printf("%05d %d %05d\n",result[i],data[result[i]],result[i+1]);
    }
    printf("%05d %d -1",result[sum-1],data[result[sum-1]]);
    return 0;
}
