#include <stdio.h> 	// header file
#include <stdlib.h> 	// header file

int mutex = 1, full = 0, empty = 3, x = 0;

int main()	// main code
{
  int n;
  void producer();
  void consumer();
  int wait(int);
  int signal(int);
  printf("\n1.producer\n2.consumer\n3.for exit");
  while (1)
  {
    printf("\n Please enter your choice:");
    scanf("%d", &n);
    switch (n)
    {
      case 1:
        if ((mutex == 1) && (empty != 0))
          producer();
        else
          printf("Oops!! the buffer is full!!");
        break;
      case 2:
        if ((mutex == 1) && (full != 0))
          consumer();
        else
          printf("Oops!! the buffer is empty!!");
        break;
      case 3:
        exit(0);
        break;
    }
  }

  return 0;
}

int wait(int s)
{
  return (--s);
}

int signal(int s)
{
  return (++s);
}

void producer()
{
  mutex = wait(mutex);
  full = signal(full);
  empty = wait(empty);
  x++;
  printf("\nItem produced by the Producer %d", x);
  mutex = signal(mutex);
}

void consumer()
{
  mutex = wait(mutex);
  full = wait(full);
  empty = signal(empty);
  printf("\nItem consumed by the Consumer %d", x);
  x--;
  mutex = signal(mutex);
}

