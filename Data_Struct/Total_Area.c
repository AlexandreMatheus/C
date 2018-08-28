#include <stdio.h>
#include <stdlib.h>

typedef struct {
  float largura;
  float comprimento;
  char nome[20];
  float area;
}dados;
int main(void) {
  int x,n,dado;
  dados *Data;
  float area_total;
  printf("Digite o total de comodos:");
  scanf(" %d",&n);
  printf("\n");
  Data = (dados *) malloc(n*sizeof(dados));
  for(x=0;x<n;x++){
    printf("Digite a largura:");
    scanf(" %f",&Data[x].largura);
    printf("Digite o comprimento:");
    scanf(" %f",&Data[x].comprimento);
    printf("Digite o nome:");
    scanf(" %s",&Data[x].nome);
    Data[x].area=Data[x].largura * Data[x].comprimento;
    area_total+=Data[x].area;
    printf("\n");
  }

  for(x=0;x<n;x++){
    printf("%d largura:%.2f\n",x+1,Data[x].largura);
    printf("%d comprimento:%.2f\n",x+1,Data[x].comprimento);
    printf("%d nome:%s\n",x+1,Data[x].nome);
    printf("%d area:%.2f\n",x+1,Data[x].area);
    printf("\n");
  }

  printf("Area Total: %.2f\n",area_total);

  return 0;
}
