#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declaração da struct
typedef struct {
    char placa[10];
    char modelo[25];
    char marca[15];
    char quilometragem[8];
} t_veiculo;

// prototipação das funções, e, em seguida, as funções
t_veiculo *loadveics(char *);
void filtro(t_veiculo *, char *, int);

t_veiculo *loadveics(char *nomearq){
    FILE* arq;
    char linha[600];

    t_veiculo *veiculos;
    veiculos = (t_veiculo *)malloc(150 * sizeof(t_veiculo));

    arq = fopen(("./%s", nomearq), "rt");
    // if preventivo caso o nome do arquivo inexista ou seja alterado por alguma razão
    if (arq == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
    }
    else {
        int i = 0;
        while (!feof(arq)) {
            fgets(linha, sizeof(linha), arq);
            if(i < 150){    // para não incluir a última linha vazia do arquivo
                strcpy(veiculos[i].placa, linha);
                fgets(linha, sizeof(linha), arq);
                strcpy(veiculos[i].modelo, linha);
                fgets(linha, sizeof(linha), arq);
                strcpy(veiculos[i].marca, linha);
                fgets(linha, sizeof(linha), arq);
                strcpy(veiculos[i].quilometragem, linha);
            }
            ++i;
        }
        //fecha o arquivo de leitura
        fclose(arq);
    }
    return veiculos;
}

void filtro(t_veiculo *vet, char *marca_veiculo, int tam_vet){
    FILE *wrt;

    // formatar o nome do arquivo para que ele tenha .txt ao final
    char nomeArq[30];
    strcpy(nomeArq, marca_veiculo);
    strcat(nomeArq, ".txt");

    wrt = fopen(("./%s", nomeArq), "wt");
    for(int i = 0; i < tam_vet; i++){
        int indexStr, iguais = 0;
        
        // retira o "\n" do final de vet[i].marca para tornar-se comparável com marca_veiculo
        if (vet[i].marca[strlen(vet[i].marca) - 1] == '\n')
            vet[i].marca[strlen(vet[i].marca) - 1] = '\0';

        // verifica se as strings são iguais
        for(indexStr = 0; indexStr < strlen(marca_veiculo) - 1; indexStr++){
            if(marca_veiculo[indexStr] == vet[i].marca[indexStr]){
                ++iguais;
            }
        }
        if(iguais == indexStr){
            // retira os "\n"'s restantes para o formato de saída requisitado
            if (vet[i].placa[strlen(vet[i].placa) - 1] == '\n')
                vet[i].placa[strlen(vet[i].placa) - 1] = '\0';
            if (vet[i].modelo[strlen(vet[i].modelo) - 1] == '\n')
                vet[i].modelo[strlen(vet[i].modelo) - 1] = '\0';
            if (vet[i].quilometragem[strlen(vet[i].quilometragem) - 1] == '\n')
                vet[i].quilometragem[strlen(vet[i].quilometragem) - 1] = '\0';
            
            // escreve no novo arquivo e, por fim, pula uma linha para o próximo veículo
            fputs(vet[i].placa, wrt);
            fputs(", ", wrt);
            fputs(vet[i].modelo, wrt);
            fputs(", ", wrt);
            fputs(vet[i].marca, wrt);
            fputs(", ", wrt);
            fputs(vet[i].quilometragem, wrt);
            fputs("\n", wrt);
        }
    }
    // fecha o arquivo de escrita
    fclose(wrt);
}

int main() {
    t_veiculo *vetveiculos;
    vetveiculos = loadveics("bdveiculos.txt");
    
    filtro(vetveiculos, "FIAT", 150);
    filtro(vetveiculos, "TOYOTA", 150);
    filtro(vetveiculos, "FORD", 150);
    filtro(vetveiculos, "RENAULT", 150);

    // para a segurança do programa que utiliza-se de ponteiros
    if(vetveiculos != NULL){ 
        free(vetveiculos);   
        vetveiculos = NULL; 
    }

    return 0;
}
