/*
Sistemas gerenciadores de banco de dados são extremamente eficientes e praticos para
manuseio de arquivos grandes. Internamente sao implementados metodos de manipulacao
de arquivos bastante sofisticados. Uma das operaçoes mais comuns em banco de dados 
relacionais ́e a junçao. Dependendo de como os dados est ̃ao organizados, algoritmos 
mais eficientes ou menos eficientes s ̃ao executados. Quando n ̃ao h ́a nenhuma 
organizaçao dos dados, o método realizado ́e o m ́etodo nested loop (laço aninhado), 
onde todo mundo  ́e comparado com todo mundo. J ́a quando as duas cole ̧c ̃oes
estao ordenadas (ou quando nao  ́e dispendiso ordená-las), o metodo usado é o 
merge join (jun ̧c ̃ao por intercalação).

Considere 2 arquivos (candidatos2021.dat e
candidatos2022.dat) com registros no mesmo
formato, cuja estrutura em linguagem C é apresentada no trecho abaixo. Considere que os
dois arquivos estejam ordenados por CPF e que em um mesmo arquivo n ̃ao haja repeti ̧c ̃ao
de CPF. Fa ̧ca um programa que EFICIENTEMENTE gere um novo arquivo contendo os dados do 
candidatos que se inscreveram no concurso, tanto no ano de 2021 como no ano de 2022
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _Registro Registro;

struct _Registro {
char cpf[15];
char curso[20];
char dataNacimento[11];
char sexo;
char email[40];
char opcaoQuadro;
};

int main(){
    FILE *fa, *fb, *fc;
    fa = fopen("candidatos2021.dat", "rb");
    fb = fopen("candidatos2022.dat", "rb");
    fc = fopen("inscritos.dat", "wb");

    Registro ea, eb;

    fread(&ea, sizeof(Registro), 1, fa);
	fread(&eb, sizeof(Registro), 1, fb);

    while(!feof(fa) && !feof(fb)){
		if(strncmp(ea.cpf, eb.cpf, 15)< 0){
			fwrite(&ea,sizeof(Registro), 1, fc);
			fread(&ea,sizeof(Registro), 1, fa);
		} else{
			fwrite(&eb, sizeof(Registro), 1, fc);
			fread(&eb,sizeof(Registro), 1,fb);
		}
	}
	while(!feof(fa)){
		fwrite(&ea, sizeof(Registro), 1, fc);
		fread(&ea, sizeof(Registro), 1, fa);
	}
	while(!feof(fb)){
		fwrite(&eb, sizeof(Registro), 1, fc);
		fread(&eb, sizeof(Registro), 1, fb);
	}
	fclose(fa);
	fclose(fb);
	fclose(fc);
}