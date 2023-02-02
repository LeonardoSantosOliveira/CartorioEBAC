#include <stdio.h> 	//biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��es de texto por regiao
#include <string.h> //biblioteca que cuida das strings

int registro() //fun��o responsavel por cadastrar os usuarios no sistema
{
	//inicio da crian��o das variaveis
	char arquivo[40];
	char cpf[40];
	char nome[60];
	char sobrenome[60];
	char cargo[40];
	//fim da crian��o das variaveis
	
	printf ("\t### CADASTRO DE DADOS ###");
	printf("\n\nCPF A SER CADASTRADO: "); //coletando informa��o do usuario
	scanf("%s", &cpf); //%s placeholder string
	
	strcpy(arquivo, cpf); //responsavel por copiar valor das strings
	
	FILE *file; //cria o arquivo no bd
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, "CPF: %s",cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nNOME: ");
	fclose(file);
	
	printf ("NOME A SER CADASTRADO: ");
	scanf("%s", &nome);
	
	file = fopen(arquivo, "a");
	fprintf (file, nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file, "\nSOBRENOME: ");
	fclose(file);
	
	printf ("SOBRENOME A SER CADASTRADO: ");
	scanf("%s", &sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo ,"a");
	fprintf(file,"\nCARGO: ");
	fclose (file);
	
	printf ("CARGO A SER CADASTRADO: ");
	scanf ("%s", &cargo);
	
	file = fopen(arquivo, "a");
	fprintf (file, cargo);
	fclose (file);
	
	printf ("\nCADASTRO RELIZADO COM SUCESSO!\n"); //RETORNA MENSAGEM POSITIVA CASO ESTEJA TUDO OK!
	
	system("pause");					
}

int consultar() //inicio da fun��o consultar
{
	setlocale(LC_ALL, "Portuguese"); //setando a localidade
	
	//inicio da declara��o das strings
	char cpf[40];
	char conteudo [200];
	//fim da declara��o das strings
	
	printf ("\t### CONSULTA DE DADOS ###");
	printf ("\n\nCPF A SER CONSULTADO: ");
	scanf ("\n%s", cpf);
	printf ("\n");
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf ("\tNAO FOI POSSIVEL LOCALIZAR CPF\n\n");
		system ("pause");	
	}
	
	while (fgets(conteudo, 200, file) != NULL)
	{
		
		printf("\t%s", conteudo);
	}
	
	printf ("\n");
	system ("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf ("\n\t### DELETAR NOMES ###\n\n");
	
	printf ("DIGITE O CPF A SER DELETADO: ");
	scanf ("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf ("OS DADOS N�O EXISTEM NO SISTEMA!\n\n");
		system ("pause");
			}	
			else {
				printf ("DADOS DELETADOS COM SUCESSO!\n !FAVOR REINICIAR O PROGRAMA PARA SALVAR AS ALTERA��ES!\n\n");
			
			}
				
	system ("pause");
}

int main ()
{
	int opcao = 0; //definindo as variaveis 
	int laco = 1;
	
			
	for (laco = 1; laco = 1;)
	{
	
		system ("cls");
			
		setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
		printf ("### CART�RIO DA EBAC ###\n\n"); // inicio do menu	
		printf ("Escolha a op��o desejada do menu:\n\n");
		printf ("\t1 - REGISTRAR NOMES\n");
		printf ("\t2 - CONSULTAR NOMES\n");
		printf ("\t3 - DELETAR NOMES\n"); // fim do menu
		printf ("\t4 - SAIR DO SISTEMA\n\n");
	
		printf ("Op��o: ");
		scanf("%d", &opcao); // lendo a op��o do usuario
	
		system("cls"); //limpando a tela
		
		switch (opcao)
		{
			case 1:
				registro();
			break;
			
			case 2:
				consultar();
			break;
			
			case 3:
				deletar();
			break;
			
			case 4:
				printf ("OBRIGADO POR UTILIZAR O SISTEMA!\n");
				return (0);
				break;
						
			default:
				printf ("\n\t### OP��O INVALIDA ###\n\n");
				system ("pause");
			break;
		}
			
}
	printf ("Esse SOFTWARE � de uso restrito\n");
	printf("Desenvolvido por: Leonardo dos Santos de Oliveira\n"); 
	printf ("ATEN��O: ESSE SOFTWARE ENCONTRA-SE EM DESENVOLVIMENTO!\n");
	
return (0);
}
