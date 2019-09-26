#include <stdio.h>
#include <string.h>

//Estrutura que armazenará os dados orçamentais do ultimo mês adicionado
typedef struct {

    char nomeMes[31];           //Nome do mês
    float receita;              //Receita total programada para os gastos do mês
    float despesasNegoci[31];   //Array de despesas em negócios
    float despesasTransp[31];   //Array de despesas em transporte
    float despesasAlimen[31];   //Array de despesas em alimentação
    float despesasLazer[31];    //Array de despesas em lazer
    float despesasOutros[31];   //Array de despesas em outras coisas
    int situ;                   /*Se situ for igual a 0 afirma que o mês está
                                com orçamento aberto e se for igual a 1 é o contrário*/

} tOrcamentoMensal;

//Função que estrutura um menu de opções que está a dispor do usuário
void ExibeMenu(){
    printf("\n\n\t\t________________________Gerencia Financeira ____________________\n"
            "\t\t|\t\t\t\t\t\t\t\t|\n"
            "\t\t|\t\t\t1 - Status\t\t\t\t|\n"
            "\t\t|\t\t\t2 - Adicionar Receita\t\t\t|\n"
            "\t\t|\t\t\t3 - Adicionar Despesa\t\t\t|\n"
            "\t\t|\t\t\t4 - Adicionar Novo \t\t\t|\n"
            "\t\t|\t\t\t5 - Fechar Orcamento \t\t\t|\n"
            "\t\t|\t\t\t6 - Historico \t\t\t\t|\n"
            "\t\t|\t\t\t7 - Fechar \t\t\t\t|\n"
            "\t\t|\t\t\t\t\t\t\t\t|\n"
            "\t\t-----------------------------------------------------------------\n\n");
}

int main(void){

    FILE *finananciasMensais;
    tOrcamentoMensal orcamentoMensal;
    int op, i;

    /*

        Aqui podemos abrir o arquivo que contém todos os dados de todos os meses,
        selecionando a ultima estrutura salva e armazenando-a em --> orcamentoMensal
        caso seu atributi sito for igual a 0, caso seja 1 deve ser pedido ao usuário
        para adicionar um novo orçamento.

    */



    while(1){

        ExibeMenu();
        printf("\t >>> Digite uma opcao: ");
        scanf("%d", &op);

        if (op == 7)
            break;

        switch(op){

            case 1:

                /*Opção 1 --->  Printará o atributo receita da estrutura juntamente com o valor das despesas
                                em cada tipo deterindado,depois mostrará o valor total de despesas(soma de todos
                                os atributos - pode haver uma função que calcula esse valor total e o retorna),
                                posteriormente chamará a função que mostra status, essa receberá como parámetro
                                o endereço da estrutura orcamentoMensal(armazenada em um pontero do mesmo tipo),
                                anteriormente iniciada, e retornará um valor float que armazena o valor da
                                diferença entre :"ptrOrcamentoMensal->receita" e a soma dos atributos despesas
                                (valor retornado da função que podemos fazer), valor esse deve ser printado para
                                o usuário saber o quanto ele ainda pode gastar.
                */
                break;


            case 2:
                printf("Mirele é chata")
                /*Opção 2 --->  Adicionar receita vai somar o valor dado pelo usuário ao atributo receita
                                estrutura, quando esse valor for adicionado ao anterior, deve-se abrir
                                novamente o arquivo e alterar a ultima estrutura.
                */
                break;


            case 3:

                /*Opção 3 --->  Adicionar dispesas, deve-se da um menu para opções de dispesas, 1 - 5, e de
                                acordo com a pção, o valor que o usuário digitar vai ser salvo na ultima
                                possição do vetor referente aquela despesa, quando esse valor for
                                adicionado, deve-se abrir novamente o arquivo e alterar a ultima estrutura.
                */
                break;


            case 4:

                /*Opção 4 --->  Adicionar novo, vai chamar uma função que receba novos valores para a estrutura
                                e depois escrever essa estrutura como a ultima salva.
                */
                break;


            case 5:

                /*Opção 4 --->  Adicionar novo, vai mudar o atributo situ para 1, abrir o arquivo e alterar
                                a ultima estrutura salva.
                */

                break;


            case 6:

                /*Opção 4 --->  lista todas as estruturas do arquivo com seus atributos.
                */

                break;

            default:
                puts("Opcao invalida");
        }
    }

    puts("\t >>> Programa Fechado");

    return 0;
}
