
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>    	// toupper

#define PULA  "\n\n\n"

//====================================================================
// Prototipos das funcoes
int    Menu(void);
short  Continua(void);
void   Leitura_Valor_Inteiro(int *Ptr);
int    Mdc(int A, int B);
//====================================================================


//====================================================================

// Elaborar comentarios internos associados a cada uma das funcoes a exemplo
// dos primeiros codigos que foram passados a voces.

int    Mdc(int A, int B){
int resto = 0;

    while ( B ) {
      resto = A%B;
      A = B;
      B = resto;
    } 
return(A);

}
//====================================================================

// Melhorar esse codigo

int Menu(void) {
int opcao;

  system("CLS");		// limpeza da tela

	printf("*****************************************************************************\n");
	printf("*                                                                           *\n");
	printf("*                                                                           *\n");
	printf("*                                   TPP 04                                  *\n");
	printf("*                                                                           *\n");
	printf("*                                                                           *\n");
	printf("*****************************************************************************\n\n\n");
		
  printf("1 - Encontrar todos os pares de primos cuja soma seja igual a n, com n no intervalo de 4 a 1000\n");
  printf("2 - Encontrar todos os primos no intervalo delimitado\n");
  printf("3 - Encontrar todos os primos gêmeos no intervalo delimitado\n");
  printf("4 - Encontrar todos os primos de Mersene no intervalo de 1 a 30\n");
  printf("5 - Encontrar todos os números felizes no intervalo de 4 a 1000\n");
  printf("6 - Encontrar o fatorial de um número inteiro, no intervalo 0 a 30, utilizando a fórmula de Stirling\n");
  
  
  printf("\n\n Escolha a opcao desejada : ");
  scanf("%d", &opcao);
  
  return(opcao);
}


short Continua(void) {
int ch;

  do {
		system("cls");
        printf("\n\n\n      Voce deseja executar outra funcao? [S,N] : ");
		ch = getchar();
		ch= toupper(ch);
  }
  while( (ch != 'S') && (ch != 'N') );

  if(ch == 'S') return(1);
  else return(0);
}

int Primo(int p){
  int i = 3, exp;
  if (p == 1) return(0);
  if (p == 2) return(1);
  if (p % 2 == 0) return(0);
  
  exp = (int)sqrt((double)p)+1;	// P:ímpar e último divisor antes de p é menor que sqrt(q)
  for (; i <= exp; i=i+2)
    if (p%i == 0)  return(0);
  return(1);
}

int feliz (){
	int res=0,soma=0, n=4, cn=0, aux=1;
	for (n; n<=1000; n++){
		cn = n;
		aux = 1;
		while (cn>1 && aux==1){
			while (cn>0){
				res=cn%10;
				cn/= 10;
				soma+= res*res;
			}
			cn = soma;
			if (cn == 4 || cn==16 || cn==37 || cn==58 || cn==89 || cn==145 || cn==42 || cn==20 ) aux=0;
			soma = 0;
		}
		if (cn==1) printf("\nO número %d é feliz =)", n);
	}
}

double Stirling(int N){
	double e=2.7182818284, pi=3.1415926535, fat, div;
	div=N/e;
	fat=sqrt(2*pi*N)*pow(div, N);
	return(fat);
}

int main(void) {
int a, b, op = 0;
setlocale(LC_ALL, "Portuguese");

 do {
	op = Menu();
	system("cls");
	printf("\n\n Opcao escolhida foi: %d\n\n", op);
	system("Pause"); 
	
    switch(op)  {
	case 1:
        	system("Pause");
         break;

	case 2:
		 system("pause");
         break;

	case 3:
		 system("Pause");
		 break;

	case 4:
		printf("*****************************************\n");
		printf("*                                   	*\n");
		printf("*                MERSENE                *\n");
		printf("*                                   	*\n");
		printf("*****************************************\n");
	
		int n, p, aux;
		printf("\n\nEsse programa encontrará todos os primos dos números de Mersene variando de 1 a 30:\n\n");
	
		for(n=1; n<=30; n++){
			p=pow(2, n)-1;
			aux=Primo(p);
			if(aux==1)
				printf("%d\n", p);
		
		break;

	case 5:
		system("cls");
		printf("*****************************************************************************\n");
		printf("*                                                                           *\n");
		printf("*                                                                           *\n");
		printf("*                              NÚMEROS FELIZES                              *\n");
		printf("*                                                                           *\n");
		printf("*                                                                           *\n");
		printf("*****************************************************************************\n\n\n");
		
		break;

	case 6:
		printf("*****************************************************************\n");
		printf("*                                      				*\n");
		printf("*                                      				*\n");
		printf("*			FÓRMULA DE STIRLING			*\n");
		printf("*                                      				*\n");
		printf("*                                      				*\n");
		printf("*****************************************************************\n\n");
	
		int N;
		double fat;
		printf("Introduza um valor entre 0 e 30:\n");
		scanf("%d", &N);

		if(0<=N<=30)
			fat=Stirling(N);

		printf("O fatorial de %d é: %lf de acordo com a Fórmula de Stirling!", N, fat);
		
		break;

	}	//switch

  } while ( Continua() );

 printf(PULA);
 system("Pause");
 return(0);

}   // main
