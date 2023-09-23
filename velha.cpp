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
    if (verificaDesequilibrioXO(velha)) {
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

bool verificaDesequilibrioXO(int velha[3][3]) {
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

    return quantidadeX > (quantidadeO + 1) || (quantidadeX + 1) < quantidadeO;
}

bool verificaVitoria(int velha[3][3], int tipoDeVitoria) {
    if (verificaVitoriaCruzada(velha, tipoDeVitoria)) {
        return true;
    }

    for (int index = 1; index <= 2; index++) {
        if (verificaVitoriaEmLinha(velha, tipoDeVitoria, index)) {
            return true;
        } else if (verificaVitoriaEmColuna(velha, tipoDeVitoria, index)) {
            return true;
        }
    }

    return false;
}

bool verificaVitoriaCruzada(int velha[3][3], int tipoDeVitoria) {
    if (velha[0][0] == tipoDeVitoria && velha[1][1] == tipoDeVitoria && velha[2][2] == tipoDeVitoria) {
        return true;
    } else if (velha[0][2] == tipoDeVitoria && velha[1][1] == tipoDeVitoria && velha[2][0] == tipoDeVitoria) {
        return true;
    }

    return false;
}

bool verificaVitoriaEmLinha(int velha[3][3], int tipoDeVitoria, int indexLinha) {
    return (velha[0][indexLinha] == tipoDeVitoria) && (velha[1][indexLinha] == tipoDeVitoria) && (velha[2][indexLinha] == tipoDeVitoria);
}

bool verificaVitoriaEmColuna(int velha[3][3], int tipoDeVitoria, int indexColuna) {
    return (velha[indexColuna][0] == tipoDeVitoria) && (velha[indexColuna][1] == tipoDeVitoria) && (velha[indexColuna][2] == tipoDeVitoria);
}