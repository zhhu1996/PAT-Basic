#include<stdio.h>
#include<string.h>
/*
长度:A < B
    :A > B   B不足的位数要当成'0'计算
*/
int main()
{
    char a[108],b[108],c[108];
    char mod13[] = "0123456789JQK";
    int lena,lenb,i,j,k,flag,t;
    char t1,t2;
    scanf("%s %s",a,b);
    lena = strlen(a); lenb = strlen(b);
    flag = 1; k = 0;
    for( i=lena-1,j=lenb-1; i>=0; i--,j-- ){
        t1 = a[i];
        if( j<0 ) t2 = '0';
        else t2 = b[j];
        if( flag ){
            t = (t1-'0'+t2-'0')%13;
            flag = 0;
        }
        else{
            t = (t2-'0') - (t1-'0');
            t = t>=0?t:(10+t);
            flag = 1;
        }
        c[k] = mod13[t]; k++;
    }
    while( j>=0 ){
        t = b[j] - '0';
        c[k] = mod13[t]; k++;
        j--;
    }
    for( i=k-1; i>=0; i-- )
        printf("%c",c[i]);
    printf("\n");
    return 0;
}
