void agendarmuseu150anos ()
{
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

    horario = listarHorarios(escolhaDia, dataFormatada);
    //strcpy(ticket[0].horario, listarHorarios(escolhaDia));

    printf("Informe a quantidade de visitantes para o agendamento do dia %s as %s horas:\n\n", dataFormatada, horario);


    ////////////////////////////////////////////////////////////////////
    // Reserva de ingressos para idosos

    int novosIdosos = 0;
    idosos = quantidadeTipoIngresso(dataFormatada,horario,"idoso");

    if (idosos < 3) {
        printf("Ingressos disponíveis para esta sessão (idosos): %d\n", 3 - idosos);
        printf("Por favor, informe quantos ingressos para idosos deseja adquirir: ");
        scanf("%d", &novosIdosos);

        if ( novosIdosos > 3 - idosos ){
            printf("\n\nNúmero de ingressos excede o permitido.\n");
            printf("O que você gostaria de fazer?\n");
            printf("1. Escolher um outro horário.\n");
            printf("2. Continuar com a seleção atual.\n\n");
            printf("Digite sua escolha (1 ou 2): ");
            scanf("%d", &escolhaRetorno);
            if (escolhaRetorno == 1) {
                agendarVisitaPaleontologia();
            }
        }

    } else {
        printf("Desculpe, não há ingressos disponíveis para IDOSOS neste horário.\n");
        printf("O que você gostaria de fazer?\n");
        printf("1. Escolher um outro horário.\n");
        printf("2. Continuar com a seleção atual.\n\n");
        printf("Digite sua escolha (1 ou 2): ");
        scanf("%d", &escolhaRetorno);

        if (escolhaRetorno == 1) {
            agendarVisitaPaleontologia();
        }
    }

    if (novosIdosos > 0) {
        char nomeIdosos[novosIdosos][100];
        int i;

        // Limpa o buffer de entrada para evitar o erro na primeira solicitação do nome
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf("\nVocê selecionou %d ingresso(s) para idoso.\n", novosIdosos);
        for (i = 0; i < novosIdosos; i++) {
            do {
                printf("Informe o nome do idoso número %d para confirmar a sua reserva: ", i + 1);
                fgets(nomeIdosos[i], sizeof(nomeIdosos[i]), stdin);

                // Remove o '\n' que pode ter sido capturado pelo fgets
                if (nomeIdosos[i][strlen(nomeIdosos[i]) - 1] == '\n') {
                    nomeIdosos[i][strlen(nomeIdosos[i]) - 1] = '\0';
                }

                if (nomeIdosos[i][0] == '\0') {
                    printf("Por favor, informe um nome válido.\n");
                }

            } while (nomeIdosos[i][0] == '\0'); // Repetirá a solicitação enquanto a entrada estiver vazia
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

    printf("Informe a quantidade de visitantes para o agendamento do dia %s as %s horas:\n\n", dataFormatada, horario);

    int novosEstudantes = 0;
    estudantes = quantidadeTipoIngresso(dataFormatada,horario, "estudante");

    if (estudantes < 5) {
        printf("Ingressos disponíveis para esta sessão (estudantes): %d\n", 5 - estudantes);
        printf("Por favor, informe quantos ingressos para estudantes deseja adquirir: ");
        scanf("%d", &novosEstudantes);
        if ( novosEstudantes > 5 - estudantes ){
            printf("\n\nNúmero de ingressos excede o permitido.\n");
            printf("O que você gostaria de fazer?\n");
            printf("1. Escolher um outro horário.\n");
            printf("2. Continuar com a seleção atual.\n\n");
            printf("Digite sua escolha (1 ou 2): ");
            scanf("%d", &escolhaRetorno);
            if (escolhaRetorno == 1) {
                agendarVisitaPaleontologia();
            }
        }
    } else {
        printf("Desculpe, não há ingressos disponíveis para ESTUDANTES neste horário.\n");
        printf("O que você gostaria de fazer?\n");
        printf("1. Escolher um outro horário.\n");
        printf("2. Continuar com a seleção atual.\n\n");
        printf("Digite sua escolha (1 ou 2): ");
        scanf("%d", &escolhaRetorno);

        if (escolhaRetorno == 1) {
            agendarVisitaPaleontologia();
        }
    }

    if (novosEstudantes > 0) {
        char nomeEstudantes[novosEstudantes][100];
        int i;

        // Limpa o buffer de entrada para evitar o erro na primeira solicitação do nome
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        printf("\nVocê selecionou %d ingressos para estudantes.\n", novosEstudantes);
        for (i = 0; i < novosEstudantes; i++) {
            do {
                printf("Informe o nome do estudante número %d para confirmar a sua reserva: ", i + 1);
                fgets(nomeEstudantes[i], sizeof(nomeEstudantes[i]), stdin);

                // Remove o '\n' que pode ter sido capturado pelo fgets
                if (nomeEstudantes[i][strlen(nomeEstudantes[i]) - 1] == '\n') {
                    nomeEstudantes[i][strlen(nomeEstudantes[i]) - 1] = '\0';
                }

                if (nomeEstudantes[i][0] == '\0') {
                    printf("Por favor, informe um nome válido.\n");
                }

            } while (nomeEstudantes[i][0] == '\0'); // Repetirá a solicitação enquanto a entrada estiver vazia
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
    printf("Informe a quantidade de visitantes para o agendamento do dia %s as %s horas:\n\n", dataFormatada, horario);

    int novosInteiras = 0;
    idosos     = quantidadeTipoIngresso(dataFormatada,horario,"idoso");
    inteiras   = quantidadeTipoIngresso(dataFormatada,horario,"inteira");
    estudantes = quantidadeTipoIngresso(dataFormatada,horario, "estudante");

    int ingressosDisponiveisInteiras = 15 - (inteiras + estudantes + idosos);
    if (ingressosDisponiveisInteiras > 0) {
        printf("Ingressos disponíveis para esta sessão (inteiras): %d\n", ingressosDisponiveisInteiras);
        printf("Por favor, informe quantos ingressos inteiras deseja adquirir: ");
        scanf("%d", &novosInteiras);
        if ( novosInteiras > ingressosDisponiveisInteiras ){
            printf("\n\nNúmero de ingressos excede o permitido.\n");
            printf("O que você gostaria de fazer?\n");
            printf("1. Escolher um outro horário.\n");
            printf("2. Continuar com a seleção atual.\n\n");
            printf("Digite sua escolha (1 ou 2): ");
            scanf("%d", &escolhaRetorno);
            if (escolhaRetorno == 1) {
                agendarVisitaPaleontologia();
            }
        }
    } else {
        printf("Desculpe, não há ingressos disponíveis para este horário.\n");
        printf("O que você gostaria de fazer?\n");
        printf("1. Escolher um outro horário.\n");
        printf("2. Continuar com a seleção atual.\n\n");
        printf("Digite sua escolha (1 ou 2): ");
        scanf("%d", &escolhaRetorno);
        if (escolhaRetorno == 1) {
            agendarVisitaPaleontologia();
        }
    }

    if (novosInteiras > 0) {
        char nomeInteiras[novosInteiras][100];
        int i;

        // Limpa o buffer de entrada para evitar o erro na primeira solicitação do nome
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        printf("\nVocê selecionou %d ingressos inteiras.\n", novosInteiras);
        for (i = 0; i < novosInteiras; i++) {
            do {
                printf("Informe o nome da pessoa número %d para confirmar a sua reserva: ", i + 1);
                fgets(nomeInteiras[i], sizeof(nomeInteiras[i]), stdin);

                // Remove o '\n' que pode ter sido capturado pelo fgets
                if (nomeInteiras[i][strlen(nomeInteiras[i]) - 1] == '\n') {
                    nomeInteiras[i][strlen(nomeInteiras[i]) - 1] = '\0';
                }

                if (nomeInteiras[i][0] == '\0') {
                    printf("Por favor, informe um nome válido.\n");
                }

            } while (nomeInteiras[i][0] == '\0'); // Repetirá a solicitação enquanto a entrada estiver vazia
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
/* FIM DO AGENDAMENTO */

const char **escolhaPasso(){
    static const char *lines[] = {
        "",
        "O que gostaria de fazer em seguida?",
        "0 - Sair.",
        "1 - Agendar visita ao museu.",
        "2 - Visitar outro museu.",
        ""
    };
    getchar();
    return lines;
}
// Matriz de agendamentos: 7 dias x 8 horarios por dia (8h as 16h30, com intervalo de 1h30)
int agendamentos[7][8] = {0};

char *listarHorarios(int dia, char *dataEscolhida) {
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
    time_t t;
    struct tm *tmp;
    char outstr[13];
    time(&t);
    tmp = localtime(&t);
    int i, escolhaDia;
    printf("\n");
    for( i = 0; i < 7; i++) {
        strftime(outstr, sizeof(outstr), "%d/%m/%Y", tmp); //ISSO TA CERTO?
        printf("%d. %s\n", i+1, outstr);
        tmp->tm_mday++; // Incrementa um dia
        mktime(tmp);
    }
    printf("\nEscolha uma data: ");
    scanf("%d", &escolhaDia);
    return escolhaDia;
}

int quantidadeTipoIngresso(char inData[12], char inHorario[6], char inTipoIngresso[12]) {
    FILE *fp = fopen("agendamentos.txt", "r");
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

    //printf("Ingressos disponíveis (%s) no dia %s as %s: %d\n", inTipoIngresso, inData, inHorario, quantidade);

    return quantidade;
}
    return 0;
}
