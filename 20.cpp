#include<iostream>
#include<algorithm>
#include<iomanip>
//对单价进行排序，每一步都选取单价最大的商品出售即可得到最大值
using namespace std;
struct cake{
    float s,m,pm;//库存 总售价 单价
}*mooncake;
bool cmp( struct cake a, struct cake b )
{
    return a.pm>b.pm;
}
int main()
{
    int n,d;
    float t1,t2,maxs;
    cin>>n>>d;
    mooncake = new struct cake[n];
    maxs = 0.0;
    for( int i=0; i<n; i++ )
        cin>>mooncake[i].s;
    for( int i=0; i<n; i++ )
    {
        cin>>mooncake[i].m;
        mooncake[i].pm = mooncake[i].m / mooncake[i].s;
    }
    sort(mooncake,mooncake+n,cmp);
    for( int i=0; i<n&&d>0; i++ )
    {
        if( d>=mooncake[i].s )
        {
            maxs += mooncake[i].m;
            d -= mooncake[i].s;
        }
        else{//当d小于某种商品的库存时意味着已经到达最后一步
            maxs += mooncake[i].pm * d;
            d = 0;
        }
    }
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<maxs;
    delete [] mooncake;
}
