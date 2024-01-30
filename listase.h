typedef void(*imprimir_lse)(void*);
typedef int(*comparar_lse)(void*, void*);

typedef struct t_lse lse;
lse* criar_lse(imprimir_lse imprimir, comparar_lse comparar);

void inserir_lse(lse *l, void* dado);
void* remover_lse(lse *l);
void* acessar_lse(lse *l, int pos);
void imprimi_lse(lse *l);
void inserir_final_lse(lse* lse, void* elem );
void inserir_ordenado_lse(lse* l, void* carga);
int tamanho(lse* l);
void* primeiro(lse* l);
void remover_prim(lse *l);
void alterar_elem(void* antigo, void* novo, lse* l);
void* remover_elem(void* elemento, lse* l);