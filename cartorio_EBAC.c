#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //aloca��o de espa�os de mem�ria
#include <locale.h> //biblioteca de aloca�� de texto por regi�o
#include <string.h>// biblioteca respons�vel por cuidar das strings

int registrar() //fun��o respons�vel por cadastrar os usu�rios no sistema.
	{
		char arquivo[40];//cria��o das vari�veis que ser�o utilizadas nessa fun��o ou strings
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char email[100];
		char cargo[40];
	
		
		printf("Digite o CPF a ser cadastrado: \n");//coletando informa��o do usu�rio
		scanf("%s", cpf);//armazenamento na string
		strcpy(arquivo,cpf);//respons�vel por copiar os valores das strings
		
		FILE *file; //cria o arquivo no banco de dados
		file=fopen(arquivo, "w");//cria o arquivo
		fprintf(file,cpf);//salva o valor da vari�vel
		fclose(file);//fecha o arquivo
		
		file=fopen (arquivo, "a");//o "a" altera um arquivo que ja existe
		fprintf(file,",");//acrescenta a virgula dentro do arquivo para separar o cpf do nome, sobrenome e cargo
		fclose(file);
		
		printf("Digite o nome a ser cadastrado: \n");//coletando informa��o do usu�rio
		scanf("%s", nome);//armazenando na string
		
		
		file=fopen(arquivo,"a");//alterando um arquivo que j� existe
		fprintf(file,nome);//salva o valor da vari�vel
		fclose(file);//fecha o arquivo
		
		file=fopen(arquivo, "a");//altera um arquivo que j� existe
		fprintf(file, ",");//acrescenta virgula depois de cada item
		fclose(file);//fecha o arquivo
		
	
		printf("Digite o sobrenome a ser cadastrado: \n");//coletando informa��o do usu�rio
		scanf("%s", sobrenome);//armazenando na string
		
		
		file=fopen(arquivo,"a");//altera um arquivo que j� existe
		fprintf(file,sobrenome);//salva o valor da vari�vel
		fclose(file);//fecha o arquivo
		
		file=fopen(arquivo, "a");//altera um arquivo que j� existe
		fprintf(file, ",");//acrescenta virgula 
		fclose(file);//fecha o arquivo
		
		printf("Digite o email a ser cadastrado: \n");//coletando informa��o do usu�rio
		fgets(email, sizeof(email), stdin); // L� uma linha inteira, incluindo espa�os em branco		
		scanf("%s", email);//salva na string
		
		file=fopen(arquivo, "a");//altera um arquivo que j� existe
		fprintf(file,email);//salva o valor da vari�vel
		fclose(file);//fecha o arquivo
		
		file=fopen(arquivo,"a");//altera um arquivo que j� existe
		fprintf(file,",");//acrescenta virgula
		fclose(file);// fecha o arquivo
		
		printf("Digite o cargo a ser cadastrado: \n");//coleta informa��o do usu�rio
		scanf("%s", cargo);//salva na string
		
		file=fopen(arquivo, "a");// abre e altera um arquivo que j� existe
		fprintf(file,cargo);//salva o valor da vari�vel
		fclose(file);//fecha o arquivo
		
		
		printf("\n\n*** Usu�rio cadastrado com sucesso!***\n\n");//mensagem de retorno para o usu�rio


	}

int consultar()//inicio das configura��es da fun��o consultar

	{
		setlocale (LC_ALL, "portuguese");//define o idioma como portugu�s
		
		char cpf[40];//cri as vari�veis
		char conteudo[200];
		
		printf("Digite o CPF a ser consultado: \n");//coleta informa��o do usu�rio
		scanf("%s", cpf);//armazena na string
		
		
		FILE *file;//define arquivo que ser� aberto
		file = fopen(cpf,"r");// l� as informa��es do arquivo
		
		if(file == NULL)//inicio de condicionalcaso o arquivo n�o exista
		{
			system("cls");//limpa o sistema
			printf("XXX CPF n�o encontrado XXX \n\n");//retorna mensagem para o usu�rio
		}
			

		
		while(fgets(conteudo, 200, file) != NULL)// cria um loop
		{
    printf("\nEssas s�o as informa��es do usu�rio: \n\n");//entrega as informa��es do usu�rio consultado
    
    		// Separar os campos do conte�do do arquivo a partir do elemento virgula
    		char *token = strtok(conteudo, ",");
    		printf("CPF: %s\n", token);

    		token = strtok(NULL, ",");
    		printf("Nome: %s\n", token);
    
    		token = strtok(NULL, ",");
    		printf("Sobrenome: %s\n", token);

    		token = strtok(NULL, ",");
    		printf("Email: %s\n", token);

   		 token = strtok(NULL, ",");
    		printf("Cargo: %s\n", token);

    		printf("\n");//espa�o est�tico ao fim das informa��es
		}

	
	
	//fecha o arquivo
	
		
	}

int deletar() //inicio das configura��es da fun��o deletar
	{
		//define as vari�veis
    	char cpf[40];
    	char conteudo[200];
    	char opcao;

    	setlocale(LC_ALL, "portuguese");//define idioma como portugu�s

    	printf("Digite o CPF a ser deletado: \n\n");//coleta informa��o do usu�rio
    	scanf("%s", cpf);//armazena na string

   	 	FILE *file;// define o arquivo que ser� aberto
    	file = fopen(cpf, "r");//abre o arquivo e l� as informa��es

    	if (file == NULL) //inicio de condi��o
		
		{
        printf("\n\nCPF n�o encontrado.\n\n");//devolve mensagem caso n�o encontre a informa��o
        return 0; // Retorna 0 se CPF n�o for encontrado
    	}

    while (fgets(conteudo, 200, file) != NULL) //inicia um loop
	
	{
        printf("\nInforma��es do usu�rio:\n\n");//devolve informa��o para o usu�rio
        
       //separa as informa��es a partir do elemento virgula
	    char *token = strtok(conteudo, ",");
        printf("CPF: %s\n", token);
        token = strtok(NULL, ",");
        printf("Nome: %s\n", token);
        token = strtok(NULL, ",");
        printf("Sobrenome: %s\n", token);
        token = strtok(NULL, ",");
        printf("Email: %s\n", token);
        token = strtok(NULL, ",");
        printf("Cargo: %s\n", token);
    }
	do //inicio da resposta do condicional para quebra o loop
	{

    	fclose(file);//fecha o arquivo

   		printf("\nDeseja deletar este usu�rio? Digite 1 para sim ou 2 para n�o: \n");//coleta informa��o do usu�rio
    	scanf(" %c", &opcao); // armazena a informa��o e l� apenas um caracter

    if (opcao == '1') // inicio de condicional
	
	{
        if (remove(cpf) == 0) //remove o usu�rio do banco de dado
		
		{ 
            printf("\n\nUsu�rio deletado com sucesso.\n\n");//devolutiva para o usu�rio
        } 
		
		else //alternativa
		
		{
            printf("Erro ao deletar usu�rio.\n\n");// devolve informa��o para o usu�rio
        }
        
    } 
	
	else if (opcao == '2') //alternativa
	
	{
        printf("\n\nUsu�rio n�o foi deletado.\n\n");//devolve informa��o para o usu�rio
        return 0; // Retorna 0 para voltar ao menu
    
	} else //alternativa
	
	{
        printf("\n\nOp��o inv�lida.\n");//devolve informa��o para o usu�rio
    }
    
    while (getchar() != '\n'); // Limpa o buffer de entrada para que mais de 1 caracter n�o gere mais de 1 resposta
	}
	
	while (opcao != '1' && opcao != '2'); // estabelece um loop
	
    return 0;
	}

	
	
int main()
	{
		int opcao=0; //Definindo as vari�veis
		int loop=1; //cria��o de nova vari�vel

		for(loop=1;loop=1;)//Estabelecendo a fun��o de repeti��o
		{

			system("cls"); //limpar sistema
			setlocale (LC_ALL,"portuguese"); //Denifindo Linguagem

			printf ("*** Cart�rio da EBAC ***\n\n"); //Inicio do Menu
			printf ("Digite o n�mero correspondente � op��o desejada:\n\n");
			printf ("\t1. Registrar usu�rio \n");
			printf ("\t2. Consultar cpf \n");
			printf ("\t3. Deletar usu�rio \n\n");
			printf ("Op��o: ");//Final do Menu	

		scanf ("%d", &opcao); //Armazenando a escolha do usu�rio
		system ("cls");// Sistema "limpa" a tela depois da sele��o de op��o
		
		
		switch(opcao)//inicio das op��es
			{
				case 1:
					registrar();
					system("pause");
					break;
				
				case 2:
					consultar();
					system("pause");
					break;
				
				case 3:
					deletar();
					system("pause");
					break;
					
			
				default:
					printf("Op��o inv�lida\n\n");
					system("pause");
					break;//fim das op��es
			}

		}
	}	

