#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct informacoes{
    float valor;
    int dia,mes,ano;
    char categoria[100];
    char descricao[100];
    char nome[100];
};


void RelatorioAno(){
    system("clear");

    struct informacoes B[100];
    char CategoriaProcura[100];
    int mesProcura;
    int anoProcura;
    int diaProcura;  
    int i = 0;
    int j = 0;
    int compara = 0;

    printf("\n<========= RELATÓRIO ANUAL =========>\n");
    printf("\nDigite a categoria:");
    scanf("%s", CategoriaProcura);
    printf("Digite:\n");
    printf("\n=>ano:");
    scanf("%d", &anoProcura);
    
    printf("\n");

    FILE* arquivo = fopen("registros.txt","rb");
    while(fread(&B[i],sizeof(struct informacoes), 1,arquivo ) == 1){
          
        compara =  strcmp(CategoriaProcura, B[i].categoria);
        i++;
    }
    fclose(arquivo);
    
     
    
    
    FILE* arquivoHTML = fopen("RelatorioANO.html","w");
        fprintf(arquivoHTML,"<html>\n");
        fprintf(arquivoHTML, "<body>");
        fprintf(arquivoHTML, "<p>REGISTROS DO ANO => (%d)</p>", anoProcura);

        for(j=0; j<i; j++){
        if(compara == 0){
            if(B[j].ano == anoProcura){

                fprintf(arquivoHTML, "\n\n<p>Nome do registro: %s</p>", B[j].nome);
                fprintf(arquivoHTML, "\n<p>Valor: %f</p>", B[j].valor);
                fprintf(arquivoHTML,"\n<p>Data: (%d/%d/%d)</p>", B[j].dia, B[j].mes,B[j].ano);
                fprintf(arquivoHTML, "\n<p>Categoria: %s</p>", B[j].categoria);
                fprintf(arquivoHTML,"\n<p>Descrição: %s</p>",B[j].descricao);
                fprintf(arquivoHTML,"<p>\n=====================</p>");          
            }
        }
        //
        //if(compara > 0  || compara < 0  ){
        //    system("clear");
        //    printf("\n Essa categoria não existe !!! \n");
        //  }
    }
      fprintf(arquivoHTML,"\n</body>");
      fprintf(arquivoHTML,"\n</html>");
fclose(arquivoHTML);



}


void RelatorioMes(){
    system("clear");

    struct informacoes B[100];
    char CategoriaProcura[100];
    int mesProcura;
    int anoProcura;
    int diaProcura;  
    int i = 0;
    int j = 0;
    int compara = 0;

    printf("\n<========= RELATÓRIO MENSAL =========>\n");
    printf("\nDigite a categoria:");
    scanf("%s", CategoriaProcura);
    printf("Digite: \n");
    printf("\n=>mes:");
    scanf("%d", &mesProcura);
    printf("\n=>ano:");
    scanf("%d", &anoProcura);
    
    printf("\n");

    FILE* arquivo = fopen("registros.txt","rb");
    while(fread(&B[i],sizeof(struct informacoes), 1,arquivo ) == 1){
          
        compara =  strcmp(CategoriaProcura, B[i].categoria);
        i++;
    }
    fclose(arquivo);
    
     
    
    
    FILE* arquivoHTML = fopen("RelatorioMES.html","w");
        fprintf(arquivoHTML,"<html>\n");
        fprintf(arquivoHTML, "<body>");
        fprintf(arquivoHTML, "<p>REGISTROS DO MES =>(%d)/<p>", mesProcura);

        for(j=0; j<i; j++){
        if(compara == 0){
            if(B[j].mes == mesProcura && B[j].ano == anoProcura){

                fprintf(arquivoHTML, "\n\n<p>Nome do registro: %s</p>", B[j].nome);
                fprintf(arquivoHTML, "\n<p>Valor: %f</p>", B[j].valor);
                fprintf(arquivoHTML,"\n<p>Data: (%d/%d/%d)</p>", B[j].dia, B[j].mes,B[j].ano);
                fprintf(arquivoHTML, "\n<p>Categoria: %s</p>", B[j].categoria);
                fprintf(arquivoHTML,"\n<p>Descrição: %s</p>",B[j].descricao);
                fprintf(arquivoHTML,"<p>\n=====================</p>");          
            }
        }

        //f(compara > 0  || compara < 0  ){
        // system("clear");
        // printf("\n Essa categoria não existe !!! \n");
        // }
        }

      fprintf(arquivoHTML,"\n</body>");
      fprintf(arquivoHTML,"\n</html>");
      fclose(arquivoHTML);



}

void MenuRelatorio(){
    system("clear");
    int resp;
    
  
    do{  
    printf("\n<========= RELATÓRIO =========>\n");
    printf("\nO que deseja fazer ? \n");
    printf("\n1 - Gerar  RELATÓRIO MENSAL");
    printf("\n2 - Gerar RELATÓRIO ANUAL");
    printf("\n0 - voltar para o menu\n");
    printf("\n=>");
    scanf("%d", &resp);

    if(resp < 0 || resp >2 ){
      printf("\nEssa opção não existe !!! \n ");
    }

     else if(resp == 0){
        return;
    }

    else if(resp == 1){
        RelatorioMes();
    }

    else if(resp == 2){
        RelatorioAno();
    }

    

    }while(resp >= 0 || resp <=2 );

}

void ListarCategoria(){
  struct informacoes B[100];
  int i=1;

  char categorias[100];

  FILE* arquivo = fopen("registros.txt","rb");
  system("clear");
  printf("<========= CATEGORIAS CRIADAS =========>\n\n");
  while(fread(&B[i],sizeof(struct informacoes), 1,arquivo ) == 1){

      printf("(%d) - Categoria: %s\n",i,B[i].categoria);
      i++;   
  }
}

void BuscaCategoria(){
    struct informacoes B[100];
    int i = 0;
    int compara = 0;

    char categoriaprocura[100];

    printf("Digite a categoria: \n");
    scanf("%s", categoriaprocura);

    FILE* arquivo = fopen("registros.txt","rb");
    system("clear");
    printf("<========= REGISTROS =========>\n\n");
    while(fread(&B[i],sizeof(struct informacoes), 1,arquivo ) == 1){
      
        compara =  strcmp(categoriaprocura, B[i].categoria);

        if(compara == 0){

            printf("\nNome do registro: %s",B[i].nome);
            printf("\nValor: %f", B[i].valor);
            printf("\nData: (%d/%d/%d)", B[i].dia, B[i].mes,B[i].ano);
            printf("\nDescrição: %s\n",B[i].descricao);
            printf("=====================\n");  
        }
      }
}

void MenuCategoria(){
    system("clear");
          
    int resp = 0;
    
    do{  
    printf("\n<========= CATEGORIA =========>\n");
    printf("\nO que deseja fazer ? ○\n");
    printf("\n1 - Listar todas as categorias");
    printf("\n2 - Consultar registros de cada categoria");
    printf("\n0 - voltar\n");
    printf("\n=>");
    scanf("%d", &resp);

    if(resp < 0 || resp >2 ){
      printf("\nEssa opção não existe !!! \n ");
    }

     else if(resp == 0){
     return;
    }

    else if(resp == 1){
      ListarCategoria();
    }

    else if(resp == 2){
      BuscaCategoria();
    }

void BuscaRegistro(){
    system("clear");
    struct informacoes B[100];
    char CategoriaProcura[100];
    char NomeProcura[100];
    int compara1, compara2;
    int opcao;

    int i=0;

   printf("Digite a CATEGORIA do registro que deseja alterar:\n ");
   printf("=>");
   scanf("%s%*c", CategoriaProcura); 

   printf("Digite o NOME do registro que deseja alterar:\n");
   printf("=>");
   fgets(NomeProcura,100,stdin);

   FILE* arquivo = fopen("registros.txt","rb");

   while(fread(&B[i],sizeof(struct informacoes), 1,arquivo ) == 1){
     
     compara1 =  strcmp(CategoriaProcura, B[i].categoria);
     compara2 =  strcmp(NomeProcura, B[i].nome);


     if(compara1 == 0 && compara2 == 0){
            system("clear");
            printf("<========= REGISTRO =========>\n");
            printf("\nNome do registro: %s",B[i].nome);
            printf("\nValor: %f", B[i].valor);
            printf("\nData: (%d/%d/%d)", B[i].dia, B[i].mes,B[i].ano);
            printf("\nCategoria: %s",B[i].categoria);
            printf("\nDescrição: %s\n",B[i].descricao);
            printf("=====================\n");
    }
    
  }
  if(compara1 > 0 || compara2 > 0 || compara1 < 0 || compara2 < 0 ){
    printf("\n Registro não encontado !!! \n");
  }
fclose(arquivo);
}  

void AlteraRegistro(){
    system("clear");
    struct informacoes A[100];

    int i = 0, j = 0;
    char NomeProcura[100];
    char CategoriaProcura[100];
    int compara1, compara2;
    int opcao;

    printf("Digite a CATEGORIA do registro que deseja alterar:\n ");
    printf("=>");
    scanf("%s%*c", CategoriaProcura);

    printf("Digite o NOME do registro que deseja alterar:\n");
    printf("=>");
    fgets(NomeProcura,100,stdin);
  
    FILE* arquivo = fopen("registros.txt","rb");

    while(fread(&A[i],sizeof(struct informacoes), 1,arquivo ) == 1){
  
        compara1 =  strcmp(CategoriaProcura, A[i].categoria);
        compara2 =  strcmp(NomeProcura, A[i].nome);
        
        
        if(compara1 == 0 && compara2 == 0){
            system("clear");
            printf("<========= REGISTRO =========>\n");
            printf("\nNome do registro: %s",A[i].nome);
            printf("\nValor: %f", A[i].valor);
            printf("\nData: (%d/%d/%d)", A[i].dia, A[i].mes,A[i].ano);
            printf("\nCategoria: %s",A[i].categoria);
            printf("\nDescrição: %s\n",A[i].descricao);
            printf("=====================\n");
            printf("\n<=== O que deseja alterar ===>\n\n");
            printf("1 ===> NOME\n");
            printf("2 ===> VALOR\n");
            printf("3 ===> DIA\n");
            printf("4 ===> MES\n");
            printf("5 ===> ANO\n");
            printf("6 ===> CATEGORIA\n");
            printf("7 ===> DESCRIÇÃO\n");
            printf("0 ===> VOLTAR\n");
            printf("\n=>");
            scanf("%d%*c", &opcao);

            if(opcao == 0){
              return;
            }

            if(opcao == 1){
                system("clear");
                j = 0;
                char NovoNome[100];
                printf("Digite o NOVO NOME de seu registro\n");
                fgets(NovoNome, 100, stdin);
                strcpy(A[i].nome,NovoNome);
                printf("\n <--- REGISTRO ALTERADO COM SUCESSO !!! --->\n\n");
            }

             else if(opcao == 2){
                system("clear");
                j = 0;
                float NovoValor;
                printf("Digite o NOVO VALOR de seu registro\n");
                scanf("%f", &NovoValor);
                A[i].valor = NovoValor;
                printf("\n <--- REGISTRO ALTERADO COM SUCESSO !!! --->\n\n");
            }
             else if(opcao == 3){
                system("clear");
                j = 0;
                int NovoDia;
                printf("Digite o NOVO DIA de seu registro\n");
                scanf("%d", &NovoDia);
                A[i].dia = NovoDia;
                printf("\n <--- REGISTRO ALTERADO COM SUCESSO !!! --->\n\n");
            }

            else if(opcao == 4){
                system("clear");
                j = 0;
                int NovoMes;
                printf("Digite o NOVO MES de seu registro\n");
                scanf("%d", &NovoMes);
                A[i].mes = NovoMes;
                printf("\n <--- REGISTRO ALTERADO COM SUCESSO !!! --->\n\n");
            }

            else if(opcao == 5){
                system("clear");
                j = 0;
                int NovoAno;
                printf("Digite o NOVO ANO de seu registro\n");
                scanf("%d", &NovoAno);
                A[i].ano = NovoAno;
                printf("\n <--- REGISTRO ALTERADO COM SUCESSO !!! --->\n\n");
            }

            else if(opcao == 6){
                system("clear");
                j = 0;
                char NovoCategoria[100];
                printf("Digite a NOVA CATEGORIA de seu registro\n");
                scanf("%s", NovoCategoria);
                strcpy(A[i].categoria,NovoCategoria);
                printf("\n <--- REGISTRO ALTERADO COM SUCESSO !!! --->\n\n");
            }

            else if(opcao == 7){
                system("clear");
                j = 0;
                char NovoDesc[100];
                printf("Digite a NOVA DESCRIÇÃO de seu registro\n");
                fgets(NovoDesc, 100, stdin);
                strcpy(A[i].descricao,NovoDesc);
                printf("\n <--- REGISTRO ALTERADO COM SUCESSO !!! --->\n\n");
            }
      
      
        }

        
        i++;
    }

    if(compara1 > 0 || compara2 > 0 || compara1 < 0 || compara2 < 0 ){
    printf("\n Registro não encontado !!! \n");
  }

    fclose(arquivo);
    
    
    FILE* arquivo2 = fopen("registros.txt", "wb");
    for(j=0; j < i; j++){
        fwrite(&A[j], sizeof(struct informacoes), 1, arquivo2); 
    }
    fclose(arquivo2);

}

 


void ListarRegistro(){
    system("clear");
    struct informacoes A[100];
    int i;


    FILE* arquivo = fopen("registros.txt","rb");  

    if(arquivo==NULL){
        printf("Arquivo não encontrado");
    }
    else{
        printf("<========= LISTA DE REGISTROS =========>\n\n");

    while(fread(&A[i],sizeof(struct informacoes), 1,arquivo ) == 1){
  
        printf("\nNome do registro: %s",A[i].nome);
        printf("\nValor: %f", A[i].valor);
        printf("\nData: (%d/%d/%d)", A[i].dia, A[i].mes,A[i].ano);
        printf("\nCategoria: %s",A[i].categoria);
        printf("\nDescrição: %s\n",A[i].descricao);
        printf("=====================\n");
        i++;
      }

    }
    fclose(arquivo); 
  }


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
        printf("\n=>");
        scanf("%d", &resp);
  
        if(resp == 1){
            system("clear");
            contador++;
          }
        else if(resp == 2){
            FILE* arquivo = fopen("registros.txt", "ab");
            for(i=0; i<contador; i++){
                fwrite(&T[i], sizeof(struct informacoes), 1, arquivo); 
          }
        fclose(arquivo);
        break;
        return;
      }
    }
  }


void MenuRegistro(){

    int i = 1;
    int resp2 = 0;
    system("clear");
    do{
        printf("\n<=========== REGISTRO ===========>\n\n O que deseja fazer?      \n\n");
        printf("0 - Voltar para o Menu \n");
        printf("1 - Cadastrar novo registro \n");
        printf("2 - Buscar registro \n");
        printf("3 - Listar registros\n");
        printf("4 - Alterar registro\n");
        printf("\n=>");
        scanf("%d", &resp2);
        if(resp2 == 0){
            printf("Voltando para o menu...\n\n");
            return;
          }

        else if(resp2< 0 || resp2 > 4 ){
            printf("Essa opção não existe !!! \n ");
            printf("\n ");
          }

        else if(resp2 == 1){
            cadastroRegistro();
          }

        else if(resp2 == 2){
            BuscaRegistro();
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
        printf("\n=>");
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

        else if(resp1 == 2){
            MenuCategoria();
          }  


    }while(resp1 >= 0 || resp1 <=3 );

    }

int main(void){
    struct informacoes T[100];
    menu();
    return 0;
}


