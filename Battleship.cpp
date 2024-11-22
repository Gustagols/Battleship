#include <iostream>
#include <cstdlib>
#include <limits>
#include <time.h>


    // BATTLESHIP;

    // ROW INSTEAD OF LINE

    // COLORS OF THE GAME

    char red[] = { 0x1b, '[', '1', ';', '3', '1', 'm', 0 };
    char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
    char yellow[] = { 0x1b, '[', '1', ';', '3', '3', 'm', 0 };
    char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char purple[] = { 0x1b, '[', '1', ';', '3', '5', 'm', 0 };
    char lightblue[] = { 0x1b, '[', '1', ';', '3', '6', 'm', 0 };
    char white[] = { 0x1b, '[', '1', ';', '3', '9', 'm', 0 };


    void cleanScreen(){
     #ifdef _WIN32
        system("CLS"); // Windows
    #else
        system("clear"); // Linux and MacOS
    #endif
    }


    using namespace std;


    //   EASY LEVEL

    void initializeBoard (char board[4][4], char mask[4][4]){

        int row, column;
        for(row = 0; row < 4; row++){
        for(column = 0; column < 4; column++){
        board[row][column] = 'W';
        mask[row][column] = '~';
        }
        }
        }


   void showBoard(char board[4][4], char mask[4][4]){

        cout << yellow;
        cout << "Make 30 points to beat the game!";
        cout << lightblue;
        cout << " - Easy\n\n";
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
        cout << white;


        int row, column;

        for(row = 0; row < 4; row++){
        cout << row << "  - ";
        for(column = 0; column < 4; column++){


        switch(mask[row][column]){

        case 'W': cout << blue << " " << mask[row][column] << white; break;
        case 'B': cout << green << " " << mask[row][column] << white; break;
        case 'S': cout << yellow << " " << mask[row][column] << white; break;
        default:  cout << " " << mask[row][column] << white; break;
        }
        }
        cout << "\n";
        }
        }


    void enemyPosition(char board[4][4]){

        int boatQuantity = 3, boatsPositioned = 0;

        while(boatsPositioned < boatQuantity){

        int boatRow = rand()%4;
        int boatColumn = rand()%4;

        if(board[boatRow][boatColumn] == 'W'){
           board[boatRow][boatColumn] = 'B';
           boatsPositioned++;
        }
        }

        int shipQuantity = 4, shipsPositioned = 0;

        while(shipsPositioned < shipQuantity){

        int shipRow = rand()%4;
        int shipColumn = rand()%4;

        if(board[shipRow][shipColumn] == 'W'){
            board[shipRow][shipColumn] = 'S';
            shipsPositioned++;
        }
        }
        }


    void checkBoard(char board[4][4]){

        cout << lightblue;
        cout << "\n       Board\n\n";

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
        cout << white;


        int row, column;

        for(row = 0; row < 4; row++){
        cout << row << "  - ";
        for(column = 0; column < 4; column++){


        switch(board[row][column]){

        case 'W': cout << blue << " " << board[row][column] << white; break;
        case 'B': cout << green << " " << board[row][column] << white; break;
        case 'S': cout << yellow << " " << board[row][column] << white; break;
        default:  cout << " " << board[row][column] << white; break;
        }
        }
        cout << "\n";
        }
        }


    void game(){

        char board[4][4], mask[4][4];
        int attempts = 0, maxAttempts = 6;
        int rowPlayed, columnPlayed;
        int points = 0;
        int option;


        initializeBoard(board, mask);
        enemyPosition(board);

        while(attempts < maxAttempts){

        cleanScreen();

        showBoard(board, mask);

        cout << "\nPoints: " << points;
        cout << "\nAmmunition: " << (maxAttempts - attempts);

        cout << "\n\nInsert a row: ";
        cin >> rowPlayed;

        if(cin.fail()) {
        cleanScreen();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
        }

        while(rowPlayed < 0 || rowPlayed > 3){
        cleanScreen();
        showBoard(board, mask);
        cout << "\nPoints: " << points;
        cout << "\nAmmunition: " << maxAttempts - attempts;
        cout << "\n\n(" << rowPlayed << ") Doesn't fit on the the board.\n";
        cout << "\nInsert a row: ";
        cin >> rowPlayed;
        cleanScreen();
        showBoard(board, mask);
        cout << "\nPoints: " << points;
        cout << "\nAmmunition: " << maxAttempts - attempts;
        cout << "\n\nInsert a row: " << rowPlayed;
        cout << "\n";
        }

        cout << "Insert a column: ";
        cin >> columnPlayed;

        if(cin.fail()) {
        cleanScreen();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
        }

        while(columnPlayed < 0 || columnPlayed > 3){
        cleanScreen();
        showBoard(board, mask);
        cout << "\nPoints: " << points;
        cout << "\nAmmunition: " << maxAttempts - attempts;
        cout << "\n\nInsert a row: " << rowPlayed;
        cout << "\n\n(" << columnPlayed << ") Doesn't fit on the board.\n";
        cout << "\nInsert a column: ";
        cin >> columnPlayed;
        cleanScreen();
        showBoard(board, mask);
        }

        if (mask[rowPlayed][columnPlayed] != '~') {
            continue;
        }

        if(board[rowPlayed][columnPlayed] == 'B'){
            points += 10;

        }else if(board[rowPlayed][columnPlayed] == 'S'){
            points += 20;
        }

        mask[rowPlayed][columnPlayed] = board[rowPlayed][columnPlayed];
        attempts++;

        if(attempts == maxAttempts && points < 30){
        cleanScreen();
        showBoard(board, mask);
        cout << "\nPoints: " << points;
        cout << "\nAmmunition: " << maxAttempts - maxAttempts;
        cout << red;
        cout << "\n\nWhat a pity! You lost!";
        cout << white;
        cout << "\n\n(1) Check board, (2) Play again, (3) Switch level, (4) Leave: ";
        cin >> option;

        while(option == 1){
        cleanScreen();
        checkBoard(board);
        cout << "\n\n(1) Play again, (2) Switch level, (3) Leave: ";
        cin >> option;

        if(option == 1){
        cleanScreen();
        game();
        return;
        }else if(option == 2){
        cleanScreen();
        return;
        }else{
        cout << "\n See you later!\n";
        exit(0);
        }
        break;
        }

        if(option == 2){
        cleanScreen();
        game();
        return;
        }else if(option == 3){
        cleanScreen();
        return;
        }else{
        cout << "\n See you later!\n";
        exit(0);
        }
        }

        if(points >= 30){
        cleanScreen();
        showBoard(board, mask);
        cout << "\nPoints: " << points;
        cout << "\nAmmunition: " << maxAttempts - attempts;
        cout << green;
        cout << "\n\nCongratulations! You Won!";
        cout << white;
        cout << "\n\n(1) Check board, (2) Play again, (3) Select level, (4) Leave: ";
        cin >> option;
        cleanScreen();


        while(option == 1){
        cleanScreen();
        checkBoard(board);
        cout << "\n\n(1) Play again, (2) Select level, (3) Leave: ";
        cin >> option;

        if(option == 1){
        cleanScreen();
        game();
        return;
        }else if(option == 2){
        cleanScreen();
        return;
        }else{
        cout << "\n See you later!\n";
        exit(0);
        }
        break;
        }

        if(option == 2){
        cleanScreen();
        game();
        return;
        }else if(option == 3){
        cleanScreen();
        return;
        }else{
        cout << "\n See you later!\n";
        exit(0);
        }
        }
        }
        }


    // MEDIUM LEVEL

    void initializeBoard2(char board[5][5], char mask[5][5]){

        int row, column;
        for(row = 0; row < 5; row++){
        for(column = 0; column < 5; column++){
        board[row][column] = 'W';
        mask[row][column] = '~';
        }
        }
        }

    void showBoard2(char board[5][5], char mask[5][5]){

        cout << yellow;
        cout << "\nMake 30 points to beat the game!";
        cout << purple;
        cout << " - Medium\n\n";
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
        cout << white;


        int row, column;
        for(row = 0; row < 5; row++){
        cout << row << "  - ";
        for(column = 0; column < 5; column++){

        switch(mask[row][column]){
        case 'W': cout << blue << " " << mask[row][column] << white; break;
        case 'B': cout << green << " " << mask[row][column] << white; break;
        case 'S': cout << yellow << " " << mask[row][column] << white; break;
        default:  cout << " " << mask[row][column] << white; break;
        }
        }
        cout << "\n";
        }
        }


    void enemyPosition2 (char board[5][5]){

        int boatQuantity = 6, boatsPositioned = 0;

        while(boatsPositioned < boatQuantity){

        int boatRow = rand()%5;
        int boatColumn = rand()%5;

        if(board[boatRow][boatColumn] == 'W'){
           board[boatRow][boatColumn] = 'B';
           boatsPositioned++;
        }
        }

        int shipQuantity = 3, shipsPositioned = 0;

        while(shipsPositioned < shipQuantity){

        int shipRow = rand()%5;
        int shipColumn = rand()%5;

        if(board[shipRow][shipColumn] == 'W'){
            board[shipRow][shipColumn] = 'S';
            shipsPositioned++;
        }
        }
        }


    void checkBoard2(char board[5][5]){

        cout << purple;
        cout << "\n        Board\n\n";

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
        cout << white;


        int row, column;

        for(row = 0; row < 5; row++){
        cout << row << "  - ";
        for(column = 0; column < 5; column++){

        switch(board[row][column]){
        case 'W': cout << blue << " " << board[row][column] << white; break;
        case 'B': cout << green << " " << board[row][column] << white; break;
        case 'S': cout << yellow << " " << board[row][column] << white; break;
        default:  cout << " " << board[row][column] << white; break;
        }
        }
        cout << "\n";
        }
        }


    void game2(){

        char board[5][5], mask[5][5];
        int rowPlayed, columnPlayed;
        int points = 0;
        int option;
        int attempts = 0, maxAttempts = 7;

        initializeBoard2(board, mask);
        enemyPosition2(board);

        while(attempts < maxAttempts){

        cleanScreen();

        showBoard2(board, mask);

        cout << "\nPoints: " << points;
        cout << "\nAmmunition: " << (maxAttempts - attempts);
        cout << "\n\nInsert a row: ";
        cin >> rowPlayed;

        if(cin.fail()) {
        cleanScreen();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
        }

        while(rowPlayed < 0 || rowPlayed > 4){
        cleanScreen();
        showBoard2(board, mask);
        cout << "\nPoints: " << points;
        cout << "\nAmmunition: " << maxAttempts - attempts;
        cout << "\n\n(" << rowPlayed << ") Doesn't fit on the board.\n";
        cout << "\nInsert a row: ";
        cin >> rowPlayed;
        cleanScreen();
        showBoard2(board, mask);
        cout << "\nPoints: " << points;
        cout << "\nAmmunition: " << maxAttempts - attempts;
        cout << "\n\nInsert a row: " << rowPlayed;
        cout << "\n";
        }

        cout << "Insert a column: ";
        cin >> columnPlayed;

        if(cin.fail()) {
        cleanScreen();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
        }

        while(columnPlayed < 0 || columnPlayed > 4){
        cleanScreen();
        showBoard2(board, mask);
        cout << "\nPoints: " << points;
        cout << "\nAmmunition: " << maxAttempts - attempts;
        cout << "\n\nInsert a row: " << rowPlayed;
        cout << "\n\n(" << columnPlayed << ") Doesn't fit on the board.\n";
        cout << "\nInsert a row: ";
        cin >> columnPlayed;
        cleanScreen();
        showBoard2(board, mask);
        }

        if (mask[rowPlayed][columnPlayed] != '~') {
            continue;
        }

        if(board[rowPlayed][columnPlayed] == 'B'){
            points += 10;
        }

        else if(board[rowPlayed][columnPlayed] == 'S'){
            points += 20;
        }

        mask[rowPlayed][columnPlayed] = board[rowPlayed][columnPlayed];
            attempts++;

        if(attempts == maxAttempts && points < 30){
        cleanScreen();
        showBoard2(board, mask);
        cout << "\nPoints: " << points;
        cout << "\nAmmunition: " << maxAttempts - maxAttempts;
        cout << red;
        cout << "\n\nWhat a pity! You lost!";
        cout << white;
        cout << "\n\n(1) Check board, (2) Play again, (3) Select level, (4) Leave: ";
        cin >> option;

        while(option == 1){
        cleanScreen();
        checkBoard2(board);
        cout << "\n\n(1) Play again, (2) Select level, (3) Leave: ";
        cin >> option;

        if(option == 1){
        cleanScreen();
        game2();
        return;
        }else if(option == 2){
        cleanScreen();
        return;
        }else{
        cout << "\n See you later!\n";
        exit(0);
        }
        break;
        }

        if(option == 2){
        cleanScreen();
        game2();
        return;
        }else if(option == 3){
        cleanScreen();
        return;
        }else{
        cout << "\n See you later!\n";
        exit(0);
        }
        }

        if(points >= 30){
        cleanScreen();
        showBoard2(board, mask);
        cout << "\nPoints: " << points;
        cout << "\nAmmunition: " << maxAttempts - attempts;
        cout << green;
        cout << "\n\nCongratulations! You won!";
        cout << white;
        cout << "\n\n(1) Check board, (2) Play again, (3) Select level, (4) Leave: ";
        cin >> option;
        cleanScreen();

        while(option == 1){
        cleanScreen();
        checkBoard2(board);
        cout << "\n\n(1) Play again, (2) Select level, (3) Leave: ";
        cin >> option;

        if(option == 1){
        cleanScreen();
        game2();
        return;
        }else if(option == 2){
        cleanScreen();
        return;
        }else{
        cout << "\n See you later!\n";
        exit(0);
        }
        break;
        }

        if(option == 2){
        cleanScreen();
        game2();
        }else if(option == 3){
        cleanScreen();
        return;
        }else{
        cout << "\n See you later!\n";
        exit(0);
        }
        }
        }
        }


    // HARD LEVEL

    void initializeBoard3(char board[6][6], char mask[6][6]){

        int row, column;
        for(row = 0; row < 6; row++){
        for(column = 0; column < 6; column++){
        board[row][column] = 'W';
        mask[row][column] = '~';
        }
        }
        }


    void showBoard3(char board[6][6], char mask[6][6]){

        cout << yellow;
        cout << "\nMake 30 points to beat the game!";
        cout << red;
        cout << " - Hard\n\n";
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
        cout << white;


        int row, column;

        for(row = 0; row < 6; row++){
        cout << row << "  - ";
        for(column = 0; column < 6; column++){

        switch(mask[row][column]){
        case 'W': cout << blue << " " << mask[row][column] << white; break;
        case 'B': cout << green << " " << mask[row][column] << white; break;
        case 'S': cout << yellow << " " << mask[row][column] << white; break;
        default:  cout << " " << mask[row][column] << white; break;
        }
        }
        cout << "\n";
        }
        }


    void enemyPosition3 (char board[6][6]){

        int boatQuantity = 9, boatsPositioned = 0;

        while(boatsPositioned < boatQuantity){

        int boatRow = rand()%6;
        int boatColumn = rand()%6;

        if(board[boatRow][boatColumn] == 'W'){
           board[boatRow][boatColumn] = 'B';
           boatsPositioned++;
        }
        }

        int shipQuantity = 2, shipsPositioned = 0;

        while(shipsPositioned < shipQuantity){

        int shipRow = rand()%6;
        int shipColumn = rand()%6;

        if(board[shipRow][shipColumn] == 'W'){
            board[shipRow][shipColumn] = 'S';
            shipsPositioned++;
            }
            }
        }


    void checkBoard3(char board[6][6]){

        cout << red;
        cout << "\n         Board\n\n";

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
        cout << white;


        int row, column;

        for(row = 0; row < 6; row++){
        cout << row << "  - ";
        for(column = 0; column < 6; column++){

        switch(board[row][column]){
        case 'W': cout << blue << " " << board[row][column] << white; break;
        case 'B': cout << green << " " << board[row][column] << white; break;
        case 'S': cout << yellow << " " << board[row][column] << white; break;
        default: cout << " " << board[row][column] << white; break;
        }
        }
        cout << "\n";
        }
        }


    void game3(){

        char board[6][6], mask[6][6];
        int rowPlayed, columnPlayed;
        int points = 0;
        int option;
        int attempts = 0, maxAttempts = 8;

        initializeBoard3(board, mask);
        enemyPosition3(board);

        while(attempts < maxAttempts){

        cleanScreen();

        showBoard3(board, mask);

        cout << "\nPoints: " << points;
        cout << "\nAmmunition: " << (maxAttempts - attempts);
        cout << "\n\nInsert a row: ";
        cin >> rowPlayed;

        if(cin.fail()) {
        cleanScreen();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
        }

        while(rowPlayed < 0 || rowPlayed > 5){
        cleanScreen();
        showBoard3(board, mask);
        cout << "\nPoints: " << points;
        cout << "\nAmmunition: " << maxAttempts - attempts;
        cout << "\n\n(" << rowPlayed << ") Doesn't fit on the board.\n";
        cout << "\nInsert a row: ";
        cin >> rowPlayed;
        cleanScreen();
        showBoard3(board, mask);
        cout << "\nPoints: " << points;
        cout << "\nAmmunition: " << maxAttempts - attempts;
        cout << "\n\nInsert a row: " << rowPlayed;
        cout << "\n";
        }

        cout << "Insert a column: ";
        cin >> columnPlayed;

        if(cin.fail()) {
        cleanScreen();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
        }

        while(columnPlayed < 0 || columnPlayed > 5){
        cleanScreen();
        showBoard3(board, mask);
        cout << "\nPoints: " << points;
        cout << "\nAmmunition: " << maxAttempts - attempts;
        cout << "\n\nInsert a row: " << rowPlayed;
        cout << "\n\n(" << columnPlayed << ") Doesn't fit on the board.\n";
        cout << "\nInsert a row: ";
        cin >> columnPlayed;
        cleanScreen();
        showBoard3(board, mask);
        }

        if(mask[rowPlayed][columnPlayed] != '~') {
            continue;
        }

        if(board[rowPlayed][columnPlayed] == 'B'){
            points += 10;

        } else if(board[rowPlayed][columnPlayed] == 'S'){
            points += 20;
        }

        mask[rowPlayed][columnPlayed] = board[rowPlayed][columnPlayed];
            attempts++;

        if(attempts == maxAttempts && points < 30){
        cleanScreen();
        showBoard3(board, mask);
        cout << "\nPoints: " << points;
        cout << "\nAmmunition: " << maxAttempts - maxAttempts;
        cout << red;
        cout << "\n\nWhat a pity! You lost!";
        cout << white;
        cout << "\n\n(1) Check board, (2) Play again, (3) Select level, (4) Level: ";
        cin >> option;

        while(option == 1){
        cleanScreen();
        checkBoard3(board);
        cout << "\n\n(1) Play again, (2) Select level, (3) Leave: ";
        cin >> option;

        if(option == 1){
        cleanScreen();
        game3();
        return;
        }else if(option == 2){
        cleanScreen();
        return;
        }else{
        cout << "\n See you later!\n";
        exit(0);
        }
        break;
        }

        if(option == 2){
        cleanScreen();
        game3();
        return;
        }else if(option == 3){
        cleanScreen();
        return;
        }else{
        cout << "\n See you later!\n";
        exit(0);
        }
        }

        if(points >= 30){
        cleanScreen();
        showBoard3(board, mask);
        cout << "\nPoints: " << points;
        cout << "\nAmmunition: " << maxAttempts - attempts;
        cout << green;
        cout << "\n\nCongratulations! You won!";
        cout << white;
        cout << "\n\n(1) Check board, (2) Play again, (3) Select level, (4) Leave: ";
        cin >> option;
        cleanScreen();

        while(option == 1){
        cleanScreen();
        checkBoard3(board);
        cout << "\n\n(1) Play again, (2) Select level, (3) Leave: ";
        cin >> option;

        if(option == 1){
        cleanScreen();
        game3();
        return;
        }else if(option == 2){
        cleanScreen();
        return;
        }else{
        cout << "\n See you later!\n";
        exit(0);
        }
        break;
        }

        if(option == 2){
        cleanScreen();
        game3();
        }else if(option == 3){
        cleanScreen();
        return;
        }else{
        cout << "\n See you later!\n";
        exit(0);
        }
        }
        }
        }


    void selectLevel(){

        cleanScreen();

        int level = 0;

        while(level != 4 && level != 5){
        cout << yellow;
        cout << "\n Which level?\n";
        cout << lightblue;
        cout << "\n 1 - Easy (4x4)\n";
        cout << purple;
        cout << " 2 - Medium (5x5)\n";
        cout << red;
        cout << " 3 - Hard (6x6)\n";
        cout << white;
        cout << "\npress 4 to return to menu or 5 to leave the game...";
        cout << "\n\nInsert an option and hit ENTER: ";
        cin >> level;

        if(cin.fail()) {
        cleanScreen();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
        }

        if(level == 1){
        game();
        }else if(level == 2) {
        game2();
        }else if(level == 3){
        game3();
        }else if(level == 4){
        cleanScreen();
        }
        else if(level == 5) {
        cout << "\n\nSee you later!\n";
        exit(0);
        }else{
        selectLevel();
        }
        }
        }


    void initialMenu(){

        char choice = 'y' || 'Y';
        cout << white;

        int option = 0;

        while(option != 4){
        cout << yellow;
        cout << "Welcome to Battleship!";
        cout << white;
        cout << "\n\n1 - Play";
        cout << "\n2 - About";
        cout << "\n3 - Details";
        cout << "\n4 - Leave";
        cout << "\n\nChoose an option and hit ENTER: ";
        cin >> option;

        if(cin.fail()) {
        cleanScreen();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
        }

        switch(option){

            case 1:
            selectLevel();
            break;

            case 2:
            cleanScreen();
            cout << yellow;
            cout << "\n Welcome to Battleship!\n";
            cout << white;
            cout << "\n\nPirates are trying to invade your island! Hit their boats and ships to beat them!\n\n";
            cout << "\n   There are three levels:\n";
            cout << lightblue;
            cout << "\n - Easy (4x4 board = 12 positions)\n";
            cout << " - ";
            cout << white;
            cout << "3 boats, 4 ships and 6 ammunitions to attack\n";
            cout << purple;
            cout << "\n - Medium (5x5 board = 25 positions)\n";
            cout << " - ";
            cout << white;
            cout << "6 boats, 3 ships and 7 ammunitions to attack\n";
            cout << red;
            cout << "\n - Hard (6x6 board = 36 positions)\n";
            cout << red;
            cout << " - ";
            cout << white;
            cout << "8 boats, 2 ships and 8 ammunitions to attack\n";
            cout << "\n\nIn any level, you need 30 points to win.\n";
            cout << blue;
            cout << "\nWater (W)";
            cout << white;
            cout << " = 0 points,";
            cout << green;
            cout << " Boats (B)";
            cout << white;
            cout << " = 10 points, and";
            cout << yellow;
            cout << " Ships (S)";
            cout << white;
            cout << " = 20 points!\n";
            cout << white;
            cout << "\n";
            cout << "\n\nReturn to menu? (y/n): ";
            cin >> choice;



            if(choice == 'y' || choice == 'Y'){
            cleanScreen();
            initialMenu();
            }else{
            cout << "\n\nSee you later!\n";
            exit(0);
            }
            break;

            case 3:
            cleanScreen();
            cout << yellow;
            cout << "\n Developed by Gustagols";
            cout << green;
            cout << "\n Language: C++";
            cout << "\n Used C Library: #include <time.h>";
            cout << red;
            cout << "\n\n Game suggestions: ";
            cout << "\n\n- ";
            cout << white;
            cout << "The game could show a message when the player\n";
            cout << " hit Water, Boat, or Ship, like:\n";
            cout << blue;
            cout << "\n You hit the Water! (+0 pts)";
            cout << green;
            cout << "\n Yout hit a Boat! (+10 pts)";
            cout << yellow;
            cout << "\n You hit a Ship! (+20 pts)";
            cout << red;
            cout << "\n\n- ";
            cout << white;
            cout << "The game could have a better algorithm to distance boats and ships.";
            cout << red;
            cout << "\n\n- ";
            cout << white;
            cout << "The game could run a 30 seconds timer whenever a player starts a game, \nsimulating the approach of the pirates to the island.";
            cout << red;
            cout << "\n\n- ";
            cout << white;
            cout <<"Ideally, the code shouldn't repeat in order for each option selected to work,\n";
            cout << " this made the program be more or less three times bigger than it should've been.";
            cout << lightblue;
            cout << "\n\n\nFor last, if you press Ctrl + C when the game is expecting a number, click ENTER, you should be fine.";
            cout << "\nIf you press Ctrl + C when the game is expecting a letter, it will probably close the game.";
            cout << white;
            cout << "\n\n\nReturn to menu? (y/n): ";
            cin >> choice;

            if(choice == 'y' || choice == 'Y'){
            cleanScreen();
            initialMenu();
            }else{
            cout << "\n\nSee you later!\n";
            exit(0);
            }
            break;


            case 4:
            cout << "\n\nSee you later!\n";
            exit(0);
            break;


            default:
            cleanScreen();
            initialMenu();
            break;
            }
            }
            }


        int main(){
        srand((unsigned)time(NULL));
        initialMenu();
        return 0;
        }





