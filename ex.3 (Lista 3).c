#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct alunos{
	char nome[50];
	int matricula;
	double nota1;
	double nota2;
	double nota3;
}taluno;

int qnt=0;


void cadastrarAluno(taluno aluno[]){
	printf("Dados para cadastrar aluno %d \n", qnt+1);
	printf("Matricula:\n");
	scanf("%d",&aluno[qnt].matricula);
	printf("Nome: \n");
	fflush(stdin);
	gets(aluno[qnt].nome);
	printf("Nota da primeira prova: \n");
	scanf("%lf",&aluno[qnt].nota1);
	printf("Nota da segunda prova: \n");
	scanf("%lf",&aluno[qnt].nota2);
	printf("Nota da terceira prova: \n");
	scanf("%lf",&aluno[qnt].nota3);
	
	qnt++;
}


void mostrarAlunos(taluno aluno[]){
	int i;
	for(i=0;i<qnt;i++){
		
		printf("Dados do aluno %d\n",i+1);
		printf("Matricula: %d\n",aluno[i].matricula);
		printf("Nome:%s\n",aluno[i].nome);
		printf("Nota na prova 1: %.2lf\n", aluno[i].nota1);
		printf("Nota na prova 2: %.2lf\n", aluno[i].nota2);
		printf("Nota na prova 3: %.2lf\n", aluno[i].nota3);
	}
}


void salvarDados(taluno aluno[]){
	int i;
	FILE *arq;
	arq = fopen("alunos.texto", "w");
	fprint(arq, "%d", qnt);
	for(i=0;i<qnt;i++){
		
		fprintf(arq, "%i\n",aluno[i].matricula);
		fprintf(arq, "%s\n",aluno[i].nome);
		fprintf(arq, "%lf\n", aluno[i].nota1);
		fprintf(arq, "%lf\n", aluno[i].nota2);
		fprintf(arq, "%lf\n", aluno[i].nota3);
	}
	printf("Os dados foram salvos com sucesso!");
}


void carregarDados(taluno aluno[]){
	FILE *arq;
	int i;
	arq = fopen("alunos.texto", "r");
    if(arq==NULL){
    	printf("Arquivo nao foi encontrado!\n");
    	return;
	}
    
    fscanf(arq, "%d", &qnt);
	for(i=0;i<qnt;i++){
		
	    fscanf(arq, "%i\n",&aluno[i].matricula);
		fscanf(arq, "%s\n",&aluno[i].nome);
		fscanf(arq, "%lf\n",&aluno[i].nota1);
		fscanf(arq, "%lf\n",&aluno[i].nota2);
		fscanf(arq, "%lf\n",&aluno[i].nota3);	
}
fclose(arq);
printf("Os dados foram carregados com sucesso!\n");
}


void buscarAlunoMatricula(taluno aluno[]){
	int i,matricula,encontrou;
	printf("Digite a matricula do aluno:\n");
	scanf("%d",&matricula);
	for(i=0;i<qnt;i++){
		
	if(matricula == aluno[i].matricula){
	    printf("Dados do aluno %d\n",i+1);
		printf("Matricula: %d\n",aluno[i].matricula);
		printf("Nome:%s\n",aluno[i].nome);
		printf("Nota na prova 1: %.2lf\n", aluno[i].nota1);
		printf("Nota na prova 2: %.2lf\n", aluno[i].nota2);
		printf("Nota na prova 3: %.2lf\n", aluno[i].nota3);	
	}
		
	}
	
}


void buscarAlunoNome(taluno alkuno[]){
	int i, encontrou;
	char nome[50];
	printf("Digite o nome do aluno:\n");
	fflush(stdin);
	gets(nome);
	for(i=0;i<qnt;i++){
		
	if(strcmp(strupr(nome),strupr(aluno[i].nome)) == 0){
	    printf("Dados do aluno %d\n",qnt+1);
		printf("Matricula: %d\n",aluno[i].matricula);
		printf("Nome:%s\n",aluno[i].nome);
		printf("Nota na prova 1: %2lf\n", aluno[i].nota 1);
		printf("Nota na prova 2: %2lf\n", aluno[i].nota 2);
		printf("Nota na prova 3: %2lf\n", aluno[i].nota 3);	
		encontrou=1;
	}
}


void maiorMedia(taluno aluno[]){
	int maiorPosicao,i;
	double media,maior;
	maior = (aluno[0].nota1 + aluno[0].nota2 +aluno[0].nota3)/3;
	for(i=0;i<qnt;i++){
		media = (aluno[i].nota1 + aluno[i].nota2 +aluno[i].nota3)/3;
		if(media>maior){
			maior=media;
			maiorPosicao = i;
		}
	}
	printf("O aluno com maior media:\n");
	
	printf("Dados do aluno %d\n",maiorPosicao+1);
		printf("Matricula: %d\n",aluno[maiorPosicao].matricula);
		printf("Nome:%s\n",aluno[maiorPosicao].nome);
		printf("Nota na prova 1: %2lf\n", aluno[maiorPosicao].nota 1);
		printf("Nota na prova 2: %2lf\n", aluno[maiorPosicao].nota 2);
		printf("Nota na prova 3: %2lf\n", aluno[maiorPosicao].nota 3);	
		printf("Media:%.2lf\n",maior);
}


void alunosAprovados(taluno aluno[]){
	int i;
	double media;
	
	printf("Alunos aprovados:\n");
	printf("Matricula-Nome-Media");
	for(i=0;i<qnt;i++){
		media = (aluno[i].nota1 + aluno[i].nota2 + aluno[i].nota3)/3;
		if(media=>6){
			media = (aluno[i].nota1 + aluno[i].nota2 + aluno[i].nota3)/3;
			printf("%d - %s - %.2lf", aluno[i].matricula,aluno[i].nome,media);
		}
	}
	
	printf("Alunos reprovados:\n");
	printf("Matricula-Nome-Media");
		for(i=0;i<qnt;i++){
		media = (aluno[i].nota1 + aluno[i].nota2 + aluno[i].nota3)/3;
		if(media<6){
			media = (aluno[i].nota1 + aluno[i].nota2 + aluno[i].nota3)/3;
			printf("%d - %s - %.2lf", aluno[i].matricula,aluno[i].nome,media);
}


int menu(){
	int op;
	printf("Cadastros de alunos: \n");
	printf("1- Adiciona novo aluno \n");
	printf("2- Mostrar todos os alunos \n");
	printf("3- Salvar em arquivo texto \n");
	printf("4- Carregar arquivo texto \n");
	printf("5- Buscar aluno pelo numero de matricula: \n");
	printf("6- Buscar aluno pelo nome: \n");
	printf("7- Aluno com maior média: \n");
	printf("8- Alunos reprovados e aprovados: \n");
	printf("9- Sair \n");
	scanf("%d",&op);
	return op;
}


int main(){
	int op=0;
	taluno aluno[max];
	do{
		op=menu();
		switch(op){
			
			case 1: cadastrarAluno(aluno);
			break;
			
			case 2: mostrarAlunos(aluno);
			break;
			
			case 3: salvarDados(aluno);
			break;
			
			case 4: carregarDados(aluno);
			break;
			
			case 6: buscarAlunoNome(aluno);
			break;
			
			case 7: maiorMedia(aluno);
			break;
			
			case 8: alunosAprovados(aluno);
			break;
			
			case 9: Saindo...
			break;
		}
		
		getch();
		system("cls");
	}while(op!=0);
	return 0;
}

