#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int no_of_process;
int no_of_resource;
int available[10];
int sequence[10];
int id;
int newRequest;
int g,b,a;

pthread_mutex_t t;

void pthread_function();
void safe_sequence();
struct file
{
	int Allocation[10];
	int Max[10];
	int need[10];
	int flag;
};

int main()
{
	struct file f[10];
	printf("-------------------------------------------------------------\n");
	printf("                     BANKER'S  ALGORITHM                     \n");
	printf("-------------------------------------------------------------\n");
	printf("Enter the Number of Processes : ");
	scanf("%d",&no_of_process);
	printf("Enter the Number of Resources : ");
	scanf("%d",&no_of_resource);
	for(int i=0;i<no_of_process;i++)
	{
		printf("Enter the Details of the Process P%d\n",i);
		printf("Enter the Allocation      : ");
		for(int j=0;j<no_of_resource;j++)
		{
			scanf("%d",&f[i].Allocation[j]);
		}
		printf("Enter the Max Requirement  : ");
		for(int j=0;j<no_of_resource;j++)
		{
			scanf("%d",&f[i].Max[j]);
		}
		f[i].flag=0;
	}
	printf("Enter the Available Resources  : ");
	for(int i=0;i<no_of_resource;i++)
	{
		scanf("%d",&available[i]);
	}
	printf("Enter Your New Request Details");
	printf("\nEnter the Process ID :");
	scanf("%d",&id);
	printf("Enter the Request for the Resource :");
	for(int i=0;i<no_of_resource;i++)
	{
		scanf("%d",&newRequest);
		f[id].Allocation[i] += newRequest;
	}
	for(int i=0;i<no_of_process;i++)
	{
		for(int j=0;j<no_of_resource;j++)
		{
			f[i].need[j]=f[i].Max[j]-f[i].Allocation[j];
			if(f[i].need[j]<0)
			{
				f[i].need[j]=0;
			}
		}
	}


    int count = 0;
    int fl = 0;
    while(count!=no_of_process)
    {
        g=0;
        for(int j=0;j<no_of_process;j++)
        {
            if(f[i].flag=0)
            {
                b=0;
                for(int p=0;p<no_of_resource;p++)
                {
                    if(available[p]>=f[j].need[p])
                        b=b+1;
                    else
                        b=b-1;
                }
                if(b==no_of_resource)
                {
                    printf("\nP%d is Visited",j);
                    sequence[fl++]=j;
                    f[i].flag=1;
                    for(int k=0;k<no_of_resource;k++)
                        available[k]=available[k]+f[i].Allocation[k];
                    count=count+1;
                    printf("(");
                    for(int k=0;k<no_of_resource;k++)
                        printf("%3d",available[k]);
                    printf(")");
                    g=1;
                }
            }
        }
        if(g==0)
        {
            printf("\nRequest not Granted");
            printf("\nDead Lock occurred");
            printf("\nSystem is in Safe Sequence");
        }
    }

}
void pthread_funtion()
{

}
void safe_sequence()
{

}
