#include<stdio.h>
#include<string.h>
/*
每个表情可能不止一个字符，所以用二维数组存储
输出"Are you kidding me? @\\/@\n"  双反斜杠表示反斜杠
选择表情的时候要判断序号是否合理，即不超过上下限
*/
int main()
{
    char a[12][6],b[12][6],c[12][6];
    char t;
    int i,j,len1,len2,len3,n,tmp,flag;
    int x[5];
    flag = 1;
    i=j=0;
    while( (t=getchar())!='\n' ){
        if( t=='[' ){
			t = getchar();
			while( t!=']'){
				a[i][j++] = t;
				t = getchar();
			}
			a[i][j] = '\0';
			i++;
			j=0;
		}
        else if( t==' ')
            continue;
    }
    len1 = i;
    i=j=0;
    while( (t=getchar())!='\n' ){
        if( t=='[' ){
			t = getchar();
			while( t!=']'){
				b[i][j++] = t;
				t = getchar();
			}
			b[i][j] = '\0';
			i++;
			j=0;
		}
        else if( t==' ')
            continue;
    }
    len2 = i;
    i=j=0;
    while( (t=getchar())!='\n' ){
        if( t=='[' ){
			t = getchar();
			while( t!=']'){
				c[i][j++] = t;
				t = getchar();
			}
			c[i][j] = '\0';
			i++;
			j=0;
		}
        else if( t==' ')
            continue;
    }
    len3 = i;
    scanf("%d",&n);
    for( j=0; j<n; j++ ){
    for( i=0; i<5; i++ ){
        scanf("%d",&x[i]);
        if( (i==0||i==4) && (x[i]>len1||x[i]<1) )
            flag = 0;
        if( (i==1||i==3) && (x[i]>len2||x[i]<1) )
            flag = 0;
        if( i==2 && (x[i]>len3||x[i]<1) )
            flag = 0;
    }
    if( !flag )
        printf("Are you kidding me? @\\/@\n");
    else{
        for( i=0; i<5; i++ ){
            if( i==0||i==4 )
                printf("%s",a[x[i]-1]);

            if( i==1||i==3 )
            {
                if( i==1 )
                    printf("(");
                printf("%s",b[x[i]-1]);
                if( i==3)
                    printf(")");
            }

            if( i==2 )
                printf("%s",c[x[i]-1]);

        }
        printf("\n");
    }
    }
}
