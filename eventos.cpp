#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "eventos.hpp"
#include "lembrete.hpp"
#include "compromisso.hpp"
#include "aniversario.hpp"

void removeBarraN2(char texto[]){
	int indiceUltimoCaractere = strlen(texto) - 1;
	if(texto[indiceUltimoCaractere] == '\n') {
		texto[indiceUltimoCaractere] = '\0';
	}
}

char menuEventos ()
{
	printf ("Qual o tipo de evento voce deseja pesquisar?\n");
	printf ("\n\t(C)ompromisso");
	printf ("\n\t(A)niversario");
	printf ("\n\t(L)embrete");
	printf("\n\tPor (D)ata");
	printf("\n\nDigite a letra correspondente a opcao desejada:");

	char c;
	FILE *arq;

	printf ("\nDigite a opcao: ");
	scanf (" %c", &c);
	if(toupper(c) == 'A'){
		printf ("\n\tAniversario por numero: (A)");
		printf ("\n\tAniversario por nome: (B)");
		scanf (" %c", &c);
	}

	return toupper(c);
}

void abrirArquivo()
{
	FILE *arq;
	int diaP, mesP, anoP;
	char tipo = menuEventos();
	switch (tipo)
	{
		case 'C':
			arq = fopen ("compromisso.txt", "r");
			pesquisarNumero(arq);
		break;
		case 'A':
			arq = fopen ("aniversario.txt", "r");
			pesquisarNumero(arq);
		break;
		case 'L':
			arq = fopen ("lembrete.txt", "r");
			pesquisarNumero(arq);
		break;
		case 'B':
			pesquisarNome ();
		break;
		case 'D':
			pesquisarData();
		break;
	}
}

void pesquisarNumero(FILE *arq)
{
	int numeroEvento, achei = 0;
	FILE *tmp;
	char tipo, lixo[LIXO];

	int numero, dia, mes, ano, horaInicial, minutoInicial, horaFinal, minutoFinal;
	char descricao[100], nome[50];

	if(arq == NULL)
	{
		printf("Erro ao abrir o arquivo\n");
		return;
	}

	printf("\nDigite o numero do evento: ");
	scanf("%d", &numeroEvento);

	if (tipo=='A')
	{
		fgets(nome, sizeof(nome), arq);
		removeBarraN2(nome);
	} else {
		fgets(descricao, sizeof(descricao), arq);
		removeBarraN2(descricao);
	}

	while(numero != numeroEvento)
	{
		if (tipo=='C') {
			fscanf (arq,"%d%d%d%d%d%d%%d", &numero, &dia, &mes, &ano, &horaInicial, &minutoInicial, &horaFinal, &minutoFinal);
			fgets (lixo, sizeof(lixo), arq);
		} else if (tipo=='A'){
			fscanf (arq,"%d%d%d%d", &numero, &dia, &mes, &ano);
			fgets (lixo, sizeof(lixo), arq);
		} else {
			fscanf (arq,"%d%d%d%d%d%d", &numero, &dia, &mes, &ano, &horaInicial, &minutoInicial);
			fgets (lixo, sizeof(lixo), arq);
		}

		if(numero == numeroEvento)
		{
			achei = 1;
			if (tipo=='C')
				printf("\nNumero: %d\nDescricao: %s\nDia: %d/%d\nDe: %d:%d\nAté: %d:%d", numero, descricao, dia, mes, ano, horaInicial, minutoInicial, horaFinal, minutoFinal);
			else if (tipo=='A')
				printf("\nNumero: %d\nDescricao: %s\nDia:%d/%d/%d", numero, nome, dia, mes, ano);
			else
				printf("\nNumero: %d\nDescricao: %s\nDia: %d/%d/%d\nHorario: %d:%d", numero, descricao, dia, mes, ano, horaInicial, minutoInicial);
		}

		fgets(nome, sizeof(nome), arq);
		removeBarraN2(nome);
	}
	fclose(arq);
	if(achei == 0)	//nao encontrou
		printf("Evento inexistente.\n");
}

void pesquisarNome (){

	infoA p;
	FILE *arq;
	int achei = 0;

	arq = fopen("aniversario.txt","r");

	char nome[20];
	printf("Digite o nome a ser pesquisado:");
	fflush(stdin);
	scanf("%s", &nome);

	while(!feof(arq)){

		fscanf(arq,"%s\n%d %d %d %d",  &p.nome, &p.num, &p.dia, &p.mes, &p.ano);

		if(strcmp(nome, p.nome) == 0){
			achei++;
			printf("\nNumero: %d\nDescricao: %s\nDia:%d/%d/%d", p.num, p.nome, p.dia, p.mes, p.ano);
		}
	}
	fclose(arq);
	if(achei == 0)	//nao encontrou
		printf("Evento inexistente.\n");
}

void pesquisarData()
{
	struct tm *data_hora_atual;
	time_t segundos;
	time(&segundos);
	data_hora_atual = localtime(&segundos);

	int n, achei = 0;
	FILE *arq, *tmp;
	char tipo, lixo[LIXO];

	int numero, dia, mes, ano, horaInicial, minutoInicial, horaFinal, minutoFinal;
	char descricao[100], nome[50];
	int diaP, mesP, anoP;

	if(arq == NULL)
	{
		printf("Erro ao abrir o arquivo\n");
		return;
	}

	printf("\nDigite a data a ser pesquisada.\n");
	printf("Dia:\n");
	scanf("%d", &diaP);
	printf("Mes:\n");
	scanf("%d", &mesP);
	printf("Ano:\n");
	scanf("%d", &anoP);

	float resultado;
	float resulado = (anoP * 365.25) + (mesP * 30.4167) + diaP;
	char v[3];
	v[0] = 'A';
	v[1] = 'C';
	v[2] = 'L';
	for(int i = 0; i < 3; i++){
		tipo = v[i];
		switch (tipo)
		{
			case 'C':
				arq = fopen ("compromisso.txt", "r");
			break;
			case 'A':
				arq = fopen ("aniversario.txt", "r");
			break;
			case 'L':
				arq = fopen ("lembrete.txt", "r");
			break;
		}
		if (tipo=='A')
		{
			fgets(nome, sizeof(nome), arq);
			removeBarraN2(nome);
		} else {
			fgets(descricao, sizeof(descricao), arq);
			removeBarraN2(descricao);
		}

		while(!feof(arq))
		{
			if (tipo=='C') {
				fscanf (arq,"%d%d%d%d%d%d%d%d", &numero, &dia, &mes, &ano, &horaInicial, &minutoInicial, &horaFinal, &minutoFinal);
				fgets (lixo, sizeof(lixo), arq);
			} else if (tipo=='A'){
				fscanf (arq,"%d%d%d%d", &numero, &dia, &mes, &ano);
				fgets (lixo, sizeof(lixo), arq);
				ano = data_hora_atual->tm_year+1900;
			} else {
				fscanf (arq,"%d%d%d%d%d%d", &numero, &dia, &mes, &ano, &horaInicial, &minutoInicial);
				fgets (lixo, sizeof(lixo), arq);
			}
			resultado = (ano * 365.25) + (mes * 30.4167) + dia;

			if(resulado == resultado)
			{
				achei = 1;
				if (tipo=='C')
					printf("\nNumero: %d\nDescricao: %s\nDia: %d/%d\nDe: %d:%d\nAté: %d:%d", numero, descricao, dia, mes, ano, horaInicial, minutoInicial, horaFinal, minutoFinal);
				else if (tipo=='A')
					printf("\nNumero: %d\nDescricao: %s\nDia:%d/%d/%d", numero, nome, dia, mes, ano);
				else
					printf("\nNumero: %d\nDescricao: %s\nDia: %d/%d/%d\nHorario: %d:%d", numero, descricao, dia, mes, ano, horaInicial, minutoInicial);
			}

			if (tipo=='A')
			{
				fgets(nome, sizeof(nome), arq);
				removeBarraN2(nome);
			} else {
				fgets(descricao, sizeof(descricao), arq);
				removeBarraN2(descricao);
			}
		}
		fclose(arq);
		if(achei == 0)	//nao encontrou
		printf("Evento inexistente.\n");
	}
}

void DataAtual(int diaAt, int mesAt, int anoAt)
{
	int n, anoL, achei, livre = 0;
	FILE *arq, *tmp;
	char tipo, lixo[LIXO];

	int numero, dia, mes, ano, horaInicial, minutoInicial, horaFinal, minutoFinal;
	char descricao[100], nome[50];

	if(arq == NULL)
	{
		printf("Erro ao abrir o arquivo\n");
		return;
	}

	float resultado;
	float resulado = (anoAt * 8760) + (mesAt * 730) + (diaAt * 24);
	char v[3];
	v[0] = 'A';
	v[1] = 'C';
	v[2] = 'L';
	for(int i = 0; i < 3; i++){
		tipo = v[i];
		achei = 0;
		switch (tipo)
		{
			case 'C':
				arq = fopen ("compromisso.txt", "r");
			break;
			case 'A':
				arq = fopen ("aniversario.txt", "r");
			break;
			case 'L':
				arq = fopen ("lembrete.txt", "r");
			break;
		}
		if (tipo=='A')
		{
			fgets(nome, sizeof(nome), arq);
			removeBarraN2(nome);
		} else {
			fgets(descricao, sizeof(descricao), arq);
			removeBarraN2(descricao);
		}

		while(!feof(arq))
		{
			if (tipo=='C') {
				fscanf (arq,"%d%d%d%d%d%d%d%d", &numero, &dia, &mes, &ano, &horaInicial, &minutoInicial, &horaFinal, &minutoFinal);
				fgets (lixo, sizeof(lixo), arq);
			} else if (tipo=='A'){
				fscanf (arq,"%d%d%d%d", &numero, &dia, &mes, &anoL);
				fgets (lixo, sizeof(lixo), arq);
				ano = anoAt;
			} else {
				fscanf (arq,"%d%d%d%d%d%d", &numero, &dia, &mes, &ano, &horaInicial, &minutoInicial);
				fgets (lixo, sizeof(lixo), arq);
			}
			resultado = (ano * 8760) + (mes * 730) + (dia * 24);

			if(resulado == resultado)
			{
				achei++;
				livre++;
				if (tipo=='C')
					printf("\t%s [%02d:%02d - %02d:%02d]\n", descricao, horaInicial, minutoInicial, horaFinal, minutoFinal);
				else if (tipo=='A')
					printf("\n\tAniversario: %s\n", nome);
				else
					printf("\t%s - %02d:%02d\n", descricao, horaInicial, minutoInicial);
			}

			if (tipo=='A')
			{
				fgets(nome, sizeof(nome), arq);
				removeBarraN2(nome);
			} else {
				fgets(descricao, sizeof(descricao), arq);
				removeBarraN2(descricao);
			}
		}
		fclose(arq);
		if(achei == 0){
			if(tipo == 'A')	//nao encontrou aniversarios
			printf("\n\tSem aniversarios hoje.\n");
			if(tipo == 'C')	//nao encontrou compromissos
				printf("\tSem compromissos hoje.\n");
			if(tipo == 'L')	//nao encontrou lembretes
				printf("\tSem lembretes para hoje.\n");
		}
	}
	if(livre == 0){
			printf("\n\t -> Dia livre hoje, bom descanso. ^^\n");
		}
}
