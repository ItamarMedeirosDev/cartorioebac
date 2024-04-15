#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //alocação de espaços de memória
#include <locale.h> //biblioteca de alocaçõ de texto por região
#include <string.h>// biblioteca responsável por cuidar das strings

int registrar() //função responsável por cadastrar os usuários no sistema.
	{
		char arquivo[40];//criação das variáveis que serão utilizadas nessa função ou strings
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char email[100];
		char cargo[40];
	
		
		printf("Digite o CPF a ser cadastrado: \n");//coletando informação do usuário
		scanf("%s", cpf);//armazenamento na string
		strcpy(arquivo,cpf);//responsável por copiar os valores das strings
		
		FILE *file; //cria o arquivo no banco de dados
		file=fopen(arquivo, "w");//cria o arquivo
		fprintf(file,cpf);//salva o valor da variável
		fclose(file);//fecha o arquivo
		
		file=fopen (arquivo, "a");//o "a" altera um arquivo que ja existe
		fprintf(file,",");//acrescenta a virgula dentro do arquivo para separar o cpf do nome, sobrenome e cargo
		fclose(file);
		
		printf("Digite o nome a ser cadastrado: \n");//coletando informação do usuário
		scanf("%s", nome);//armazenando na string
		
		
		file=fopen(arquivo,"a");//alterando um arquivo que já existe
		fprintf(file,nome);//salva o valor da variável
		fclose(file);//fecha o arquivo
		
		file=fopen(arquivo, "a");//altera um arquivo que já existe
		fprintf(file, ",");//acrescenta virgula depois de cada item
		fclose(file);//fecha o arquivo
		
	
		printf("Digite o sobrenome a ser cadastrado: \n");//coletando informação do usuário
		scanf("%s", sobrenome);//armazenando na string
		
		
		file=fopen(arquivo,"a");//altera um arquivo que já existe
		fprintf(file,sobrenome);//salva o valor da variável
		fclose(file);//fecha o arquivo
		
		file=fopen(arquivo, "a");//altera um arquivo que já existe
		fprintf(file, ",");//acrescenta virgula 
		fclose(file);//fecha o arquivo
		
		printf("Digite o email a ser cadastrado: \n");//coletando informação do usuário
		fgets(email, sizeof(email), stdin); // Lê uma linha inteira, incluindo espaços em branco		
		scanf("%s", email);//salva na string
		
		file=fopen(arquivo, "a");//altera um arquivo que já existe
		fprintf(file,email);//salva o valor da variável
		fclose(file);//fecha o arquivo
		
		file=fopen(arquivo,"a");//altera um arquivo que já existe
		fprintf(file,",");//acrescenta virgula
		fclose(file);// fecha o arquivo
		
		printf("Digite o cargo a ser cadastrado: \n");//coleta informação do usuário
		scanf("%s", cargo);//salva na string
		
		file=fopen(arquivo, "a");// abre e altera um arquivo que já existe
		fprintf(file,cargo);//salva o valor da variável
		fclose(file);//fecha o arquivo
		
		
		printf("\n\n*** Usuário cadastrado com sucesso!***\n\n");//mensagem de retorno para o usuário


	}

int consultar()//inicio das configurações da função consultar

	{
		setlocale (LC_ALL, "portuguese");//define o idioma como português
		
		char cpf[40];//cri as variáveis
		char conteudo[200];
		
		printf("Digite o CPF a ser consultado: \n");//coleta informação do usuário
		scanf("%s", cpf);//armazena na string
		
		
		FILE *file;//define arquivo que será aberto
		file = fopen(cpf,"r");// lê as informações do arquivo
		
		if(file == NULL)//inicio de condicionalcaso o arquivo não exista
		{
			system("cls");//limpa o sistema
			printf("XXX CPF não encontrado XXX \n\n");//retorna mensagem para o usuário
		}
			

		
		while(fgets(conteudo, 200, file) != NULL)// cria um loop
		{
    printf("\nEssas são as informações do usuário: \n\n");//entrega as informações do usuário consultado
    
    		// Separar os campos do conteúdo do arquivo a partir do elemento virgula
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

    		printf("\n");//espaço estético ao fim das informações
		}

	
	
	//fecha o arquivo
	
		
	}

int deletar() //inicio das configurações da função deletar
	{
		//define as variáveis
    	char cpf[40];
    	char conteudo[200];
    	char opcao;

    	setlocale(LC_ALL, "portuguese");//define idioma como português

    	printf("Digite o CPF a ser deletado: \n\n");//coleta informação do usuário
    	scanf("%s", cpf);//armazena na string

   	 	FILE *file;// define o arquivo que será aberto
    	file = fopen(cpf, "r");//abre o arquivo e lê as informações

    	if (file == NULL) //inicio de condição
		
		{
        printf("\n\nCPF não encontrado.\n\n");//devolve mensagem caso não encontre a informação
        return 0; // Retorna 0 se CPF não for encontrado
    	}

    while (fgets(conteudo, 200, file) != NULL) //inicia um loop
	
	{
        printf("\nInformações do usuário:\n\n");//devolve informação para o usuário
        
       //separa as informações a partir do elemento virgula
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

   		printf("\nDeseja deletar este usuário? Digite 1 para sim ou 2 para não: \n");//coleta informação do usuário
    	scanf(" %c", &opcao); // armazena a informação e lê apenas um caracter

    if (opcao == '1') // inicio de condicional
	
	{
        if (remove(cpf) == 0) //remove o usuário do banco de dado
		
		{ 
            printf("\n\nUsuário deletado com sucesso.\n\n");//devolutiva para o usuário
        } 
		
		else //alternativa
		
		{
            printf("Erro ao deletar usuário.\n\n");// devolve informação para o usuário
        }
        
    } 
	
	else if (opcao == '2') //alternativa
	
	{
        printf("\n\nUsuário não foi deletado.\n\n");//devolve informação para o usuário
        return 0; // Retorna 0 para voltar ao menu
    
	} else //alternativa
	
	{
        printf("\n\nOpção inválida.\n");//devolve informação para o usuário
    }
    
    while (getchar() != '\n'); // Limpa o buffer de entrada para que mais de 1 caracter não gere mais de 1 resposta
	}
	
	while (opcao != '1' && opcao != '2'); // estabelece um loop
	
    return 0;
	}

	
	
int main()
	{
		int opcao=0; //Definindo as variáveis
		int loop=1; //criação de nova variável

		for(loop=1;loop=1;)//Estabelecendo a função de repetição
		{

			system("cls"); //limpar sistema
			setlocale (LC_ALL,"portuguese"); //Denifindo Linguagem

			printf ("*** Cartório da EBAC ***\n\n"); //Inicio do Menu
			printf ("Digite o número correspondente à opção desejada:\n\n");
			printf ("\t1. Registrar usuário \n");
			printf ("\t2. Consultar cpf \n");
			printf ("\t3. Deletar usuário \n\n");
			printf ("Opção: ");//Final do Menu	

		scanf ("%d", &opcao); //Armazenando a escolha do usuário
		system ("cls");// Sistema "limpa" a tela depois da seleção de opção
		
		
		switch(opcao)//inicio das opções
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
					printf("Opção inválida\n\n");
					system("pause");
					break;//fim das opções
			}

		}
	}	

