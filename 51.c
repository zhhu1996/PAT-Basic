#include <stdio.h>
#include <math.h>
//当实部为-0.002时应该输出0.00 但是如果用标准输出函数就会输出-0.00  所以要分开考虑
int main()
{
    double r1,r2,p1,p2;
    scanf("%lf %lf %lf %lf",&r1,&p1,&r2,&p2);
    double r = r1*r2;
    double p = p1+p2;
    double answerr = r*cos(p);
    double answerp = r*sin(p);
    if( answerr>-0.005&&answerr<0 )
    printf("0.00");
    else
    printf("%0.2lf",answerr);

    if( answerp > 0 )
        printf("+%0.2lfi",answerp);
    else if( answerp <0&&answerp>=-0.05 )
    	printf("+0.00i");
    else
        printf("-%0.2lfi",-answerp);
}
