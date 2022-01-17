#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100


typedef struct {
     char nome [30];
	 float potencia, horas;	
}tEletro;
int qnt=0;

		
int menu(){
	int op;
	printf("Cadastros dos Eletros \n");
	printf("1-Cadastrar Eletro \n");
	printf("2-Mostrar todos os Eletros \n");
	printf("3-Buscar Eletro pelo nome \n");
	printf("4-Consumo \n");
	printf("5-Sair \n");
	return op;
}


void add(tEletro e[]){
	if (qnt==MAX){
		printf("Sistema cheio \n");
	}
	printf("Cadastramento de Eletros\n");
	printf("Nome do Eletrodomestico: \n");
	fflush(stdin);
	gets(e[qnt].nome);
	printf("Potencia: ");
	scanf("%f", &e[qnt].potencia);
	printf("Tempo medio em horas, ativo por dia: ");
	scanf("%f", &e[qnt].horas);
	qnt++;
	printf("Adicionado com sucesso!!! \n");
}


void lista(tEletro e[]){
	int i;
	for(i=0; i<qnt; i++){
		printf("Eletrodomestico %d \n", i+1);
		printf("Nome: %s\n",e[i].nome);
		printf("Potencia: %.2f KW\n",e [i].potencia);
		printf("Tempo medio ativo por dia: %.2f Hrs\n",e[i].horas);
	}
}


void buscaEletro(tEletro e[], char buscaNome[]){
	int i, encontrou=0;
	for(i=0; i<qnt; i++){
		if(strcmp(strupr(e[i].nome) , strupr(buscaNome) )==0){
		printf("Eletro %d \n", i+1);
		printf("Nome:%s\n Potencia:%f KW\n Tempo medio ativo por dia:%.2f Hrs\n");
		    e[i].nome, e[i].potencia, e[i].horas;
			printf("\n\n");
			encontrou=1;
			break;
		}
		if(!encontrou)
		printf("Eletrodomestico nao encontrado! ");
		}
	}
	
	
	void consumoTotal(tEletro e[],float valorKWh){
		int i;
		float consumoDiarioKW = 0;
		for(i=0; i<qnt; i++){
			consumoDiarioKW += e[i].potencia * e[i].horas;
		}
		printf("\nConsumo Diario em KW:%2lf\n Consumo Diario em R$:%.2lf\n", consumoDiarioKW, consumoDiarioKW * valorKWh);
		printf("\nConsumo Mensal em KW:%2lf\n Consumo Mensal em R$:%.2lf\n", consumoDiarioKW * 30, (consumoDiarioKW *30) * valorKWh);
	}


int main(){
	int op;
	tEletro e[MAX];
	char buscaNome[30];
	float valorKWh;
	
	do{
		op = menu();
		switch(op)
		{
			case 1: add(e);
			break;
			
			case 2: lista(e);
			break;
			
			case 3: printf("Nome do eletrodomestico para busca:");
			fflush(stdin); gets(buscaNome);
			buscaEletro(e, buscaNome);
			break;
			
			case 4: printf("Qual o valor da busca:");
			scanf("%f", &valorKWh);
			consumoTotal(e, valorKWh);
			
			case 5:
				printf("Saindo...\n");
				break;
		}
		getch();
		system("cls");
	}while(op!=0);
	return 0;
}
