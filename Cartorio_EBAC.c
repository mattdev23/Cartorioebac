#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdio.h> //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{ 
    // In�cio cria��o de vari�veis/string 
  char arquivo[40];
    char cpf[40];
    char nome[40];
	char sobrenome[40];
    char cargo[40];
    // final da cria��o de vari�veis/string 
    
    printf("Digite o CPF a ser cadastrado:    "); //coletando informa��o do usu�rio 
    scanf("%s", cpf); // %S refere - se a string 

    strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string

    FILE *file;  //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever  
    fprintf(file,cpf); //salvo o valor da vari�vel 
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo,"a"); //cria o arquivo e o "a" significa 
    fprintf(file,","); //salva o valor da vari�vel 
    fclose(file);  //fecha o arquivo
    
    printf("Digite o nome a ser cadastrado:  "); //coletando informa��o do usu�rio
    scanf("%s",nome); //%s refere-se a string
    
    file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa 
    fprintf(file,nome); //salva o valor da vari�vel 
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo,"a"); //cria o arquivo e o "a" significa 
    fprintf(file,","); //salva o valor da vari�vel 
    fclose(file); //fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio 
    scanf("%s",sobrenome); //%s refere-se a string
    
    file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa 
    fprintf(file,sobrenome); //salva o valor da vari�vel 
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo,"a"); //cria o arquivo e o "a" significa 
    fprintf(file,","); //salva o valor da vari�vel 
    fclose(file); //fecha o arquivo 

    printf("Digite o cargo a ser cadastrado:  "); //coletando informa��o do usu�rio 
    scanf("%s",cargo); //%s refere-se a string
    
    file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa 
    fprintf(file,cargo); //salva o valor da vari�vel 
    fclose(file); //fecha o arquivo 
    
    system("pause");
    
}

int consulta()
{
	   setlocale(LC_ALL, "Portuguese");  //Definindo a linguagem 
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf,"r");
   
   if(file== NULL)
{
       printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
    }

   while(fgets(conteudo, 200, file) != NULL)
   {
       printf("\nEssas s�o as informa��es do usu�rio:\n ");
       printf("%s",conteudo);
       printf("\n\n");
   }

   system("pause");
   


}  
int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
	 
    if(file == NULL)
    {
    	printf("O usu�rio n�o se encontra no sistema.\n");
    	system("pause");
	}
    
    else 
	{
		printf("\nO usu�rio digitado n�o se encontra no sistema. \n \n");
		system("pause");
		return NULL; 
	}
    
}   




int main()
{
     int opcao =0; //Definindo as vari�veis 
     int laco=1;
     
     for(laco=1;laco=1;)
    { 
	 
     system("cls"); //respons�vel por limpar a tela 
   
     setlocale(LC_ALL, "Portuguese");  //Definindo a linguagem 
    
     printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu 
    printf("Escolha a op��o desejada do menu:\n\n");       printf("\t1 - Registrar nomes\n");
    printf("\t2 - Consultar nomes\n");
    printf("\t3 - Deletar nomes\n|\n");
    printf ("Op��o:"); //fim do menu	  
    scanf("%d", &opcao); //armazenamento a escolha do usu�rio 
    
	system("cls");     
 switch(opcao) //inicio da sele��o do menu 
    { 
           case 1:
          registro(); //chamada de fun��es 
	     break;
      	 
	     case 2:
	     consulta();
	     break; 
	    
	     case 3:
	     deletar();
	     break;
	    
	     default: 
	     printf("Essa op��o n�o est� disponivel!\n");
        system("pause"); 
	     break;     
	} //fim de sele��o 
    
	 
	 

    
}
}
