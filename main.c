#include <stdio.h>
#include <unistd.h>

void mensagem()
{
  printf("Eu sou um programa escrito em C com id %d\n", getpid());
  printf("Meu pai é o processo %d\n\n", getppid());
}

int main()
{
  int valor = fork();
  
  if (valor == 0) {    // Processo filho
    mensagem();
    printf("Eu sou o filho e o valor de fork eh %d\n", valor);
  }
  else if (valor > 0) {  // Processo pai
    mensagem();
    wait();   // Faz com que o pai aguarde a execução do processo filho
    printf("Meu filho eh o processo %d\n", valor);
  }
  return 0;  
}
