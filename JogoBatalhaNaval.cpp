#include <iostream>
#include <cstdlib>
#include <limits>
#include <time.h>
#include <locale.h>


    // BATALHA NAVAL;


    // CORES DO JOGO

    char red[] = { 0x1b, '[', '1', ';', '3', '1', 'm', 0 };
    char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
    char yellow[] = { 0x1b, '[', '1', ';', '3', '3', 'm', 0 };
    char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char purple[] = { 0x1b, '[', '1', ';', '3', '5', 'm', 0 };
    char lightblue[] = { 0x1b, '[', '1', ';', '3', '6', 'm', 0 };
    char normal[] = { 0x1b, '[', '1', ';', '3', '9', 'm', 0 };


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

        cout << yellow;
        cout << "Faça 30 pontos para ganhar o jogo!";
        cout << lightblue;
        cout << " - Fácil\n\n";
        cout << yellow;

        int cont;

        for(cont = 0; cont < 4; cont++){
        if(cont == 0){
        cout << "      ";
        }
        cout << cont << " " << yellow;
        }
        cout << "\n";

        for(cont = 0; cont < 4; cont++){
        if(cont == 0){
        cout << "      " << lightblue;
        }
        cout << "| " << lightblue;
        }
        cout << " \n";
        cout << normal;


        int linha, coluna;

        for(linha = 0; linha < 4; linha++){
        cout << linha << "  - ";
        for(coluna = 0; coluna < 4; coluna++){


        switch(mascara[linha][coluna]){

        case 'M': cout << blue << " " << mascara[linha][coluna] << normal; break;
        case 'B': cout << green << " " << mascara[linha][coluna] << normal; break;
        case 'N': cout << yellow << " " << mascara[linha][coluna] << normal; break;
        default:  cout << " " << mascara[linha][coluna] << normal; break;
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

        cout << lightblue;
        cout << "\n     Gabarito\n\n";

        int cont;

        for(cont = 0; cont < 4; cont++){
        if(cont == 0){
        cout << yellow;
        cout << "      ";
        }
        cout << cont << " " << yellow;
        }
        cout << "\n";


        for(cont = 0; cont < 4; cont++){
        if(cont == 0){
        cout << "      " << lightblue;
        }
        cout << "| " << lightblue;
        }
        cout << "\n";
        cout << normal;


        int linha, coluna;

        for(linha = 0; linha < 4; linha++){
        cout << linha << "  - ";
        for(coluna = 0; coluna < 4; coluna++){


        switch(tabuleiro[linha][coluna]){

        case 'M': cout << blue << " " << tabuleiro[linha][coluna] << normal; break;
        case 'B': cout << green << " " << tabuleiro[linha][coluna] << normal; break;
        case 'N': cout << yellow << " " << tabuleiro[linha][coluna] << normal; break;
        default:  cout << " " << tabuleiro[linha][coluna] << normal; break;
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
            pontos = pontos + 10;

        }else if(tabuleiro[linhaJogada][colunaJogada] == 'N'){
            pontos = pontos + 20;
        }

        mascara[linhaJogada][colunaJogada] = tabuleiro [linhaJogada][colunaJogada];
        tentativas++;

        if(tentativas == maxTentativas && pontos < 30){
        limpaTela();
        exibeTabuleiro(tabuleiro, mascara);
        cout << "\nPontos: " << pontos;
        cout << "\nMunição: " << maxTentativas -5;
        cout << red;
        cout << "\n\nQue pena! Você perdeu!";
        cout << normal;
        cout << "\n\n(1) Ver gabarito, (2) Jogar novamente, (3) Mudar dificuldade, (4) Sair: ";
        cin >> opcao;

        while(opcao == 1){
        limpaTela();
        gabarito(tabuleiro);
        cout << "\n(1) Jogar novamente, (2) Mudar dificuldade, (3) Sair: ";
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

        if(pontos>=30){
        limpaTela();
        exibeTabuleiro(tabuleiro, mascara);
        cout << "\nPontos: " << pontos;
        cout << green;
        cout << "\n\nParabéns, você ganhou!";
        cout << normal;
        cout << "\n\n(1) Ver gabarito, (2) Jogar novamente, (3) Mudar dificuldade, (4) Sair: ";
        cin >> opcao;
        limpaTela();


        while(opcao == 1){
        limpaTela();
        gabarito(tabuleiro);
        cout << "\n(1) Jogar novamente, (2) Mudar dificuldade, (3) Sair: ";
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

    void iniciaTabuleiro2 (char tabuleiro[5][5], char mascara[5][5]){

        int linha, coluna;
        for(linha = 0; linha < 5; linha++){
        for(coluna = 0; coluna < 5; coluna++){
        tabuleiro[linha][coluna] = 'M';
        mascara[linha][coluna] = '~';
        }
        }
        }

    void exibeTabuleiro2 (char tabuleiro[5][5], char mascara[5][5]){

        cout << yellow;
        cout << "\nFaça 30 pontos para ganhar o jogo!";
        cout << purple;
        cout << " - Médio\n\n";
        cout << yellow;

        int cont;
        for(cont = 0; cont < 5; cont++){
        if(cont == 0){
        cout << "      ";
        }
        cout << cont << " " << yellow;
        }
        cout << "\n";

        for(cont = 0; cont < 5; cont++){
        if(cont == 0){
        cout << "      " << purple;
        }
        cout << "| " << purple;
        }
        cout << " \n";
        cout << normal;


        int linha, coluna;
        for(linha = 0; linha < 5; linha++){
        cout << linha << "  - ";
        for(coluna = 0; coluna < 5; coluna++){

        switch(mascara[linha][coluna]){
        case 'M': cout << blue << " " << mascara[linha][coluna] << normal; break;
        case 'B': cout << green << " " << mascara[linha][coluna] << normal; break;
        case 'N': cout << yellow << " " << mascara[linha][coluna] << normal; break;
        default:  cout << " " << mascara[linha][coluna] << normal; break;
        }
        }
        cout << "\n";
        }
        }


    void posicionaInimigos2 (char tabuleiro[5][5]){

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

        cout << purple;
        cout << "\n      Gabarito\n\n";

        int cont;
        for(cont = 0; cont < 5; cont++){
        if(cont == 0){
        cout << yellow;
        cout << "      ";
        }
        cout << cont << " " << yellow;
        }
        cout << "\n";

        for(cont = 0; cont < 5; cont++){
        if(cont == 0){
        cout << "      " << purple;
        }
        cout << "| " << purple;
        }
        cout << "\n";
        cout << normal;


        int linha, coluna;

        for(linha = 0; linha < 5; linha++){
        cout << linha << "  - ";
        for(coluna = 0; coluna < 5; coluna++){

        switch(tabuleiro[linha][coluna]){
        case 'M': cout << blue << " " << tabuleiro[linha][coluna] << normal; break;
        case 'B': cout << green << " " << tabuleiro[linha][coluna] << normal; break;
        case 'N': cout << yellow << " " << tabuleiro[linha][coluna] << normal; break;
        default:  cout << " " << tabuleiro[linha][coluna] << normal; break;
        }
        }
        cout << "\n";
        }
        }


    void jogo2(){

        char tabuleiro[5][5], mascara[5][5];
        int linhaJogada, colunaJogada;
        int pontos = 0;
        int opcao;
        int tentativas = 0, maxTentativas = 7;

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
        pontos = pontos + 10;
        }

        else if(tabuleiro[linhaJogada][colunaJogada] == 'N'){
        pontos = pontos + 20;
        }

        mascara[linhaJogada][colunaJogada] = tabuleiro [linhaJogada][colunaJogada];
        tentativas++;

        if(tentativas == maxTentativas && pontos < 30){
        limpaTela();
        exibeTabuleiro2(tabuleiro, mascara);
        cout << "\nPontos: " << pontos;
        cout << "\nMunição: " << maxTentativas -5;
        cout << red;
        cout << "\n\nQue pena! Você perdeu!";
        cout << normal;
        cout << "\n\n(1) Ver gabarito, (2) Jogar novamente, (3) Mudar dificuldade, (4) Sair: ";
        cin >> opcao;

        while(opcao == 1){
        limpaTela();
        gabarito2(tabuleiro);
        cout << "\n(1) Jogar novamente, (2) Mudar dificuldade, (3) Sair: ";
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

        if(pontos>=30){
        limpaTela();
        exibeTabuleiro2(tabuleiro, mascara);
        cout << "\nPontos: " << pontos;
        cout << green;
        cout << "\n\nParabéns, você ganhou!";
        cout << normal;
        cout << "\n\n(1) Ver gabarito, (2) Jogar novamente, (3) Mudar dificuldade, (4) Sair: ";
        cin >> opcao;
        limpaTela();

        while(opcao == 1){
        limpaTela();
        gabarito2(tabuleiro);
        cout << "\n(1) Jogar novamente, (2) Mudar dificuldade, (3) Sair: ";
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

    void iniciaTabuleiro3 (char tabuleiro[6][6], char mascara[6][6]){

        int linha, coluna;
        for(linha = 0; linha < 6; linha++){
        for(coluna = 0; coluna < 6; coluna++){
        tabuleiro[linha][coluna] = 'M';
        mascara[linha][coluna] = '~';
        }
        }
        }


    void exibeTabuleiro3 (char tabuleiro[6][6], char mascara[6][6]){

        cout << yellow;
        cout << "\nFaça 30 pontos para ganhar o jogo!";
        cout << red;
        cout << " - Difícil\n\n";
        cout << yellow;

        int cont;

        for(cont = 0; cont < 6; cont++){
        if(cont == 0){
        cout << "      ";
        }
        cout << cont << " " << yellow;
        }
        cout << "\n";

        for(cont = 0; cont < 6; cont++){
        if(cont == 0){
        cout << "      " << red;
        }
        cout << "| " << red;
        }
        cout << " \n";
        cout << normal;


        int linha, coluna;

        for(linha = 0; linha < 6; linha++){
        cout << linha << "  - ";
        for(coluna = 0; coluna < 6; coluna++){

        switch(mascara[linha][coluna]){
        case 'M': cout << blue << " " << mascara[linha][coluna] << normal; break;
        case 'B': cout << green << " " << mascara[linha][coluna] << normal; break;
        case 'N': cout << yellow << " " << mascara[linha][coluna] << normal; break;
        default:  cout << " " << mascara[linha][coluna] << normal; break;
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

        cout << red;
        cout << "\n       Gabarito\n\n";

        int cont;
        for(cont = 0; cont < 6; cont++){
        if(cont == 0){
        cout << yellow;
        cout << "      ";
        }
        cout << cont << " " << yellow;
        }
        cout << "\n";

        for(cont = 0; cont < 6; cont++){
        if(cont == 0){
        cout << "      " << red;
        }
        cout << "| " << red;
        }
        cout << "\n";
        cout << normal;


        int linha, coluna;

        for(linha = 0; linha < 6; linha++){
        cout << linha << "  - ";
        for(coluna = 0; coluna < 6; coluna++){

        switch(tabuleiro[linha][coluna]){
        case 'M': cout << blue << " " << tabuleiro[linha][coluna] << normal; break;
        case 'B': cout << green << " " << tabuleiro[linha][coluna] << normal; break;
        case 'N': cout << yellow << " " << tabuleiro[linha][coluna] << normal; break;
        default: cout << " " << tabuleiro[linha][coluna] << normal; break;
        }
        }
        cout << "\n";
        }
        }


    void jogo3(){

        char tabuleiro[6][6], mascara[6][6];
        int linhaJogada, colunaJogada;
        int pontos = 0;
        int opcao;
        int tentativas = 0, maxTentativas = 8;

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
        pontos = pontos + 10;

        } else if(tabuleiro[linhaJogada][colunaJogada] == 'N'){
        pontos = pontos + 20;
        }

        mascara[linhaJogada][colunaJogada] = tabuleiro [linhaJogada][colunaJogada];
        tentativas++;

        if(tentativas == maxTentativas && pontos < 30){
        limpaTela();
        exibeTabuleiro3(tabuleiro, mascara);
        cout << "\nPontos: " << pontos;
        cout << "\nMunição: " << maxTentativas -5;
        cout << red;
        cout << "\n\nQue pena! Você perdeu!";
        cout << normal;
        cout << "\n\n(1) Ver gabarito, (2) Jogar novamente, (3) Mudar dificuldade, (4) Sair: ";
        cin >> opcao;

        while(opcao == 1){
        limpaTela();
        gabarito3(tabuleiro);
        cout << "\n(1) Jogar novamente, (2) Mudar dificuldade, (3) Sair: ";
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

        if(pontos>=30){
        limpaTela();
        exibeTabuleiro3(tabuleiro, mascara);
        cout << "\nPontos: " << pontos;
        cout << green;
        cout << "\n\nParabéns, você ganhou!";
        cout << normal;
        cout << "\n\n(1) Ver gabarito, (2) Jogar novamente, (3) Mudar dificuldade, (4) Sair: ";
        cin >> opcao;
        limpaTela();

        while(opcao == 1){
        limpaTela();
        gabarito3(tabuleiro);
        cout << "\n(1) Jogar novamente, (2) Mudar dificuldade, (3) Sair: ";
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
        cout << yellow;
        cout << "\n Qual dificuldade?\n";
        cout << lightblue;
        cout << "\n 1 - Fácil (4x4)\n";
        cout << purple;
        cout << " 2 - Médio (5x5)\n";
        cout << red;
        cout << " 3 - Difícil (6x6)\n";
        cout << normal;
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
        cout << normal;

        int opcao = 0;

        while(opcao != 4){
        cout << yellow;
        cout << "Bem vindo à Batalha Naval!";
        cout << normal;
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
            cout << yellow;
            cout << "\n Bem vindo à Batalha Naval!\n";
            cout << normal;
            cout << "\n\nPiratas estão tentando invadir sua ilha! Acerte barcos e navios para vencê-los!\n";
            cout << "\nExistem três níveis de dificuldades:\n\n";
            cout << lightblue;
            cout << "\n - Fácil (tabuleiro 4x4 = 12 posições)\n";
            cout << " - ";
            cout << normal;
            cout << "3 barcos, 4 navios e 6 munições para atacar\n";
            cout << purple;
            cout << "\n - Médio (tabuleiro 5x5 = 25 posições)\n";
            cout << " - ";
            cout << normal;
            cout << "6 barcos, 3 navios e 7 munições para atacar\n";
            cout << red;
            cout << "\n - Difícil (tabuleiro 6x6 = 36 posições)\n";
            cout << red;
            cout << " - ";
            cout << normal;
            cout << "8 barcos, 2 navios e 8 munições para atacar\n";
            cout << "\n\nEm qualquer dificuldade, você precisa de 30 pontos pra vencer.\n";
            cout << blue;
            cout << "\nMar (M)";
            cout << normal;
            cout << " vale 0 pontos,";
            cout << green;
            cout << " Barcos (B)";
            cout << normal;
            cout << " valem 10 pontos, e";
            cout << yellow;
            cout << " Navios (N)";
            cout << normal;
            cout << " valem 20 pontos!\n";
            cout << normal;
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
            cout << yellow;
            cout << "\n Desenvolvido por Gustagols";
            cout << green;
            cout << "\n Linguagem: C++";
            cout << "\n Bibliotecas C: #include <time.h> e #include <locale.h>";
            cout << red;
            cout << "\n\n Sugestões sobre o jogo: ";
            cout << "\n\n- ";
            cout << normal;
            cout << "O jogo poderia exibir uma mensagem quando o usuário\n";
            cout << " acertasse o Mar, um Barco, ou um Navio, como:\n";
            cout << blue;
            cout << "\n Você acertou o Mar!    (+0 pts)";
            cout << green;
            cout << "\n Você acertou um Barco! (+10 pts)";
            cout << yellow;
            cout << "\n Você acertou um Navio! (+20 pts)";
            cout << red;
            cout << "\n\n- ";
            cout << normal;
            cout << "O jogo poderia ter um algoritmo que separasse melhor os barcos e navios.";
            cout << red;
            cout << "\n\n- ";
            cout << normal;
            cout << "O jogo poderia ter um timer de 30 segundos para o usuário fazer suas jogadas, \n simulando assim a aproximação dos piratas à ilha.";
            cout << red;
            cout << "\n\n- ";
            cout << normal;
            cout <<"Idealmente, o código não deveria repetir para que cada dificuldade selecionada funcionasse,\n";
            cout << " isso causou que o programa ficasse + ou - 3 vezes maior que do ele deveria ser.";
            cout << lightblue;
            cout << "\n\n\nPor último, se você apertar Ctrl + C quando o programa estiver esperando um número, clique ENTER em seguida, tudo deve voltar ao normal.";
            cout << "\nSe você apertar Ctrl + C quando o programa estiver esperando uma letra, ele provavelmente será encerrado.";
            cout << normal;
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





