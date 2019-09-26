#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {ABERTO, FECHADO} tSituacao;
typedef enum{AGUA, LUZ, INTERNET, EDUCACAO, TRANSPORTE, ALIMENTO, LAZER, OUTROS} tDespesa;

//Estrutura que armazenará os dados orçamentais do ultimo mês adicionado
typedef struct {

    char nomeMes[31];           //Nome do mês
    float receita;
    float despesas[8];          //Array com as diferentes despesas, será acessado com o enum
    tSituacao situ;             /*Se situ for igual a ABERTO afirma que o mês está
                                com orçamento aberto e se for igual a FECHADO é o contrário*/

} tOrcamentoMensal;

//Função que estrutura um menu de opções que está a dispor do usuário
void ExibeMenu(){
    printf("\n\n\t\t________________________Gerencia Financeira ____________________\n"
            "\t\t|\t\t\t\t\t\t\t\t|\n"
            "\t\t|\t\t\t1 - Status\t\t\t\t|\n"                  //Mirele
            "\t\t|\t\t\t2 - Adicionar Receita\t\t\t|\n"         //Louise
            "\t\t|\t\t\t3 - Adicionar Despesa\t\t\t|\n"         //Louise
            "\t\t|\t\t\t4 - Adicionar Novo Orcamento\t\t\t|\n"  //Joao :3
            "\t\t|\t\t\t5 - Fechar Orcamento \t\t\t|\n"         //Joao
            "\t\t|\t\t\t6 - Historico \t\t\t\t|\n"              //Milere
            "\t\t|\t\t\t7 - Atualizar Despesa \t\t\t\t|\n"
            "\t\t|\t\t\t8 - Fechar \t\t\t\t|\n"
            "\t\t|\t\t\t\t\t\t\t\t|\n"
            "\t\t-----------------------------------------------------------------\n\n");
}

//Função que estrutura um menu de opções para gerencia de despesas do usuário
void MenuDespesa(){
     printf("\n\n\t\t________________________Gerencia Financeira ____________________\n"
            "\t\t|\t\t\t\t\t\t\t\t|\n"
            "\t\t|\t\t\t1 - Agua\t\t\t\t|\n"
            "\t\t|\t\t\t2 - Luz\t\t\t|\n"
            "\t\t|\t\t\t3 - Internet\t\t\t|\n"
            "\t\t|\t\t\t4 - Educacao\t\t\t|\n"
            "\t\t|\t\t\t5 - Transporte \t\t\t|\n"
            "\t\t|\t\t\t6 - Alimentacao \t\t\t\t|\n"
            "\t\t|\t\t\t7 - Lazer \t\t\t\t|\n"
            "\t\t|\t\t\t8 - Outros \t\t\t\t|\n"
            "\t\t|\t\t\t9 - Voltar para menu principal \t\t\t\t|\n"
            "\t\t|\t\t\t\t\t\t\t\t|\n"
            "\t\t-----------------------------------------------------------------\n\n");
}



//Função pra criar o novo orcamento com os valores zerados
void ZeraArray(float ar[], int t){
    int i;
    for(i=0; i<t; i++){
        ar[i]=0;
    }
}

int main(void){

    FILE *financasMensais;
    tOrcamentoMensal orcamentoMensal;
    int op, i, opDespesa;
    /*
        Aqui podemos abrir o arquivo que contém todos os dados de todos os meses,
        selecionando a ultima estrutura salva e armazenando-a em --> orcamentoMensal
        caso seu atributo situ for igual a ABERTO, caso seja FECHADO deve ser pedido ao usuário
        para adicionar um novo orçamento. MILEEEEEEERE
    */



    while(1){

        ExibeMenu();
        printf("\t >>> Digite uma opcao: ");
        scanf("%d", &op);
        fflush(stdin);

        if (op == 8)
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
                /*Opção 2 --->  Adicionar receita vai somar o valor dado pelo usuário ao atributo receita
                                estrutura, quando esse valor for adicionado ao anterior, deve-se abrir
                                novamente o arquivo e alterar a ultima estrutura.
                */
                break;


            case 3:



                /*Opção 3 --->  Adicionar dispesas, deve-se da um menu para opções de despesas, 1 - 5, e de
                                acordo com a opção, o valor que o usuário digitar vai ser salvo na ultima
                                possição do vetor referente aquela despesa, quando esse valor for
                                adicionado, deve-se abrir novamente o arquivo e alterar a ultima estrutura.
                */
                break;


            case 4:

                /*Opção 4 --->  Adicionar novo, vai chamar uma função que receba novos valores para a estrutura
                                e depois escrever essa estrutura como a ultima salva.
                */
                if(orcamentoMensal.situ == ABERTO){
                    puts("\t >>> Voce ainda possui um orcamento aberto, por favor feche-o antes de criar um novo");
                    break;
                }
                financasMensais = fopen("Financas.dat", "ab");
                if(financasMensais == NULL){
                    puts("\t >>> Nao foi possivel abrir o arquivo");
                    return 1;
                }
                printf("\t >>> Digite o nome do mes: ");
                fgets(orcamentoMensal.nomeMes, 31, stdin);
                fflush(stdin);
                orcamentoMensal.receita = 0;
                ZeraArray(orcamentoMensal.despesas, 8);
                orcamentoMensal.situ = ABERTO;

                fwrite(&orcamentoMensal, sizeof(tOrcamentoMensal), 1, financasMensais);

                fclose(financasMensais);
                puts("\t >>> Orcamento aberto com sucesso");
                break;


            case 5:

                /*Opção 5 --->  vai mudar o atributo situ para FECHADO, abrir o arquivo e alterar
                                a ultima estrutura salva.
                */

                break;


            case 6:

                /*Opção 6 --->  lista todas as estruturas do arquivo com seus atributos.
                */

                break;

            case 7:
                MenuDespesa();
                financasMensais = fopen("Financas.dat", "r+b");

                    if(financasMensais == NULL){
                        puts("\t >>> Nao foi possivel abrir o arquivo");
                        return 1;
                    }else{
                        fread(&orcamentoMensal, sizeof(tOrcamentoMensal), 1, financasMensais);
                        printf("Digite a despesa que sera adicionada: \n");
                        scanf("%d", &opDespesa);

                        if (opDespesa == 9)
                            break;

                        switch(opDespesa){
                            case 1:
                                puts("Agua:");
                                scanf("%f", &orcamentoMensal.despesas[AGUA]);
                                break;

                            case 2:
                                puts("Luz:");
                                scanf("%f", &orcamentoMensal.despesas[LUZ]);
                                break;

                            case 3:
                                puts("Internet:");
                                scanf("%f", &orcamentoMensal.despesas[INTERNET]);
                                break;

                            case 4:
                                puts("Educacao:");
                                scanf("%f", &orcamentoMensal.despesas[EDUCACAO]);
                                break;

                            case 5:
                                puts("Transporte:");
                                scanf("%f", &orcamentoMensal.despesas[TRANSPORTE]);
                                break;

                            case 6:
                                puts("Alimento:");
                                scanf("%f", &orcamentoMensal.despesas[ALIMENTO]);
                                break;

                            case 7:
                                puts("Lazer:");
                                scanf("%f", &orcamentoMensal.despesas[LAZER]);
                                break;

                            case 8:
                                puts("Outros:");
                                scanf("%f", &orcamentoMensal.despesas[OUTROS]);
                                 break;

                            default:
                                puts("Opcao invalida");
                                break;
                        }
                    }
                fseek(financasMensais, -sizeof(tOrcamentoMensal), SEEK_CUR);
                fwrite(&orcamentoMensal, sizeof(tOrcamentoMensal), 1, financasMensais);
                fclose(financasMensais);
                break;

            default:
                puts("Opcao invalida");
        }
    }

    financasMensais = fopen("Financas.dat", "r");
    fread(&orcamentoMensal, sizeof(tOrcamentoMensal), 1, financasMensais);
    printf("Agua: %.2f\n", orcamentoMensal.despesas[AGUA]);
    printf("Luz: %.2f\n", orcamentoMensal.despesas[LUZ]);


    puts("\t >>> Programa Fechado");

    return 0;
}
