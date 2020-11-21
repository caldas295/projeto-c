#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


