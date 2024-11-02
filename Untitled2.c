#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

// Estruturas de Dados
typedef struct {
    char data[11];
    char horario[6];
    char tipoIngresso[10];
    char nome[100];
} Ingressos;


// Matriz de agendamentos: 7 dias x 8 horarios por dia (8h as 16h30, com intervalo de 1h30)
int agendamentos[7][8] = {0};


void limparTela() {
    system("cls");
}

void mostrarBoasVindas() {
    limparTela();
    printf("Bem-vindo ao nosso sistema de agendamento de museus!\n");
    printf("----------------------------------------------------\n\n");

    printf("Pressione Enter para continuar...");
    getchar();
}

void listarMuseus() {
    limparTela();
    printf("Escolha um dos museus abaixo:\n");
    printf("1. Arte Moderna - Exposicao de arte contemporanea.\n");
    printf("2. 150 Santos Dumont - Homenagem a Santos Dumont e sua contribuicao a aviacao.\n");
    printf("3. Jogos Olimpicos de Paris 2024 - Uma visao antecipada dos Jogos Olimpicos de 2024.\n");
    printf("4. Museu de Paleontologia 'Prof. Antonio Celso de Arruda Campos'\n");
    printf("5. ATTD 2024 - Mostra de tecnologia avancada.\n\n");
    printf("Digite o n mero correspondente ao museu ou 0 para sair: ");
}

void displayArteModernaInfo() {
    printf("Arte Moderna - Historia e Principais Caracteristicas:\n");
    printf("A Arte Moderna e um movimento artistico que surgiu na Europa no final do seculo XIX e se estendeu ate meados do seculo XX, abrangendo areas como arquitetura, escultura, literatura e pintura.\n");
    printf("Principais Caracteristicas da Arte Moderna:\n");
    printf("1. Rompimento com os padroes vigentes.\n");
    printf("2. Reflete o momento historico de grandes avancos tecnologicos, incluindo a Revolucao Industrial e as Guerras Mundiais.\n");
    printf("3. Arte contestadora, refletindo as incertezas da contemporaneidade.\n");
    printf("4. Rejeicao ao academicismo.\n");
    printf("5. Informalidade e liberdade de expressao.\n");
    printf("6. Uso arbitrario das cores.\n");
    printf("Principais Artistas do Modernismo:\n");
    printf("Na Europa: Wassily Kandinsky, Pablo Picasso, Georges Braque, entre outros.\n");
    printf("No Brasil: Mario de Andrade, Tarsila do Amaral, Anita Malfatti, entre outros.\n");
    printf("Principais Movimentos da Arte Moderna:\n");
    printf("1. Expressionismo: Foco nas emocoes e ang stias.\n");
    printf("2. Fauvismo: Uso de cores puras e formas simplificadas.\n");
    printf("3. Cubismo: Geometrizacao das formas e representacao de objetos em todos os  ngulos.\n");
    printf("4. Abstracionismo: Aus ncia de relacao direta com formas realistas.\n");
    printf("5. Futurismo: Valorizacao do industrialismo, aceleracao e tecnologia.\n");
    printf("6. Surrealismo e Dadaismo: Fantasia, loucura e impulso dos artistas.\n");
    printf("7. Concretismo: Criacao de novas linguagens com formas geometricas.\n");
    printf("A Arte Moderna teve um impacto significativo nas artes e na cultura em todo o mundo, desafiando convencoes e promovendo a inovacao artistica.\n");
}

void displaySantosDumontInfo() {
    printf("Comemoracao dos 150 anos de nascimento de Alberto Santos Dumont:\n");
    printf("1. Celebracoes em sua cidade natal, Santos Dumont, incluindo um museu dedicado a ele, o Museu de Cabangu.\n");
    printf("2. O inventor fez o primeiro voo oficial de uma aeronave mais pesada que o ar em 1906, em Paris, com o 14 Bis.\n");
    printf("3. O 14 Bis original foi construido com materiais como madeira, bambu, seda e um motor.\n");
    printf("4. Restauracao da replica do 14 Bis em Juiz de Fora, Minas Gerais, realizada pelo Senai.\n");
    printf("5. Entrega da medalha Santos Dumont a homenageados em Minas Gerais.\n");
    printf("6. Exposicoes e homenagens em varias cidades do Brasil, incluindo Sao Paulo e Brasilia.\n");
    printf("7. Evento com a presenca do presidente e vice-presidente do Brasil, Lula e Geraldo Alckmin.\n");
    printf("8. Esquadrilha da Fumaca escreveu no ceu de Brasilia: 'Santos Dumont 150 anos' em homenagem ao aniversario do inventor.\n");
}

void displayJogosOlimpicosInfo() {
    printf("Jogos Olimpicos de Paris 2024 - Informacoes Principais:\n");
    printf("1. Localizacao e Historia: Os Jogos Olimpicos de 2024 serao realizados na cidade de Paris, Franca, marcando a terceira vez que a cidade sediara os Jogos (anteriormente em 1900 e 1924).\n");
    printf("2. Processo de Candidatura: Paris e Los Angeles foram as cidades candidatas para os Jogos de 2024. Outras cidades, como Hamburgo, Roma e Budapeste, retiraram suas candidaturas por varios motivos.\n");
    printf("3. Candidatura de Paris: Paris anunciou sua candidatura em junho de 2015, visando o centenario dos Jogos Olimpicos realizados na cidade. Apos hesitacoes iniciais, a cidade decidiu oficialmente concorrer aos Jogos em 2016. A candidatura de Paris 2024 foi apoiada pelo Comit  Olimpico da Franca e por varias cidades internacionais.\n");
    printf("4. Programa Esportivo: Os Jogos Olimpicos de 2024 contarao com uma variedade de esportes, incluindo 28 esportes permanentes e possivelmente outros adicionais. A inclusao dos esportes eletr nicos ainda estava sob consideracao em 2020.\n");
    printf("5. Locais de Competicao: Os locais de competicao se espalharao por Paris e sua regiao metropolitana, bem como em outras cidades francesas. As cerim nias de abertura e encerramento acontecerao em locais emblematicos, como as margens do Rio Sena e o Stade de France.\n");
    printf("6. Identidade Visual: O emblema dos Jogos Olimpicos de 2024 representa Marianne, a personificacao da Franca, com uma chama formada em seus cabelos. Os Jogos Paralimpicos compartilharao o mesmo logotipo, promovendo os principios da Revolucao Francesa: igualdade, liberdade e fraternidade.\n");
    printf("7. Mascotes: Os mascotes dos Jogos, chamados Phryges, t m um design que gerou comparacoes humoristicas com o clitoris, mas foram projetados para serem sem g nero.\n");
    printf("8. Participacao de Atletas Russos e Bielorrussos: A participacao de atletas russos e bielorrussos nos Jogos de 2024 foi objeto de controversia devido a situacao geopolitica. O COI decidiu que eles poderiam participar sem exibir bandeira ou hino nacionais, uma decisao criticada por alguns paises e lideres.\n");
    printf("9. Revezamento da Tocha Olimpica: O revezamento da tocha comecara em Olimpia, na Grecia, e percorrera mais de 400 cidades e departamentos ultramarinos ao longo de 80 dias.\n");
}

void displayATTDInfo() {
    printf("Confer ncia ATTD sobre Tecnologias Avancadas e Tratamentos da Diabetes - Principais Pontos:\n");
    printf("1. A Confer ncia Internacional sobre Tecnologias Avancadas e Tratamentos da Diabetes (ATTD) foi criada em 2008 e realizou 16 reunioes anuais desde entao.\n");
    printf("2. O objetivo da reuniao da ATTD e destacar tecnologias e tratamentos inovadores no controle do diabetes.\n");
    printf("3. Os principais topicos discutidos incluem Sistemas de Apoio a Decisao, sistemas de apoio a decisao baseados em big data e intelig ncia artificial, p ncreas artificial, bombas de insulina, sensores de glicose, novas insulinas e outros medicamentos, entre outros.\n");
    printf("4. A ATTD re ne desenvolvedores de tecnologias, profissionais de sa de, pesquisadores e pessoas com diabetes.\n");
    printf("5. A ATTD tambem promove uma Feira Internacional de Novas Tecnologias e publica um ATTD YEARBOOK anual.\n");
    printf("6. O Portal Educacional ATTD oferece recursos adicionais, incluindo webcasts e reunioes online.\n");
}

void displayPaleontologia() {
    limparTela();
    printf("Museu de Paleontologia 'Prof. Antonio Celso de Arruda Campos' e um museu dedicado aos fosseis e a historia da vida na Terra.\n");
}

char* listarHorarios(int dia, char* dataEscolhida) {
    //limparTela();
    char *horarios[] = {"08:00", "09:30", "11:00", "13:00", "14:30", "16:00"};
    int escolhaHorario;
    printf("Horarios disponiveis para o dia %s:\n", dataEscolhida);
    int i;
    for( i = 0; i < 6; i++) {
        if(agendamentos[dia][i] < 15)
            printf("%d. %s\n", i+1, horarios[i]);
    }
    printf("\nEscolha um horario: ");
    scanf("%d", &escolhaHorario);
    escolhaHorario--; // Ajustar para indice base 0
    return horarios[escolhaHorario];
}


int salvarAgendamento(Ingressos ingressos) {
    FILE *fp = fopen("agendamentos.txt", "a");
    if (fp == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo para escrita.\n");
        return 0;
    }

    fprintf(fp, "%s,%s,%s,%s\n", ingressos.data, ingressos.horario, ingressos.tipoIngresso, ingressos.nome);
    fclose(fp);

    return 1;
}

int listarDias() {
    //limparTela();
    time_t t;
    struct tm *tmp;
    char outstr[13];
    time(&t);
    tmp = localtime(&t);
    int i, escolhaDia;
    printf("\n");
    for( i = 0; i < 7; i++) {
        strftime(outstr, sizeof(outstr), "%d/%m/%Y", tmp);
        printf("%d. %s\n", i+1, outstr);
        tmp->tm_mday++; // Incrementa um dia
        mktime(tmp);
    }
    printf("\nEscolha uma data: ");
    scanf("%d", &escolhaDia);
    return escolhaDia;
}

int quantidadeTipoIngressokmentos.txt", "r");
    if (fp == NULL) {
        //fprintf(stderr, "Erro ao abrir o arquivo para leitura.\n");
        return 0;
    }

    char linha[256];
    int quantidade = 0;

    while (fgets(linha, sizeof(linha), fp)) {
        char *data, *horario, *tipoIngresso, *nome;
        data = strtok(linha, ",");
        horario = strtok(NULL, ",");
        tipoIngresso = strtok(NULL, ",");
        nome = strtok(NULL, "\n");

        if (strcmp(data, inData) == 0 && strcmp(horario, inHorario) == 0) {
            if (strcmp(tipoIngresso, inTipoIngresso) == 0) {
                quantidade++;
            }
        }
    }

    fclose(fp);

    //printf("Ingressos dispon veis (%s) no dia %s as %s: %d\n", inTipoIngresso, inData, inHorario, quantidade);

    return quantidade;
}

void agendarVisitaPaleontologia() {
    Ingressos ticket[15];
    char *horario;
    char tipoIngresso[10];
    char nome[100];
    char dataFormatada[11];
    int escolhaHorario, escolhaDia;
    int idosos = 0;
    int inteiras = 0;
    int estudantes = 0;
    int total = 0;
    int escolhaRetorno = 1;

    escolhaDia = listarDias();

    time_t time_v;
    struct tm *dateShow;

    time(&time_v);
    dateShow = localtime(&time_v);

    dateShow->tm_mday += escolhaDia - 1;

    mktime(dateShow);
    // Formatar a data
    strftime(dataFormatada, sizeof(dataFormatada), "%d/%m/%Y", dateShow);
    //strcpy(ticket[0].data,dataFormatada);

    limparTela();
    horario = listarHorarios(escolhaDia, dataFormatada);
    //strcpy(ticket[0].horario, listarHorarios(escolhaDia));

    limparTela();
    printf("Informe a quantidade de visitantes para o agendamento do dia %s as %s horas:\n\n", dataFormatada, horario);


    ////////////////////////////////////////////////////////////////////
    // Reserva de ingressos para idosos

    int novosIdosos     = 0;
    idosos              = quantidadeTipoIngresso(dataFormatada,horario,"idoso");
    if (idosos < 3) {
        printf("Ingressos dispon veis para esta sess o (idosos): %d\n", 3 - idosos);
        printf("Por favor, informe quantos ingressos para idosos deseja adquirir: ");
        scanf("%d", &novosIdosos);

        if ( novosIdosos > 3 - idosos ){
            printf("\n\nN mero de ingressos excede o permitido.\n");
            printf("O que voc  gostaria de fazer?\n");
            printf("1. Escolher um outro hor rio.\n");
            printf("2. Continuar com a sele  o atual.\n\n");
            printf("Digite sua escolha (1 ou 2): ");
            scanf("%d", &escolhaRetorno);
            if (escolhaRetorno == 1) {
                agendarVisitaPaleontologia();
            }
        }

    } else {
        printf("Desculpe, n o h  ingressos dispon veis para IDOSOS neste hor rio.\n");
        printf("O que voc  gostaria de fazer?\n");
        printf("1. Escolher um outro hor rio.\n");
        printf("2. Continuar com a sele  o atual.\n\n");
        printf("Digite sua escolha (1 ou 2): ");
        scanf("%d", &escolhaRetorno);

        if (escolhaRetorno == 1) {
            agendarVisitaPaleontologia();
        }
    }

    if (novosIdosos > 0) {
        char nomeIdosos[novosIdosos][100];
        int i;

        // Limpa o buffer de entrada para evitar o erro na primeira solicita  o do nome
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf("\nVoc  selecionou %d ingresso(s) para idoso.\n", novosIdosos);
        for (i = 0; i < novosIdosos; i++) {
            do {
                printf("Informe o nome do idoso n mero %d para confirmar a sua reserva: ", i + 1);
                fgets(nomeIdosos[i], sizeof(nomeIdosos[i]), stdin);

                // Remove o '\n' que pode ter sido capturado pelo fgets
                if (nomeIdosos[i][strlen(nomeIdosos[i]) - 1] == '\n') {
                    nomeIdosos[i][strlen(nomeIdosos[i]) - 1] = '\0';
                }

                if (nomeIdosos[i][0] == '\0') {
                    printf("Por favor, informe um nome v lido.\n");
                }

            } while (nomeIdosos[i][0] == '\0'); // Repetir  a solicita  o enquanto a entrada estiver vazia
        }

        for (i = 0; i < novosIdosos; i++) {
            Ingressos ingressoIdoso;
            strcpy(ingressoIdoso.data, dataFormatada);
            strcpy(ingressoIdoso.horario, horario);
            strcpy(ingressoIdoso.tipoIngresso, "idoso");
            strcpy(ingressoIdoso.nome, nomeIdosos[i]);

            salvarAgendamento(ingressoIdoso);
        }

    }


    ////////////////////////////////////////////////////////////////////
    // Reserva de ingressos para estudantes

    limparTela();
    printf("Informe a quantidade de visitantes para o agendamento do dia %s as %s horas:\n\n", dataFormatada, horario);

    int novosEstudantes = 0;
    estudantes = quantidadeTipoIngresso(dataFormatada,horario, "estudante");

    if (estudantes < 5) {
        printf("Ingressos dispon veis para esta sess o (estudantes): %d\n", 5 - estudantes);
        printf("Por favor, informe quantos ingressos para estudantes deseja adquirir: ");
        scanf("%d", &novosEstudantes);
        if ( novosEstudantes > 5 - estudantes ){
            printf("\n\nN mero de ingressos excede o permitido.\n");
            printf("O que voc  gostaria de fazer?\n");
            printf("1. Escolher um outro hor rio.\n");
            printf("2. Continuar com a sele  o atual.\n\n");
            printf("Digite sua escolha (1 ou 2): ");
            scanf("%d", &escolhaRetorno);
            if (escolhaRetorno == 1) {
                agendarVisitaPaleontologia();
            }
        }
    } else {
        limparTela();
        printf("Desculpe, n o h  ingressos dispon veis para ESTUDANTES neste hor rio.\n");
        printf("O que voc  gostaria de fazer?\n");
        printf("1. Escolher um outro hor rio.\n");
        printf("2. Continuar com a sele  o atual.\n\n");
        printf("Digite sua escolha (1 ou 2): ");
        scanf("%d", &escolhaRetorno);

        if (escolhaRetorno == 1) {
            agendarVisitaPaleontologia();
        }
    }

    if (novosEstudantes > 0) {
        char nomeEstudantes[novosEstudantes][100];
        int i;

        // Limpa o buffer de entrada para evitar o erro na primeira solicita  o do nome
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        printf("\nVoc  selecionou %d ingressos para estudantes.\n", novosEstudantes);
        for (i = 0; i < novosEstudantes; i++) {
            do {
                printf("Informe o nome do estudante n mero %d para confirmar a sua reserva: ", i + 1);
                fgets(nomeEstudantes[i], sizeof(nomeEstudantes[i]), stdin);

                // Remove o '\n' que pode ter sido capturado pelo fgets
                if (nomeEstudantes[i][strlen(nomeEstudantes[i]) - 1] == '\n') {
                    nomeEstudantes[i][strlen(nomeEstudantes[i]) - 1] = '\0';
                }

                if (nomeEstudantes[i][0] == '\0') {
                    printf("Por favor, informe um nome v lido.\n");
                }

            } while (nomeEstudantes[i][0] == '\0'); // Repetir  a solicita  o enquanto a entrada estiver vazia
        }

        for (i = 0; i < novosEstudantes; i++){
            Ingressos ingressosEstudantes;
            strcpy(ingressosEstudantes.data, dataFormatada);
            strcpy(ingressosEstudantes.horario, horario);
            strcpy(ingressosEstudantes.tipoIngresso, "estudante");
            strcpy(ingressosEstudantes.nome, nomeEstudantes[i]);

            salvarAgendamento(ingressosEstudantes);
        }

    }



    ////////////////////////////////////////////////////////////////////
    // Reserva de ingressos inteiras
    limparTela();
    printf("Informe a quantidade de visitantes para o agendamento do dia %s as %s horas:\n\n", dataFormatada, horario);

    int novosInteiras = 0;
    idosos     = quantidadeTipoIngresso(dataFormatada,horario,"idoso");
    inteiras   = quantidadeTipoIngresso(dataFormatada,horario,"inteira");
    estudantes = quantidadeTipoIngresso(dataFormatada,horario, "estudante");

    int ingressosDisponiveisInteiras = 15 - (inteiras + estudantes + idosos);
    if (ingressosDisponiveisInteiras > 0) {
        printf("Ingressos dispon veis para esta sess o (inteiras): %d\n", ingressosDisponiveisInteiras);
        printf("Por favor, informe quantos ingressos inteiras deseja adquirir: ");
        scanf("%d", &novosInteiras);
        if ( novosInteiras > ingressosDisponiveisInteiras ){
            printf("\n\nN mero de ingressos excede o permitido.\n");
            printf("O que voc  gostaria de fazer?\n");
            printf("1. Escolher um outro hor rio.\n");
            printf("2. Continuar com a sele  o atual.\n\n");
            printf("Digite sua escolha (1 ou 2): ");
            scanf("%d", &escolhaRetorno);
            if (escolhaRetorno == 1) {
                agendarVisitaPaleontologia();
            }
        }
    } else {
        limparTela();
        printf("Desculpe, n o h  ingressos dispon veis para este hor rio.\n");
        printf("O que voc  gostaria de fazer?\n");
        printf("1. Escolher um outro hor rio.\n");
        printf("2. Continuar com a sele  o atual.\n\n");
        printf("Digite sua escolha (1 ou 2): ");
        scanf("%d", &escolhaRetorno);
        if (escolhaRetorno == 1) {
            agendarVisitaPaleontologia();
        }
    }

    if (novosInteiras > 0) {
        char nomeInteiras[novosInteiras][100];
        int i;

        // Limpa o buffer de entrada para evitar o erro na primeira solicita  o do nome
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        printf("\nVoc  selecionou %d ingressos inteiras.\n", novosInteiras);
        for (i = 0; i < novosInteiras; i++) {
            do {
                printf("Informe o nome da pessoa n mero %d para confirmar a sua reserva: ", i + 1);
                fgets(nomeInteiras[i], sizeof(nomeInteiras[i]), stdin);

                // Remove o '\n' que pode ter sido capturado pelo fgets
                if (nomeInteiras[i][strlen(nomeInteiras[i]) - 1] == '\n') {
                    nomeInteiras[i][strlen(nomeInteiras[i]) - 1] = '\0';
                }

                if (nomeInteiras[i][0] == '\0') {
                    printf("Por favor, informe um nome v lido.\n");
                }

            } while (nomeInteiras[i][0] == '\0'); // Repetir  a solicita  o enquanto a entrada estiver vazia
        }

        for (i = 0; i < novosInteiras; i++){
            Ingressos ingressosInteiras;
            strcpy(ingressosInteiras.data, dataFormatada);
            strcpy(ingressosInteiras.horario, horario);
            strcpy(ingressosInteiras.tipoIngresso, "inteira");
            strcpy(ingressosInteiras.nome, nomeInteiras[i]);

            salvarAgendamento(ingressosInteiras);
        }

    }

    printf("\n\nAgendamento realizado com sucesso!\n");
}


int main() {
    int escolha;
    setlocale(LC_ALL,"Portuguese");
    mostrarBoasVindas();
    listarMuseus();
    scanf("%d", &escolha);

    switch(escolha) {
        case 1:
            displayArteModernaInfo();
            break;
        case 2:
            displaySantosDumontInfo();
            break;
        case 3:
            displayJogosOlimpicosInfo();
            break;
        case 4:
            displayPaleontologia();
            agendarVisitaPaleontologia();
            break;
        case 5:
            displayATTDInfo();
            break;
        default:
            printf("Opcao invalida ou ainda nao implementada.\n");
            break;
    }

    return 0;
}

// Resto do codigo permanece inalterado

