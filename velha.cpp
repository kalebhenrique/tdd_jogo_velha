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

	for (int linha = 0; linha <= 2; linha++) {
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

	return 0;
}

bool verificaDesequilibrioXO(int X, int O) {
	return X > (O + 1) || (X + 1) < O;
}