#include <stdio.h>
#include <stdlib.h>


typedef struct No { //cria a estrutura do nó
    int valor;
    struct No *prox;

} No;

void inserir(No** lista, int valor){ //inclusão
    No* novo = malloc(sizeof(No));
    
    if (novo == NULL){
        printf("Erro ao alocar memória");
        return;
    }

    novo->valor= valor; 
    novo->prox = NULL;

    // lista vazia 
    if(*lista == NULL){
        *lista = novo; 
    }

    // lista ja com elementos 
    else {
        No* atual = *lista;

        while(atual->prox != NULL){
            atual = atual->prox;
        }

        atual->prox = novo;

    }
    printf("Valor %d inserido com sucesso\n", valor);
}

void listar(No* lista){ //consulta

    if(lista == NULL){
        printf("A lista está vazia \n");
        return;
    }

    printf("Lista de elementos: \n");

    while(lista !=NULL){
        printf("%d ->", lista->valor);
        lista = lista->prox;
    }
    printf("NULL \n");

}

void remover(No**lista, int valor){ //remoção
    No* atual = *lista; 

    No* anterior = NULL; 

    while(atual != NULL && atual->valor != valor){
        anterior = atual;
        atual = atual->prox;
    }

    if(atual == NULL){
        printf("Elemento não encontrado",valor);
        return;
    }
    //caso 1
    if(anterior == NULL){
        *lista = atual->prox;
    }
    else{ 
        //caso 2 no meio  ou final da lista
        anterior->prox = atual->prox;
    }
    free(atual); //libera o nó atual
    printf("Valor removido com sucesso\n", valor);
}


void buscar(No* lista, int valor){ //consulta
    if(lista == NULL){
        printf("A lista está vazia\n");
        return;
    }

    No* atual = lista;
    int posicao = 1; 
    int encontrado = 0;

    while(atual != NULL){
        if(atual->valor == valor){
            printf("Valor %d encontrado na posição %d \n", valor, posicao);
            encontrado = 1;
        }
        atual = atual ->prox;
        posicao++;
    }

    if(!encontrado){
        printf("Valor não foi encontrado na lista \n", valor);
    }
}

void alterar(No* lista, int valorAntigo, int valorNovo){ // altera
    if(lista == NULL){
        printf("A lista está vazia\n");
        return;
    }

    No* atual = lista;

    while(atual!= NULL){
        if(atual->valor == valorAntigo){
            atual->valor = valorNovo; //atualiza o valor 
            printf("Valor %d alterado para %d com sucesso \n", valorAntigo, valorNovo);
            return;
        }
        atual = atual->prox;
    }
    printf("Elemento %d não encontrado para alteração\n", valorAntigo);
}

int main(){
    No* lista = NULL;

    int opcao;
    int valor; 
    int valorNovo;

    do{
        printf("Escolhauma opção: \n");
        printf("1 - Inserir elemento\n");
        printf("2 - Listar elemento\n");
        printf("3 - Remover elemento\n");
        printf("4 - Buscar elemento\n");
        printf("5 - Alterr elemento\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1: //inserir
        
             printf("Digite o valor para inserir:");
             scanf("%d", &valor);
            
             inserir(&lista, valor);
             break;

            case 2:
            listar(lista);
            break;

            case 3: //remover
             
            printf("Digite o valor para remover: ");
            scanf("%d", &valor);

            remover(&lista, valor);
            break;

            case 4: //buscar
            printf("Digite o valor para buscar: ");
            scanf("%d", &valor);
            buscar(lista, valor);
            break;

            case 5:  //alterar
            printf("Digite o valor para alterar: ");
            scanf("%d", &valor);
            printf("Digite o novo valor: ");
            scanf("%d", &valorNovo);
            alterar(lista, valor, valorNovo);
            break;



            case 0:
            printf("Até mais!");
            break;
              
            
            default: 
            printf("Opção inválida");


    } 

} while(opcao != 0);
  return 0; 
}