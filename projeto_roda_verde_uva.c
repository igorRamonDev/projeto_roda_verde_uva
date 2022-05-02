#include <stdio.h>

#include <stdlib.h>

#include <string.h>

struct Produtos

{

  int codigo, qtdEst, qtdMinEst;

  char nome[30];

  float valor;

};

struct Carrinho

{

  char nomeCliente[50];

  int codProduto, qtdDesejada;

  float valTotal;

};

int main()

{

  struct Produtos cadProduto[5];

  struct Carrinho pedido[5];

  int i, login, cep, celular, cpf, opcao, pesqProd, achei = 0, posicao, compra, codDesejo, posicaoC, acheiC = 0, qtdCompra, pagamento;

  int qtdItens = 1, resp = 1, ncartao, seguranca;

  float valorPagar = 0, vencimento;

  char nome[30], cliente[12], sobrenome[12], endereco[30], email[34], conf[3], conf2[10];

  printf("========================\nRODA VERDE COMPOSTAGEM\n=========================");

  printf("\n[1]-Loja \n[2]-Cliente \nEscolha a opçao desejada..:");

  scanf("%d", & login);

  switch (login)

  {

  case 1:

  {

    for (i = 0; i < 3; i++)

    {

      printf("\n\n******************************\nSISTEMA RODA VERDE COMPOSTAGEM\n******************************");

      printf("\nDigite o nome do produto..:");

      scanf("%s", & cadProduto[i].nome);

      printf("Digite o codigo do produto..: ");

      scanf("%d", & cadProduto[i].codigo);

      printf("Digite o valor do produto..:R$ ");

      scanf("%f", & cadProduto[i].valor);

      printf("Digite a quantidade em Estoque..: ");

      scanf("%d", & cadProduto[i].qtdEst);

      printf("\n--------------------------------------------------\n");

    }

    printf("\n\n--------------------PRODUTOS---------------------\n");

    for (i = 0; i < 3; i++)

    {

      printf("Nome do produto..: %s", cadProduto[i].nome);

      printf("\nCodigo do Produto..: %d", cadProduto[i].codigo);

      printf("\nQuantidade em Estoque..: %d", cadProduto[i].qtdEst);

      printf("\nValor do Produto..: %.2f", cadProduto[i].valor);

      printf("\n-----------------------------------------------------------------\n");

    }

    printf("\n\n------------------------SISTEMA RODA VERDE-----------------------\n");

    printf("\nNome\tCodigo\tValor\tEstoque\n");

    for (i = 0; i < 3; i++)

    {

      printf("%s\t%d\t%.2f\t%d\n", cadProduto[i].nome, cadProduto[i].codigo, cadProduto[i].valor,

        cadProduto[i].qtdEst);

    }

    printf("\n----------------------------------------------------------------\n");

  }

  case 2:

  {

    printf("\nSeja bem vindo a Roda Verde Compostagem.\nVamos começar fazendo o seu cadastro.\n\nPrimeiramente gostariamos de saber seu nome..:");

    scanf("%s", & cliente);

    printf("Olá %s, por favor digite seu sobrenome..:", cliente);

    scanf("%s", & sobrenome);

    printf("Ok, Sr(a) %s %s, por onde voce conheceu a Roda Verde?..:", cliente, sobrenome);

    scanf("%s", & conf2);

    printf("Hmm, que legal! Agora nos informe seu CPF..:");

    scanf("%d", & cpf);

    printf("Digite seu CEP..:");

    scanf("%d", & cep);

    printf("Digite seu endereço..:");

    scanf("%s", & endereco);

    printf("Digite seu email..:");

    scanf("%s", & email);

    printf("Voce gostaria de receber novidades e promoçoes por email?..:");

    scanf("%s", & conf);

    printf("Digite seu celular..:");

    scanf("%d", & celular);

    printf("Ok, seu cadastro foi finalizado e registrado no sistema.");

    printf("\n**********************\nRODA VERDE COMPOSTAGEM\n**********************\n1- Adicionar Produtos no carrinho\n5- Sair\nEscolha uma opçao..:");

    scanf("%d", & opcao);

    switch (opcao)

    {

    case 1:

      printf("\n\n Seja bem vindo, esses sao nossos produtos..");

      printf("\n\n--------------------PRODUTOS---------------------\n");

      for (i = 0; i < 3; i++)

      {

        printf("Nome do produto..: %s", cadProduto[i].nome);

        printf("\nCodigo do Produto..: %d", cadProduto[i].codigo);

        printf("\nQuantidade em Estoque..: %d", cadProduto[i].qtdEst);

        printf("\nQuantidade minima em Estoque..: %d", cadProduto[i].qtdMinEst);

        printf("\nValor do Produto..: %.2f", cadProduto[i].valor);

        printf("\n-----------------------------------------------------------------\n");

      }

      while (resp == 1 && qtdItens <= 5)

      {

        printf("\nItem..:%d\n", qtdItens);

        printf("Informe o codigo do produto que o Sr(a) deseja..:");

        scanf("%d", & codDesejo);

        for (i = 0; i < 3; i++)

        {

          if (cadProduto[i].codigo == codDesejo)

          {

            posicaoC = i;

            acheiC = 1;

            break;

          }

        }

        if (acheiC == 1)

        {

          printf("\nQuantidade desejada..:");

          scanf("%d", & qtdCompra);

          if (cadProduto[posicaoC].qtdEst < qtdCompra)

          {

            printf("\nDesculpe - Nao temos a quantidade desejada em estoque.");

          } else

          {

            pedido[qtdItens - 1].codProduto = codDesejo;

            pedido[qtdItens - 1].qtdDesejada = qtdCompra;

            pedido[qtdItens - 1].valTotal = qtdCompra * cadProduto[posicaoC].valor;

            cadProduto[posicaoC].qtdEst = cadProduto[posicaoC].qtdEst - qtdCompra;

            printf("Produto adicionado ao carrinho\n");

            qtdItens++;

            acheiC = 0;

          }

        } else

        {

          printf("\nProduto nao disponivel");

        }

        if (qtdItens == 6)

        {

          printf("Voce ja adicionou o maximo de produtos permitidos em seu carrinho");

          break;

        } else

        {

          printf("\nDeseja adicionar mais um item no carrinho? 1- Sim 2- Nao..:");

          scanf("%d", & resp);

        }

      }

      if (qtdItens <= 6)

      {

        printf("\n------------------------FINALIZANDO PEDIDO----------------------\n");

        printf("\nCodigo\tQuantidade\tR$ Total\n");

        for (i = 0; i < qtdItens - 1; i++)

        {

          valorPagar = valorPagar + pedido[i].valTotal;

          printf("%d\t%d\t\t%.2f\n", pedido[i].codProduto, pedido[i].qtdDesejada, pedido[i].valTotal);

        }

        printf("\nValor final da compra..: R$%.2f", valorPagar);

        printf("\nComo desejar efetuar o pagamento?\n1- Pix\n2- Boleto\n3- Cartao de Crédito..:");

        scanf("%d", & pagamento);

        if (pagamento = 1)

        {

          printf("Chave aleatória para pagamento por pix: f217c621-df3e-41bc-b02341\nEmail: rodaverdecompostagem@gmail.com");

          printf("\nPagamento aprovado! Voce receberá maiores informacoes em seu email");

          printf("A Roda Verde Compostagem e o Mundo agradeçe sua compra\nPreserve o meio ambiente");

        } else if (pagamento = 2)

        {

          printf("Codigo de barras para pagamento por boleto: 34191.79001 01043.510047 91020.150008 4 86650026000\n");

          printf("O pagamento por boleto pode demorar até 3 dias utéis, assim que recebermos seu pagamento voce receberá maiores informacoes em seu email");

          printf("A Roda Verde Compostagem e o Mundo agradeçe sua compra\nPreserve o meio ambiente");

        } else

        {

          printf("Digite o numero do cartao..:");

          scanf("%d", & ncartao);

          printf("Digite agora a data de vencimento (MM/YY)..:");

          scanf("%f", & vencimento);

          printf("Digite agora o cod de segurança");

          scanf("%d", & seguranca);

          printf("Pagamento aprovado! Voce receberá maiores informacoes em seu email");

          printf("A Roda Verde Compostagem e o Mundo agradeçe sua compra\nPreserve o meio ambiente");

        }

        printf("\n-----------------------------------------------\n");

      } else

      {

      }

      return 0;

    }

  }

  }

}