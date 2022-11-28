#include<stdio.h>

void main()
{
	int n, fac=1;
printf("Enter the value of n");
scanf("%d",&n);
for (int i=1;i<=n;i++)
{
	fac*=i;
}
printf("The factorial of the number is %d ",fac);
}		