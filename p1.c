#include<stdio.h>
#include<unistd.h>

#include<sys/types.h>
int main()
{
pid_t p;
printf("before fork\n");
p=fork();
if(p==0)
{
printf("I am  having student id %d\n",getpid());
printf("My parent's id is %d\n",getppid());
}
else{
printf("My student's id is %d\n",p);
printf("I am having parent id %d\n",getpid());
}
printf("Common\n");
}


