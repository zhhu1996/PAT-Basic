#include<stdio.h>
int T,K;
void beginGame();
int playGame( int n1, int b, int t, int n2 );

void beginGame()
{//input T and K
    scanf("%d %d",&T,&K);
}
int playGame( int n1, int b, int t, int n2 )
{//compare n1 and n2
    if( (n1<n2&&b==1) || (n1>n2&&b==0) ) return 1;
    else return -1;
}
int main()
{
    int n1,b,t,n2;
    beginGame();
    for( int i=0; i<K; i++ ){// 3 conditions
        scanf("%d %d %d %d",&n1,&b,&t,&n2);
        if( t>T ){
            printf("Not enough tokens.  Total = %d.\n",T);
        }
        else{
            if( playGame(n1,b,t,n2)==1 ){
                T += t;
                printf("Win %d!  Total = %d.\n",t,T);
            }
            else {
                T -= t;
                printf("Lose %d.  Total = %d.\n",t,T);
                if( T==0 ){
                    printf("Game Over.");
                    break;
                }
            }
        }
    }

}
