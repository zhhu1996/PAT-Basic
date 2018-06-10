#include<iostream>
using namespace std;
int main()
{
    int n,x,y,maxsc,maxnum,score[100001];
    cin>>n;
    for( int i=1; i<=n; i++ )
        score[i] = 0;
    maxsc = maxnum = 0;
    for( int i=0; i<n; i++ )
    {
        cin>>x>>y;
        score[x] += y;
        if( maxsc<score[x] ){//可以在累加的同时求最大值
            maxsc = score[x]; maxnum = x;
        }
    }
    cout<<maxnum<<" "<<maxsc;
}
