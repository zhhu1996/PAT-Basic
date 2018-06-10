#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    int x,y,color;
}Node;
int M,N,TOL;
int a[1024][1024];
int cnt[1<<24] = {0};
int dx[] = {-1,-1,-1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0,-1,-1};
int check( int x, int y )
{
    if( x<0||y<0||x>N||x>M )
        return 0;
    return 1;
}

int main()
{
    scanf("%d %d %d",&M,&N,&TOL);
    vector<struct node>g;
    for( int i=0; i<N; i++ )
        for( int j=0; j<M; j++ )
        {
            scanf("%d",&a[i][j]);
            cnt[a[i][j]]++;
        }
    for( int i=0; i<N; i++ )
        for( int j=0; j<M; j++ )
        {
            if( cnt[a[i][j]]==1 ){
                int k;
                for( k=0; k<8; k++ ){
                    if( check(i+dx[k],j+dy[k])&& abs(a[i][j]-a[i+dx[k]][j+dy[k]])<=TOL )
                        break;
                }
                if( k==8 )
                {
                    Node.x=j+1; Node.y=i+1;
                    Node.color=a[i][j];
                    g.push_back(Node);
                }
            }
        }
    if (g.size() == 1)
    {
        printf("(%d, %d): %d", g[0].x, g[0].y, g[0].color);
    }
    else if (g.size() == 0)printf("Not Exist");
    else printf("Not Unique");
    return 0;
}
