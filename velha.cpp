/**
 * Copyright [2023] <Kaleb Henrique>
 * \file  velha.cpp
 */

#include "headers/velha.hpp"

/** 
 * @brief  verifica situacao do jogo da velha  
 * @author Kaleb Henrique 
 * @param  velha uma matrix 3x3: 0 => vazio, 1 => jogada X, 2 => jogada O
 * @return um numero inteiro que pertence ao intervalo [-2,2]
 * 
 *  Esta função verifica a situacao do jogo da velha e retorna um numero inteiro:
 *  -2 => jogo impossivel
 *  -1 => jogo indefinido
 *   0 => empate
 *   1 => vitoria de X
 *   2 => vitoria de O
 */

int verificaVelha(int velha[3][3]) {
    int contadorVazio = 0;
    int contadorX = 0;
    int contadorO = 0;
    bool vitoriaDeX;
    bool vitoriaDeO;

    for (int linha = 0; linha <= 2; linha++) {
        for (int coluna = 0; coluna <= 2; coluna++) {
            if (velha[linha][coluna] == 1) {
                contadorX++;
            } else if (velha[linha][coluna] == 2) {
                contadorO++;
            } else {
                contadorVazio++;
            }
        }
    }

    if (verificaDesequilibrioXO(contadorX, contadorO)) {
        return -2;
    }

    vitoriaDeX = verificaVitoria(velha, 1);
    vitoriaDeO = verificaVitoria(velha, 2);

    if (vitoriaDeX && vitoriaDeO) {
        return -2;
    } else if (vitoriaDeX) {
        return 1;
    } else if (vitoriaDeO) {
        return 2;
    } else if (contadorVazio == 0) {
        return 0;
    }

    return -1;
}

bool verificaDesequilibrioXO(int x, int o) {
    return x > (o + 1) || (x + 1) < o;
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
