#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
   
    int cod_prod;
    double preco;
    
    //mecanismo p/ unir nos!
    struct No * prox;
}NO;

NO * inicio = NULL;
NO * fim = NULL;
int tam = 0;

void add(int cod_prod, double preco, int pos)
{
    
    if(pos >= 0 && pos <= tam){
    
        NO * novo = malloc(sizeof(NO));
        novo->cod_prod = cod_prod;
        novo->preco = preco;
        novo->prox = NULL;
    
        if(inicio == NULL){ //lista vazia
            inicio = novo;
            fim = novo;
            tam++;
        }else if(pos == 0){ //inicio
            novo->prox = inicio;
            inicio = novo;
            tam++;
        }else if(pos == tam){ //fim
            fim->prox = novo;
            fim = novo;
            tam++;
        }else{ // "no meio"
            
            NO * aux = inicio;
            for(int i = 0; i < pos-1; i++);
                aux = aux->prox;
            
            }
            novo->prox = aux->prox;
            aux->prox = novo;
            tam++;
            
        }
    
    }else{
        printf("deu ruim!!\n");
    }
}


void imprimir()
{
    NO * aux = inicio;
    for(int i = 0; i < tam; i++){
        printf("\n Lista normal: %d \n", aux->cod_prod);
            aux = aux->prox;
    }
}
void inverso(NO *ponteiro)
{
    if (ponteiro -> prox != NULL) inverso(ponteiro -> prox);
    printf("\n Lista Iversa: %d\n", ponteiro -> cod_prod);
}    

int main(){
    add(29383, 50.0, 0);
    add(29848, 150.0, 0);
    add(29646, 20.0, 2);
    add(29133, 20.0, 0);
    add(4444, 70.0, 3);
    imprimir();
    inverso(inicio);
    return 0;
}




