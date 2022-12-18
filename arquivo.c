#include<stdio.h>
#include<string.h>
#include"arquivo.h"

void menuRelatorios(){
	char op;
	printf ("   Qual relatorio dos eventos voce deseja?\n");
	printf ("\n\tRelatorio (I)nteiro");
	printf ("\n\tRelatorio por (P)eriodo");
	printf ("\n\tRelatorio (A)niversarios");
	printf ("\n\tRelatorio (L)embretes");
	printf ("\n\tRelatorio (C)ompromissos");
	printf("\n\n   Digite a letra correspondente a opcao desejada:");
	scanf(" %c",&op);
	switch(op){
		case 'I':
			RelatorioC();
		break;
		case 'P':
			RelatorioP();
		break;
		case 'A':
			RelatorioEA();
		break;
		case 'L':
			RelatorioEL();
		break;
		case 'C':
			RelatorioEC();
		break;
	}
}

void removeBarraN1(char texto[]){
    int indiceUltimoCaractere = strlen(texto) - 1;
    if(texto[indiceUltimoCaractere] == '\n') {
        texto[indiceUltimoCaractere] = '\0';
    }
}

 void RelatorioC (){

    FILE * arq1 , *arq2 , *arq3 , *arq4;
    char arquivo4[100], lixo[10];

    infoA a;
    LEMBRETE l ;
    COMPROMISSO  c ;

    arq1 = fopen("aniversario.txt","r");

    if (arq1 == NULL){
        printf ("erro no arquivo 1:\n");
    }

    printf ("arquivo 1 aberto:\n");

    arq2 = fopen("lembrete.txt","r");

    if (arq2 == NULL){
        printf ("erro no arquivo 2:\n");
    }

    printf ("arquivo 2 aberto:\n");

    arq3 = fopen("compromisso.txt","r");

    if (arq3 == NULL){
        printf ("erro no arquivo 3:\n");
    }

    printf ("arquivo 3 aberto:\n");

    printf ("digite o nome do arquivo:\n");
    scanf ("%s",&arquivo4);
    fgets(lixo, sizeof(lixo), arq1);

    arq4 = fopen(arquivo4, "w");

    if (arq4 == NULL){
        printf ("erro no arquivo 4:\n");
    }

    printf ("arquivo 4 aberto:\n");

    fgets(a.nome,100,arq1);
    removeBarraN1(a.nome);

    while (!feof(arq1)){

        fscanf (arq1,"%d %d %d %d",&a.num,&a.dia,&a.mes,&a.ano);
        fgets(lixo, sizeof(lixo), arq1);
        fprintf (arq4," %d/%d/%d :A: %s",a.dia,a.mes,a.ano,a.nome);
        fgets(a.nome, 100,arq1);
        removeBarraN1(a.nome);

    }

    fgets (l.descricao,100,arq2);
    removeBarraN1(l.descricao);

     while (!feof(arq2)){

        fscanf (arq2,"%d %d %d %d %d %d",&l.num,&l.dia,&l.mes,&l.ano,&l.hora,&l.min);
		fgets(lixo, sizeof(lixo), arq2);
        fprintf (arq4," %d/%d/%d :L: %s - %d:%d",l.dia,l.mes,l.ano,l.descricao,l.hora,l.min);
        fgets (l.descricao,100,arq2);
        removeBarraN1(l.descricao);

    }
    fgets (c.descricao,100,arq3);
    removeBarraN1(c.descricao);

    while (!feof(arq3)){
        fscanf (arq3,"%d %d %d %d %d %d %d %d",&c.numero,&c.dia,&c.mes,&c.ano,&c.hora_inicial,&c.minuto_inicial,&c.hora_final,&c.minuto_final);
        fgets(lixo, sizeof(lixo), arq1);
        fprintf (arq4," %d/%d/%d :C: %s [%d:%d - %d:%d]",c.dia,c.mes,c.ano,c.descricao,c.hora_inicial,c.minuto_inicial,c.hora_final,c.minuto_final);

        fgets (c.descricao,100,arq3);
        removeBarraN1(c.descricao);
   }
   fclose(arq1);
   fclose(arq2);
   fclose(arq3);
   fclose(arq4);
}
void RelatorioP() {

    infoA a;
    LEMBRETE l ;
    COMPROMISSO  c ;

	FILE * arq1 , *arq2 , *arq3 , *arq4;
    char arquivo4[100], lixo[10];
	int diaI,mesI,anoI,diaF,mesF,anoF;

    arq1 = fopen("aniversario.txt","r");

    if (arq1 == NULL){
        printf ("erro no arquivo 1:\n");
    }

    printf ("arquivo 1 aberto:\n");

    arq2 = fopen("lembrete.txt","r");

    if (arq2 == NULL){
        printf ("erro no arquivo 2:\n");
    }

    printf ("arquivo 2 aberto:\n");

    arq3 = fopen("compromisso.txt","r");

    if (arq3 == NULL){
        printf ("erro no arquivo 3:\n");
    }

    printf ("arquivo 3 aberto:\n");

    printf ("digite o nome do arquivo:\n");
    scanf ("%s",&arquivo4);
    fgets(lixo, sizeof(lixo), arq1);

    arq4 = fopen(arquivo4, "w");

    if (arq4 == NULL){
        printf ("erro no arquivo 4:\n");
    }

    printf ("arquivo 4 aberto:\n");

	printf ("digite uma data inicial:\n");//pedir ao usuario o periodo que ele deseja
	scanf  ("%d%d%d",&diaI,&mesI,&anoI);
	fgets(lixo, sizeof(lixo), arq1);
	printf ("digite uma data final:\n");
	scanf  ("%d%d%d",&diaF,&mesF,&anoF);
    fgets(lixo, sizeof(lixo), arq1);

	fgets(a.nome,100,arq1);
    removeBarraN1(a.nome);

	while(!feof(arq1)){// vai verificar se as datas de aniversario estao nesse periodo

		fscanf (arq1,"%d %d %d",&a.dia,&a.mes,&a.ano);
		fgets(lixo, sizeof(lixo), arq1);
		if ((anoI < a.ano) && (anoF > a.ano)){
				if ((mesI < a.mes) && (mesF > a.mes)){
						if ((diaI < a.dia) && (diaF > a.dia)){
							fprintf (arq1, "%d/%d/%d :A: %s",a.dia,a.mes,a.ano,a.nome);
						}
				}
		    	if (mesI == a.mes){
	    			if (diaI < a.dia){
	    				fprintf (arq1, "%d/%d/%d :A: %s",a.dia,a.mes,a.ano,a.nome);
	        		}
	        	}
	        	if (mesF == a.mes){
	    			if (diaF < a.dia){
	    				fprintf (arq1, "%d/%d/%d :A: %s",a.dia,a.mes,a.ano,a.nome);
	        		}
	        	}
		}
	    if (anoI == a.ano){
			if (mesI < a.mes){
				if (diaI < a.dia){
					fprintf (arq1, "%d/%d/%d :A: %s",a.dia,a.mes,a.ano,a.nome);
				}
			}
		  	if (mesI == a.mes){
	    		if (diaI < a.dia){
	    			fprintf (arq1, "%d/%d/%d :A: %s",a.dia,a.mes,a.ano,a.nome);
	        	}
	        }
     	}
	  	if (anoF == a.ano){
	    	if (mesF > a.mes){
				if (diaF > a.dia){
					fprintf (arq1, "%d/%d/%d :A: %s",a.dia,a.mes,a.ano,a.nome);
				}
			}
		  	if (mesF == a.mes){
	    		if (diaF > a.dia){
	    			fprintf (arq1, "%d/%d/%d :A: %s",a.dia,a.mes,a.ano,a.nome);
	        	}
	        }
     	}
		fgets(a.nome, 100,arq1);
        removeBarraN1(a.nome);
	}
	fgets(l.descricao,100,arq2);
    removeBarraN1(l.descricao);

	while(!feof(arq2)){// vai verificar se os lembretes estao nesse periodo

			fscanf (arq2,"%d %d %d",&l.dia,&l.mes,&l.ano);
		    fgets(lixo, sizeof(lixo), arq1);
		if ((anoI < l.ano) && (anoF > l.ano)){
				if ((mesI < l.mes) && (anoF > l.mes)){
						if ((diaI < l.dia) && (diaF > l.dia)){
							fprintf (arq2, "%d/%d/%d :L: %s - %d:%d",l.dia,l.mes,l.ano,l.descricao,l.hora,l.min);
						}
				}
		    	if (mesI == l.mes){

    		if (diaI < l.dia){
	    			fprintf (arq2, "%d/%d/%d :L: %s - %d:%d",l.dia,l.mes,l.ano,l.descricao,l.hora,l.min);
	        	}
	        }
     	}
	  	if (anoF == l.ano){
	    	if (mesF > l.mes){
				if (diaF > l.dia){
					fprintf (arq2, "%d/%d/%d :L: %s - %d:%d",l.dia,l.mes,l.ano,l.descricao,l.hora,l.min);
				}
			}
		  	if (mesF == l.mes){
	    		if (diaF > l.dia){
	    			fprintf (arq2, "%d/%d/%d :L: %s - %d:%d",l.dia,l.mes,l.ano,l.descricao,l.hora,l.min);
	        	}
	        }
     	}
		fgets(l.descricao, 100,arq2);
        removeBarraN1(l.descricao);
	}

		fgets(c.descricao,100,arq3);
        removeBarraN1(c.descricao);

	while(!feof(arq3)){// vai verificar se as datas de aniversario estao nesse periodo

		fscanf (arq3,"%d %d %d",&c.dia,&c.mes,&c.ano);
        fgets(lixo, sizeof(lixo), arq1);

		if ((anoI < c.ano) && (anoF > c.ano)){
				if ((mesI < c.mes) && (anoF > c.mes)){
						if ((diaI < a.dia) && (diaF > c.dia)){
							fprintf (arq3, "%d/%d/%d :C: %s",c.dia,c.mes,c.ano,c.descricao,c.hora_inicial,c.hora_final);
						}
				}
		    	if (mesI == c.mes){
	    			if (diaI < c.dia){
	    				fprintf (arq3, "%d/%d/%d :C: %s",c.dia,c.mes,c.ano,c.descricao,c.hora_inicial,c.hora_final);
	        		}
	        	}
	        	if (mesF == c.mes){
	    			if (diaF < c.dia){
	    				fprintf (arq3, "%d/%d/%d :C: %s",c.dia,c.mes,c.ano,c.descricao,c.hora_inicial,c.hora_final);
	        		}
	        	}
		}
	    if (anoI == c.ano){
			if (mesI < c.mes){
				if (diaI < c.dia){
					fprintf (arq3, "%d/%d/%d :C: %s",c.dia,c.mes,c.ano,c.descricao,c.hora_inicial,c.hora_final);
				}
			}
		  	if (mesI == c.mes){
	    		if (diaI < c.dia){
	    			fprintf (arq3, "%d/%d/%d :C: %s",c.dia,c.mes,c.ano,c.descricao,c.hora_inicial,c.hora_final);
	        	}
	        }
     	}
	  	if (anoF == c.ano){
	    	if (mesF > c.mes){
				if (diaF > c.dia){
					fprintf (arq3, "%d/%d/%d :C: %s",c.dia,c.mes,c.ano,c.descricao,c.hora_inicial,c.hora_final);
				}
			}
		  	if (mesF == c.mes){
	    		if (diaF > c.dia){
	    			fprintf (arq3, "%d/%d/%d :C: %s",c.dia,c.mes,c.ano,c.descricao,c.hora_inicial,c.hora_final);
	        	}
	        }
     	}
		fgets(c.descricao, 100,arq3);
        removeBarraN1(c. descricao);
	}
   fclose(arq1);
   fclose(arq2);
   fclose(arq3);
   fclose(arq4);
}
void RelatorioEA() {

	infoA a;
	char arquivo5[100], lixo[10];

    FILE *arq1 = fopen("aniversario.txt","r");

    if (arq1 == NULL){
        printf ("erro no arquivo 1:\n");
    }
    printf ("arquivo 1 aberto:\n");

    printf ("digite o nome do arquivo de saida para aniversario:\n");
    scanf ("%s",&arquivo5);
    fgets(lixo, sizeof(lixo), arq1);

    FILE *arq5 = fopen(arquivo5,"w");

    if (arq5 == NULL){
    	printf ("erro no arquivo 5:\n");
	}

	printf ("arquivo 5 aberto:\n");

	fgets(a.nome,100,arq1);
    removeBarraN1(a.nome);

    while (!feof(arq1)){

        fscanf (arq1,"%d %d %d %d",&a.num,&a.dia,&a.mes,&a.ano);
        fgets(lixo, sizeof(lixo), arq1);
        fprintf (arq5," %d/%d/%d :A: %s",a.dia,a.mes,a.ano,a.nome);
        fgets(a.nome, 100,arq1);
        removeBarraN1(a.nome);
    }
	fclose(arq1);
   fclose(arq5);
}

void RelatorioEL(){

	LEMBRETE l ;

	char arquivo6[100], lixo[10];
	FILE *arq2 = fopen("lembrete.txt","r");

    if (arq2 == NULL){
        printf ("erro no arquivo 2:\n");
    }
    printf ("arquivo 2 aberto:\n");

    printf ("digite o nome do arquivo de saida para lembrete:\n");
    scanf ("%s",&arquivo6);
    fgets(lixo, sizeof(lixo), arq2);

    FILE *arq6 = fopen(arquivo6,"w");

    if (arq6 == NULL){
    	printf ("erro no arquivo 6:\n");
	}
	printf ("arquivo 6 aberto:\n");

    fgets (l.descricao,100,arq2);
    removeBarraN1(l.descricao);

    while (!feof(arq2)){

        fscanf (arq2,"%d %d %d %d %d %d",&l.num,&l.dia,&l.mes,&l.ano,&l.hora,&l.min);
        fgets(lixo, sizeof(lixo), arq2);
        fprintf (arq6," %d/%d/%d :L: %s - %d:%d",l.dia,l.mes,l.ano,l.descricao,l.hora,l.min);
        fgets (l.descricao,100,arq2);
        removeBarraN1(l.descricao);
    }
	fclose(arq2);
	fclose(arq6) ;
}
void RelatorioEC(){

	COMPROMISSO c;

    char arquivo7[100], lixo[10];
    FILE *arq3 = fopen("compromisso.txt","r");

    if (arq3 == NULL){
        printf ("erro no arquivo 3:\n");
    }
   printf ("arquivo 3 aberto:\n");

    printf ("digite o nome do arquivo de saida para compromisso:\n");
    scanf ("%s",&arquivo7);
    fgets(lixo, sizeof(lixo), arq3);

    FILE *arq7 = fopen(arquivo7,"w");

    if (arq7 == NULL){
    	printf ("erro no arquivo 7:\n");
	}
	printf ("arquivo 7 aberto:\n");

	fgets (c.descricao,100,arq3);
           removeBarraN1(c.descricao);

    while (!feof(arq3)){
        fscanf (arq3,"%d %d %d %d %d %d %d %d",&c.numero,&c.dia,&c.mes,&c.ano,&c.hora_inicial,&c.minuto_inicial,&c.hora_final,&c.minuto_final);
        fgets(lixo, sizeof(lixo), arq3);
        fprintf (arq7," %d/%d/%d :C: %s [%d:%d - %d:%d]",c.dia,c.mes,c.ano,c.descricao,c.hora_inicial,c.minuto_inicial,c.hora_final,c.minuto_final);
        fgets (c.descricao,100,arq3);
        removeBarraN1(c.descricao);
   }
   fclose(arq3);
   fclose(arq7);
}

