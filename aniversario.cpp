#include"aniversario.hpp"
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int opcaoMenu(){

	char op;
	printf("O que voce deseja?\n");
	printf("\t(C)adastrar\n");
	printf("\t(E)xcluir\n");
	printf("\t(A)lterar\n");
	printf("\t(F)inalizar\n");
	printf("\n");
	printf("\nDigite a letra correspondente a opcao desejada:");
	scanf(" %c", &op);
	op = toupper(op);

	do{
		switch(op){
			case 'C':
				cadastrarA();
				printf("-----------------------------------------------------------------------------\n");
				break;

			case 'E':
				excluirA();
				printf("-----------------------------------------------------------------------------\n");
				break;

			case 'A':
				editarA();
				printf("-----------------------------------------------------------------------------\n");
				break;

			case 'F':
				return 1;
				printf("-----------------------------------------------------------------------------\n");
				break;

			default:
				printf("Opcao invalida!\n");
				printf("-----------------------------------------------------------------------------\n");
				return 1;

		}


	}while(op != 'f');

	return 0;
}

void lerA(infoA &p){
	printf("Digite o nome:\n ");
	fflush(stdin);
	fgets(p.nome,sizeof(p.nome),stdin);
	printf("Digite o numero:\n");
	scanf("%d", &p.num);

	int resultado;
	resultado=teste_de_duplicidade(p.num);

	if(resultado==0){
		printf("Valor ja existente!\n");

		printf("Digite outro numero:\n");
		scanf("%d", &p.num);
	}

	printf("Digite o dia do nascimento:\n");
	scanf("%d", &p.dia);
	printf("Digite o mes do nascimento:\n");
	scanf("%d", &p.mes);
	printf("Digite o ano do nascimento:\n");
	scanf("%d", &p.ano);
}

void cadastrarA(){

	infoA p;

	FILE *arq = fopen("aniversario.txt","a");

	lerA(p);
	fprintf(arq, "%s\n%d %d %d %d\n", p.nome, p.num, p.dia, p.mes, p.ano);
	printf("\n**");
	printf("Aniversario cadastrado com sucesso!");
}

int teste_de_duplicidade(int numero){

	FILE *arq;

	arq = fopen("aniversario.txt","r");

	while(!feof(arq)){
		infoA p;

		fscanf(arq,"%s\n%d %d %d %d",  &p.nome, &p.num, &p.dia, &p.mes, &p.ano);

		if(numero==p.num){
			return 0;
		}
	}

	fclose(arq);

	return 1;
}

void editarA(){

	FILE *arq, *arq2;
	int num;
	infoA p;
	char lixo[10];

	printf("Digite o numero do aniversariante:\n");
	scanf("%d", &num);

	arq = fopen("aniversario.txt","r");
	arq2 = fopen("auxiliador.txt","w");

	fgets(p.nome, 30, arq);

	while(!feof(arq)){
		fscanf(arq,"%d", &p.num);
		fscanf(arq,"%d", &p.dia);
		fscanf(arq,"%d", &p.mes);
		fscanf(arq,"%d", &p.ano);
		fgets(lixo, sizeof(lixo), arq);

		if(num==p.num){
			lerA(p);
			fprintf(arq2,"%s\n%d %d %d %d\n", p.nome, p.num, p.dia, p.mes, p.ano);
		}else{
			fprintf(arq2,"%s\n%d %d %d %d\n", p.nome, p.num, p.dia, p.mes, p.ano);
		}

		fgets(p.nome, 30, arq);
		removebarraN(p.nome);

	}

	fclose(arq);
	fclose(arq2);

	remove("aniversario.txt");
	rename("auxiliador.txt","aniversario.txt");
	printf("\n**");
	printf("Aniversario editado com sucesso!");
}

void excluirA(){

	FILE *arq, *arq2;
	int num;
	infoA p;
	char lixo[10];

	printf("Digite o numero do aniversariante:\n");
	scanf("%d", &num);

	arq = fopen("aniversario.txt","r");
	arq2 = fopen("auxiliador.txt","w");

	fgets(p.nome, 30, arq);
	removebarraN(p.nome);

	while(!feof(arq)){
		fscanf(arq,"%d", &p.num);
		fscanf(arq,"%d", &p.dia);
		fscanf(arq,"%d", &p.mes);
		fscanf(arq,"%d", &p.ano);
		fgets(lixo, sizeof(lixo), arq);

		if(num!=p.num)
			fprintf(arq2,"%s\n%d %d %d %d\n", p.nome, p.num, p.dia, p.mes, p.ano);

		fgets(p.nome, 30, arq);
		removebarraN(p.nome);
	}

	fclose(arq);
	fclose(arq2);

	remove("aniversario.txt");
	rename("auxiliador.txt","aniversario.txt");
	printf("\n**");
	printf("Aniversario excluido com sucesso!");
}

void removebarraN(char texto[]){

	int indiceUltimoCaractere = strlen(texto) - 1;

	if(texto[indiceUltimoCaractere] == '\n')
		texto[indiceUltimoCaractere] = '\0';
}
