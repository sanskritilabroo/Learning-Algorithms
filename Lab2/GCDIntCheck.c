#include<stdio.h>

unsigned int IntCheck(unsigned int m, unsigned int n) 
{
	unsigned int r1;unsigned int r2;
	unsigned int t = (m < n) ? m : n;
	int opcount = 0; // variable to count how many times the basic operation executes.
	while(t!=0)
	{
		opcount++;//critical op
		r1 = m % t;//step 2
		if (r1==0)
		{
			//opcount++;
			r2 = n % t;//step 3
			if(r2==0)
			{
				printf("Operation count= %d\n", opcount);
				return t;
			}
		}
		//step 4
		t = t - 1;
	}
	printf("Operation count= %d\n", opcount);
	return m;
}
int main() 
{
	unsigned int m,n;
	printf("Enter the two numbers whose GCD has to be calculated");
	scanf("%d", &m);
	scanf("%d", &n);
	printf("GCD of two numbers using Integer Checking method is %d",IntCheck(m,n)); 
	return 0;
}