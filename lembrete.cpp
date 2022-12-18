//Lá vamos nós!!

#include "lembrete.hpp"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void MenuLembrete(){
	LEMBRETE l;
	char op;
	printf("O que voce deseja?\n");
	printf("\n(C)adastrar\n");
	printf("(E)ditar\n");
	printf("E(X)cluir\n");
	printf("\nDigite a letra correspondente a opcao desejada:");
	scanf(" %c",&op);
	op = toupper(op);
	switch(op){
		case 'E':
			editarLembrete();
		break;
		case 'X':
			excluirLembrete();
		break;
		case 'C':
			lerLembrete(l);
			cadastrarLembrete(l);
		break;
	}
}

void lerLembrete(LEMBRETE &l){
	printf("\nDigite a descricao do lembrete:\n");
	fflush(stdin);
	fgets(l.descricao,sizeof(l.descricao),stdin);
	printf("O numero:\n");
	scanf("%d", &l.num);
	confereNumeroLembrete(l);
	printf("O dia:\n");
	scanf("%d", &l.dia);
	printf("O mes:\n");
	scanf("%d", &l.mes);
	printf("O ano:\n");
	scanf("%d", &l.ano);
	printf("A hora:\n");
	scanf("%d", &l.hora);
	printf("Os minutos:\n");
	scanf("%d", &l.min);
}

void cadastrarLembrete(LEMBRETE &l){
	FILE *arq;
	arq = fopen("lembrete.txt", "a");
	fputs(l.descricao, arq);
	fprintf(arq, "\n%d ", l.num);
	fprintf(arq, "%d ", l.dia);
	fprintf(arq, "%d ", l.mes);
	fprintf(arq, "%d ", l.ano);
	fprintf(arq, "%d ", l.hora);
	fprintf(arq, "%d\n", l.min);
	printf("\n**");
	printf("Lembrete cadastrado com sucesso!");
	fclose(arq);
}

void confereNumeroLembrete(LEMBRETE &l){

	LEMBRETE j;
	FILE *arq;
	arq = fopen("lembrete.txt", "a+");

	fgets(j.descricao, 50, arq);
	fscanf(arq, "%d", &j.num);
	fscanf(arq, "%d", &j.dia);
	fscanf(arq, "%d", &j.mes);
	fscanf(arq, "%d", &j.ano);
	fscanf(arq, "%d", &j.hora);
	fscanf(arq, "%d", &j.min);
	while(!feof(arq)){
		if(l.num == j.num){
			printf("Numero ja existente, insira outro:\n");
			scanf("%d", &l.num);
		}
		fgets(j.descricao, 50, arq);
		fscanf(arq, "%d", &j.num);
		fscanf(arq, "%d", &j.dia);
		fscanf(arq, "%d", &j.mes);
		fscanf(arq, "%d", &j.ano);
		fscanf(arq, "%d", &j.hora);
		fscanf(arq, "%d", &j.min);
	}
	fclose(arq);
}

void editarLembrete(){
	FILE *arqOriginal;
	FILE *arqNovo;
	arqOriginal = fopen("lembrete.txt", "r");
	arqNovo = fopen("arquivo.txt", "w");
	int n;
	char CaminhaoDeLixo[10];
	printf("\nDigite o numero do lembrete a ser editado:\n");
	scanf("%d", &n);
	LEMBRETE v;
	fgets(v.descricao, 50, arqOriginal);
	fscanf(arqOriginal, "%d", &v.num);
	fscanf(arqOriginal, "%d", &v.dia);
	fscanf(arqOriginal, "%d", &v.mes);
	fscanf(arqOriginal, "%d", &v.ano);
	fscanf(arqOriginal, "%d", &v.hora);
	fscanf(arqOriginal, "%d", &v.min);
	fgets(CaminhaoDeLixo, 10, arqOriginal);
	removeBarraN(v.descricao);

	while(!feof(arqOriginal)){
		if(v.num == n){
			lerLembrete(v);
			fputs(v.descricao, arqNovo);
			fprintf(arqNovo, "\n%d ", v.num);
			fprintf(arqNovo, "%d ", v.dia);
			fprintf(arqNovo, "%d ", v.mes);
			fprintf(arqNovo, "%d ", v.ano);
			fprintf(arqNovo, "%d ", v.hora);
			fprintf(arqNovo, "%d\n", v.min);
		}else{
			fputs(v.descricao, arqNovo);
			fprintf(arqNovo, "\n%d ", v.num);
			fprintf(arqNovo, "%d ", v.dia);
			fprintf(arqNovo, "%d ", v.mes);
			fprintf(arqNovo, "%d ", v.ano);
			fprintf(arqNovo, "%d ", v.hora);
			fprintf(arqNovo, "%d\n", v.min);
		}

		fgets(v.descricao, 50, arqOriginal);
		fscanf(arqOriginal, "%d", &v.num);
		fscanf(arqOriginal, "%d", &v.dia);
		fscanf(arqOriginal, "%d", &v.mes);
		fscanf(arqOriginal, "%d", &v.ano);
		fscanf(arqOriginal, "%d", &v.hora);
		fscanf(arqOriginal, "%d", &v.min);
		fgets(CaminhaoDeLixo, 10, arqOriginal);
		removeBarraN(v.descricao);
	}
	fclose(arqOriginal);
	fclose(arqNovo);

	remove("lembrete.txt");
	rename("arquivo.txt", "lembrete.txt");
	printf("\n**");
	printf("Lembrete editado com sucesso!");
}

void excluirLembrete(){
	FILE *arqOriginal;
	FILE *arqNovo;
	arqOriginal = fopen("lembrete.txt", "r");
	arqNovo = fopen("arquivo.txt", "w");
	int n;
	char CaminhaoDeLixo[10];
	printf("\nDigite o numero do lembrete a ser excluido: ");
	scanf("%d", &n);
	LEMBRETE v;
	fgets(v.descricao, 50, arqOriginal);
	removeBarraN(v.descricao);
	fscanf(arqOriginal, "%d", &v.num);
	fscanf(arqOriginal, "%d", &v.dia);
	fscanf(arqOriginal, "%d", &v.mes);
	fscanf(arqOriginal, "%d", &v.ano);
	fscanf(arqOriginal, "%d", &v.hora);
	fscanf(arqOriginal, "%d", &v.min);
	fgets(CaminhaoDeLixo, 10, arqOriginal);

	while(!feof(arqOriginal)){
		if(v.num == n){

		}else{
			fputs(v.descricao, arqNovo);
			fprintf(arqNovo, "\n%d ", v.num);
			fprintf(arqNovo, "%d ", v.dia);
			fprintf(arqNovo, "%d ", v.mes);
			fprintf(arqNovo, "%d ", v.ano);
			fprintf(arqNovo, "%d ", v.hora);
			fprintf(arqNovo, "%d\n", v.min);
		}

		fgets(v.descricao, 50, arqOriginal);
		removeBarraN(v.descricao);
		fscanf(arqOriginal, "%d", &v.num);
		fscanf(arqOriginal, "%d", &v.dia);
		fscanf(arqOriginal, "%d", &v.mes);
		fscanf(arqOriginal, "%d", &v.ano);
		fscanf(arqOriginal, "%d", &v.hora);
		fscanf(arqOriginal, "%d", &v.min);
		fgets(CaminhaoDeLixo, 10, arqOriginal);
	}
	fclose(arqOriginal);
	fclose(arqNovo);

	remove("lembrete.txt");
	rename("arquivo.txt", "lembrete.txt");
	printf("\n**");
	printf("Lembrete excluido com sucesso!");
}

void removeBarraN(char texto[]){ //função utilizada para tirar o \n da string depois de utilizar o fgets
	int indiceUltimoCaractere = strlen(texto) - 1;
	if(texto[indiceUltimoCaractere] == '\n') {
		texto[indiceUltimoCaractere] = '\0';
	}
}
