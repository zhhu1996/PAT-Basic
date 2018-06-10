#include <stdio.h>
//n是非负整数
int main()
{
    int coef,expon,flag;
    flag = 1;
    //int a[2048];

    do
    {
        scanf("%d %d",&coef,&expon);
        if( expon ){

            coef *= expon;
            expon--;
            if( flag ){
                printf("%d %d",coef,expon); flag = 0;
            }
            else
                printf(" %d %d",coef,expon);
        }
        else if( expon==0 && flag )
            printf("0 0");
    }while( expon>0 );

    return 0;
}
