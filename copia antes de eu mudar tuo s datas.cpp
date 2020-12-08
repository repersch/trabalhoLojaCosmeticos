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
	char cpf[12];
	char nome[50];
	//char dataNasc[11];
	Data dataNasc;
	char sexo;
	float salario;
	char email[60];
	char telefone[15];
}; 

struct Produto {
	int codigo;
	char descricao[100];
	int mls;
	float preco;
	int desconto;
	char validade[11];
};
	
struct Compra {
	char cpf[12];
	int codigo;
	Data dataCompra;
	char horaCompra[6];
	float valor;
};




int menuPrincipal() {
	int op;
	printf("\n---------------------------------\n"
			"        MENU DE OPÇÕES"
			"\n---------------------------------\n"
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
	printf("\n---------------------------------\n"
			"        SUBMENU CLIENTES"
			"\n---------------------------------\n"
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
		printf("Data de nascimento: %d", registroClientes[i].dataNasc);
		printf("\nSexo: %c", registroClientes[i].sexo);
		printf("\nSalário: R$%.2f", registroClientes[i].salario);
		printf("\nEmail: %s", registroClientes[i].email);
		printf("\nTelefone: %s", registroClientes[i].telefone);
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

Data criarData() {
	//no main fazer a frase chamando a função (digite a data de nascimento: )
	Data nascimento;
	nascimento.dia = -1;
	while (nascimento.dia < 0 || nascimento.dia >= 32) {
		scanf("%d", &nascimento.dia);
		if (nascimento.dia < 0 || nascimento.dia >= 32) {
			printf("Digite um dia válido: ");
		} else {
			nascimento.mes = -1;
			while (nascimento.mes < 0 || nascimento.mes > 12) {
				scanf("%d", &nascimento.mes);
				if (nascimento.mes < 0 || nascimento.mes > 12) {
					printf("Digite um mês válido: ");
				} else {
					nascimento.ano = -1;
					while (nascimento.ano < 1900 || nascimento.ano > 2020) {
						scanf("%d", nascimento.ano);
						if (nascimento.ano < 1900 || nascimento.ano > 2020){
							printf("Digite um ano válido: ");
						} 	
					}
				}
			}
		}
	}
}

void cadastrarCliente(Cliente registroClientes[], int *contClientes, char cpfBuscar[]) {
		strcpy(registroClientes[*contClientes].cpf, cpfBuscar);
		printf("Nome: "); fflush(stdin);
		gets(registroClientes[*contClientes].nome);
		printf("Data de nascimento: ");
		registroClientes[*contClientes].dataNasc = criarData();
		//gets(registroClientes[*contClientes].dataNasc);
		//scanf("%d", &registroClientes[*contClientes].dataNasc); fflush(stdin);
		
	
		printf("Sexo: ");
		scanf("%c", &registroClientes[*contClientes].sexo); 
		printf("Salário: R$");
		scanf("%f", &registroClientes[*contClientes].salario); fflush(stdin);
		printf("Email: ");
		gets(registroClientes[*contClientes].email);
		printf("Telefone: ");
		gets(registroClientes[*contClientes].telefone);
		printf("\n\nCliente cadastrado com sucesso!\n\n");
		(*contClientes)++;
}

void alterarCliente(Cliente registroClientes[], int posicao, int contClientes) {
	printf("Nome: "); fflush(stdin);
	gets(registroClientes[posicao].nome);
	printf("Data de nascimento: ");
	//gets(registroClientes[posicao].dataNasc);
	scanf("%d", registroClientes[posicao].dataNasc);
	printf("Sexo: "); 
	scanf("%c", &registroClientes[posicao].sexo);
	printf("Salário: R$");
	scanf("%f", &registroClientes[posicao].salario); fflush(stdin);
	printf("Email: ");
	gets(registroClientes[posicao].email);
	printf("Telefone: ");
	gets(registroClientes[posicao].telefone);
}

void excluirCliente(Cliente registroClientes[], int posicao, int *contClientes) {
	for (int i = posicao; i < (*contClientes - 1); i++) {
		strcpy(registroClientes[i].cpf, registroClientes[i + 1].cpf);
		strcpy(registroClientes[i].nome, registroClientes[i + 1].nome);
		//strcpy(registroClientes[i].dataNasc, registroClientes[i + 1].dataNasc);
		registroClientes[i].dataNasc = registroClientes[i + 1].dataNasc;
		registroClientes[i].sexo = registroClientes[i + 1].sexo;
		registroClientes[i].salario = registroClientes[i + 1].salario;
		strcpy(registroClientes[i].email, registroClientes[i + 1].email);
		strcpy(registroClientes[i].telefone, registroClientes[i + 1].telefone);
	}
	/*strcpy(registroClientes[*contClientes].cpf, '\0');
	strcpy(registroClientes[*contClientes].nome, '\0');
	strcpy(registroClientes[*contClientes].dataNasc, '\0');
	registroClientes[*contClientes].sexo = '\0';
	registroClientes[*contClientes].salario = '\0';
	strcpy(registroClientes[*contClientes].email, '\0');
	strcpy(registroClientes[*contClientes].telefone, '\0'); */
	(*contClientes)--;
}

int submenuProduto() {
	int op;
	printf("\n---------------------------------\n"
			"        SUBMENU PRODUTOS"
			"\n---------------------------------\n"
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
		printf("\nData de validade: %s", registroProdutos[i].validade);
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
	printf("Data de validade: ");
	gets(registroProdutos[*contProdutos].validade);
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
	printf("Data de validade: ");
	gets(registroProdutos[indice].validade);
}

void excluirProduto(Produto registroProdutos[], int indice, int *contProdutos) {
	for (int i = indice; i < (*contProdutos - 1); i++) {
		registroProdutos[i].codigo = registroProdutos[i + 1].codigo;
		strcpy(registroProdutos[i].descricao, registroProdutos[i + 1].descricao);
		registroProdutos[i].mls = registroProdutos[i + 1].mls;
		registroProdutos[i].preco = registroProdutos[i + 1].preco;
		registroProdutos[i].desconto = registroProdutos[i + 1].desconto;
		strcpy(registroProdutos[i].validade, registroProdutos[i + 1].validade);
	}
	(*contProdutos)--;
}

int validarCPF(char cpf[]) {
	//verifica se o cpf possui 11 caracteres e se todos são números, retorna 1 caso possua ou  caso não
	if (strlen(cpf) == 11) {
		int i, total;
		for (i = total = 0; cpf[i] != '\0'; i++) {
			if (isdigit(cpf[i])) {
				total++;
			}
		}
	printf("\n\nO total de caracteres é: %d\n\n", total);
	if (total == 11) {
		return 1;
		} 
	} else {
		return 0;
	}
}

int submenuCompra() {
	int op;
	printf("\n---------------------------------\n"
			"        SUBMENU COMPRAS"
			"\n---------------------------------\n"
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
		printf("\nData da compra: ");
		registroCompras[i].dataCompra = criarData();
		printf("Hora da compra: ");
		puts(registroCompras[i].horaCompra);
		printf("Total: R$%.2f", registroCompras[i].valor);
		printf("\n---------------------------------------------\n\n");
	}
}

int validarHora(char hora[]) {
	//verifica se a variável hora possui caracteres, retorna 1 se tiver ou 0 se não tiver
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
				//if(strcmp(registroCompras[i].dataCompra, data) == 0) {
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
		/////////////////////////// Confere se cpf esta correto e se o cliente esta cadastrado (caso não esteja cadastrado, volta para o main)
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
		////////////////////////// Solicitar código do produto, confere se esta correto e se existe nos registros de produtos (caso não esteja cadastrado, volta para o main)
					int codProduto; 
					printf("Digite o código do produto: ");
					scanf("%d", &codProduto);
					int encontrou = buscarProduto(registroProdutos, codProduto, contProdutos);
					if (encontrou == -1) {
						printf("\nCódigo não cadastrado.\n");
					} else {
						printf("Produto: ");
						puts(registroProdutos[encontrou].descricao);
		////////////////////////// Solicitar a data da compra e verificar se é uma data válida
						Data dataCompra;
						printf("Data da compra: ");
						fflush(stdin);
							dataCompra = criarData();
		///////////////////////// Solicitar a hora da comprar e verificar se é uma hora válida
								char hora[6];
								int ok3 = 0;
								printf("Digite a hora da compra(XX:XX): ");
								while (ok3 == 0) {
									gets(hora);
									ok3 = validarHora(hora);
									if (ok3 == 1) {
	/////////////////////////////////////Verifica se CPF, Produto, Data e Hora já foram cadastrados juntos 
										int ok4 = verificarDadosUnicos(registroCompras, *contCompras, cpfCliente, codProduto, Data.data, hora);
										if (ok4 == 1) {
											//caso já haja um registro com os mesmos dados
											printf("\nEssa compra não pode ser cadastrada pois já existe um registro com os mesmos dados.\n");
										} else {
											//caso não exista, salva os dados no registo de Compras e solicita o valor total da compra
											strcpy(registroCompras[*contCompras].cpf, cpfCliente);
											registroCompras[*contCompras].codigo = codProduto;
											strcpy(registroCompras[*contCompras].dataCompra, data);
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
							} else {
								printf("Data inválida! Por favor, Digite uma data válida(XX/XX/XXXX): ");
							}		
											
					}
				} 
			} else {
				printf("CPF inválido! Por favor, digite um CPF válido: ");
		}
	}	
	
}

int validarDadosUnicosCompra(Compra registroCompras[], int contCompras) {
	//verifica se CPf, código, data e hora já foram registrados juntos, retorna -1 caso não haja registro compatível ou o indice cad haja
	char buscarCpf[12];
	int buscaCod;
	char data[11];
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
				printf("Data da compra: ");
				gets(data);
				if (strcmp(registroCompras[i].dataCompra, data) == 0) {
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
		strcpy(registroCompras[i].cpf, registroCompras[i + 1].cpf);
		registroCompras[i].codigo = registroCompras[i + 1].codigo;
		strcpy(registroCompras[i].dataCompra, registroCompras[i + 1].dataCompra);
		strcpy(registroCompras[i].horaCompra, registroCompras[i + 1].horaCompra);
		registroCompras[i].valor = registroCompras[i + 1].valor;
	}
	(*contCompras)--;
}

int submenuRelatorios() {
	int op;
	printf("\n---------------------------------\n"
			"        SUBMENU RELATÓRIOS"
			"\n---------------------------------\n"
			"1 - Dados por quantidade de telefones\n"
			"2 - Produtos com a data de validade vencida\n"
			"3 - Registro de vendas enttre datas\n"
			"4 - Voltar\n\n"
			"Escolha uma opção: ");
	scanf("%d", &op);
	return op;
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
	int criarData[3];
	

	printf(">>>>>>> Seja bem vinda à LOJA FLORESEREMOS <<<<<<<\n\n");
	
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
									printf("Data de nascimento: %s", registroClientes[encontrou].dataNasc);
									printf("\nSexo: %c", registroClientes[encontrou].sexo);
									printf("\nSalário: R$%.2f", registroClientes[encontrou].salario);
									printf("\nEmail: %s", registroClientes[encontrou].email);
									printf("\nTelefone: %s\n\n", registroClientes[encontrou].telefone);
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
										printf("Exclusao de cliente cancelada.");
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
							printf("\nData de validade: %s\n\n", registroProdutos[encontrou].validade);					
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
								printf("Exclusão do produto cancelada.");
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
							printf("Não há registro com esses dados.");
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
								printf("\nRegistro excluido com sucesso!\n\n");
								
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
						//relatorio sobre os telefones
					} else 
					if (op == 2) 
					{
						//relatorio produtos com a validade vencida
						
						struct dataAtual {
							int dia;
							int mes;
							int ano;
						};
						struct tm tempo;
						time_t tempoSeg;
						time(&tempoSeg);
						tempo = *localtime(&tempoSeg);
						
						struct dataAtual hoje;
						hoje.dia = tempo.tm_mday;
						hoje.mes = tempo.tm_mon + 1;
						hoje.ano = tempo.tm_year + 1900;

					} else
					if (op == 3)
					{
						//relatorio compras entre datas
					}
				}
				break;
			}
		}
	}
	printf("\nSaindo..."); //não mexer aqui pra continuar funcionando
}
