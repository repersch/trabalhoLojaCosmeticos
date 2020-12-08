Tema 14: Loja de Cosméticos

Uma aplicação para controlar a compra/venda de produtos de uma loja de cosméticos precisar armazenar 
informações sobre os seus clientes, produtos e sobre cada compra/venda realizada por um cliente. 
Os dados a serem armazenados sobre cada uma dessas entidades são apresentados a seguir: 

Cliente = (CPF, Nome, Data de Nascimento, Sexo, Salário, E-mails, Telefones) 
Produto = (Código, Descrição, quantidade em ml, Preço, Desconto, Data de Validade) 
Compra/Venda = (CPF Cliente, Código Produto, Data, Hora, Valor) 

Atenção: os atributos grifados são chaves e você NÃO deve permitir a inclusão de mais de um cadastro com os mesmos valores para os atributos chaves. 
Utilizando os conhecimentos aprendidos sobre Vetores, Strings, Registros e Funções 
desenvolva um programa em C que apresente o seguinte menu de opções para o usuário e implemente 
cada operação usando função. Escolha a estrutura de dados mais apropriada para armazenar os dados de cada entidade descrita anteriormente. 

Menu de Opções: 
1) Submenu de Clientes
2) Submenu de Produtos 
3) Submenu de Compra/Vendas 
4) Submenu Relatórios
5) Sair 

Cada Submenu deverá oferecer as opções: 

Listar todos, 
Listar um elemento específico do conjunto, 
Incluir (sem repetição), 
Alterar e 
Excluir (após confirmação dos dados) um elemento do conjunto.
 
O Submenu Relatórios deverá ter uma opção para cada um dos relatórios solicitados a seguir. Relatórios: 
a) Mostrar todos os dados de todos os clientes que possuem mais do que X telefones, onde X deve ser fornecido pelo usuário; 
b) Mostrar todos os dados de todos os produtos que já tiveram sua data de validade expirada, considerando a data do sistema no momento da execução;
c) Mostrar o CPF do cliente, nome do cliente, código do produto, descrição e os demais dados das vendas que foram realizadas entre as datas X e Y, 
onde ambas as datas devem ser fornecidas pelo usuário. 

Obs: Não utilize variáveis globais. Use parâmetros para fazer a transferência de valores entre as funções. Dê nomes significativos para variáveis e funções.

