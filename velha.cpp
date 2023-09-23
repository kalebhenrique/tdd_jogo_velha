/**
 * Copyright [2023] <Kaleb Henrique>
 * \file  velha.cpp
 */

#include "headers/velha.hpp"

/** 
 * @brief  verifica situacao do jogo da velha  
 * @author Kaleb Henrique 
 * @param  velha uma matrix 3x3: 0 => vazio, 1 => jogada X, 2 => jogada O
 * 
 *  Esta função verifica a situacao do jogo da velha e retorna um numero inteiro
 */

int VerificaVelha(int velha[3][3]) {
    int quantidadeX = 0;
    int quantidadeO = 0;

    for (int linha = 0; linha <= 2; linha++) { // verificar a estrutura
        for (int coluna = 0; coluna <= 2; coluna++) {
            if (velha[linha][coluna] == 1) {
                quantidadeX++;
            } else if (velha[linha][coluna] == 2) {
                quantidadeO++;
            }
        }
    }

    if (verificaDesequilibrioXO(quantidadeX, quantidadeO)) {
        return -2;
    }

    if (verificaVitoria(velha, 1)) {
        return 1;
    }

    if (verificaVitoria(velha, 2)) {
        return 2;
    }

    return -1;
}

bool verificaDesequilibrioXO(int X, int O) {
    return X > (O + 1) || (X + 1) < O;
}

bool verificaVitoria(int velha[3][3], int tipoDeVitoria) {
    if (velha[0][0] == tipoDeVitoria && velha[1][1] == tipoDeVitoria && velha[2][2] == tipoDeVitoria) { // refatorar ifs
        return true;
    } else if (velha[0][2] == tipoDeVitoria && velha[1][1] == tipoDeVitoria && velha[2][0] == tipoDeVitoria) {
        return true;
    }

    for (int i = 1; i <= 2; i++) {
        if (velha[0][i] == tipoDeVitoria && velha[1][i] == tipoDeVitoria && velha[2][i] == tipoDeVitoria) {
            return true;
        } else if (velha[i][0] == tipoDeVitoria && velha[i][1] == tipoDeVitoria && velha[i][2] == tipoDeVitoria) {
            return true;
        }
    }

    return false;
}
