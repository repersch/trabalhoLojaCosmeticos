#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define MAX 1000

struct Data {
	int dia;
	int mes;
	int ano;
};

struct Cliente {
	char cpf[50];
	char nome[50];
	Data dataNasc;
	char sexo[10];
	float salario;
	char email[60];
	char telefones[5][30];
}; 

struct Produto {
	int codigo;
	char descricao[100];
	int mls;
	float preco;
	int desconto;
	Data validade;
};
	
struct Compra {
	char cpf[30];
	int codigo;
	Data dataCompra;
	char horaCompra[10];
	float valor;
};

int menuPrincipal() {
	int op;
	printf("\n---------------------------------------------\n"
			"                MENU DE OPÇÕES"
			"\n---------------------------------------------\n"
			"1 - Submenu de Clientes\n"
			"2 - Submenu de Produtos\n"
			"3 - Submenu de Compra/Venda\n"
			"4 - Submenu Relatórios\n"
			"5 - Sair\n\n"
			"Escolha uma opção: ");
	fflush(stdin);
	scanf("%d", &op);
	return op;
}

int submenuClientes() {
	int op;
	printf("\n---------------------------------------------\n"
			"                SUBMENU CLIENTES"
			"\n---------------------------------------------\n"
			"1 - Listar todos os clientes\n"
			"2 - Listar um cliente\n"
			"3 - Cadastrar cliente\n"
			"4 - Alterar dados do cliente\n"
			"5 - Excluir dados do cliente\n"
			"6 - Voltar\n\n"
			"Escolha uma opção: ");
	scanf("%d", &op);
	return op;
}

void listarTodosClientes(Cliente registroClientes[], int contClientes) {
	for (int i = 0; i < contClientes; i++) {
		printf("CPF: %s", registroClientes[i].cpf);
		printf("\nNome: ");
		puts(registroClientes[i].nome);
		printf("Data de nascimento: %02d/%02d/%d", registroClientes[i].dataNasc.dia, registroClientes[i].dataNasc.mes,
		 registroClientes[i].dataNasc.ano);
		printf("\nSexo: ");
		puts(registroClientes[i].sexo);
		printf("Salário: R$%.2f", registroClientes[i].salario);
		printf("\nEmail: %s", registroClientes[i].email);
		printf("\nTelefone(s): ");
		for (int x = 0; x < 5; x++) {
			if ((strlen(registroClientes[i].telefones[x])) > 0) {
				printf("\n\t%s",registroClientes[i].telefones[x]);
			}
		}
		printf("\n---------------------------------------------\n\n");
	}
}

int buscarCliente(Cliente registroClientes[], char cpfBuscar[], int contClientes) {
	//verifica se o cpf já esta cadastrado no registro de clientes, retorna -1 caso não esteja ou o indíce caso esteja
	int achou = 0;
	if (contClientes == 0) {
		return -1;
	} else {
		for (int i = 0; i < contClientes && achou == 0; i++) {
			if (strcmp(cpfBuscar, registroClientes[i].cpf) == 0) {
				achou = 1;
				return i;
			}
		}
		return -1;
	}
}

void criarData(Data data[]) {
	//cria uma data, impedindo que dados errados sejam fornecidos
	data->dia = -1;
	printf("\tDia: ");
	while (data->dia < 1 || data->dia >= 32) {
		scanf("%d", &data->dia);
		if (data->dia < 1 || data->dia >= 32) {
			printf("Digite um dia válido: ");
		} else {
			data->mes = -1;
			printf("\tMês: ");
			while (data->mes < 1 || data->mes > 12) {
				scanf("%d", &data->mes);
				if (data->mes < 1 || data->mes > 12) {
					printf("Digite um mês válido: ");
				} else {
					data->ano = -1;
					printf("\tAno: ");
					while (data->ano < 1900) {
						scanf("%d", &data->ano);
						if (data->ano < 1900){
							printf("Digite um ano válido: ");
						} 
					}
				}
			}
		}
	} 
}

void cadastrarCliente(Cliente registroClientes[], int *contClientes, char cpf[]) {
		strcpy(registroClientes[*contClientes].cpf, cpf);
		printf("Nome: "); fflush(stdin);
		gets(registroClientes[*contClientes].nome);
		printf("Data de nascimento\n");
		Data dataNasc;
		criarData(&dataNasc);
		registroClientes[*contClientes].dataNasc = dataNasc;
		printf("Sexo: "); fflush(stdin);
		gets(registroClientes[*contClientes].sexo); 
		printf("Salário: R$");
		scanf("%f", &registroClientes[*contClientes].salario); fflush(stdin);
		printf("Email: ");
		gets(registroClientes[*contClientes].email);
		printf("Telefone: ");
		char confirma;
		for (int i = 0; i < 5; i++) {
			fflush(stdin);
			gets(registroClientes[*contClientes].telefones[i]);
			if (i != 4) {
				printf("Deseja acrescentar outro telefone? [S/N] ");
				scanf("%c", &confirma); 
				if (confirma == 'S'|| confirma == 's') {
					printf("Telefone %d: ", i + 2);
				} else {
					i = 5;
				}
			}	
		}
		printf("\n\nCliente cadastrado com sucesso!\n\n");
		(*contClientes)++;
}

void alterarCliente(Cliente registroClientes[], int posicao, int contClientes) {
	printf("Nome: "); fflush(stdin);
	gets(registroClientes[posicao].nome);
	printf("Data de nascimento\n");
	Data nascimento;
	criarData(&nascimento);
	registroClientes[posicao].dataNasc = nascimento; fflush(stdin);
	printf("Sexo: "); 
	gets(registroClientes[posicao].sexo);
	printf("Salário: R$");
	scanf("%f", &registroClientes[posicao].salario); fflush(stdin);
	printf("Email: ");
	gets(registroClientes[posicao].email);
	printf("Telefone(s): ");
	char confirma;
	for (int i = 0; i < 5; i++) {
			fflush(stdin);
			gets(registroClientes[posicao].telefones[i]);
			if (i != 4) {
				printf("Deseja acrescentar outro telefone? [S/N] ");
				scanf("%c", &confirma); 
				if (confirma == 'S'|| confirma == 's') {
					printf("Telefone %d: ", i + 2);
				} else {
					i = 5;
				}
			}	
		}
}	

void excluirCliente(Cliente registroClientes[], int posicao, int *contClientes) {
	for(int i = posicao; i < *contClientes - 1; i++) {
		registroClientes[i] = registroClientes[i + 1];
	}
	(*contClientes)--;
}

int submenuProduto() {
	int op;
	printf("\n---------------------------------------------\n"
			"                SUBMENU PRODUTOS"
			"\n---------------------------------------------\n"
			"1 - Listar todos os produtos\n"
			"2 - Listar um produto\n"
			"3 - Cadastrar produto\n"
			"4 - Alterar dados do produto\n"
			"5 - Excluir dados do produto\n"
			"6 - Voltar\n\n"
			"Escolha uma opção: ");
	scanf("%d", &op);
	return op;
}

void listarTodosProdutos(Produto registroProdutos[], int contProdutos) {
	for (int i = 0; i < contProdutos; i++) {
		printf("Código: %d", registroProdutos[i].codigo);
		printf("\nDescrição: ");
		puts(registroProdutos[i].descricao);
		printf("Quantidade em ml: %d", registroProdutos[i].mls);
		printf("\nPreço: R$%.2f", registroProdutos[i].preco);
		printf("\nDesconto: %d", registroProdutos[i].desconto);
		printf("\nData de validade: %02d/%02d/%d", registroProdutos[i].validade.dia, registroProdutos[i].validade.mes, registroProdutos[i].validade.ano);
		printf("\n---------------------------------------------\n\n");
	}
}

int buscarProduto(Produto registroProdutos[], int buscarCod, int contProdutos) {
	//verifica se existe algum produto cadastrado com o código passado, retorna -1 cao não haja ou o indíce cajo haja
	int achou = 0;
	if (contProdutos == 0) {
		return -1;
	} else {
		for (int i = 0; i < contProdutos && achou == 0; i++) {
			if (registroProdutos[i].codigo == buscarCod) {
				achou = 1;
				return i;
			}
		}
		return -1;
	}
}

void cadastrarProduto(Produto registroProdutos[], int *contProdutos, int codigo) {
	registroProdutos[*contProdutos].codigo = codigo;
	printf("Descrição: "); fflush(stdin);
	gets(registroProdutos[*contProdutos].descricao);
	printf("Quantidade em ml: ");
	scanf("%d", &registroProdutos[*contProdutos].mls);
	printf("Preço: R$");
	scanf("%f", &registroProdutos[*contProdutos].preco);
	printf("Desconto: ");
	scanf("%d", &registroProdutos[*contProdutos].desconto); fflush(stdin);
	printf("Data de validade\n");
	Data validade;
	criarData(&validade);
	registroProdutos[*contProdutos].validade = validade;
	(*contProdutos)++;
}

void alterarProduto(Produto registroProdutos[], int indice, int contProdutos) {
	printf("Descrição: "); fflush(stdin);
	gets(registroProdutos[indice].descricao);
	printf("Quantidade em ml: ");
	scanf("%d", &registroProdutos[indice].mls);
	printf("Preço: R$");
	scanf("%f", &registroProdutos[indice].preco);
	printf("Desconto: ");
	scanf("%d", &registroProdutos[indice].desconto); fflush(stdin);
	printf("Data de validade\n");
	Data validade;
	criarData(&validade);
	registroProdutos[indice].validade = validade;
}

void excluirProduto(Produto registroProdutos[], int indice, int *contProdutos) {
	for (int i = indice; i < (*contProdutos - 1); i++) {
		registroProdutos[i] = registroProdutos[i + 1];
	}
	(*contProdutos)--;
}

int validarCPF(char cpf[]) {
	//verifica se o cpf possui 11 caracteres e se todos são números, retorna 1 caso possua ou 0 caso não
	if (strlen(cpf) == 11) {
		int i, total;
		for (i = total = 0; cpf[i] != '\0'; i++) {
			if (isdigit(cpf[i])) {
				total++;
			}
		}
	if (total == 11) {
		return 1;
		} 
	} else {
		return 0;
	}
}

int submenuCompra() {
	int op;
	printf("\n---------------------------------------------\n"
			"                 SUBMENU COMPRAS"
			"\n---------------------------------------------\n"
			"1 - Listar todos as compras\n"
			"2 - Listar uma compra\n"
			"3 - Cadastrar compra\n"
			"4 - Alterar dados da compra\n"
			"5 - Excluir dados da compra\n"
			"6 - Voltar\n\n"
			"Escolha uma opção: ");
	scanf("%d", &op);
	fflush(stdin);
	return op;
}

void listarTodasAsCompras(Compra registroCompras[], int contCompras) { 
	for (int i = 0; i < contCompras; i++) {
		printf("\nCPF do cliente: ");
		puts(registroCompras[i].cpf);
		printf("Código do Produto: %d", registroCompras[i].codigo);
		printf("\nData da compra: %02d/%02d/%d", registroCompras[i].dataCompra.dia, registroCompras[i].dataCompra.mes, registroCompras[i].dataCompra.ano);
		printf("\nHora da compra: ");
		puts(registroCompras[i].horaCompra);
		printf("Total: R$%.2f", registroCompras[i].valor);
		printf("\n---------------------------------------------\n\n");
	}
}

int validarHora(char hora[]) {
	//verifica se a variável hora possui 5 caracteres, retorna 1 se tiver ou 0 se não tiver
	if (strlen(hora) == 5) {
		return 1;
	} else {
		return 0;
	}
}

int verificarDadosUnicos(Compra registroCompras[], int contCompras, char cpfCliente[], int codProduto, Data *data, char hora[]) {
	// Verifica se os dados de compra: cpf, codigo, data e hora há foram cadastrados juntos, retorna 1 caso o cadastro já exista e 0 caso não exista
	for (int i = 0; i < contCompras; i++) {
		if (strcmp(registroCompras[i].cpf, cpfCliente) == 0) {
			if(registroCompras[i].codigo == codProduto) {
				if (registroCompras[i].dataCompra.dia == data->dia && registroCompras[i].dataCompra.mes == data->mes && registroCompras[i].dataCompra.ano == data->ano) {
					if(strcmp(registroCompras[i].horaCompra, hora) == 0) {
						return 1;
					}
				}
			}
		}
	}
	return 0; //significa que não existe registro igual
}

void cadastrarCompra(Cliente registroClientes[], Produto registroProdutos[], Compra registroCompras[], int contClientes, int contProdutos, int *contCompras) {
	//Faz a conferência de todos os dados que não podem se repetir no registro de Compras 
	int ok1 = 0;
	int existe = -1;
	char dadosUnicos[4][50];
	while (ok1 == 0) {
		// Confere se cpf esta correto e se o cliente esta cadastrado (caso não esteja cadastrado, volta para o main)
			char cpfCliente[12];
			fflush(stdin);
			gets(cpfCliente);
			ok1 = validarCPF(cpfCliente);
			if (ok1 == 1) {
				existe = buscarCliente(registroClientes, cpfCliente, contClientes);
				if (existe == -1) {
					printf("Cliente não cadastrado.\n");	
				} else {
					printf("Cliente: ");
					puts(registroClientes[existe].nome);
		            //Solicita código do produto, confere se esta correto e se existe nos registros de produtos (caso não esteja cadastrado, volta para o main)
					int codProduto; 
					printf("Digite o código do produto: ");
					scanf("%d", &codProduto);
					int encontrou = buscarProduto(registroProdutos, codProduto, contProdutos);
					if (encontrou == -1) {
						printf("\nCódigo não cadastrado.\n");
					} else {
						printf("Produto: ");
						puts(registroProdutos[encontrou].descricao);
		                //Solicita a data da compra e verificar se é uma data válida
						Data dataCompra;
						printf("Data da compra\n");
						fflush(stdin);
						criarData(&dataCompra); fflush(stdin);
	                  	// Solicita a hora da compra e verifica se é uma hora válida
								char hora[6];
								int ok3 = 0;
								printf("Digite a hora da compra(XX:XX): ");
								while (ok3 == 0) {
									gets(hora);
									ok3 = validarHora(hora);
									if (ok3 == 1) {
	                                //Verifica se CPF, Produto, Data e Hora já foram cadastrados juntos 
										int ok4 = verificarDadosUnicos(registroCompras, *contCompras, cpfCliente, codProduto, &dataCompra, hora);
										if (ok4 == 1) {
											//caso já haja um registro com os mesmos dados
											printf("\nEssa compra não pode ser cadastrada pois já existe um registro com os mesmos dados.\n");
										} else {
											//caso não exista, salva os dados no registo de Compras e solicita o valor total da compra
											strcpy(registroCompras[*contCompras].cpf, cpfCliente);
											registroCompras[*contCompras].codigo = codProduto;
											registroCompras[*contCompras].dataCompra = dataCompra;
											strcpy(registroCompras[*contCompras].horaCompra, hora);
											printf("Total: R$");
											scanf("%f", &registroCompras[*contCompras].valor);
											(*contCompras)++;
											printf("\nCompra cadastrada com sucesso!\n\n");
										}
									} else {
										printf("Hora inválida! Digite uma hora válida(XX:XX): ");
									}
								}
								}
							} 
							}else {
								printf("CPF inválido! Por favor, digite um CPF válido: ");	
						} 
					} 
				} 

int validarDadosUnicosCompra(Compra registroCompras[], int contCompras) {
	//verifica se CPf, código, data e hora já foram registrados juntos, retorna -1 caso não haja registro compatível ou o indice caso haja
	char buscarCpf[12];
	int buscaCod;
	Data dataCompra;
	int indice;
	char hora[6];
	
	printf("CPF do cliente: ");
	fflush(stdin);
	gets(buscarCpf);
	for (int i = 0; i < contCompras; i++) {
		if (strcmp(registroCompras[i].cpf, buscarCpf) == 0) {
			printf("Código do produto: ");
			scanf("%d", &buscaCod);
			fflush(stdin);
			if (registroCompras[i].codigo == buscaCod) {
				printf("Data da compra\n");
				Data dataCompra;
				criarData(&dataCompra); fflush(stdin);
				if (registroCompras[i].dataCompra.dia == dataCompra.dia && registroCompras[i].dataCompra.mes == dataCompra.mes && registroCompras[i].dataCompra.ano == dataCompra.ano) {
					printf("Hora da compra: ");
					gets(hora);
					if (strcmp(registroCompras[i].horaCompra, hora) == 0) {
						return i;
					}
				} 
			}
		}
	}
	return -1;
}

void excluirRegistroCompra(Compra registroCompras[], int *contCompras, int indice) {
	for (int i = indice; i < (*contCompras - 1); i++) {
		registroCompras[i] = registroCompras[i + 1];
	}
	(*contCompras)--;
}

int submenuRelatorios() {
	int op;
	printf("\n---------------------------------------------\n"
			"               SUBMENU RELATÓRIOS"
			"\n---------------------------------------------\n"
			"1 - Dados por quantidade de telefones\n"
			"2 - Produtos com a data de validade exppirada\n"
			"3 - Registro de vendas entre datas\n"
			"4 - Voltar\n\n"
			"Escolha uma opção: ");
	scanf("%d", &op);
	return op;
}

int verificarQuantidadeTelefones(Cliente registroClientes[], int i, int maximo) {
	int total = 0;
	for (int x = 0; x < 5; x++) {
		if (strlen(registroClientes[i].telefones[x]) > 0) {
			total++;
		} 
	}
	if (total >= maximo) {
		return i;
	} else {
		return -1;
	}
}

time_t converterDataParaSegundos(Data data) {
	//converte a data para segundos para poder fazer comprações
	struct tm tempo = {};
	
	tempo.tm_mday = data.dia;
	tempo.tm_mon = data.mes - 1;
	tempo.tm_year = data.ano - 1900;
	
	time_t segundos = mktime(&tempo);
	return segundos;
}

void clientesParaTeste(Cliente registroClientes[], int *contClientes) {
	//////////////////////////CLIENTE 1/////////////////////////////
	strcpy(registroClientes[*contClientes].cpf, "36691200845");
	strcpy(registroClientes[*contClientes].nome, "Renata Persch");
	registroClientes[*contClientes].dataNasc.dia = 30;
	registroClientes[*contClientes].dataNasc.mes = 10;
	registroClientes[*contClientes].dataNasc.ano = 1990;
	strcpy(registroClientes[*contClientes].email, "renata@mail.com");
	strcpy(registroClientes[*contClientes].sexo, "f");
	registroClientes[*contClientes].salario = 5800;
	strcpy(registroClientes[*contClientes].telefones[0], "16996217567");
	strcpy(registroClientes[*contClientes].telefones[1], "16996217522");
	strcpy(registroClientes[*contClientes].telefones[2], "16996217533");
	(*contClientes)++;

	//////////////////////////CLIENTE 2/////////////////////////////
	strcpy(registroClientes[*contClientes].cpf, "14521452145");
	strcpy(registroClientes[*contClientes].nome, "Leticia Romania");
	registroClientes[*contClientes].dataNasc.dia = 12;
	registroClientes[*contClientes].dataNasc.mes = 12;
	registroClientes[*contClientes].dataNasc.ano = 1990;
	strcpy(registroClientes[*contClientes].email, "leticia@mail.com");
	strcpy(registroClientes[*contClientes].sexo, "f");
	registroClientes[*contClientes].salario = 6800;
	strcpy(registroClientes[*contClientes].telefones[0], "16996122365");
	strcpy(registroClientes[*contClientes].telefones[1], "16996214422");
	(*contClientes)++;
	
	//////////////////////////CLIENTE 3/////////////////////////////
	strcpy(registroClientes[*contClientes].cpf, "25632563256");
	strcpy(registroClientes[*contClientes].nome, "Bruno Ferreira");
	registroClientes[*contClientes].dataNasc.dia = 4;
	registroClientes[*contClientes].dataNasc.mes = 5;
	registroClientes[*contClientes].dataNasc.ano = 1995;
	strcpy(registroClientes[*contClientes].email, "bruno@mail.com");
	strcpy(registroClientes[*contClientes].sexo, "m");
	registroClientes[*contClientes].salario = 4560;
	strcpy(registroClientes[*contClientes].telefones[0], "16993333567");
	strcpy(registroClientes[*contClientes].telefones[1], "16991985522");
	strcpy(registroClientes[*contClientes].telefones[2], "16996335933");
	strcpy(registroClientes[*contClientes].telefones[3], "16996217533");
	(*contClientes)++;
	
	//////////////////////////CLIENTE 4/////////////////////////////
	strcpy(registroClientes[*contClientes].cpf, "47854785478");
	strcpy(registroClientes[*contClientes].nome, "Marina Gonçalves");
	registroClientes[*contClientes].dataNasc.dia = 14;
	registroClientes[*contClientes].dataNasc.mes = 7;
	registroClientes[*contClientes].dataNasc.ano = 1994;
	strcpy(registroClientes[*contClientes].email, "marina@mail.com");
	strcpy(registroClientes[*contClientes].sexo, "f");
	registroClientes[*contClientes].salario = 3450;
	strcpy(registroClientes[*contClientes].telefones[0], "16945717567");
	strcpy(registroClientes[*contClientes].telefones[2], "16996144563");
	(*contClientes)++;
	
	//////////////////////////CLIENTE 5/////////////////////////////
	strcpy(registroClientes[*contClientes].cpf, "58965896589");
	strcpy(registroClientes[*contClientes].nome, "Pedro Moraes");
	registroClientes[*contClientes].dataNasc.dia = 29;
	registroClientes[*contClientes].dataNasc.mes = 11;
	registroClientes[*contClientes].dataNasc.ano = 1992;
	strcpy(registroClientes[*contClientes].email, "pedro@mail.com");
	strcpy(registroClientes[*contClientes].sexo, "m");
	registroClientes[*contClientes].salario = 5800;
	strcpy(registroClientes[*contClientes].telefones[0], "16996346567");
	(*contClientes)++;
	
}

void produtosParaTeste(Produto registroProdutos[], int *contProdutos) {
	//////////////////////////PRODUTO 1/////////////////////////////
	registroProdutos[*contProdutos].codigo = 13;
	strcpy(registroProdutos[*contProdutos].descricao, "Perfume");
	registroProdutos[*contProdutos].mls = 150;
	registroProdutos[*contProdutos].preco = 450;
	registroProdutos[*contProdutos].desconto = 5;
	registroProdutos[*contProdutos].validade.dia = 15;
	registroProdutos[*contProdutos].validade.mes = 10;
	registroProdutos[*contProdutos].validade.ano = 2020;
	(*contProdutos)++;
	
	//////////////////////////PRODUTO 2/////////////////////////////
	registroProdutos[*contProdutos].codigo = 14;
	strcpy(registroProdutos[*contProdutos].descricao, "Creme");
	registroProdutos[*contProdutos].mls = 250;
	registroProdutos[*contProdutos].preco = 90;
	registroProdutos[*contProdutos].desconto = 2;
	registroProdutos[*contProdutos].validade.dia = 20;
	registroProdutos[*contProdutos].validade.mes = 11;
	registroProdutos[*contProdutos].validade.ano = 2021;
	(*contProdutos)++;
	
	//////////////////////////PRODUTO 3/////////////////////////////
	registroProdutos[*contProdutos].codigo = 15;
	strcpy(registroProdutos[*contProdutos].descricao, "Shampoo");
	registroProdutos[*contProdutos].mls = 150;
	registroProdutos[*contProdutos].preco = 95;
	registroProdutos[*contProdutos].desconto = 5;
	registroProdutos[*contProdutos].validade.dia = 17;
	registroProdutos[*contProdutos].validade.mes = 07;
	registroProdutos[*contProdutos].validade.ano = 2021;
	(*contProdutos)++;
	
	//////////////////////////PRODUTO 4/////////////////////////////
	registroProdutos[*contProdutos].codigo = 16;
	strcpy(registroProdutos[*contProdutos].descricao, "Desodorante");
	registroProdutos[*contProdutos].mls = 70;
	registroProdutos[*contProdutos].preco = 20;
	registroProdutos[*contProdutos].desconto = 3;
	registroProdutos[*contProdutos].validade.dia = 20;
	registroProdutos[*contProdutos].validade.mes = 7;
	registroProdutos[*contProdutos].validade.ano = 2020;
	(*contProdutos)++;
	
	//////////////////////////PRODUTO 5/////////////////////////////
	registroProdutos[*contProdutos].codigo = 17;
	strcpy(registroProdutos[*contProdutos].descricao, "Sabonete");
	registroProdutos[*contProdutos].mls = 20;
	registroProdutos[*contProdutos].preco = 11;
	registroProdutos[*contProdutos].desconto = 0;
	registroProdutos[*contProdutos].validade.dia = 2;
	registroProdutos[*contProdutos].validade.mes = 2;
	registroProdutos[*contProdutos].validade.ano = 2021;
	(*contProdutos)++;	
}

void comprasParaTeste(Compra registroCompras[], int *contCompras) {
	//////////////////////////COMPRA 1/////////////////////////////
	strcpy(registroCompras[*contCompras].cpf, "36691200845");
	registroCompras[*contCompras].codigo = 14;
	registroCompras[*contCompras].dataCompra.dia = 8;
	registroCompras[*contCompras].dataCompra.mes = 11;
	registroCompras[*contCompras].dataCompra.ano = 2020;
	strcpy(registroCompras[*contCompras].horaCompra, "17:30");
	registroCompras[*contCompras].valor = 145;
	(*contCompras)++; 
	
	//////////////////////////COMPRA 2/////////////////////////////
	strcpy(registroCompras[*contCompras].cpf, "14521452145");
	registroCompras[*contCompras].codigo = 17;
	registroCompras[*contCompras].dataCompra.dia = 10;
	registroCompras[*contCompras].dataCompra.mes = 10;
	registroCompras[*contCompras].dataCompra.ano = 2020;
	strcpy(registroCompras[*contCompras].horaCompra, "18:00");
	registroCompras[*contCompras].valor = 95;
	(*contCompras)++; 
	
	//////////////////////////COMPRA 3/////////////////////////////
	strcpy(registroCompras[*contCompras].cpf, "25632563256");
	registroCompras[*contCompras].codigo = 13;
	registroCompras[*contCompras].dataCompra.dia = 11;
	registroCompras[*contCompras].dataCompra.mes = 9;
	registroCompras[*contCompras].dataCompra.ano = 2020;
	strcpy(registroCompras[*contCompras].horaCompra, "12:30");
	registroCompras[*contCompras].valor = 570;
	(*contCompras)++; 
	
	//////////////////////////COMPRA 4/////////////////////////////
	strcpy(registroCompras[*contCompras].cpf, "47854785478");
	registroCompras[*contCompras].codigo = 17;
	registroCompras[*contCompras].dataCompra.dia = 19;
	registroCompras[*contCompras].dataCompra.mes = 11;
	registroCompras[*contCompras].dataCompra.ano = 2020;
	strcpy(registroCompras[*contCompras].horaCompra, "13:45");
	registroCompras[*contCompras].valor = 74;
	(*contCompras)++; 
	
	//////////////////////////COMPRA 5/////////////////////////////
	strcpy(registroCompras[*contCompras].cpf, "36691200845");
	registroCompras[*contCompras].codigo = 15;
	registroCompras[*contCompras].dataCompra.dia = 22;
	registroCompras[*contCompras].dataCompra.mes = 11;
	registroCompras[*contCompras].dataCompra.ano = 2020;
	strcpy(registroCompras[*contCompras].horaCompra, "15:30");
	registroCompras[*contCompras].valor = 274;
	(*contCompras)++; 
	
	//////////////////////////COMPRA 6/////////////////////////////
	strcpy(registroCompras[*contCompras].cpf, "58965896589");
	registroCompras[*contCompras].codigo = 16;
	registroCompras[*contCompras].dataCompra.dia = 4;
	registroCompras[*contCompras].dataCompra.mes = 10;
	registroCompras[*contCompras].dataCompra.ano = 2020;
	strcpy(registroCompras[*contCompras].horaCompra, "10:43");
	registroCompras[*contCompras].valor = 45;
	(*contCompras)++; 
		
}

main() {
	setlocale(LC_ALL, "Portuguese");
	
	int opcao = 0;
	Cliente registroClientes[MAX];
	int contClientes = 0;
	Produto registroProdutos[MAX];
	int contProdutos = 0;
	Compra registroCompras[MAX];
	int contCompras = 0;
		
	//criando massa para teste
	clientesParaTeste(registroClientes, &contClientes);
	produtosParaTeste(registroProdutos, &contProdutos);
	comprasParaTeste(registroCompras, &contCompras);
		
	while (opcao < 5) 
	{
		opcao = menuPrincipal();
		switch (opcao) 
		{
			case 1: 
			{
				int op = 0;
				while (op != 6) 
				{
					op = submenuClientes();
					if (op == 1) 
					{
						printf("\n\n--- Lista de todos os clientes cadastrados ---\n\n");
						listarTodosClientes(registroClientes, contClientes);
					} else
					if (op == 2) 
					{
						printf("\n\n--- Listar cliente ---\n\n");
						printf("Digite o CPF do cliente que deseja listar: ");
						int ok = 0;
						while (ok == 0) {
							char cpfBuscar[12]; fflush(stdin);
							gets(cpfBuscar);
							ok = validarCPF(cpfBuscar); 
							if (ok == 1) {
								int encontrou = buscarCliente(registroClientes, cpfBuscar, contClientes);
								if (encontrou == -1) {
									printf("\nCPF não cadastrado.\n");
								} else {
									printf("\nNome: ");
									puts(registroClientes[encontrou].nome);
									printf("Data de nascimento: %02d/%02d/%d", registroClientes[encontrou].dataNasc.dia, registroClientes[encontrou].dataNasc.mes,
		 								registroClientes[encontrou].dataNasc.ano);
									printf("\nSexo: %s", registroClientes[encontrou].sexo);
									printf("\nSalário: R$%.2f", registroClientes[encontrou].salario);
									printf("\nEmail: %s", registroClientes[encontrou].email);
									printf("\nTelefone(s): ");
									for ( int x = 0; x < 5; x++) {
										if ((strlen(registroClientes[encontrou].telefones[x])) > 0) {
											printf("\n\t%s", registroClientes[encontrou].telefones[x]);
										}		
									}
								}
							} else {
								printf("CPF inválido! Por favor, digite um CPF válido: ");
							} 
						}
					} else
					if (op == 3)
					{
						printf("\n\n--- Cadastrar cliente ---\n\n");
						printf("Digite o CPF do cliente que deseja cadastrar: "); 
						int ok = 0;
						while (ok == 0) {
							char cpfBuscar[12]; fflush(stdin);
							gets(cpfBuscar);
							ok = validarCPF(cpfBuscar);
							if (ok == 1) {
								int existe = buscarCliente(registroClientes, cpfBuscar, contClientes);
								if (existe == -1) {
									cadastrarCliente(registroClientes, &contClientes, cpfBuscar);
								} else {
									printf("\nCPF já cadastrado.\n");
								}
							} else {
								printf("CPF inválido! Por favor, digite um CPF válido: ");
							}
						}
					} else 
					if (op == 4) 
					{
						printf("\n\n--- Alterar dados do cliente ---\n\n");
						printf("Digite o CPF do cliente que deseja alterar: ");
						int ok = 0;
						while (ok == 0) {
							char cpfBuscar[12]; fflush(stdin);
							gets(cpfBuscar);
							ok = validarCPF(cpfBuscar);
							if (ok == 1) {
								int existe = buscarCliente(registroClientes, cpfBuscar, contClientes);
								if (existe == -1) {
									printf("\nCPF não cadastrado.\n");
								} else {
									alterarCliente(registroClientes, existe, contClientes);
									printf("\nDados do cliente alterados com sucesso!\n");
								}
							} else {
								printf("CPF inválido! Por favor, digite um CPF válido: ");
							}
						}
					} else 
					if (op == 5)
					{
						printf("\n\n--- Excluir dados do cliente ---\n\n");
						printf("Digite o CPF do cliente que deseja excluir: "); 
						int ok = 0;
						while (ok == 0) {
							char cpfBuscar[12]; fflush(stdin);
							gets(cpfBuscar);
							ok = validarCPF(cpfBuscar);
							if (ok == 1) {
								int existe = buscarCliente(registroClientes, cpfBuscar, contClientes);
								if (existe == -1) {
									printf("\nCPF não cadastrado.\n");
								} else {
									char confirma;
									printf("Excluir cliente: %s? (S/N) ", registroClientes[existe].nome); fflush(stdin);
									scanf("%c", &confirma);
									if (confirma == 's') {
										excluirCliente(registroClientes, existe, &contClientes);
										printf("\nDados do cliente excluidos com sucesso!\n");
									} else {
										printf("Exclusao de cliente cancelada.\n");
									}
								} 
							} else {
								printf("CPF inválido! Por favor, digite um CPF válido: ");
							}
						}
					}	
				}
				break;
			}
			case 2:
			{
				int op = 0;
				while (op != 6) 
				{
					op = submenuProduto();
					if (op == 1) 
					{
						printf("\n\n--- Lista de todos os produtos cadastrados ---\n\n");
						listarTodosProdutos(registroProdutos, contProdutos);
					} else
					if (op == 2)
					{
						printf("\n\n--- Listar produto ---\n\n");
						int buscarCod;
						printf("Digite o código do produto que deseja listar: ");
						scanf("%d", &buscarCod);
						int encontrou = buscarProduto(registroProdutos, buscarCod, contProdutos);
						if (encontrou == -1) {
							printf("\nCódigo não cadastrado.\n");
						} else {
							printf("\nDescrição: ");
							puts(registroProdutos[encontrou].descricao);
							printf("Quantidade em ml: %d", registroProdutos[encontrou].mls);
							printf("\nPreço: R$%.2f", registroProdutos[encontrou].preco);
							printf("\nDesconto: %d%", registroProdutos[encontrou].desconto);
							printf("\nData de validade: %02d/%02d/%d\n\n", registroProdutos[encontrou].validade.dia, registroProdutos[encontrou].validade.mes, registroProdutos[encontrou].validade.ano);					
						}
					} else 
					if (op == 3)
					{
						printf("\n\n--- Cadastrar produto ---\n\n");	
						int buscarCod;
						printf("Digite o código do produto que deseja cadastrar: ");
						scanf("%d", &buscarCod);
						int existe = buscarProduto(registroProdutos, buscarCod, contProdutos);
						if (existe == -1) {
							cadastrarProduto(registroProdutos, &contProdutos, buscarCod);
							printf("\nProduto cadastrado com sucesso!\n");
						} else {
							printf("\nCódigo de produto já cadastrado.\n");
						}
					} else
					if (op == 4)
					{
						printf("\n\n--- Alterar dados do produto ---\n\n");
						int buscarCod;
						printf("Digite o cóigo do produto que deseja alterar: ");
						scanf("%d", &buscarCod);
						int existe = buscarProduto(registroProdutos, buscarCod, contProdutos);
						if (existe == -1) {
							printf("\nCódigo de produto não cadastrado.\n");
						} else {
							alterarProduto(registroProdutos, existe, contProdutos);
							printf("\nDados do produto alterados com sucesso!\n");
						}
					} else 
					if (op == 5) 
					{
						printf("\n\n--- Excluir dados do produto ---\n\n");
						int buscarCod;
						printf("Digite o código do produto que deseja excluir: ");
						scanf("%d", &buscarCod);
						int existe = buscarProduto(registroProdutos, buscarCod, contProdutos);
						if (existe == -1) {
							printf("\nCódigo de produto não cadastrado.\n");
						} else {
							char confirma;
							printf("Excluir produto: %s? (S/N) ", registroProdutos[existe].descricao); fflush(stdin);
							scanf("%c", &confirma);
							if (confirma == 's') {
								excluirProduto(registroProdutos, existe, &contProdutos);
								printf("\nDados do produto excluidos com sucesso!\n");
							} else {
								printf("Exclusão do produto cancelada.\n");
							}
						}
					} 
				}
				break;	
			}
			case 3:
			{
				int op = 0;
				while (op != 6) 
				{
					op = submenuCompra();
					if (op == 1) 
					{
						printf("\n\n--- Lista de todos as compras cadastradas ---\n\n");
						listarTodasAsCompras(registroCompras, contCompras);
					} else 
					if (op == 2) 
					{
						printf("\n\n--- Listar dados de compra ---\n\n");
						int indice = validarDadosUnicosCompra(registroCompras, contCompras);
						if (indice == -1) {
							printf("Não há registro com esses dados.\n\n");
						} else {
							char cpf[12];
							strcpy(cpf, registroCompras[indice].cpf);
							int codigo = registroCompras[indice].codigo;
							for (int i = 0; i < contClientes; i++) {
								if (strcmp(registroClientes[i].cpf, cpf) == 0) {
									printf("Nome: ");
									puts(registroClientes[i].nome);
								}
							}
							for (int i = 0; i < contProdutos; i ++) {
								if (registroProdutos[i].codigo == codigo) {
									printf("Produto: ");
									puts(registroProdutos[i].descricao);
								}
							}
							printf("Valor total: R$%.2f\n\n", registroCompras[indice].valor);
						}
					} else 
					if (op == 3)
					{
						printf("\n\n--- Cadastrar compra ---\n\n");
						printf("CPF do cliente: ");
						cadastrarCompra(registroClientes, registroProdutos, registroCompras, contClientes, contProdutos, &contCompras);
					} else 
					if (op == 4) 
					{
						printf("\n\n--- Alterar cadastro de compra ---\n\n");
						int indice = validarDadosUnicosCompra(registroCompras, contCompras);
						if (indice == -1) {
							printf("Não há registro com esses dados.");
						} else {
							printf("Digite o novo valor total: R$");
							scanf("%f", &registroCompras[indice].valor);
							printf("\nValor alterado com sucesso!");
						}
					} else 
					if (op == 5) 
					{
						printf("\n\n--- Excluir cadastro de compra ---\n\n");
						int indice = validarDadosUnicosCompra(registroCompras, contCompras);
						if (indice == -1) {
							printf("Não há registro com esses dados.\n");
						} else {
							char cpf[12];
							strcpy(cpf, registroCompras[indice].cpf);
							int codigo = registroCompras[indice].codigo;
							for (int i = 0; i < contClientes; i++) {
								if (strcmp(registroClientes[i].cpf, cpf) == 0) {
									printf("Nome: ");
									puts(registroClientes[i].nome);
								}
							}
							for (int i = 0; i < contProdutos; i ++) {
								if (registroProdutos[i].codigo == codigo) {
									printf("Produto: ");
									puts(registroProdutos[i].descricao);
								}
							}
							printf("Valor total: R$%.2f\n\n", registroCompras[indice].valor);
							char resp;
							printf("Confirmar exclusão do registro [S/N]? ");
							scanf("%c", &resp);
							if (resp == 's' || resp == 'S') {
								excluirRegistroCompra(registroCompras, &contCompras, indice);
								printf("\nRegistro excluído com sucesso!\n\n");
								
							} else {
								printf("Exclusão cancelada.\n\n");
							}
						}	
					}	
				}
				break;
			}
			case 4: 
			{
				int op = 0;
				while (op != 4) {
					op = submenuRelatorios();
					if (op == 1) 
					{
						int quantTelefones;
						int indice;
						printf("\n\n--- Registros com mais de X telefones ---\n\n");
						printf("Determine a quantidade de telefones: ");
						scanf("%d", &quantTelefones);
						printf("\n\nRegistro de clientes que possuem mais de %d telefones cadastrados\n\n", quantTelefones);
						for (int i = 0; i < contClientes; i++) {
							indice = verificarQuantidadeTelefones(registroClientes, i, quantTelefones);
							if (indice != -1) {
								printf("CPF: ");
								puts(registroClientes[indice].cpf);
								printf("Nome: ");
								puts(registroClientes[indice].nome);
								printf("Data de nascimento: %02d/%02d/%d", registroClientes[indice].dataNasc.dia, registroClientes[indice].dataNasc.mes,
		 							registroClientes[indice].dataNasc.ano);
								printf("\nSexo: ");
								puts(registroClientes[indice].sexo);
								printf("Salário: R$%.2f", registroClientes[indice].salario);
								printf("\nEmail: %s", registroClientes[indice].email);
								printf("\nTelefone(s): ");
								for (int x = 0; x < 5; x++) {
									if ((strlen(registroClientes[i].telefones[x])) > 0) {
										printf("\n\t%s",registroClientes[i].telefones[x]);
									}
								}	
								printf("\n---------------------------------------------\n\n");	
							}
						}	
					} else 
					if (op == 2) 
					{
						time_t validade;
						time_t dataAtual;
						time(&dataAtual);
						
						printf("\n\n--- Produtos com a data de validade expirada ---\n\n");
						int cont;
						for (int i = 0; i < contProdutos; i++) { 
							validade = converterDataParaSegundos(registroProdutos[i].validade);
							if (dataAtual > validade) {
									cont++;
									printf("Código: %d", registroProdutos[i].codigo);
									printf("\nDescrição: ");
									puts(registroProdutos[i].descricao);
									printf("Quantidade em ml: %d", registroProdutos[i].mls);
									printf("\nPreço: R$%.2f", registroProdutos[i].preco);
									printf("\nDesconto: %d", registroProdutos[i].desconto);
									printf("\nData de validade: %02d/%02d/%d", registroProdutos[i].validade.dia, registroProdutos[i].validade.mes, registroProdutos[i].validade.ano);
									printf("\n---------------------------------------------\n\n");
							}
						}
						if (cont == 0) {
							printf("\nNão existem produtos com a data de validade expirada em estoque.\n\n");
						}				
					} else
					if (op == 3)
					{
						Data final, inicial;
						int achou = 0;
						time_t dataInicial;
						time_t dataFinal;
						int cont = 0;
						
						printf("\n\n--- Relatório de compras entre datas ---\n\n");
						printf("Data inicial\n");
						fflush(stdin);
						criarData(&inicial);
						printf("Data final\n");
						fflush(stdin);
						criarData(&final);
						dataInicial = converterDataParaSegundos(inicial);
						dataFinal = converterDataParaSegundos(final);
						printf("\n\nCompras feitas entre %02d/%02d/%d e %02d/%02d/%d:\n", inicial.dia, inicial.mes, inicial.ano, final.dia, final.mes, final.ano);
						for (int i = 0; i < contCompras; i++) {
							time_t  dataDaCompra;
							dataDaCompra = converterDataParaSegundos(registroCompras[i].dataCompra);
							if(dataDaCompra > dataInicial && dataDaCompra < dataFinal) {
								cont++;
								printf("\nCliente \n\tCPF: ");
								puts(registroCompras[i].cpf);
								for (int x = 0; x < contClientes && achou == 0; x++) {
									if (strcmp(registroCompras[i].cpf, registroClientes[x].cpf) == 0) {
										printf("\tNome: ");
										puts(registroClientes[x].nome);
										achou = 1;
									}
								}
								achou = 0;
								printf("Produto\n\tCódigo: %d", registroCompras[i].codigo);
								for (int y = 0; y < contProdutos && achou == 0; y++) {
									if (registroCompras[i].codigo == registroProdutos[y].codigo) {
										printf("\n\tDescrição: ");
										puts(registroProdutos[y].descricao);
									}
								}
								printf("Compra");
								printf("\n\tData: %02d/%02d/%d", registroCompras[i].dataCompra.dia, registroCompras[i].dataCompra.mes, registroCompras[i].dataCompra.ano);
								printf("\n\tHora: ");
								puts(registroCompras[i].horaCompra);
								printf("\tValor total: %.2f", registroCompras[i].valor);
								printf("\n---------------------------------------------\n\n");
								}	
							}
							if ( cont == 0) {
								printf("\nNão existem compras registradas nesse período.\n\n");
							}
						}
					}break;
				}
			}
		
		}printf("\nSaindo..."); 
	}
	

