#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
地球文转火星文比较简单，注意13的倍数都只会输出tam 而不会输出tam tret
火星文转地球文比较复杂，用字符串函数判断是否存在空格， 在没有空格的时候也需要比较两次，
因为13的倍数也是只会输出一个单词的
*/
char *base[]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char *advance[]={"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

void TransmitEtoM( int n )
{
    if( n>=0&&n<=12 )
        printf("%s\n",base[n]);
    else{
        if( n%13==0 )
            printf("%s\n",advance[n/13-1]);
        else
            printf("%s %s\n",advance[n/13-1],base[n%13]);
    }
}

void TransmitMtoE( char s[] )
{
    char *p,*k;
    char s1[10],s2[10];
    int i=0,j=0;
    int num = 0;
    p = strchr(s,' ');
    k = s;
    if( p )
    {
        for( ; k<p; k++ )
            s1[i++] = *k;
        s1[i] = '\0';
        for( p++; *p; p++ )
            s2[j++] = *p;
        s2[j] = '\0';
        for( int it=0; it<12; it++ )
            if( !strcmp(s1,advance[it])){
			   num += (it+1)*13;break;
			}

        for( int it=0; it<=12; it++ )
            if( !strcmp(s2,base[it]) ){
			    num += it;break;
			}

        printf("%d\n",num);
    }
    else{
        for( int it=0; it<12; it++ )
            if( !strcmp(s,advance[it]) ) {
                num = (it+1)*13;
                printf("%d\n",num);
                return;
            }


	        for( int it=0; it<=12; it++ )
	            if( !strcmp(s,base[it]) )
	                num += it;
	        printf("%d\n",num);

	}
}

int main()
{
    int n;
    char s[10];
    scanf("%d",&n);
    getchar();
    for( int i=1; i<=n; i++ )
    {
        gets(s);
        if( s[0]>='0'&&s[0]<='9' )
            TransmitEtoM(atoi(s));
        else
            TransmitMtoE(s);
    }
    return 0;
}
