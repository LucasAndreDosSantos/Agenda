#ifndef COMPROMISSO_H
#define COMPROMISSO_H 
typedef struct{
	
	char descricao[100];
	int numero;
	int dia, mes, ano;
	int hora_inicial, minuto_inicial;
	int hora_final, minuto_final;
	
}COMPROMISSO;

void MenuCompromissos();
void LerCompromisso(COMPROMISSO &a);
void CadastrarCompromisso(COMPROMISSO &a);
void ConfereNumeroCompromisso(COMPROMISSO &a);
void EditarCompromisso();
void ExcluirCompromisso();
void RemoveBarraN(char texto[]);

#endif
