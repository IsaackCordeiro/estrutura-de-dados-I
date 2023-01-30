/*
    Aqui está:
    - Os protótipos das funções
    - O tipo de dado armazenado na árvore
    - O ponteiro "arvore"
*/

typedef struct NO* ArvBin;

ArvBin* cria_ArvBin();

void libera_NO(struct NO* no);

void libera_ArvBin(ArvBin *raiz);

int estaVazia_ArvBin(ArvBin *raiz);

int altura_ArvBin(ArvBin *raiz);

int totalNO_ArvBin(ArvBin *raiz);

void preOrdem_ArvBin(ArvBin *raiz);

void emOrdem_ArvBin(ArvBin *raiz);

void posOrdem_ArvBin(ArvBin *raiz);