//Vamos lá!

#ifndef LEMBRETE_H
#define LEMBRETE_H

typedef struct{
	char descricao[50];
	int num, dia, mes, ano, hora, min;
}LEMBRETE;

void MenuLembrete();
void lerLembrete(LEMBRETE &l);
void cadastrarLembrete(LEMBRETE &l);
void confereNumeroLembrete(LEMBRETE &l);
void editarLembrete();
void excluirLembrete();
void removeBarraN(char texto[]);

#endif
