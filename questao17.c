/*Faça um programa que gerencie o estoque de um mercado e:
Crie e leia um vetor de 5 produtos, com os dados: código (inteiro), nome (máximo 15 letras), preço e quantidade.
Leia um pedido, composto por um código de produto e a quantidade. Localize este código no vetor e, se houver
quantidade suficiente para atender ao pedido integralmente, atualize o estoque e informe o usuário. Repita este 
processo até ler um código igual a zero. Se por algum motivo não for possível atender ao pedido, mostre uma
mensagem informamando qual erro ocorreu.*/

  #include <stdio.h>
  #include <string.h>

  #define tamanho 900

  int i;

  struct Produto
  {
    char nome[tamanho];
    int codigo;
    int quantidade;
    float preco;
  };
  struct Pedido
  {
    int cod;
    int quanti;
    float subtotal;
  };

  void registraProdutos()
  {
    #define tam 5
    struct Produto produto[tam];

    for (i = 0; i < tam; i++)
    {
        printf("Digite o nome do %dº produto:", i + 1);
        fflush(stdin);
        fgets(produto[i].nome, tamanho, stdin);

        printf("Digite o código desse produto:");
        scanf("%d", &produto[i].codigo);

        printf("Digite a quantidade desse produto em estoque:");
        scanf("%d", &produto[i].quantidade);

        printf("Digite o preço desse produto:");
        scanf("%f", &produto[i].preco);
    }

  }
  void fazPedido()
  {
    #define tm 5
    struct Produto produto[tm];

    int numero;
    float soma = 0.0;

    printf("Realize seus pedidos:\n");

    printf("Quantos desejas comprar?\n");
    scanf("%d", &numero);

    struct Pedido pedido[numero];

    for ( i = 0; i < numero; i++)
    {
      if(strlen(produto[0].nome) == 0){
        printf("Não há produtos cadastrados\n");
        return 0;
      }
      printf("| %d | - %s", produto[i].codigo+1,produto[i].nome);
    }

  
    printf("Faça suas escolhas baseando-se nos códigos dos produtos.\n");

    for (i = 0; i < numero; i++)
    {
      printf("Código do produto:\n");
      scanf("%d", &pedido[i].cod);

      printf("Quantidade que desejas:\n");
      scanf("%d", &pedido[i].quanti);

      while (1)
      {
        if (produto[pedido[i].cod - 1].quantidade - pedido[i].quanti > 0)
        {
          pedido[i].subtotal = produto[i].preco*pedido[i].quanti;
          printf("Executando próximo pedido...\n");
          break;
        }
        else
        {
          printf("Quantidade insuficiente em estoque.\n");
          printf("Quantidade disponível:", produto[pedido[i].cod-1].quantidade);
        }
      }
    }
    printf("Nota fiscal...\n");
  
    for (i = 0; i < numero; i++)
    {
      printf("descrição: %s\ncódigo: %d\npreço :R$ %.2f\n%d quantidade: %d\nsubtotal: R$ %.2f\n", produto[i].nome, produto[i].codigo, pedido[i].quanti, pedido[i].subtotal);

      soma += pedido[i].subtotal;
    }
    printf("Total: R$ %.2f.", soma);

  }
  
int main()
  {
    int verdade = 1, escolha;

    while (verdade == 1)
    {
      printf("Bem-vindo ao mercantil!\n");
      printf("Menu\n");
      printf("1 - cadastrar produtos.\n");
      printf("2 - Fazer pedidos.\n");
      printf("3 - Encerrar programa.\n");

      scanf("%d", &escolha);

      switch (escolha)
      {
        case 1:
        registraProdutos();
        break;

        case 2:
        fazPedido();
        break;

        case 3:
        escolha = 2;
        break;

        default:
        break;
      }
    }
    return 0;
  }