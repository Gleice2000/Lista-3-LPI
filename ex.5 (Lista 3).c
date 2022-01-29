#include <stdio.h>
#include <string.h>

int max=100;
int qnt=0; 

typedef struct jogo{
	char titulo[30];
	char console[15];
	int ano;
	int ranking;
    struct emprestimo emprestimo;
}tjogo;


struct emprestimo{
	char data[50];
	char nomePessoa[30];
    char emprestado[1];
}temprestimo;


void cadastrarJogo(tjogo jogo[]){
	printf("Dados para jogo %d \n",qnt+1);
	printf("Titulo do jogo:\n");
	fflush(stdin); 
	gets(jogo[qnt].titulo);
	printf("Console: \n");
	fflush(stdin); 
	gets(jogo[qnt].console);
	printf("Ano de lançamento:\n");
	scanf("%i",&jogo[qnt].ano);
	printf("Ranking:\n");
	scanf("%i",&jogo[qnt].ranking);
	

	qnt++;
	return 1;  
}


void mostrarJogo(tjogo jogo[])
{
	int i;
	for(i=0;i<qnt;i++){
		printf("Dados para jogos %d \n",i+1);
		printf("Titulo: %s\n",jogo[i].titulo);
		printf("Console: %s\n",jogo[i].console);
		printf("Ano: %i\n",jogo[i].ano);
		printf("Ranking: %i\n",jogo[i].ranking);
		printf("Emprestado: %s\n",jogo[i].emprestimo.emprestado);
		printf("Nome Pessoa: %s\n",jogo[i].emprestimo.nomePessoa);
		printf("Data: %s\n",jogo[i].emprestimo.data);
	}
}

void buscarTitulo(tjogo jogo[])
{
	int i;
	char nome[30];
	printf("Digite o nome do jogo a ser buscado:\n");
	fflush(stdin);
	gets(nome);
		for(i=0;i<qnt;i++){
		printf("Dados para jogos %d \n",i+1);
		printf("Titulo: %s\n",jogo[i].titulo);
		printf("Console: %s\n",jogo[i].console);
		printf("Ano: %i\n",jogo[i].ano);
		printf("Ranking: %i\n",jogo[i].ranking);
		printf("Emprestado: %s\n",jogo[i].emprestimo.emprestado);
		printf("Nome Pessoa: %s\n",jogo[i].emprestimo.nomePessoa);
		printf("Data: %s\n",jogo[i].emprestimo.data);
	}
}

void buscarConsole(tjogo jogo[])
{
	int i;
	char nome[30];
	printf("Digite o nome do console:\n");
	fflush(stdin);
	gets(nome);
	for(i=0;i<qnt;i++){
		if(strcmp(strupr(nome),strupr(jogo[i].console)) ==0){
		
		printf("Dados para jogos %d \n",i+1);
		printf("Titulo: %s\n",jogo[i].titulo);
		printf("Console: %s\n",jogo[i].console);
		printf("Ano: %i\n",jogo[i].ano);
		printf("Ranking: %i\n",jogo[i].ranking);
		printf("Emprestado: %s\n",jogo[i].emprestimo.emprestado);
		printf("Nome Pessoa: %s\n",jogo[i].emprestimo.nomePessoa);
		printf("Data: %s\n",jogo[i].emprestimo.data);
	}
}
}

void emprestar(tjogo jogo[])
{
	int i;
	char nome[30],opcao[1];
	printf("Digite o titulo do jogo que deseja emprestar\n");
	fflush(stdin);
	gets(nome);
	for(i=0;i<qnt;i++){
		if(strcmp(strupr(nome),strupr(jogo[i].titulo)) ==0){
		printf("Deseja emprestar o jogo %i - %s?(S/N):\n",i,jogo[i].titulo);
		fflush(stdin);
		gets(opcao);
		if(strcmp(strupr(opcao),strupr("S")) ==0){
			printf("Digite a data do emprestimo:\n");
			fflush(stdin);
			gets(jogo[i].emprestimo.data);
			printf("Digite o nome da pessoa:\n");
			fflush(stdin);
			gets(jogo[i].emprestimo.nomePessoa);
			strcpy(jogo[i].emprestimo.emprestado,"S");
		}
}
}
}


void devolver(tjogo jogo[])
{
	int i;
	char nome[30],opcao[1];
	printf("Digite o titulo do jogo que deseja devolver\n");
	fflush(stdin);
	gets(nome);
	for(i=0;i<qnt;i++){
		if(strcmp(strupr(nome),strupr(jogo[i].titulo)) ==0){
		printf("Deseja devolver o jogo %i - %s?(S/N):\n",i,jogo[i].titulo);
		fflush(stdin);
		gets(opcao);
		if(strcmp(strupr(opcao),strupr("S")) == 0){
			strcpy(jogo[i].emprestimo.emprestado,"N");
			strcpy(jogo[i].emprestimo.data,"Nao-emprestado");
			strcpy(jogo[i].emprestimo.nomePessoa,"Nao-emprestado");
			
		printf("Jogo devolvido");
		}
}
}
}


void listaEmprestados(tjogo jogo[])
{
	int i;
	printf("Jogos emprestados:\n");
	for(i=0;i<qnt;i++){
		if(strcmp(jogo[i].emprestimo.emprestado,"S")==0){
		printf("Dados para jogos %d \n",i+1);
		printf("Titulo: %s\n",jogo[i].titulo);
		printf("Console: %s\n",jogo[i].console);
		printf("Ano: %i\n",jogo[i].ano);
		printf("Ranking: %i\n",jogo[i].ranking);
		printf("Emprestado: %s\n",jogo[i].emprestimo.emprestado);
		printf("Nome Pessoa: %s\n",jogo[i].emprestimo.nomePessoa);
		printf("Data: %s\n",jogo[i].emprestimo.data);
	}
}
}

int menu()
{
	int op;
	printf(" Sistema para catalagos de jogos \n");
	printf(" Sistema para controle de colecoes de jogos \n");
	printf("1- Adicionar novo jogo \n");
	printf("2- Mostrar todos os jogos \n");
	printf("3- Buscar por titulo \n");
	printf("4- Buscar por console \n");
	printf("5- Realizar emprestimo \n");
	printf("6- Realizar devolucao \n");
	printf("7- Lista de jogos emprestados \n");
	printf("8-Sair\n");
	scanf("%d",&op);
	return op;
}


int main()
{
	int op=0
    tjogo jogo[max];

	do
	{
		op = menu();
		switch(op)
		{
			case 1: cadastrarJogo(jogo);
	            break;
			case 2: mostrarJogo(jogo);
				break;
			case 3: buscarTitulo(jogo);
				break;
			case 4: buscarConsole(jogo);
				break;
			case 5: emprestar(jogo);
			    break;
			case 6: devolver(jogo);
			    break;
			case 7:listaEmprestados(jogo);
			    break;			 	
		}
	 	getch(); 
		system("cls");
	}
	while(op!=0);	

	return 0;
}
