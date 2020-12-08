Tema 14: Loja de Cosm�ticos

Uma aplica��o para controlar a compra/venda de produtos de uma loja de cosm�ticos precisar armazenar 
informa��es sobre os seus clientes, produtos e sobre cada compra/venda realizada por um cliente. 
Os dados a serem armazenados sobre cada uma dessas entidades s�o apresentados a seguir: 

Cliente = (CPF, Nome, Data de Nascimento, Sexo, Sal�rio, E-mails, Telefones) 
Produto = (C�digo, Descri��o, quantidade em ml, Pre�o, Desconto, Data de Validade) 
Compra/Venda = (CPF Cliente, C�digo Produto, Data, Hora, Valor) 

Aten��o: os atributos grifados s�o chaves e voc� N�O deve permitir a inclus�o de mais de um cadastro com os mesmos valores para os atributos chaves. 
Utilizando os conhecimentos aprendidos sobre Vetores, Strings, Registros e Fun��es 
desenvolva um programa em C que apresente o seguinte menu de op��es para o usu�rio e implemente 
cada opera��o usando fun��o. Escolha a estrutura de dados mais apropriada para armazenar os dados de cada entidade descrita anteriormente. 

Menu de Op��es: 
1) Submenu de Clientes
2) Submenu de Produtos 
3) Submenu de Compra/Vendas 
4) Submenu Relat�rios
5) Sair 

Cada Submenu dever� oferecer as op��es: 

Listar todos, 
Listar um elemento espec�fico do conjunto, 
Incluir (sem repeti��o), 
Alterar e 
Excluir (ap�s confirma��o dos dados) um elemento do conjunto.
 
O Submenu Relat�rios dever� ter uma op��o para cada um dos relat�rios solicitados a seguir. Relat�rios: 
a) Mostrar todos os dados de todos os clientes que possuem mais do que X telefones, onde X deve ser fornecido pelo usu�rio; 
b) Mostrar todos os dados de todos os produtos que j� tiveram sua data de validade expirada, considerando a data do sistema no momento da execu��o;
c) Mostrar o CPF do cliente, nome do cliente, c�digo do produto, descri��o e os demais dados das vendas que foram realizadas entre as datas X e Y, 
onde ambas as datas devem ser fornecidas pelo usu�rio. 

Obs: N�o utilize vari�veis globais. Use par�metros para fazer a transfer�ncia de valores entre as fun��es. D� nomes significativos para vari�veis e fun��es.

