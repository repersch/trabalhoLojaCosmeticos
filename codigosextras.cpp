	/*for ( int i = 0; i < strlen(data); i++) { //transforma os '.' em '/'
							if (data[i] == '.') {
								data[i] = '/';
							}
						}*/




////////////////////////////////primeira tentativa de manipular datas//////////////////////////////

time_t agora;
						char datahora[100];
						char data[100];
						char diaS[5];
						char mesS[5];
						char anoS[10];
					
						
						agora = time(NULL);
						strftime(datahora, sizeof(datahora), "%d.%m.%Y - %H:%M:%S", localtime(&agora)); // recebe data e hora do sistema
						strncpy(data, datahora, 10); //retira só a data
						//int dataInt = atoi(data);
						//printf("Data inteiro: %d", dataInt);
						//printf("%c", data[4]);
						for (int i = 0; i < strlen(data); i++) {
							if ( i == 0 || i ==1) {
								strcat(*diaS, data[i]);
								//*diaS =  *diaS + data[i];
								printf("\n%s\n", diaS);
							} else 
							if (i == 3 || i == 4) {
								//strcpy(mesS, data[i]);
								*mesS = *mesS + data[i];
							} else 
							if (i >= 6) {
								//strcpy(anoS, data[i]);
								*anoS = *anoS + data[i];
							}
						}
						printf("\nDia: %s", diaS);
						printf("\nMês: %s", mesS);
						printf("\nAno: %s", anoS);
						//strncpy(diaS, data, 2);
						//printf("DIA: %s", diaS); 
						
						
						//////////////////////a segunda tentativa de manipular datas/////////////////////////
						
							tm *data_hora_atual;
						time_t segundos;
						time(&segundos);
						data_hora_atual = localtime(&segundos);
						int diaAtual = data_hora_atual->tm_mday;
						printf("\n%d\n", diaAtual);
						int mesAtual = data_hora_atual->tm_mon + 1;
						printf("\n%d\n", mesAtual);
						int anoAtual = data_hora_atual->tm_year + 1900;
						printf("\n%d\n", anoAtual);
						


///////////////////////////////////PARTES DE CÓDIGO TIRADAS//////////////////////////////////////


void validarDadosCompra(Cliente registroClientes[], Produto registroProdutos[], Compra registroCompras[], DadosUnicos, int contClientes, int contProdutos, int *contCompras) {
	int ok1 = 0;
	int existe = -1;
	char dadosUnicos[4][50];
	while (ok1 == 0) {
		//while (existe == -1) {
		/////////////////////////// primeiro conferir e validar o cpf - salvar em uma variável para conferir no final
			char cpfCliente[12];
			fflush(stdin);
			gets(cpfCliente);
			ok1 = validarCPF(cpfCliente);
			if (ok1 == 1) {
				existe = buscarCliente(registroClientes, cpfCliente, contClientes);
				if (existe != -1) {
					printf("Cliente: ");
					puts(registroClientes[existe].nome);
					//cpfCliente = registroClientes[existe].cpf; 
		////////////////////////// segundo solicitar, conferir e validar o código do produto
					int codProduto; 
					printf("Digite o código do produto: ");
					scanf("%d", &codProduto);
					int encontrou = buscarProduto(registroProdutos, codProduto, contProdutos);
					if (encontrou == -1) {
						printf("\nCódigo não cadastrado.\n");
					} else {
						printf("Produto: ");
						puts(registroProdutos[encontrou].descricao);
		////////////////////////// terceiro solicitar e validar data da compra
						char data[11];
						int ok2 = 0;
						printf("Data da compra: ");
						fflush(stdin);
						while (ok2 == 0) {
							gets(data);
							ok2 = validarData(data);	
							if (ok2 == 1) {
		///////////////////////// quarto solicitar e validar hora da compra
								char hora[6];
								int ok3 = 0;
								printf("Digite a hora da compra(XX:XX): ");
								while (ok3 == 0) {
									gets(hora);
									ok3 = validarHora(hora);
									if (ok3 = 1) {
										DadosUnicos.codigo = cpfCliente;
										DadosUnicos.codigo = codProduto;
										DadosUnicos.dataCompra = data;
										DadosUnicos.horaCompra = hora;
										for (int i = 0; i < *contCompras; i++) {
											if (DadosUnicos == registroCompras[i].dados) {
												registroCompras[*contCompras].dados = DadosUnicos;
											}
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
					printf("Cliente não cadastrado.\n\n");	
				}
			} else {
				printf("CPF inválido! Por favor, digite um CPF válido: ");
			}
		}
		
		
}






///////conferindo se esta funcionando////
						printf("/n/nInformações salvas no vetor Dados: ");
						for (int i =0; i<4; i++) {
							puts(dados[i]);
						}
						
						
						
						
						/////////////////////ptra vez tentando fazer os comandos dos dados de compra///////////////////
						//char dados[4][50];
						int ok = 0, cpfOk = 0;
						char cpf[12];
						char confirme;
						printf("Digite o CPF do cliente (ou digite 0 para voltar ao Menu): ");
						while (ok == 0 && strcmp(cpf, "sair") != 0) {
							fflush(stdin);
							gets(cpf);
						
							int ok = validarCPF(cpf);
							if (ok == 0) {
								printf("CPF inválido! Por favor, digite um CPF válido: ");
							} else {
								for (int i =0; i < contClientes; i++) {
									if (strcmp(registroClientes[i].cpf, cpf) == 0) {	
										printf("Cliente: "); 
										puts(registroClientes[i].nome);
										printf("Confirmar (S/N)? ");
										scanf("%c", &confirme);
										if (confirme == 's' || confirme == 'S') {
											//strcpy(dados[0], cpf);
											cpfOk = 1;
										} else {
											printf("Digite outro CPF (ou digite sair para voltar ao Menu): ");	
											
							}
										}
									} 
								}
								printf("CPF não cadastrado! Por favor, digite o CPF (ou digite sair para voltar ao Menu): ");
								}
							
						} 
						//proximo comando
						
						
						
						
						
						
						
						
						
						
						
						
//////////////////////////////////mais outra tentativa////////////////////////////////////////////////////////////////////////////

char cpf[12];
						int codigo;
						int ok = 0;
						char confirma;
						int cpfOk = 0;
						printf("\n\n--- Cadastrar compra ---\n\n");
						printf("CPF do cliente: ");
						while (cpfOk == 0){
							while (ok == 0) {
								gets(cpf);
								ok = validarCPF(cpf);
								if (ok == 0) {
									printf("CPF inválido! Por favor, digite um CPF válido: ");
								} else {
									for (int i = 0; i < contClientes; i++) {
										if (strcmp(registroClientes[i].cpf, cpf) == 0) {
											printf("Nome: ");
											puts(registroClientes[i].nome);
											printf("Confirmar (S/N)? ");
											scanf("%c", &confirma);
											if (confirma == 's'|| confirma == 'S') {
												cpfOk = 1;
												////////////////////////////////////////////////cpf confirmado, cliente validado//
												printf("\nCódigo do produto: ");
												scanf("%d", codigo);fflush(stdin);
												for (int i = 0; i < contProdutos; i++) {
													if (registroProdutos[i].codigo == codigo) {
														printf("Produto: "); 
														puts(registroProdutos[i].descricao);
														
													}
												}
												printf("Produto não cadastrado.");
											}
										}
									}
								
								
								
								}cpfOk = 1;
							}printf("CPF não cadastrado.");	//se chegar aqui sai da opção
						}						
					}					
					
					
					
					
					
						gets(cpf);
						for (int i = 0; i < contClientes; i++) {
							if (strcmp(registroClientes[i].cpf, cpf) == 0){
								printf("Nome: ");
								puts(registroClientes[i].nome);
								
								printf("\nCódigo do produto:");
								scanf("%d", &codigo);
								fflush(stdin);
								for (int i = 0; i < contProdutos; i++) {
									if (registroProdutos[i].codigo == codigo) {
										printf("Produto: ");
										puts(registroProdutos[i].descricao);
										char cod = (char) codigo;
										printf("\nData da compra: ");
										gets(data);
										printf("Hora da compra: ");
										gets(hora);
									
										
										//////conferindo se esta funcionando////
										printf("/n/nInformações salvas no vetor Dados: ");
										for (int i =0; i<4; i++) {
											puts(dados[i]);
										}
									}
								}
							}
						}
						printf("Cadastro não concluido.");
					}
