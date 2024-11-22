#include <iostream>
#include <cstdlib>
#include <limits>
#include <time.h>
#include <locale.h>


    // BATALHA NAVAL;


    // CORES DO JOGO

    char vermelho[] = { 0x1b, '[', '1', ';', '3', '1', 'm', 0 };
    char verde[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
    char amarelo[] = { 0x1b, '[', '1', ';', '3', '3', 'm', 0 };
    char azul[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char roxo[] = { 0x1b, '[', '1', ';', '3', '5', 'm', 0 };
    char azulmarinho[] = { 0x1b, '[', '1', ';', '3', '6', 'm', 0 };
    char branco[] = { 0x1b, '[', '1', ';', '3', '9', 'm', 0 };


    void limpaTela(){
     #ifdef _WIN32
        system("CLS"); // Comando para Windows
    #else
        system("clear"); // Comando para Linux ou MacOS
    #endif
    }


    using namespace std;


    //   NÍVEL - FÁCIL

    void iniciaTabuleiro(char tabuleiro[4][4], char mascara[4][4]){

        int linha, coluna;
        for(linha = 0; linha < 4; linha++){
        for(coluna = 0; coluna < 4; coluna++){
        tabuleiro[linha][coluna] = 'M';
        mascara[linha][coluna] = '~';
        }
        }
        }


   void exibeTabuleiro(char tabuleiro[4][4], char mascara[4][4]){

        cout << amarelo;
        cout << "Faça 30 pontos para ganhar o jogo!";
        cout << azulmarinho;
        cout << " - Fácil\n\n";
        cout << amarelo;

        int cont;

        for(cont = 0; cont < 4; cont++){
        if(cont == 0){
        cout << "      ";
        }
        cout << cont << " " << amarelo;
        }
        cout << "\n";

        for(cont = 0; cont < 4; cont++){
        if(cont == 0){
        cout << "      " << azulmarinho;
        }
        cout << "| " << azulmarinho;
        }
        cout << " \n";
        cout << branco;


        int linha, coluna;

        for(linha = 0; linha < 4; linha++){
        cout << linha << "  - ";
        for(coluna = 0; coluna < 4; coluna++){


        switch(mascara[linha][coluna]){

        case 'M': cout << azul << " " << mascara[linha][coluna] << branco; break;
        case 'B': cout << verde << " " << mascara[linha][coluna] << branco; break;
        case 'N': cout << amarelo << " " << mascara[linha][coluna] << branco; break;
        default:  cout << " " << mascara[linha][coluna] << branco; break;
        }
        }
        cout << "\n";
        }
        }


    void posicionaInimigos(char tabuleiro[4][4]){

        int quantidadeBarcos = 3, barcosPosicionados = 0;

        while(barcosPosicionados < quantidadeBarcos){

        int linhaBarco = rand()%4;
        int colunaBarco = rand()%4;

        if(tabuleiro[linhaBarco][colunaBarco] == 'M'){
           tabuleiro[linhaBarco][colunaBarco] = 'B';
           barcosPosicionados++;
        }
        }

        int quantidadeNavio = 4, naviosPosicionados = 0;

        while(naviosPosicionados < quantidadeNavio){

        int linhaNavio = rand()%5;
        int colunaNavio = rand()%5;

        if(tabuleiro[linhaNavio][colunaNavio] == 'M'){
        tabuleiro[linhaNavio][colunaNavio] = 'N';
        naviosPosicionados++;
        }
        }
        }


    void gabarito(char tabuleiro[4][4]){

        cout << azulmarinho;
        cout << "\n     Gabarito\n\n";

        int cont;

        for(cont = 0; cont < 4; cont++){
        if(cont == 0){
        cout << amarelo;
        cout << "      ";
        }
        cout << cont << " " << amarelo;
        }
        cout << "\n";


        for(cont = 0; cont < 4; cont++){
        if(cont == 0){
        cout << "      " << azulmarinho;
        }
        cout << "| " << azulmarinho;
        }
        cout << "\n";
        cout << branco;


        int linha, coluna;

        for(linha = 0; linha < 4; linha++){
        cout << linha << "  - ";
        for(coluna = 0; coluna < 4; coluna++){


        switch(tabuleiro[linha][coluna]){

        case 'M': cout << azul << " " << tabuleiro[linha][coluna] << branco; break;
        case 'B': cout << verde << " " << tabuleiro[linha][coluna] << branco; break;
        case 'N': cout << amarelo << " " << tabuleiro[linha][coluna] << branco; break;
        default:  cout << " " << tabuleiro[linha][coluna] << branco; break;
        }
        }
        cout << "\n";
        }
        }


    void jogo(){

        char tabuleiro[4][4], mascara[4][4];
        int tentativas = 0, maxTentativas = 6;
        int linhaJogada, colunaJogada;
        int pontos = 0;
        int opcao;


        iniciaTabuleiro(tabuleiro, mascara);
        posicionaInimigos(tabuleiro);

        while(tentativas < maxTentativas){

        limpaTela();

        exibeTabuleiro(tabuleiro, mascara);

        cout << "\nPontos: " << pontos;
        cout << "\nMunição: " << (maxTentativas - tentativas);

        cout << "\n\nDigite uma linha: ";
        cin >> linhaJogada;

        if(cin.fail()) {
        limpaTela();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
        }

        while(linhaJogada < 0 || linhaJogada > 3){
        limpaTela();
        exibeTabuleiro(tabuleiro, mascara);
        cout << "\nPontos: " << pontos;
        cout << "\nMunição: " << maxTentativas - tentativas;
        cout << "\n\n(" << linhaJogada << ") Não se encaixa no limite do tabuleiro.\n";
        cout << "\nDigite uma linha: ";
        cin >> linhaJogada;
        limpaTela();
        exibeTabuleiro(tabuleiro, mascara);
        cout << "\nPontos: " << pontos;
        cout << "\nMunição: " << maxTentativas - tentativas;
        cout << "\n\nDigite uma linha: " << linhaJogada;
        cout << "\n";
        }

        cout << "Digite uma coluna: ";
        cin >> colunaJogada;

        if(cin.fail()) {
        limpaTela();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
        }

        while(colunaJogada < 0 || colunaJogada > 3){
        limpaTela();
        exibeTabuleiro(tabuleiro, mascara);
        cout << "\nPontos: " << pontos;
        cout << "\nMunição: " << maxTentativas - tentativas;
        cout << "\n\nDigite uma linha: " << linhaJogada;
        cout << "\n\n(" << colunaJogada << ") Não se encaixa no limite do tabuleiro.\n";
        cout << "\nDigite uma coluna: ";
        cin >> colunaJogada;
        limpaTela();
        exibeTabuleiro(tabuleiro, mascara);
        }

        if (mascara[linhaJogada][colunaJogada] != '~') {
            continue;
        }

        if(tabuleiro[linhaJogada][colunaJogada] == 'B'){
            pontos += 10;

        }else if(tabuleiro[linhaJogada][colunaJogada] == 'N'){
            pontos += 20;
        }

        mascara[linhaJogada][colunaJogada] = tabuleiro [linhaJogada][colunaJogada];
        tentativas++;

        if(tentativas == maxTentativas && pontos < 30){
        limpaTela();
        exibeTabuleiro(tabuleiro, mascara);
        cout << "\nPontos: " << pontos;
        cout << "\nMunição: " << maxTentativas - maxTentativas;
        cout << vermelho;
        cout << "\n\nQue pena! Você perdeu!";
        cout << branco;
        cout << "\n\n(1) Ver gabarito, (2) Jogar novamente, (3) Selecionar nível, (4) Sair: ";
        cin >> opcao;

        while(opcao == 1){
        limpaTela();
        gabarito(tabuleiro);
        cout << "\n\n(1) Jogar novamente, (2) Selecionar nível, (3) Sair: ";
        cin >> opcao;

        if(opcao == 1){
        limpaTela();
        jogo();
        return;
        }else if(opcao == 2){
        limpaTela();
        return;
        }else{
        cout << "\n Até logo!\n";
        exit(0);
        }
        break;
        }

        if(opcao == 2){
        limpaTela();
        jogo();
        return;
        }else if(opcao == 3){
        limpaTela();
        return;
        }else{
        cout << "\n Até logo!\n";
        exit(0);
        }
        }

        if(pontos >= 30){
        limpaTela();
        exibeTabuleiro(tabuleiro, mascara);
        cout << "\nPontos: " << pontos;
        cout << "\nMunição: " << maxTentativas - tentativas;
        cout << verde;
        cout << "\n\nParabéns, você ganhou!";
        cout << branco;
        cout << "\n\n(1) Ver gabarito, (2) Jogar novamente, (3) Selecionar nível, (4) Sair: ";
        cin >> opcao;
        limpaTela();


        while(opcao == 1){
        limpaTela();
        gabarito(tabuleiro);
        cout << "\n\n(1) Jogar novamente, (2) Selecionar nível, (3) Sair: ";
        cin >> opcao;

        if(opcao == 1){
        limpaTela();
        jogo();
        return;
        }else if(opcao == 2){
        limpaTela();
        return;
        }else{
        cout << "\n Até logo!\n";
        exit(0);
        }
        break;
        }

        if(opcao == 2){
        limpaTela();
        jogo();
        return;
        }else if(opcao == 3){
        limpaTela();
        return;
        }else{
        cout << "\n Até logo!\n";
        exit(0);
        }
        }
        }
        }


    // NÍVEL MÉDIO

    void iniciaTabuleiro2(char tabuleiro[5][5], char mascara[5][5]){

        int linha, coluna;
        for(linha = 0; linha < 5; linha++){
        for(coluna = 0; coluna < 5; coluna++){
        tabuleiro[linha][coluna] = 'M';
        mascara[linha][coluna] = '~';
        }
        }
        }

    void exibeTabuleiro2(char tabuleiro[5][5], char mascara[5][5]){

        cout << amarelo;
        cout << "\nFaça 30 pontos para ganhar o jogo!";
        cout << roxo;
        cout << " - Médio\n\n";
        cout << amarelo;

        int cont;
        for(cont = 0; cont < 5; cont++){
        if(cont == 0){
        cout << "      ";
        }
        cout << cont << " " << amarelo;
        }
        cout << "\n";

        for(cont = 0; cont < 5; cont++){
        if(cont == 0){
        cout << "      " << roxo;
        }
        cout << "| " << roxo;
        }
        cout << " \n";
        cout << branco;


        int linha, coluna;
        for(linha = 0; linha < 5; linha++){
        cout << linha << "  - ";
        for(coluna = 0; coluna < 5; coluna++){

        switch(mascara[linha][coluna]){
        case 'M': cout << azul << " " << mascara[linha][coluna] << branco; break;
        case 'B': cout << verde << " " << mascara[linha][coluna] << branco; break;
        case 'N': cout << amarelo << " " << mascara[linha][coluna] << branco; break;
        default:  cout << " " << mascara[linha][coluna] << branco; break;
        }
        }
        cout << "\n";
        }
        }


    void posicionaInimigos2(char tabuleiro[5][5]){

        int quantidadeBarcos = 6, barcosPosicionados = 0;

        while(barcosPosicionados < quantidadeBarcos){

        int linhaBarco = rand()%5;
        int colunaBarco = rand()%5;

        if(tabuleiro[linhaBarco][colunaBarco] == 'M'){
           tabuleiro[linhaBarco][colunaBarco] = 'B';
           barcosPosicionados++;
        }
        }

        int quantidadeNavio = 3, naviosPosicionados = 0;

        while(naviosPosicionados < quantidadeNavio){

        int linhaNavio = rand()%5;
        int colunaNavio = rand()%5;

        if(tabuleiro[linhaNavio][colunaNavio] == 'M'){
            tabuleiro[linhaNavio][colunaNavio] = 'N';
            naviosPosicionados++;
        }
        }
        }


    void gabarito2(char tabuleiro[5][5]){

        cout << roxo;
        cout << "\n      Gabarito\n\n";

        int cont;
        for(cont = 0; cont < 5; cont++){
        if(cont == 0){
        cout << amarelo;
        cout << "      ";
        }
        cout << cont << " " << amarelo;
        }
        cout << "\n";

        for(cont = 0; cont < 5; cont++){
        if(cont == 0){
        cout << "      " << roxo;
        }
        cout << "| " << roxo;
        }
        cout << "\n";
        cout << branco;


        int linha, coluna;

        for(linha = 0; linha < 5; linha++){
        cout << linha << "  - ";
        for(coluna = 0; coluna < 5; coluna++){

        switch(tabuleiro[linha][coluna]){
        case 'M': cout << azul << " " << tabuleiro[linha][coluna] << branco; break;
        case 'B': cout << verde << " " << tabuleiro[linha][coluna] << branco; break;
        case 'N': cout << amarelo << " " << tabuleiro[linha][coluna] << branco; break;
        default:  cout << " " << tabuleiro[linha][coluna] << branco; break;
        }
        }
        cout << "\n";
        }
        }


    void jogo2(){

        char tabuleiro[5][5], mascara[5][5];
        int tentativas = 0, maxTentativas = 7;
        int linhaJogada, colunaJogada;
        int pontos = 0;
        int opcao;


        iniciaTabuleiro2(tabuleiro, mascara);
        posicionaInimigos2(tabuleiro);

        while(tentativas < maxTentativas){

        limpaTela();

        exibeTabuleiro2(tabuleiro, mascara);

        cout << "\nPontos: " << pontos;
        cout << "\nMunição: " << (maxTentativas - tentativas);
        cout << "\n\nDigite uma linha: ";
        cin >> linhaJogada;

        if(cin.fail()) {
        limpaTela();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
        }

        while(linhaJogada < 0 || linhaJogada > 4){
        limpaTela();
        exibeTabuleiro2(tabuleiro, mascara);
        cout << "\nPontos: " << pontos;
        cout << "\nMunição: " << maxTentativas - tentativas;
        cout << "\n\n(" << linhaJogada << ") Não se encaixa no limite do tabuleiro.\n";
        cout << "\nDigite uma linha: ";
        cin >> linhaJogada;
        limpaTela();
        exibeTabuleiro2(tabuleiro, mascara);
        cout << "\nPontos: " << pontos;
        cout << "\nMunição: " << maxTentativas - tentativas;
        cout << "\n\nDigite uma linha: " << linhaJogada;
        cout << "\n";
        }

        cout << "Digite uma coluna: ";
        cin >> colunaJogada;

        if(cin.fail()) {
        limpaTela();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
        }

        while(colunaJogada < 0 || colunaJogada > 4){
        limpaTela();
        exibeTabuleiro2(tabuleiro, mascara);
        cout << "\nPontos: " << pontos;
        cout << "\nMunição: " << maxTentativas - tentativas;
        cout << "\n\nDigite uma linha: " << linhaJogada;
        cout << "\n\n(" << colunaJogada << ") Não se encaixa no limite do tabuleiro.\n";
        cout << "\nDigite uma coluna: ";
        cin >> colunaJogada;
        limpaTela();
        exibeTabuleiro2(tabuleiro, mascara);
        }

        if (mascara[linhaJogada][colunaJogada] != '~') {
            continue;
        }

        if(tabuleiro[linhaJogada][colunaJogada] == 'B'){
            pontos += 10;
        }

        else if(tabuleiro[linhaJogada][colunaJogada] == 'N'){
            pontos += 20;
        }

        mascara[linhaJogada][colunaJogada] = tabuleiro [linhaJogada][colunaJogada];
        tentativas++;

        if(tentativas == maxTentativas && pontos < 30){
        limpaTela();
        exibeTabuleiro2(tabuleiro, mascara);
        cout << "\nPontos: " << pontos;
        cout << "\nMunição: " << maxTentativas - maxTentativas;
        cout << vermelho;
        cout << "\n\nQue pena! Você perdeu!";
        cout << branco;
        cout << "\n\n(1) Ver gabarito, (2) Jogar novamente, (3) Selecionar nível, (4) Sair: ";
        cin >> opcao;

        while(opcao == 1){
        limpaTela();
        gabarito2(tabuleiro);
        cout << "\n\n(1) Jogar novamente, (2) Selecionar nível, (3) Sair: ";
        cin >> opcao;

        if(opcao == 1){
        limpaTela();
        jogo2();
        return;
        }else if(opcao == 2){
        limpaTela();
        return;
        }else{
        cout << "\n Até logo!\n";
        exit(0);
        }
        break;
        }

        if(opcao == 2){
        limpaTela();
        jogo2();
        return;
        }else if(opcao == 3){
        limpaTela();
        return;
        }else{
        cout << "\n Até logo!\n";
        exit(0);
        }
        }

        if(pontos >= 30){
        limpaTela();
        exibeTabuleiro2(tabuleiro, mascara);
        cout << "\nPontos: " << pontos;
        cout << "\nMunição: " << maxTentativas - tentativas;
        cout << verde;
        cout << "\n\nParabéns, você ganhou!";
        cout << branco;
        cout << "\n\n(1) Ver gabarito, (2) Jogar novamente, (3) Selecionar nível, (4) Sair: ";
        cin >> opcao;
        limpaTela();

        while(opcao == 1){
        limpaTela();
        gabarito2(tabuleiro);
        cout << "\n\n(1) Jogar novamente, (2) Selecionar nível, (3) Sair: ";
        cin >> opcao;

        if(opcao == 1){
        limpaTela();
        jogo2();
        return;
        }else if(opcao == 2){
        limpaTela();
        return;
        }else{
        cout << "\n Até logo!\n";
        exit(0);
        }
        break;
        }

        if(opcao == 2){
        limpaTela();
        jogo2();
        }else if(opcao == 3){
        limpaTela();
        return;
        }else{
        cout << "\n Até logo!\n";
        exit(0);
        }
        }
        }
        }


    //NÍVEL DIFÍCIL

    void iniciaTabuleiro3(char tabuleiro[6][6], char mascara[6][6]){

        int linha, coluna;
        for(linha = 0; linha < 6; linha++){
        for(coluna = 0; coluna < 6; coluna++){
        tabuleiro[linha][coluna] = 'M';
        mascara[linha][coluna] = '~';
        }
        }
        }


    void exibeTabuleiro3(char tabuleiro[6][6], char mascara[6][6]){

        cout << amarelo;
        cout << "\nFaça 30 pontos para ganhar o jogo!";
        cout << vermelho;
        cout << " - Difícil\n\n";
        cout << amarelo;

        int cont;

        for(cont = 0; cont < 6; cont++){
        if(cont == 0){
        cout << "      ";
        }
        cout << cont << " " << amarelo;
        }
        cout << "\n";

        for(cont = 0; cont < 6; cont++){
        if(cont == 0){
        cout << "      " << vermelho;
        }
        cout << "| " << vermelho;
        }
        cout << " \n";
        cout << branco;


        int linha, coluna;

        for(linha = 0; linha < 6; linha++){
        cout << linha << "  - ";
        for(coluna = 0; coluna < 6; coluna++){

        switch(mascara[linha][coluna]){
        case 'M': cout << azul << " " << mascara[linha][coluna] << branco; break;
        case 'B': cout << verde << " " << mascara[linha][coluna] << branco; break;
        case 'N': cout << amarelo << " " << mascara[linha][coluna] << branco; break;
        default:  cout << " " << mascara[linha][coluna] << branco; break;
        }
        }
        cout << "\n";
        }
        }


    void posicionaInimigos3 (char tabuleiro[6][6]){

        int quantidadeBarcos = 9, barcosPosicionados = 0;

        while(barcosPosicionados < quantidadeBarcos){

        int linhaBarco = rand()%6;
        int colunaBarco = rand()%6;

        if(tabuleiro[linhaBarco][colunaBarco] == 'M'){
           tabuleiro[linhaBarco][colunaBarco] = 'B';
           barcosPosicionados++;
        }
        }

        int quantidadeNavio = 2, naviosPosicionados = 0;

        while(naviosPosicionados < quantidadeNavio){

        int linhaNavio = rand()%6;
        int colunaNavio = rand()%6;

        if(tabuleiro[linhaNavio][colunaNavio] == 'M'){
            tabuleiro[linhaNavio][colunaNavio] = 'N';
            naviosPosicionados++;
            }
            }
        }


    void gabarito3(char tabuleiro[6][6]){

        cout << vermelho;
        cout << "\n       Gabarito\n\n";

        int cont;
        for(cont = 0; cont < 6; cont++){
        if(cont == 0){
        cout << amarelo;
        cout << "      ";
        }
        cout << cont << " " << amarelo;
        }
        cout << "\n";

        for(cont = 0; cont < 6; cont++){
        if(cont == 0){
        cout << "      " << vermelho;
        }
        cout << "| " << vermelho;
        }
        cout << "\n";
        cout << branco;


        int linha, coluna;

        for(linha = 0; linha < 6; linha++){
        cout << linha << "  - ";
        for(coluna = 0; coluna < 6; coluna++){

        switch(tabuleiro[linha][coluna]){
        case 'M': cout << azul << " " << tabuleiro[linha][coluna] << branco; break;
        case 'B': cout << verde << " " << tabuleiro[linha][coluna] << branco; break;
        case 'N': cout << amarelo << " " << tabuleiro[linha][coluna] << branco; break;
        default:  cout << " " << tabuleiro[linha][coluna] << branco; break;
        }
        }
        cout << "\n";
        }
        }


    void jogo3(){

        char tabuleiro[6][6], mascara[6][6];
        int tentativas = 0, maxTentativas = 8;
        int linhaJogada, colunaJogada;
        int pontos = 0;
        int opcao;


        iniciaTabuleiro3(tabuleiro, mascara);
        posicionaInimigos3(tabuleiro);

        while(tentativas < maxTentativas){

        limpaTela();

        exibeTabuleiro3(tabuleiro, mascara);

        cout << "\nPontos: " << pontos;
        cout << "\nMunição: " << (maxTentativas - tentativas);
        cout << "\n\nDigite uma linha: ";
        cin >> linhaJogada;

        if(cin.fail()) {
        limpaTela();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
        }

        while(linhaJogada < 0 || linhaJogada > 5){
        limpaTela();
        exibeTabuleiro3(tabuleiro, mascara);
        cout << "\nPontos: " << pontos;
        cout << "\nMunição: " << maxTentativas - tentativas;
        cout << "\n\n(" << linhaJogada << ") Não se encaixa no limite do tabuleiro.\n";
        cout << "\nDigite uma linha: ";
        cin >> linhaJogada;
        limpaTela();
        exibeTabuleiro3(tabuleiro, mascara);
        cout << "\nPontos: " << pontos;
        cout << "\nMunição: " << maxTentativas - tentativas;
        cout << "\n\nDigite uma linha: " << linhaJogada;
        cout << "\n";
        }

        cout << "Digite uma coluna: ";
        cin >> colunaJogada;

        if(cin.fail()) {
        limpaTela();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
        }

        while(colunaJogada < 0 || colunaJogada > 5){
        limpaTela();
        exibeTabuleiro3(tabuleiro, mascara);
        cout << "\nPontos: " << pontos;
        cout << "\nMunição: " << maxTentativas - tentativas;
        cout << "\n\nDigite uma linha: " << linhaJogada;
        cout << "\n\n(" << colunaJogada << ") Não se encaixa no limite do tabuleiro.\n";
        cout << "\nDigite uma coluna: ";
        cin >> colunaJogada;
        limpaTela();
        exibeTabuleiro3(tabuleiro, mascara);
        }

        if(mascara[linhaJogada][colunaJogada] != '~') {
            continue;
        }

        if(tabuleiro[linhaJogada][colunaJogada] == 'B'){
            pontos += 10;

        } else if(tabuleiro[linhaJogada][colunaJogada] == 'N'){
            pontos += 20;
        }

        mascara[linhaJogada][colunaJogada] = tabuleiro [linhaJogada][colunaJogada];
        tentativas++;

        if(tentativas == maxTentativas && pontos < 30){
        limpaTela();
        exibeTabuleiro3(tabuleiro, mascara);
        cout << "\nPontos: " << pontos;
        cout << "\nMunição: " << maxTentativas - maxTentativas;
        cout << vermelho;
        cout << "\n\nQue pena! Você perdeu!";
        cout << branco;
        cout << "\n\n(1) Ver gabarito, (2) Jogar novamente, (3) Selecionar nível, (4) Sair: ";
        cin >> opcao;

        while(opcao == 1){
        limpaTela();
        gabarito3(tabuleiro);
        cout << "\n\n(1) Jogar novamente, (2) Selecionar nível, (3) Sair: ";
        cin >> opcao;

        if(opcao == 1){
        limpaTela();
        jogo3();
        return;
        }else if(opcao == 2){
        limpaTela();
        return;
        }else{
        cout << "\n Até logo!\n";
        exit(0);
        }
        break;
        }

        if(opcao == 2){
        limpaTela();
        jogo3();
        return;
        }else if(opcao == 3){
        limpaTela();
        return;
        }else{
        cout << "\n Até logo!\n";
        exit(0);
        }
        }

        if(pontos >= 30){
        limpaTela();
        exibeTabuleiro3(tabuleiro, mascara);
        cout << "\nPontos: " << pontos;
        cout << "\nMunição: " << maxTentativas - tentativas;
        cout << verde;
        cout << "\n\nParabéns, você ganhou!";
        cout << branco;
        cout << "\n\n(1) Ver gabarito, (2) Jogar novamente, (3) Mudar dificuldade, (4) Sair: ";
        cin >> opcao;
        limpaTela();

        while(opcao == 1){
        limpaTela();
        gabarito3(tabuleiro);
        cout << "\n\n(1) Jogar novamente, (2) Selecionar nível, (3) Sair: ";
        cin >> opcao;

        if(opcao == 1){
        limpaTela();
        jogo3();
        return;
        }else if(opcao == 2){
        limpaTela();
        return;
        }else{
        cout << "\n Até logo!\n";
        exit(0);
        }
        break;
        }

        if(opcao == 2){
        limpaTela();
        jogo3();
        }else if(opcao == 3){
        limpaTela();
        return;
        }else{
        cout << "\n Até logo!\n";
        exit(0);
        }
        }
        }
        }


    void nivel(){

        limpaTela();

        int dificuldade = 0;

        while(dificuldade != 4 && dificuldade != 5){
        cout << amarelo;
        cout << "\n Qual nível?\n";
        cout << azulmarinho;
        cout << "\n 1 - Fácil (4x4)\n";
        cout << roxo;
        cout << " 2 - Médio (5x5)\n";
        cout << vermelho;
        cout << " 3 - Difícil (6x6)\n";
        cout << branco;
        cout << "\nclique 4 para voltar ao menu ou 5 para sair do jogo...";
        cout << "\n\nEscolha uma opção e tecle ENTER: ";
        cin >> dificuldade;

        if(cin.fail()) {
        limpaTela();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
        }

        if(dificuldade == 1){
        jogo();
        }else if(dificuldade == 2) {
        jogo2();
        }else if(dificuldade == 3){
        jogo3();
        }else if(dificuldade == 4){
        limpaTela();
        }

        else if(dificuldade == 5) {
        cout << "\n\nAté logo!\n";
        exit(0);
        }else{
        nivel();
        }
        }
        }


    void menuInicial(){

        char escolha = 's' || 'S';
        cout << branco;

        int opcao = 0;

        while(opcao != 4){
        cout << amarelo;
        cout << "Bem vindo à Batalha Naval!";
        cout << branco;
        cout << "\n\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Detalhes";
        cout << "\n4 - Sair";
        cout << "\n\nEscolha uma opção e tecle ENTER: ";
        cin >> opcao;

        if(cin.fail()) {
        limpaTela();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
        }

        switch(opcao){

            case 1:
            nivel();
            break;

            case 2:
            limpaTela();
            cout << amarelo;
            cout << "\n Bem vindo à Batalha Naval!\n";
            cout << branco;
            cout << "\n\nPiratas estão tentando invadir sua ilha! Acerte barcos e navios para vencê-los!\n\n";
            cout << "\n   Existem três níveis:\n";
            cout << azulmarinho;
            cout << "\n - Fácil (tabuleiro 4x4 = 12 posições)\n";
            cout << " - ";
            cout << branco;
            cout << "3 barcos, 4 navios e 6 munições para atacar\n";
            cout << roxo;
            cout << "\n - Médio (tabuleiro 5x5 = 25 posições)\n";
            cout << " - ";
            cout << branco;
            cout << "6 barcos, 3 navios e 7 munições para atacar\n";
            cout << vermelho;
            cout << "\n - Difícil (tabuleiro 6x6 = 36 posições)\n";
            cout << vermelho;
            cout << " - ";
            cout << branco;
            cout << "8 barcos, 2 navios e 8 munições para atacar\n";
            cout << "\n\nEm qualquer dificuldade, você precisa de 30 pontos pra vencer.\n";
            cout << azul;
            cout << "\nMar (M)";
            cout << branco;
            cout << " vale 0 pontos,";
            cout << verde;
            cout << " Barcos (B)";
            cout << branco;
            cout << " valem 10 pontos, e";
            cout << amarelo;
            cout << " Navios (N)";
            cout << branco;
            cout << " valem 20 pontos!\n";
            cout << branco;
            cout << "\n\nDeseja voltar ao menu? (s/n): ";
            cin >> escolha;

            if(escolha == 's' || escolha == 'S'){
            limpaTela();
            menuInicial();
            }else{
            cout << "\n\nAté logo!\n";
            exit(0);
            }
            break;

            case 3:
            limpaTela();
            cout << amarelo;
            cout << "\n Desenvolvido por Gustagols";
            cout << verde;
            cout << "\n Linguagem: C++";
            cout << "\n Bibliotecas C: #include <time.h> e #include <locale.h>";
            cout << vermelho;
            cout << "\n\n Sugestões sobre o jogo: ";
            cout << "\n\n- ";
            cout << branco;
            cout << "O jogo poderia exibir uma mensagem quando o usuário\n";
            cout << " acertasse o Mar, um Barco, ou um Navio, como:\n";
            cout << azul;
            cout << "\n Você acertou o Mar!    (+0 pts)";
            cout << verde;
            cout << "\n Você acertou um Barco! (+10 pts)";
            cout << amarelo;
            cout << "\n Você acertou um Navio! (+20 pts)";
            cout << vermelho;
            cout << "\n\n- ";
            cout << branco;
            cout << "O jogo poderia ter um algoritmo que separasse melhor os barcos e navios.";
            cout << vermelho;
            cout << "\n\n- ";
            cout << branco;
            cout << "O jogo poderia ter um timer de 30 segundos para o usuário fazer suas jogadas, \n simulando assim a aproximação dos piratas à ilha.";
            cout << vermelho;
            cout << "\n\n- ";
            cout << branco;
            cout <<"Idealmente, o código não deveria repetir para que cada dificuldade selecionada funcionasse,\n";
            cout << " isso causou que o programa ficasse + ou - 3 vezes maior que do ele deveria ser.";
            cout << azulmarinho;
            cout << "\n\n\nPor último, se você apertar Ctrl + C quando o programa estiver esperando um número, clique ENTER em seguida, tudo deve voltar ao normal.";
            cout << "\nSe você apertar Ctrl + C quando o programa estiver esperando uma letra, ele provavelmente será encerrado.";
            cout << branco;
            cout << "\n\n\nDeseja voltar ao menu? (s/n): ";
            cin >> escolha;

            if(escolha == 's' || escolha == 'S'){
            limpaTela();
            menuInicial();
            }else{
            cout << "\n\nAté logo!\n";
            exit(0);
            }
            break;


            case 4:
            cout << "\n\nAté logo!\n";
            exit(0);
            break;


            default:
            limpaTela();
            menuInicial();
            break;
            }
            }
            }


        int main(){
        setlocale(LC_ALL, "pt_BR.UTF-8");
        srand((unsigned)time(NULL));
        menuInicial();
        return 0;
        }




