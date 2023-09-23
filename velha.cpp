/**
 * Copyright [2023] <Kaleb Henrique>
 * \file  velha.cpp
 */

#include "headers/velha.hpp"

/** 
 * @brief  verifica situacao do jogo da velha  
 * @author Kaleb Henrique 
 * @param  velha uma matrix 3x3
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

    if (verificaVitoriaX(velha)) {
        return 1;
    }

    return -1;
}

bool verificaDesequilibrioXO(int X, int O) {
    return X > (O + 1) || (X + 1) < O;
}

bool verificaVitoriaX(int velha[3][3]) {
    if (velha[0][0] == 1 && velha[1][1] == 1 && velha[2][2] == 1) {
        return true;
    } else if (velha[0][2] == 1 && velha[1][1] == 1 && velha[2][0] == 1) {
        return true;
    }

    for (int i = 1; i <= 2; i++) {
        if (velha[0][i] == 1 && velha[1][i] == 1 && velha[2][i] == 1) {
            return true;
        } else if (velha[i][0] == 1 && velha[i][1] == 1 && velha[i][2] == 1) {
            return true;
        }
    }

    return false;
}
