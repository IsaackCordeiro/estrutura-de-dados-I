
struct aluno{
    int matricula;
    char nome[30];
    float nota1, nota2, nota3;
};

typedef struct elemento *Lista;

Lista *cria_lista();

void libera_lista(Lista *li);

int tamanho_lista(Lista *li);

int lista_vazia(Lista *li);

int insere_lista_inicio(Lista *li, struct aluno al);

int insere_lista_final(Lista *li, struct aluno al);

int insere_lista_ordenado(Lista *li, struct aluno al);

int remove_lista_inicio(Lista *li);

int remove_lista_final(Lista *li);

int remove_lista_meio(Lista *li, int mat);

int consulta_lista_pos(Lista* li, int pos, struct aluno *al);

Lista* ultimo(Lista *li);

int maiores(Lista* li, int n);