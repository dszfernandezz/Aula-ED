#define N 5

struct filav{
    int n;
    int ini;
    float v[N];
};
typedef struct filav FilaV;

FilaV *cria_pilhav();

void insere_filaV(FilaV *f, float v);

float retira_filaV(FilaV *f);

int filaV_vazia(FilaV *f);

void libera_filaV(FilaV *f);

void imprime_filaV(FilaV *f);

