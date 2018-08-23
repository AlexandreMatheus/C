#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	MAX 1024
// Tipo base dos elementos da lista
typedef struct elementos {
    char nome[50];
    char telefone1[13],telefone2[13];
    
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
  int t,pos=0,i=0,pos_mostrar,search,pos_excluir,removido,escolha,menu;
  char dado[50];
  t_elemento *list_position_data;
  
  do{
  switch (menu){
    case 1:
      // inserir 
      printf("Digite o nome a ser inserido na agenda: "); //printa msg1
      scanf(" %s",&m_nome.nome); //pega nome
      printf("Digite o Telefone1: ");//printa msg2
      scanf(" %s",&m_nome.telefone1);
      printf("Digite o Telefone2: ");//printa msg3
      scanf(" %s",&m_nome.telefone2);
      t=inserir(&m_lista,pos,m_nome);
      break;
    case 2:
      // apagar
      break;
    case 3:
      // função 3
      break;
    case 4:
      // listar
      for(i = 0; i <= m_lista.n; i++){
    printf("O nome do %d elemento e: [%s]\nO telefone1 e: [%s]\nO telefone2 e: [%s]\n", i , m_lista.vetor[i].nome,m_lista.vetor[i].telefone1,m_lista.vetor[i].telefone2);}
      break;
    case 5:
      // função 5
      break;
  }scanf(" %d",&menu);}while (menu!=5);
  
  return 0;
}
