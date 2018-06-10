#include<stdio.h>
int hasStu = 0, hasThg = 0;
void checkStu( char *s, int k, int *o, int length  );

void checkStu( char *s, int k, int *o, int length )
{//check one student
    int temp, cnt=0;
    for( int i=0; i<k; i++ ){
        scanf("%d",&temp);
        for( int j=0; j<length; j++ ){
            if( temp == o[j] ){
                cnt++;
                if( cnt==1 ){
                    printf("%s:",s);
                    hasStu++;
                }
                printf(" %04d",temp); //take account into the formation:xxxx
                hasThg++;
            }
        }
    }
    if( cnt!=0 ) printf("\n");
}

int main()
{
    int N,M,K,order1,order2,Mthing[20];
    char name[5];
    scanf("%d %d",&N,&M);
    for( int i=0; i<M; i++ )
        scanf("%d",&Mthing[i]);
    for( int i=0; i<N; i++ ){
        scanf("%s",name);
        scanf("%d",&K);
        checkStu(name,K,Mthing,M);
    }
    printf("%d %d",hasStu,hasThg);
}
