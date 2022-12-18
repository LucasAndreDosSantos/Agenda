#ifndef ANIVERSARIO_H
#define ANIVERSARIO_H 

typedef struct{
	int num;
	char nome[30];
	int dia;
	int mes;
	int ano;
}infoA;

void lerA(infoA &p);
void editarA();
void excluirA();
void cadastrarA();
int opcaoMenu();
void removebarraN(char texto[]);
int teste_de_duplicidade(int numero);

#endif
