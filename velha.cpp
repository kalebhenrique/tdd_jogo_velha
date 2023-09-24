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
    bool vitoriaDeX = false;
    bool vitoriaDeO = false;

    if (verificaDesequilibrioXO(velha)) {
        return -2;
    }

    vitoriaDeX = verificaVitoria(velha, 1);  // verificar estrutura
    vitoriaDeO = verificaVitoria(velha, 2);

    if (vitoriaDeX && vitoriaDeO) {
        return -2;
    } else if (vitoriaDeX) {
        return 1;
    } else if (vitoriaDeO) {
        return 2;
    }

    return -1;
}

bool verificaDesequilibrioXO(int velha[3][3]) {
    int quantidadeX = 0;
    int quantidadeO = 0;

    for (int linha = 0; linha <= 2; linha++) {  // verificar a estrutura
        for (int coluna = 0; coluna <= 2; coluna++) {
            if (velha[linha][coluna] == 1) {
                quantidadeX++;
            } else if (velha[linha][coluna] == 2) {
                quantidadeO++;
            }
        }
    }

    return quantidadeX > (quantidadeO + 1) || (quantidadeX + 1) < quantidadeO;
}

bool verificaVitoria(int velha[3][3], int tipoDeVitoria) {
    if (ganhouCruzado(velha, tipoDeVitoria)) {
        return true;
    }

    for (int index = 0; index <= 2; index++) {
        if (ganhouEmColuna(velha, tipoDeVitoria, index)) {
            return true;
        } else if (ganhouEmLinha(velha, tipoDeVitoria, index)) {
            return true;
        }
    }

    return false;
}

bool ganhouCruzado(int velha[3][3], int tipoDeVitoria) {
    return (velha[0][0] == tipoDeVitoria &&
            velha[1][1] == tipoDeVitoria &&
            velha[2][2] == tipoDeVitoria) ||
           (velha[0][2] == tipoDeVitoria &&
            velha[1][1] == tipoDeVitoria &&
            velha[2][0] == tipoDeVitoria);
}

bool ganhouEmColuna(int velha[3][3], int tipoDeVitoria, int indexColuna) {
    return velha[0][indexColuna] == tipoDeVitoria &&
           velha[1][indexColuna] == tipoDeVitoria &&
           velha[2][indexColuna] == tipoDeVitoria;
}

bool ganhouEmLinha(int velha[3][3], int tipoDeVitoria, int indexLinha) {
    return velha[indexLinha][0] == tipoDeVitoria &&
           velha[indexLinha][1] == tipoDeVitoria &&
           velha[indexLinha][2] == tipoDeVitoria;
}
