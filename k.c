#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>

void *runner(void * param)
{
	printf("OS2019\n");	
	pthread_exit("dshhhkjkkkkkkkksdkkkkkkkkkkkkkkkkk");
}
int main()
{
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	
	pthread_create(&tid,&attr,runner,NULL);
	int f=pthread_join(tid,NULL);
	printf("%d",f);
	return 0;
	
	
}
