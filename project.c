#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int no_of_process;
int no_of_resource;

pthread_mutex_t t;

int main()
{
	printf("-------------------------------------------------------------\n");
	printf("                     BANKER'S  ALGORITHM                     \n");
	printf("-------------------------------------------------------------\n");
	printf("Enter the Number of Processes : ");
	scanf("%d",&no_of_process);
	printf("Enter the Number of Resources : ");
	scanf("%d",&no_of_resource);
}
