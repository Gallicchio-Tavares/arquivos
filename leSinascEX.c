// http://10.101.1.135:1234/sinasc.csv.gz
// Teresina = 221100
// Curitiba = 410690
// ordenado por município e por data de nascimento
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 2048

// index,CODMUNRES,data_nasc,PESO,SEMAGESTAC,adeq_peso_id_gestac,SEXO,IDANOMAL,RACACOR,ESCMAEAGR1,ESTCIVMAE,IDADEMAE,CONSULTAS,PARTO,STTRABPART,KOTELCHUCK,APGAR5,TPROBSON

struct DadosNascimento {
    int index;
    int CODMUNRES;
    char data_nasc[11];
    int PESO;
    int SEMAGESTAC;
    float adeq_peso_id_gestac;
    int SEXO;
    int IDANOMAL;
    int RACACOR;
    int ESCMAEAGR1;
    int ESTCIVMAE;
    int IDADEMAE;
    int CONSULTAS;
    int PARTO;
    int STTRABPART;
    int KOTELCHUCK;
    int APGAR5;
    int TPROBSON;
};

void separaData(char* data, int *dia, int *mes, int *ano)
{   // atoi() significa ascii to integer
    *ano = atoi(strtok(data,"-")); // dividir a string no hífen
    *mes = atoi(strtok(NULL,"-"));
    *dia = atoi(strtok(NULL,"-"));
}
// 1. Qual é o peso médio dos nascidos em 2015 em Teresina e em Curitiba?
float totalPesoTeresina = 0;
float totalPesoCuritiba = 0;
int contadorTeresina = 0;
int contadorCuritiba = 0;

void processa(struct DadosNascimento* dn) {
    int dia, mes, ano;

    separaData(dn->data_nasc, &dia, &mes, &ano);
    if(ano == 2015){
        if(dn->CODMUNRES == 221100) {
            totalPesoTeresina += dn->PESO;
            contadorTeresina++;
        } else if(dn->CODMUNRES == 410690){
            totalPesoCuritiba += dn->PESO;
            contadorCuritiba++;
        }
    }    
}
// 2. Indique, por ano, a quantidade de prematuros nascidos na cidade do Rio de Janeiro (330455)
int contPrem12 = 0;
int contPrem13 = 0;
int contPrem14 = 0;
int contPrem15 = 0;
int contPrem16 = 0;
int contPrem17 = 0;
int contPrem18 = 0;
int contPrem19 = 0;

void processa2(struct DadosNascimento* dn){
    int dia, mes, ano;
    separaData(dn->data_nasc, &dia, &mes, &ano);
    if(dn->CODMUNRES == 330455){
        if(ano == 2012){
            if(dn->SEMAGESTAC < 37){
            contPrem12++;
            }
        }else if (ano == 2013){
            if(dn->SEMAGESTAC < 37){
            contPrem13++;
            }
        } else if (ano == 2014){
            if(dn->SEMAGESTAC < 37){
            contPrem14++;
            }
        }else if (ano == 2015) {
            if(dn->SEMAGESTAC < 37){
            contPrem15++;
            }
        } else if (ano == 2016) {
           if(dn->SEMAGESTAC < 37){
            contPrem16++;
            }
        } else if (ano == 2017) {
            if(dn->SEMAGESTAC < 37){
            contPrem17++;
            }
        } else if (ano == 2018){
            if(dn->SEMAGESTAC < 37){
            contPrem18++;
            }
        } else if (ano == 2019){
            if(dn->SEMAGESTAC < 37){
            contPrem19++;
            }
        }

    }
}


int main()
{
    char *prox = NULL;
    int lc = 0;
    static char buffer[MAX];
    struct DadosNascimento dn;
    char* linha[18];
    int i;
    FILE *f = fopen("sinasc.csv","r");
    fgets(buffer,MAX,f);
    fgets(buffer,MAX,f);

    while(!feof(f)) {
        linha[0] = strtok_r(buffer,",\n",&prox);
        for(i=1; i<18; i++) {
            linha[i] = strtok_r(NULL,",\n",&prox);
            if(linha[i]==NULL) {
                linha[i]="";
            }
        }
        dn.index = atoi(linha[0]);
        dn.CODMUNRES = atoi(linha[1]);
        strcpy(dn.data_nasc,linha[2]);
        dn.PESO = atoi(linha[3]);
        dn.SEMAGESTAC = atoi(linha[4]);
        dn.adeq_peso_id_gestac = atof(linha[5]);
        dn.SEXO = atoi(linha[6]);
        dn.IDANOMAL = atoi(linha[7]);
        dn.RACACOR = atoi(linha[8]);
        dn.ESCMAEAGR1 = atoi(linha[9]);
        dn.ESTCIVMAE = atoi(linha[10]);
        dn.IDADEMAE = atoi(linha[11]);
        dn.CONSULTAS = atoi(linha[12]);
        dn.PARTO = atoi(linha[13]);
        dn.STTRABPART = atoi(linha[14]);
        dn.KOTELCHUCK = atoi(linha[15]);
        dn.APGAR5 = atoi(linha[16]);
        dn.TPROBSON = atoi(linha[17]);

        processa(&dn);
        processa2(&dn);
        lc++;
        if(lc % 100000 == 0){
            printf("\033[32m.\033[m");
            fflush(stdout);
        }
        
        fgets(buffer,MAX,f);
    }
    
    printf("Peso médio Teresina: %f ", totalPesoTeresina/contadorTeresina);
    printf("Peso médio Curitiba: %f ", totalPesoCuritiba/contadorCuritiba);

    printf("\nPrematuros nascidos no Rio de Janeiro:\n");
    printf("2012: %d\n2013: %d\n2014: %d\n2015: %d\n2016: %d\n2017: %d\n2018: %d\n2019: %d\n",contPrem12,contPrem13,contPrem14,contPrem15,contPrem16,contPrem17,contPrem18,contPrem19);
    fclose(f);
    return 0;
}
