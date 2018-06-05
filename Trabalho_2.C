
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
	printf("*                                Bem-Vindo!!!                               *\n");
	printf("*                                                                           *\n");
	printf("*                                                                           *\n");
	printf("*****************************************************************************\n\n\n");
		
  printf("1 - Encontrar o MDC entre dois inteiros \n");
  printf("2 - Encontrar o REVERSO de um inteiro\n");
  printf("3 - Encontrar a QUANTIDADE de algarismos de um inteiro\n");
  printf("4 - \n");
  printf("5 - \n");
  printf("6 - Encontrar todos os números felizes no intervalo de 4 a 1000\n");
  
  
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

int main(void) {
int a, b, op = 0;


 do {
	op = Menu();
	system("cls");
	printf("\n\n Opcao escolhida foi: %d\n\n", op);
	system("Pause"); 
	
    switch(op)  {
	case 1:
		 printf("MDC ENTRE DOIS NUMEROS INTEIROS.\n\n");
         printf("Introduza um valor inteiro: ");
         scanf("%d",&a);
		 printf("Introduza um valor inteiro: ");
         scanf("%d",&b);
		 
		// printf("\n\n A= %d  B= %d",a, b);
		 printf("\n\n  MDC(%d,%d) = %d",a,b,Mdc(a,b));
		 printf(PULA);
         system("Pause");
         break;

	case 2:
		 printf("REVERSO DE UM NUMERO INTEIRO.");
		 system("pause");
         break;

	case 3:
		 printf("QUANTIDADE DE ALGARISMOS DE UM NUMERO INTEIRO.");
		 system("Pause");
		 break;

	case 4:
		 printf("K-ESIMO DIGITO DA DIREITA PARA A ESQUERDA.");
		 break;

	case 5:
		 printf("QUANTIDADE DE PRIMOS NUM INTERVALO.");
		 break;

	case 6:
		 system("cls");
		printf("*****************************************************************************\n");
		printf("*                                                                           *\n");
		printf("*                                                                           *\n");
		printf("*                              Números felizes                              *\n");
		printf("*                                                                           *\n");
		printf("*                                                                           *\n");
		printf("*****************************************************************************\n\n\n");
		 break;
	case 9: printf("OUTRAS FUNCOES....");
		break;

	}	//switch

  } while ( Continua() );

 printf(PULA);
 system("Pause");
 return(0);

}   // main
