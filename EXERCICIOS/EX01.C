#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	MAX 10
// Tipo base dos elementos da lista
typedef struct elementos {
    char nome[50];
    // Outros elementos
} t_elemento;

// Estrutura da lista
typedef struct lista {
    t_elemento vetor[MAX];//vet que armazena elem. da pilha
    int n; // posicao (indice) do ultimo elemento da lista
} t_lista; // tipo lista

t_lista criar() {
    t_lista lista;

    lista.n = -1;

    return lista;
}
int isVazia(t_lista * lista) {
    return (lista->n == -1);
}

int isCheia(t_lista * lista) {
    return (lista->n == MAX-1);
}
int getTamanho(t_lista * lista) {
    return lista->n + 1;
}
t_elemento * getElemento(t_lista * lista, int pos) {
    // verifica se pos eh valida
    if ( (pos > lista->n) || (pos < 0) )
        return 0;

    return &(lista->vetor[pos]);
}
int compara(t_elemento dado1, t_elemento dado2) {
    return strcmp(dado1.nome, dado2.nome);
}
int getPosicao(t_lista * lista, t_elemento dado) {
    int i;
    for (i=0; i<=lista->n; i++)
        if (compara(lista->vetor[i], dado)==0)
            return i;

    return -1;
}



int deslocaDireita(t_lista * lista, int pos) {
    int i;

    for (i=lista->n + 1; i>pos; i--)
        lista->vetor[i] = lista->vetor[i-1];

    return 1;
}
int deslocaEsquerda(t_lista * lista, int pos) {
    int i;

    for (i=pos; i<(lista->n); i++)
        lista->vetor[i] = lista->vetor[i+1];

    return 1;
}
int inserir (t_lista * lista, int pos, t_elemento dado) {
    if ( isCheia(lista) || (pos > lista->n + 1) || (pos < 0) )
        return 0;

    deslocaDireita(lista, pos);
    lista->vetor[pos] = dado;
    (lista->n)++;
    return 1;
}
int remover (t_lista *lista, int pos) {
    if ( (pos > lista->n) || (pos < 0) )
        return 0;

    deslocaEsquerda(lista, pos);

    (lista->n)--;
    return 1;
}



int main(void) {
  t_lista m_lista;
  m_lista=criar();
  t_elemento m_nome;
  int t,pos=0,i=0,pos_mostrar,search,pos_excluir,removido,escolha;
  char dado[50];
  t_elemento *list_position_data;
  for (pos=0;pos<3;pos++){
    scanf(" %s",&m_nome.nome);
    t=inserir(&m_lista,pos,m_nome);
  }

  printf("digite o indice que quer ver o nome:");
  scanf("%d",&pos_mostrar);

  list_position_data = getElemento(&m_lista, pos_mostrar - 1); //pega o valor armazenado na posição (pos_mostrar) da lista (m_lista) 

  printf("O valor armazenado na posicao %d e [%s]: \n",pos_mostrar, list_position_data);

  printf("digite o indice que queira excluir:");
  scanf("%d",&pos_excluir);

  removido = remover(&m_lista, pos_excluir - 1);
	if(removido) printf("O item [%d] foi removido\n", pos_excluir);
	else printf("O item [%d] não pode ser removido\n",pos_excluir);
  printf("Deseja mostrar a lista atual? 1-sim 2-não");
  scanf("%d",&escolha);
  if(escolha==1){
  for(i = 0; i <= m_lista.n; i++)
  printf("O nome do %d elemento e: [%s]\n", i + 1, m_lista.vetor[i].nome);}
  else
  return 0;
}
