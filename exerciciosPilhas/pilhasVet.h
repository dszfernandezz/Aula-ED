#define N 50

struct pilhav{
    int n;
    float v[N];
};
typedef struct pilhav PilhaV;

PilhaV *cria_PilhaV();

void imprime_vet(PilhaV *p);

void push(PilhaV *p, float v);

float pop(PilhaV *p);

int PilhaV_vazia(PilhaV *p);

void libera_PilhaV(PilhaV *p);
