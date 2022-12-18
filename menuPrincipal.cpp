#include <stdio.h>
#include <string.h>
#include <time.h> //necessário para usar localtime() e struct tm
#include <ctype.h>
#include "aniversario.hpp"
#include "compromisso.hpp"
#include "lembrete.hpp"
#include "eventos.hpp"
#include "arquivo.h"
int main(void)
{
	struct tm *data_hora_atual;  
	char mes[15], op;
	time_t segundos;
	time(&segundos);
	data_hora_atual = localtime(&segundos);  
  
	switch (data_hora_atual->tm_mon)
	{
		case 0:
  			strcpy(mes, "janeiro");
  			break;
  		case 1:
  			strcpy(mes, "fevereiro");
  			break;
  		case 2:
  			strcpy(mes, "marco");
  			break;
  		case 3:
  			strcpy(mes, "abril");
  			break;
  		case 4:
  			strcpy(mes, "maio");
  			break;
  		case 5:
  			strcpy(mes, "junho");
  			break;
  		case 6:
  			strcpy(mes, "julho");
  			break;
  		case 7:
  			strcpy(mes, "agosto");
  			break;
  		case 8:
			strcpy(mes, "setembro");
			break;
		case 9:
			strcpy(mes, "outubro");
  			break;
  		case 10:
  			strcpy(mes, "novembro");
  			break;
		case 11:
  			strcpy(mes, "dezembro");
  			break;
  	}
  	
  	int feira = data_hora_atual->tm_wday-1;
  	char diaFeira[7][8] = {"Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sabado", "Domingo"};
  	
	if(feira >= 0 && feira < 5){
		printf("\tMINHA AGENDA\t\t %s-feira, %02d de %s de %d\n", diaFeira[feira], data_hora_atual->tm_mday, mes, data_hora_atual->tm_year+1900);
	}else{
		printf("\tMINHA AGENDA\t\t %s, %02d de %s de %d\n", diaFeira[feira], data_hora_atual->tm_mday, mes, data_hora_atual->tm_year+1900);
	}
	
	printf("\n\tEventos do dia\n");
	
	DataAtual(data_hora_atual->tm_mday, data_hora_atual->tm_mon+1, data_hora_atual->tm_year+1900);
	
	printf("\n ________________________________________________________________\n");
	
	printf("\n\t(A)niversarios\n");
	printf("\t(C)ompromissos\n");
	printf("\t(L)embretes\n");
	printf("\t(P)esquisa\n");
	printf("\t(R)elatorios\n");
	printf("\t(S)air\n");
	printf("\n\tDigite a letra correspondente a opcao desejada: ");
	scanf(" %c", &op);
	op = toupper(op);
	switch (op){
		case 'A':
			opcaoMenu();
		break;
		case 'C':
			MenuCompromissos();
		break;
		case 'L':
			MenuLembrete();
		break;
		case 'P':
			abrirArquivo();
		break;
		case 'R':
			menuRelatorios();
		break;
		case 'S':
			return 0;
		break;
	}
	
	return 0;
}
