#include <stdio.h>
#include <unistd.h>

void mensagem()
{
  printf("ID FILHO %d - ", getpid());
  printf("ID PAI %d\n", getppid());
}

int main()
{
  int pid = fork();
  if (pid == 0)
  {
    printf("Primeiro filho\n");
    mensagem();
  }
  else
  {
    wait();
    pid = fork();
    wait();
    if (pid == 0)
    {
      printf("\nSegundo filho\n");
      for(int i = 1; i < 11; i++){
        printf("Execucao %d\n", i);
        mensagem();
      }
      
    }
    else
    {
      pid = fork();
      wait();
      if (pid == 0)
      {
        printf("\nTerceiro filho\n");
        mensagem();
        int a;
        int b;
        printf("Digite um numero inteiro\n");
        scanf("%i", &a);
         printf("Digite um numero inteiro\n");
        scanf("%i", &b);
        printf("Soma: %d\n", a + b);
      }
    }
  }
  return 0;
}