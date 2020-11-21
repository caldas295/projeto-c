#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadastroRegistro(){

struct informacoes T[100];

int resp;
int i=0;
int contador = 1;
system("clear");
printf("<========= CADASTRAR =========>\n\n");
for(i=0; i<100; i++){
  
  printf("Digite o valor: ");
  scanf("%f", &T[i].valor);

  printf("\nDigite o dia: ");
  scanf("%d", &T[i].dia);

  printf("\nDigite o mes: ");
  scanf("%d", &T[i].mes);

  printf("\nDigite o ano: ");
  scanf("%d%*c", &T[i].ano);

  printf("\nDê um nome para seu registro:");
  fgets(T[i].nome, 100, stdin);

  printf("\nDigite a categoria: ");
  scanf("%s%*c", T[i].categoria);

  printf("\nAdicione uma descrição:");
  fgets(T[i].descricao, 100, stdin);

  printf("\nDeseja adicionar mais um registro ?\n");
  printf("1 ===> SIM\n");
  printf("2 ===> NÃO\n");
  printf("\nresposta:");
  scanf("%d", &resp);

void MenuRegistro(){

int i = 1;
int resp2 = 0;
system("clear");
do{
  printf("\n<=========== REGISTRO ===========>\n\n O que deseja fazer?\n\n");
  printf("0 - Voltar para o Menu \n");
  printf("1 - Cadastrar novo registro \n");
  printf("2 - Remover registro \n");
  printf("3 - Listar registros\n");
  printf("4 - Alterar registro\n");
  scanf("%d", &resp2);
  if(resp2 == 0){
    printf("Voltando para o menu...\n\n");
    return;
  }

  else if(resp2< 0 || resp2 > 4 ){
    printf("Esta opção não existe !!! \n ");
    printf("\n ");
  }

  else if(resp2 == 1){
    ;
 
    cadastroRegistro();
  }

  else if(resp2 == 3){
    
    ListarRegistro();
  }

   else if(resp2 == 4){
    
    AlteraRegistro();
  }

}while(resp2 >= 0 || resp2 <=4 );

}


void menu(){
int resp1 = 0; 


do{
  system("clear");
  printf("<=========== MENU ===========>\n");
  printf("0 - Sair \n");
  printf("1 - Registro \n");
  printf("2 - Categorias \n");
  printf("3 - Relatório \n");
  printf("<============================>\n");
  scanf("%d", &resp1);

  if(resp1 == 0){
    printf("saindo...");
    break;
  }

  else if(resp1 < 0 || resp1 > 3 ){
   
    printf("Esta opção não existe !!! \n ");
    printf("\n ");
    
  }

  else if(resp1 == 1){
   
    MenuRegistro();
    
  }

 
  }while(resp1 >= 0 || resp1 <=3 );

}

int main(void){
  struct informacoes T[100];
  menu();
  return 0;
}


