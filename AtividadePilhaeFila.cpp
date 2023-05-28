#include<stdio.h>

struct No {
    int valor;
    No *prox;
};

struct Fila {
    No *cabeca, *cauda;
    int n;

    Fila() {
        cabeca = cauda = NULL;
        n = 0;
    }

    bool vazia() { // O(1)
        return (cabeca == NULL);
    }

    void inserir(int v) { // O(1)
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = NULL;
            cauda->prox = novo;
            cauda = novo;
        }
        n++;
    }

    int tamanho() { // O(1)
        return n;
    }

    void remover() { // O(1)
        if (!vazia()) {
            if (tamanho() == 1) {
                No *aux = cabeca;
                cabeca = NULL;
                cauda = NULL;
                delete(aux);
            } else {
                No *aux = cabeca;
                cabeca = cabeca->prox;
                delete(aux);
            }
            n--;
        }
    }

    int frente() {
        if (vazia()) {
            return NULL;
        }
        return cabeca->valor;
        }

    void inverterOrdem(int v){
        inserir(v);
    }

    void imprimir() {
        if(vazia()) {
            printf("\nFila vazia!\n");
        }else {
            No *aux = new No();
            aux = cabeca;
            printf("\nFila: ");
            while(aux != NULL){
                printf("%d ", aux->valor);
                aux = aux->prox;
            }
            printf("\n");
        }
    }

};

struct Pilha {

    No *topo;
    int n;

    Pilha() {
        topo = NULL;
        n = 0;
    }

    bool vazia() { // O(1)
        return (topo == NULL);
    }

    void inserir(int v) { // O(1)
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            topo = novo;
        } else {
            novo->prox = topo;
            topo = novo;
        }
        n++;
    }

    int tamanho() { // O(1)
        return n;
    }

    void remover() { // O(1)
        if (!vazia()) {
            if (tamanho() == 1) {
                No *aux = topo;
                topo = NULL;
                delete(aux);
            } else {
                No *aux = topo;
                topo = topo->prox;
                delete(aux);
            }
            n--;
        }
    }

    int topoPilha() {
        if (vazia()) {
            return NULL;
        }
        return topo->valor;
    }

    void imprimir() {
        if(vazia()) {
            printf("\nPilha vazia!\n");
        }else {
            No *aux = new No();
            aux = topo;
            printf("\nPilha: ");
            while(aux != NULL){
                printf("%d ", aux->valor);
                aux = aux->prox;
            }
            printf("\n");
        }
    }

};

int main() {

    Fila f;
    Pilha p;

    int qtdElementos, i, v;

    scanf("%d", &qtdElementos);

    for(i = 0; i < qtdElementos; i++){
        scanf("%d", &v);
        f.inserir(v);
        p.inserir(v);
    }

    f.imprimir();
    p.imprimir();

    for(i = 0; i < qtdElementos; i++){
        f.remover();
        f.inverterOrdem(p.topoPilha());
        p.remover();
    }

    f.imprimir();

    return 0;
}
