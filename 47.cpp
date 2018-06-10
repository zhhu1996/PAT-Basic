#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n,maxs,maxi,team,id,score,ts[1001]={0};
    scanf("%d",&n);
    for( int i=0; i<n; i++ ){
        scanf("%d-%d %d",&team,&id,&score);
        ts[team] += score;
    }
    maxs = 0; maxi = 1;
    for( int i=1; i<=1000; i++ ){
        if( maxs<ts[i] ){ maxs = ts[i]; maxi = i; }
    }
    printf("%d %d",maxi,maxs);
}
