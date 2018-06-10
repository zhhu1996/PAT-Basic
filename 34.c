#include<stdio.h>
#include<math.h>
/*乘法可能会超出范围  所以选用更大的精度*/
long long getCommon( long long a, long long b )
{//求最大公约数
    if( b==0 ) return a;
    return getCommon(b,a%b);
}
void show( long long up, long long down )
{//化简分数
    long long d;
    if(down<0){up=-up;down=-down;}
    d=getCommon(labs(up),labs(down));
    up/=d; down/=d;
    if(up<0)printf("(");
    if(up==0)printf("0");
    else if(down==1)printf("%lld",up);
    else if( labs(up)>labs(down) )printf("%lld %lld/%lld",up/down,labs(up)%down,down);
    else printf("%lld/%lld",up,down);
    if(up<0)printf(")");
}
int main()
{
      long long  up1, up2, down1, down2;
      long long  up=0, down=1;
      scanf("%lld/%lld %lld/%lld",&up1,&down1,&up2,&down2);
      // +
      up=up1*down2+down1*up2;
      down=down1*down2;
      show(up1,down1);printf(" + ");show(up2,down2);printf(" = ");show(up,down);printf("\n");
      //  -
      up=up1*down2-down1*up2;
      down=down1*down2;
      show(up1,down1);printf(" - ");show(up2,down2);printf(" = ");show(up,down);printf("\n");
      //  *
      up=up1*up2;
      down=down1*down2;
      show(up1,down1);printf(" * ");show(up2,down2);printf(" = ");show(up,down);printf("\n");
      //  /
      if(up2==0){show(up1,down1);printf(" / ");show(up2,down2);printf(" = ");printf("Inf\n");}
      else{
      up=up1*down2;
      down=down1*up2;
      show(up1,down1);printf(" / ");show(up2,down2);printf(" = ");show(up,down);printf("\n");
      }
      return 0;
}


/*
#include<stdio.h>
//这道题目实在是难调试
long long getMaxCommon( long long a, long long b )
{
    if( a<0 )
        a = -a;
    long long c = a%b;
    while( c ){
        a = b;
        b = c;
        c = a%b;
    }
    return b;
}

void getEasy( long tmpa1, long tmpb1 )
{
	int flag = 0;
    long common1 = getMaxCommon(tmpa1,tmpb1);
    tmpa1 /= common1;
    tmpb1 /= common1;
    long k = tmpa1/tmpb1;
    if( tmpa1<0 ){
		flag = 1;
    	tmpa1 = -tmpa1;
	}
	tmpa1 %= tmpb1;
    if( k<0 ){
        if( tmpa1 )
            printf("(%ld %ld/%ld)",k,tmpa1,tmpb1);
        else
            printf("(%ld)",k);
    }
    else if( k==0 )
    {
        if( tmpa1==0 )
            printf("0");
        else{
			if( flag )
            	printf("(%ld/%ld)",-tmpa1,tmpb1);
            else
            	printf("%ld/%ld",tmpa1,tmpb1);
		}
	}
    else{
        if( tmpa1 )
            printf("%ld %ld/%ld",k,tmpa1,tmpb1);
        else
            printf("%ld",k);
    }
}

void Plus( long a1, long b1, long a2, long b2 )
{
    long long k,answer1,answer2,common;
    int flag = 0;
    answer1 = a1*b2 + a2*b1;
    answer2 = b1*b2;
    if( answer1==0 ){
        printf("0\n");
        return;
    }
    if( answer1<0 )
    {
        flag = 1;
        answer1 = -answer1;
    }
    common = getMaxCommon(answer1,answer2);
    answer1 /= common;
    answer2 /= common;
    k = answer1/answer2;
    answer1 %= answer2;
    if( flag )
        k = -k;
    if( k ){
        if( answer1 ){
            if( flag ){
                printf("(");
                printf("%lld %lld/%lld",k,answer1,answer2);
                printf(")\n");
            }
            else
                printf("%lld %lld/%lld\n",k,answer1,answer2);

        }
        else{
            if( flag ){
                printf("(");
            printf("%lld",k);
            printf(")\n");
        	}
			else
				printf("%lld",k);
        }
    }
    else{
        if( answer1 ){
            printf("%lld/%lld\n",answer1,answer2);
        }
        else
            printf("0\n");
    }
}

void Minus( long a1, long b1, long a2, long b2 )
{
	long long k,answer1,answer2,common;
    int flag = 0;
    answer1 = a1*b2 - a2*b1;
    answer2 = b1*b2;
    if( answer1==0 ){
        printf("0\n");
        return;
    }
    if( answer1<0 )
    {
        flag = 1;
        answer1 = -answer1;
    }
    common = getMaxCommon(answer1,answer2);
    answer1 /= common;
    answer2 /= common;
    k = answer1/answer2;
    answer1 %= answer2;
    if( flag )
        k = -k;
    if( k ){
        if( answer1 ){
            if( flag ){
                printf("(");
                printf("%lld %lld/%lld",k,answer1,answer2);
                printf(")\n");
            }
            else
                printf("%lld %lld/%lld\n",k,answer1,answer2);

        }
        else{
            if( flag ){
                printf("(");
            printf("%lld",k);
            printf(")\n");
        	}
			else
				printf("%lld\n",k);
        }
    }
    else{
        if( answer1 ){
        	if( flag )
        		printf("(%lld/%lld)\n",-answer1,answer2);
        	else
            	printf("%lld/%lld\n",answer1,answer2);
        }
        else
            printf("0\n");
    }
}

void Multi( long a1, long b1, long a2, long b2 )
{
	long long k,answer1,answer2,common;
    int flag = 0;
    answer1 = a1*a2;
    answer2 = b1*b2;
    if( answer1==0 ){
        printf("0\n");
        return;
    }
    if( answer1<0 )
    {
        flag = 1;
        answer1 = -answer1;
    }
    common = getMaxCommon(answer1,answer2);
    answer1 /= common;
    answer2 /= common;
    k = answer1/answer2;
    answer1 %= answer2;
    if( flag )
        k = -k;
    if( k ){
        if( answer1 ){
            if( flag ){
                printf("(");
                printf("%lld %lld/%lld",k,answer1,answer2);
                printf(")\n");
            }
            else
                printf("%lld %lld/%lld\n",k,answer1,answer2);

        }
        else{
            if( flag ){
                printf("(");
            printf("%lld",k);
            printf(")\n");
        	}
			else
				printf("%lld",k);
        }
    }
    else{
        if( answer1 ){
        	if( flag )
            	printf("(%lld/%lld)\n",-answer1,answer2);
            else
            	printf("%lld/%lld\n",answer1,answer2);
        }
        else
            printf("0\n");
    }
}

void Divide( long a1, long b1, long a2, long b2 )
{
    if( a2==0 ){
    	printf("Inf\n");
    	return;
	}
	else if( a2>0 )
    	Multi(a1,b1,b2,a2);
    else
    	Multi(a1,b1,-b2,-a2);
}
int main()
{
    long a1,b1,a2,b2;
    //long tmpa1,tmpb1,tmpa2,tmpb2;
    scanf("%ld/%ld %ld/%ld",&a1,&b1,&a2,&b2);
    getEasy(a1,b1);
    printf(" + ");
    getEasy(a2,b2);
    printf(" = ");
    Plus(a1,b1,a2,b2);

    getEasy(a1,b1);
    printf(" - ");
    getEasy(a2,b2);
    printf(" = ");
    Minus(a1,b1,a2,b2);

    getEasy(a1,b1);
    printf(" * ");
    getEasy(a2,b2);
    printf(" = ");
    Multi(a1,b1,a2,b2);

    getEasy(a1,b1);
    printf(" / ");
    getEasy(a2,b2);
    printf(" = ");
    Divide(a1,b1,a2,b2);

}
*/
