//Solução feita por João Henrique Terência e Biaca Tavares


#include <stdio.h>
#include <string.h>

typedef struct _Endereco Endereco;

// registroCEP = struct.Struct("72s72s72s72s2s8s2s")

struct _Endereco
{
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2]; // Ao Espaço no final da linha + quebra de linha
};

int main(int argc, char**argv)
{
	FILE *f;
	Endereco e;
	int qt;
	int c = 0; //Quantidade de vezes que o loop é rodado
    int inicio, meio, fim, achei;
    long posicaoDoPonteiro;

	if(argc != 2)
	{
		fprintf(stderr, "USO: %s [CEP]", argv[0]);
		return 1;
	}

    achei = 0;
    inicio = 0;
	printf("Tamanho da Estrutura: %ld\n\n", sizeof(Endereco));
	f = fopen("cep_ordenado2.dat","rb");
    //fread(destino(Aonde vc vai salvar os dados), quantidade de bytes, quantidade de elementos lidos,arquivo de entrada(entrada))
	fseek(f, 0, SEEK_END);
    //ftell retorna a posição atual do ponteiro no arquivo
    //posicaoDoPonteiro é um long pq ftell retorna um long
    posicaoDoPonteiro = ftell(f);
    qt = posicaoDoPonteiro/sizeof(Endereco);
    fim = qt - 1;
	
    while(inicio <= fim){
        c++;
        meio = (inicio + fim)/2;
        fseek(f, meio * sizeof(Endereco) ,SEEK_SET);
        fread(&e,sizeof(Endereco),1,f);
        if(strncmp(argv[1], e.cep, 8) == 0){
            printf("%.72s\n%.72s\n%.72s\n%.72s\n%.2s\n%.8s\n",e.logradouro,e.bairro,e.cidade,e.uf,e.sigla,e.cep);
			break;
        } else if(strcmp(argv[1],e.cep) < 0){
			fim = meio - 1;
		}else{
			inicio = meio + 1;
		}
    }

	printf("Total Lido: %d\n", c);
	fclose(f);
}