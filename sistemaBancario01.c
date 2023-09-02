#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define tam 900

struct Conta
{
    char tipoConta[tam];
    int numeroConta;
    int agencia;
    float saldo;
};

struct Titular
{
    char nome[tam];
    char cpf[tam];
    char endereco[tam];
    char telefone[tam];
};


struct Conta conta[tam];

struct Titular titular[tam];

int numeroContas, numero1, numero2;
float subtracaoConta;


void menu();

void criarConta();

void consultarConta();

void removerConta();

void creditar();

void debitar();

void renderJuros();

void efetuarTransferencia();

void listarContas();

int main()
{
    menu();

    return 0;
}

void menu()
{
    
    int opcao;

    printf("****************************************************\n");
    printf("--------Bem-vindo ao nosso sistema bancário---------\n");
    printf("-------------Seu money, nossa alegria!--------------\n");
    printf("------Selecione uma alternativa e seja feliz--------\n");
    printf("|                                                   |\n");
    printf("|       Seção de contas e dados                     |\n");
    printf("|                                                   |\n");
    printf("|       1 - Cadastrar conta:                        |\n");
    printf("|       2 - Consultar conta                         |\n");
    printf("|       3 - Remover conta                           |\n");
    printf("|                                                   |\n");
    printf("|       Seção de questões financeiras               |\n");
    printf("|                                                   |\n");
    printf("|       4 - Creditar                                |\n");
    printf("|       5 - Debitar                                 |\n");
    printf("|       6 - Render juros                            |\n");
    printf("|       7 - Efetuar transferência                   |\n");
    printf("|                                                   |\n");
    printf("|       Seção de gestão do sistema                  |\n");
    printf("|                                                   |\n");
    printf("|       8 - Listar contas ativas                    |\n");
    printf("|       9 - Sair do sistema                         |\n");
    printf("*****************************************************\n");

    scanf("%d", &opcao);

    switch(opcao)
    {
        case 1:
            criarConta();
            break;
        case 2:
            consultarConta();
            break;
        case 3:
            removerConta();
            break;
        case 4:
            creditar();
            break;
        case 5:
            debitar();
            break;
        case 6:
            renderJuros();
            break;
        case 7:
            efetuarTransferencia();
            break;
        case 8:
            listarContas();
            break;
        case 9:
            printf("Agradeço sua interação comigo, até logo!");
            exit(EXIT_SUCCESS);

    
        default:
            printf("Opção inexistente.\n");
            break;

    }


}

void criarConta()
{
    printf("Solicitando operação para cadastro de conta no sistema.\n");

    printf("Quantas contas desejas cadastrar?");
    scanf("%d", &numeroContas);

    printf("Por favor, informar dados corretamente...\n");

    for (int i = 0; i < numeroContas; i++)
    {

        getchar();

        printf("Tipo de conta %d: ", i + 1);
        fflush(stdin);
        fgets(conta[i].tipoConta, tam, stdin);

        printf("Nome do titular %d: ", i + 1);
        fflush(stdin);
        fgets(titular[i].nome, tam, stdin);

        printf("Número de cadastro de pessoa física (CPF): ");
        fflush(stdin);
        fgets(titular[i].cpf, tam, stdin);
        
        printf("Endereço do titular: ");
        fflush(stdin);
        fgets(titular[i].endereco, tam, stdin);

        printf("Telefone do titular: ");
        fflush(stdin);
        fgets(titular[i].telefone, tam, stdin);
        

        printf("Número da conta:");
        scanf("%d", &conta[i].numeroConta);

        printf("Número da agência:");
        scanf("%d", &conta[i].agencia);

        printf("Saldo inicial:");
        scanf("%f", &conta[i].saldo);

        printf("Cadastro de conta realizado com sucesso!\n");

        getchar();
    }
       

        
    menu();
}




void consultarConta()
{
    
    if (numeroContas != 0)
    {   
        printf("Faça a busca por meio do número da conta:\n");

        printf("Digite o número da conta que desejas consultar:");
        scanf("%d", &numero1);
        for (int i = 0; i < numeroContas; i++)
        {
            if (numero1 == conta[i].numeroConta)
            {
                printf("Conta encontrada com sucesso.\n");
                printf("Visualização de dados.\n");

                printf("Conta %d:\n", i + 1);
                printf("Tipo de conta: %s\n", conta[i].tipoConta);
                printf("Nome: %s", titular[i].nome);
                printf("CPF: %s", titular[i].cpf);
                printf("Endereço: %s", titular[i].endereco);
                printf("Telefone: %s", titular[i].telefone);
                printf("Número da conta: %d\n", conta[i].numeroConta);
                printf("Número da agência: %d\n", conta[i].agencia);
                printf("Saldo: R$ %.2f\n", conta[i].saldo);
                printf("\n");
                

            }
            else if (i == numeroContas - 1)
            {
                printf("Conta não encontrada.\n");
                
            }
        }
    }
    else
    {
        printf("Nenhuma conta criada ainda.\n");
    }
    menu();
    
}

void removerConta()
{
    int numero, resposta;

    if (numeroContas != 0)
    {
        printf("Digite o número da conta que desejas remover:");
        scanf("%d", &numero);

        int contaEncontrada = -1; 

        for (int i = 0; i < numeroContas; i++)
        {
            if (numero == conta[i].numeroConta)
            {
                printf("Conta encontrada com sucesso.\n");

                if (conta[i].saldo > 0)
                {
                    printf("Sua conta possui um valor, em reais, de R$ %.2f.\n", conta[i].saldo);

                    printf("Avisaremos de antemão que após a remoção da conta sem operação de saque do dinheiro armazenado, não será possível recuperá-lo novamente.\n");
                    printf("Desejas continuar a operação?\n1-Sim\n2-Não\n");
                    scanf("%d", &resposta);

                    if (resposta == 1)
                    {
                        for (int j = i; j < numeroContas - 1; j++)
                        {
                            titular[j] = titular[j + 1];
                            conta[j] = conta[j + 1]; 

                        }
                        numeroContas--; 
                        printf("Conta removida com sucesso.\n");
                    }
                    else if (resposta == 2)
                    {
                        printf("Operação cancelada.\n");
                    }
                    else
                    {
                        printf("Opção inexistente. Operação cancelada.\n");
                    }
                }
                else
                {
                    for (int j = i; j < numeroContas - 1; j++)
                    {
                        titular[j] = titular[j + 1];
                        conta[j] = conta[j + 1]; 
                    }
                    numeroContas--; 
                    printf("Conta removida com sucesso.\n");
                }
                contaEncontrada = i;
                break; 
            }
        }

        if (contaEncontrada == -1)
        {
            printf("Conta não encontrada.\n");
        }
    }
    else
    {
        printf("Nenhuma conta cadastrada ainda.\n");
    }
    menu(); 
}

void creditar()
{

}
void debitar()
{
        
    if (numeroContas != 0)
    {   
        printf("Faça a busca por meio do número da conta:\n");

        printf("Digite o número da conta que desejas consultar:");
        scanf("%d", &numero1);

        for (int i = 0; i < numeroContas; i++)
        {    
            if (numero1 == conta[i].numeroConta)
            {
                printf("Conta encontrada com sucesso.\n");

                printf("Solicitando operação, por favor aguarde\n");

                printf("Selecione a opçao.\n");
                printf("==============================\n");
            }
        }
    }
}
void renderJuros()
{

}
void efetuarTransferencia()
{
    int i, j;
    float quantidade;

    if (numeroContas != 0)
    {
        printf("Realize a operação utilizando o número das contas.\n");

        printf("Digite o número da conta do remetente:");
        scanf("%d", &numero1);

        for (i = 0; i < numeroContas; i++)
        {
            if (numero1 == conta[i].numeroConta)
            {
                printf("Conta encontrada com sucesso.\n");

                printf("Digite o número da conta do destinatário:");
                scanf("%d", &numero2);

                for(j = 0; j < numeroContas; j++)
                {
                    if (numero2 == conta[j].numeroConta)
                    {
                        printf("Conta encontrada com sucesso.\n");
                        printf("Digite, em reais, a quantidade que desejas transferir:");
                        scanf("%f", &quantidade);

                        if (quantidade <= conta[i].saldo)
                        {
                            printf("Por favor, confirme os dados:\n");
                    
                            printf("Dados do remetente:\n");
                            printf("Conta %d:\n", i + 1);
                            printf("Tipo de conta: %s\n", conta[i].tipoConta);
                            printf("Nome: %s", titular[i].nome);
                            printf("CPF: %s", titular[i].cpf);
                            printf("Número da conta: %d\n", conta[i].numeroConta);
                            printf("Número da agência: %d\n", conta[i].agencia);

                            printf("Dados do destinatário:\n");
                            printf("Conta %d:\n", j + 1);
                            printf("Tipo de conta: %s\n", conta[j].tipoConta);
                            printf("Nome: %s", titular[j].nome);
                            printf("CPF: %s", titular[j].cpf);
                            printf("Número da conta: %d\n", conta[j].numeroConta);
                            printf("Número da agência: %d\n", conta[j].agencia);

                            int resposta;

                            printf("Tudo ok?\n1-sim\n2-não\n");
                            scanf("%d", &resposta);

                            if (resposta == 1)
                            {
                                printf("Transferência no valor de R$ %.2f de  %s para %s realizada com sucesso.\n", quantidade, titular[i].nome, titular[j].nome);

                                printf("==================================================================\n");
                                printf("========================Comprovante===============================\n");
                                printf("===================Dados do recebedor=============================\n");
                                printf("            Nome: %s                \n", titular[j].nome);
                                printf("            CPF: %s                 \n", titular[j].cpf);
                                printf("            Número da conta:  %d    \n", conta[j].numeroConta);
                                printf("            Tipo de conta: %s       \n", conta[j].tipoConta);
                                printf("\n\n");

                                printf("======================Dados do pagador===== ======================\n");
                                printf("            Nome: %s                \n", titular[i].nome);
                                printf("            CPF: %s                 \n", titular[i].cpf);
                                printf("            Número da conta: %d     \n", conta[i].numeroConta);
                                printf("            Tipo de conta: %s       \n", conta[i].tipoConta);
                                printf("\n\n");

                                printf("======================Dados da transação==========================\n");
                                printf("           Valor transferido: R$ %.2f\n", quantidade);
                                printf("           ID da transação: %d      \n",  rand() % (500000000 - 100));
                                printf("           Código da operação: %d   \n", rand() % (500000000 - 500));
                                printf("          \nPaís da instituição bancária: Brasil\n");
                                conta[i].saldo -= quantidade;
                                conta[j].saldo += quantidade;
                            }
                            else if (resposta == 2)
                            {
                                printf("Voltando ao início.");
                            }
                            else
                            {
                                printf("Opção inexistente. Voltando ao início...\n");
                            }

                        }
                        else
                        {
                            printf("Não há saldo suficiente para realizar a operação. voltando ao início.\n");

                        }
                    }
                    else if (j == numeroContas - 1)
                    {
                        printf("Conta de destinatário não encontrada.\n");
                    }
                }     
            }
            else if (i == numeroContas - 2)
            {
                printf("Conta de remetente não encontrada.\n");
            }

        }
    }
    else 
    {
        printf("Nenhuma conta cadastrada ainda.\n");
    }
     menu();
    

}
void listarContas()
{

    if (numeroContas != 0)
    { 
        printf("\nInformações das contas criadas:\n");
        for (int i = 0; i < numeroContas; i++)
        {
            printf("Conta %d:\n", i + 1);
            printf("Tipo de conta: %s", conta[i].tipoConta);
            printf("Nome: %s", titular[i].nome);
            printf("CPF: %s", titular[i].cpf);
            printf("Endereço: %s", titular[i].endereco);
            printf("Telefone: %s", titular[i].telefone);
            printf("Número da conta: %d\n", conta[i].numeroConta);
            printf("Número da agência: %d\n", conta[i].agencia);
            printf("Saldo: R$ %.2f\n", conta[i].saldo);
            printf("\n");
        }
    }
    else
    {
       printf("Nenhuma conta criada ainda.\n");
    }
     menu();
}