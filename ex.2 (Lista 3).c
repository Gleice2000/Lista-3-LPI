#include <stdio.h>
#include <string.h>
#define MAX 10


typedef struct livros{
	char titulo[50];
	char autor[50];
	int ano;
	int prateleira;
}tlivro;


int qnt=0; 


int addLivro(tlivro li[])
{
	if(qnt==MAX) 
	  return 0;
	printf("Dados para o livro \n");
	printf("Titulo do livro:");
	fflush(stdin); 
	gets(li[qnt].titulo);
	printf("Autor do livro:");
	fflush(stdin); 
	gets(li[qnt].autor);
	printf("Ano de lançamento:");
	scanf("%d",&li[qnt].ano);
	printf("Prateleira guardada:");
	scanf("%d",&li[qnt].prateleira);
	qnt++;
	return 1;  
}


void mostrarLivros(tlivro li[])
{
	int i;
	printf(" Bandas cadastradas \n");
	for(i=0;i<qnt;i++){
		printf("Livro %d\n",i+1);
		printf("Titulo:%s\n",li[i].titulo);
		printf("Autor:%s\n",li[i].autor);
		printf("Ano:%d\n",li[i].ano);
		printf("Prateleira:%d\n",li[i].prateleira);
	}
}

void buscarLivro(tlivro li[], char nomeBusca[50])
{
	int i, existe=0;
	char aux[50];	
	for(i=0;i<qnt;i++)
	{
		strcpy(aux,li[i].titulo); 
	 if(strcmp( strupr(aux), strupr(nomeBusca))==0)
	 { 
		printf("Livro %d\n",i+1);
		printf("Titulo:%s\n",li[i].titulo);
		printf("Autor:%s\n",li[i].autor);
		printf("Ano:%d\n",li[i].ano);
		printf("Prateleira:%d\n",li[i].prateleira);
		existe = 1;
	  }
	}
	if(!existe) 
	   printf("Livro nao encontrado :(\n");   
}


int menu()
{
	int op;
	printf(" Sistema de Cadastro de Livros: \n");
	printf("1- Adiciona livro \n");
	printf("2- Mostra livros \n");
	printf("3- Busca livro \n");
	printf("4- Sair \n");
	scanf("%d",&op);
	return op;
}


int main()
{
	tlivro livros[MAX];
	char buscar[50];
	int op;

	do
	{
		op = menu();
		switch(op)
		{
			case 1: if(addLivro(livros)==1)
			 			printf("Livro adicionado :)\n");
			 		else
					 	printf("Limite atingido :(\n");
				break;
			case 2: mostrarLivros(livros);
				break;
			case 3: printf("Nome do livro para buscar:");
					fflush(stdin); gets(buscar);
					buscarLivro(livros,buscar);
				break;
			
			case 4: 
					printf("Saindo... \n");
				break;
			default: printf("Opcao invalida\n");			 	
		}
	 	getch(); 
		system("cls");
	}
	while(op!=0);	

	return 0;
}
