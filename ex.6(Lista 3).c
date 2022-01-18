#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 100

typedef struct n{
	char mes[12];
	int ano;
}tNascimento;


typedef struct{
	char codigo[15], abate[1];
	float alimento, leite;
    struct n dataNascimento;
}tGado;

anoAtual = 2022;
qnt = 0;


int menu(){
	int op;
	
	printf("Controle de cabeças de gado \n");
	printf("1-Cadastrar novo gado: \n");
	printf("2-Animais cadastrados: \n");
	printf("3-Leite produzido por semana: \n");
	printf("4-Sair \n");
	printf("%d", &op);
	return op;
}


void cadastrar(tGado g[]){
	printf("Cadastro de cabeças de gado");
	printf("Código da cabeça de gado:");
	fflush(stdin); gets(g[qnt].codigo);
	printf("Quantidade de litros de leite por semana:");
	scanf("%f", &g[qnt].leite);
	printf("Quantidade de alimento por semana:");
	scanf("%f", &g[qnt].alimento);
	printf("Data de Nascimento");
	printf("Mes(extenso):");
	fflush(stdin); gets(g[qnt].dataNascimento.mes);
	printf("Ano(0000):");
	scanf("%d", &g[qnt].dataNascimento.ano);
	
	
	int idade = anoAtual - g[qnt].dataNascimento.ano;
	if(idade > 5 || g[qnt].leite<40){
		g[qnt].abate[0]='s';
	}
	else{
		g[qnt].abate[0] = 'n';
	}
	printf("Abate: %s", g[qnt].abate);
	qnt++;
}


void mostrarCadastro(tGado gados[]){
	int i;
	if(qnt > 0){
		printf("Ha %d gados cadastrados:", qnt);
		for(i=0; i<qnt; i++){
		printf("Gado %d", i+1);
		printf("Codigo %s",gados[i].codigo);
		printf("Quantidade de litros de leite por semana: %1.f",gados[i].leite);
		printf("Quantidade de alimentos por semana: %1.f",gados[i].alimento);
		printf("Data e Nascimento: %s%d",gados[i].dataNascimento.mes,gados[i].dataNascimento.ano);
		printf("Abate: %s", gados[i].abate);	
		}
	}else{
		printf("Não ha gados cadastrados!!!");
	}
}


float producaoTotalLeite(tGado gados[]){
	int i;
	float total = 0;
	for(i=0; i<qnt; i++){
		total += gados[i].leite;
	}
	return total;
}


main(){
	tGado g[MAX];
	int op;
	
	do{
		op=menu();
		switch(op)
		{
		case 1: cadastrar(g);
		break;
		
		case 2: mostrarCadastros(g);
		break;
		
		case 3:printf("\n%.1f litros produzidos semanais",producaoTotalLeite(g));
			
		case 4: printf("Saindo...");
		break;}
		
	getch();
	system("cls");
		}while (op!=0);
	return 0;
	}


