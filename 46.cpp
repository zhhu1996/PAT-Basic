#include<iostream>
using namespace std;
int main()
{
    int n,sum,a[110][4]={0},cnt[2]={0};
    cin>>n;
    for( int i=0; i<n; i++ ){
        for( int j=0; j<4; j++ )
            cin>>a[i][j];
        sum = a[i][0]+a[i][2];
        if( (sum==a[i][1]&&sum!=a[i][3])||(sum==a[i][3]&&sum!=a[i][1]) )
        {//只有一方猜中答案才更新喝酒次数
            if( sum==a[i][1]&&sum!=a[i][3] )
                cnt[1]++;
            else
                cnt[0]++;
        }
    }
    cout<<cnt[0]<<" "<<cnt[1];
}
