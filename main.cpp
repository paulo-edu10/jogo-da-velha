#include <iostream>
#include <string>
#include <time.h>

using namespace std;

char tabuleiro[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
int base_tabuleiro[3][3] = {{1, 2, 3},{4,5,6},{7,8,9}};
bool valida = false;
int contador = 0;
char ganhador;
int jogadas = 0;

void imprimeTabuleiro(){
    cout << "Entre une position" << endl << endl;

    system("cls");
    for(int i=0; i<3;i++){
        for(int j=0;j<3;j++){
            cout << "[" << base_tabuleiro[i][j] << "]\t";
        }
        cout << endl;
    }

    cout << endl << endl;

    for(int i=0; i<3;i++){
        for(int j=0;j<3;j++){
            cout << "[" << tabuleiro[i][j] << "]\t";
        }
        cout << endl;
    }
}

void sleep(time_t atraso){
    time_t tempo1, tempo2;
    time(&tempo1);
    do{
        time(&tempo2);
    }while((tempo2-tempo1)<atraso);
}

void validaPosicao(){
    char testa = 'X';
    int numerador = 0;
    do{
       if(tabuleiro[0][0] == testa && tabuleiro[0][1] == testa && tabuleiro[0][2] == testa){
            valida = true;
            ganhador = testa;
       }else if(tabuleiro[0][0] == testa && tabuleiro[1][1] == testa && tabuleiro[2][2] == testa){
           valida = true;
           ganhador = testa;
       }else if(tabuleiro[0][0] == testa && tabuleiro[1][0] == testa && tabuleiro[2][0] == testa){
           valida = true;
           ganhador = testa;
       }else if(tabuleiro[1][0] == testa && tabuleiro[1][1] == testa && tabuleiro[1][2] == testa){
           valida = true;
           ganhador = testa;
       }else if(tabuleiro[2][0] == testa && tabuleiro[2][1] == testa && tabuleiro[2][2] == testa){
           valida = true;
           ganhador = testa;
       }else if(tabuleiro[0][1] == testa && tabuleiro[1][1] == testa && tabuleiro[1][2] == testa){
           valida = true;
           ganhador = testa;
       }else if(tabuleiro[0][2] == testa && tabuleiro[1][2] == testa && tabuleiro[2][2] == testa){
           valida = true;
           ganhador = testa;
       }
       testa = 'O';
       numerador++;
    }while(numerador < 2);
}

void insereNaMatriz(int posicao, char player){
    switch (posicao) {
    case 1:
        if(tabuleiro[0][0] != 'X'){
            tabuleiro[0][0] = player;
            contador++;
        }else{
            cout << "Posicao Invalida";
            sleep(5);
        }
        break;
    case 2:
        if(tabuleiro[0][1] == ' '){
            tabuleiro[0][1] = player;
            contador++;
        }else{
            cout << "Posicao Invalida";
            sleep(5);
        }
        break;
    case 3:
        if(tabuleiro[0][2] == ' '){
            tabuleiro[0][2] = player;
            contador++;
        }else{
            cout << "Posicao Invalida";
            sleep(5);
        }
        break;
    case 4:
       if(tabuleiro[1][0] == ' '){
            tabuleiro[1][0] = player;
            contador++;
       }else{
           cout << "Posicao Invalida";
           sleep(5);
       }
        break;
    case 5:
        if(tabuleiro[1][1] == ' '){
            tabuleiro[1][1] = player;
            contador++;
        }else{
            cout << "Posicao Invalida";
            sleep(5);
        }
        break;
    case 6:
        if(tabuleiro[1][2] == ' '){
            tabuleiro[1][2] = player;
            contador++;
        }else{
            cout << "Posicao Invalida";
            sleep(5);
        }
        break;
    case 7:
        if(tabuleiro[2][0] == ' '){
            tabuleiro[2][0] = player;
            contador++;
        }else{
            cout << "Posicao Invalida";
            contador++;
            sleep(5);
        }
        break;
    case 8:
        if(tabuleiro[2][1] == ' '){
            tabuleiro[2][1] = player;
            contador++;
        }else{
            cout << "Posicao Invalida";
            sleep(5);
        }
        break;
    case 9:
       if(tabuleiro[2][2] == ' '){
            tabuleiro[2][2] = player;
            contador++;
       }else{
           cout << "Posicao Invalida";
           sleep(5);
       }
        break;
    default:
        cout << "Posicao Invalida";
        sleep(5);
        break;
    }
}

void inserePosicao(int lugar){

    char peca;
    int posicao;

    if(lugar%2 == 0){
        peca = 'O';
        cout << endl<< "Vez do Jogador 'O': " << endl;
        cout << "Insira a posicao desejada: ";
        cin >> posicao;
        insereNaMatriz(posicao, peca);

    }else{
        peca = 'X';
        cout << endl<< "Vez do Jogador 'X': " << endl;
        cout << "Insira a posicao desejada: ";
        cin >> posicao;
        insereNaMatriz(posicao, peca);
    }
}

int main()
{    

    cout << "Salut mes amis, voulez vous a jouer?" << endl << endl;
    system("pause");
    imprimeTabuleiro();

    do{
        inserePosicao(contador);
        imprimeTabuleiro();
        validaPosicao();
    }while(valida == false);

    system("cls");

    cout << "O jogador " << ganhador << " venceu a partida." << endl;

    sleep(2);

    cout << "chuva de prata" << endl;

    sleep(2);

    while(true){
        cout << ". ";
    }

    return 0;

}
