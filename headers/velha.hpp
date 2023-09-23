/**
 * Copyright [2023] <Kaleb Henrique>
*/
int VerificaVelha( int velha[3][3] );
 
bool verificaDesequilibrioXO(int velha[3][3]);

bool verificaVitoria(int velha[3][3], int tipoDeVitoria);

bool verificaVitoriaCruzada(int velha[3][3], int tipoDeVitoria);

bool verificaVitoriaEmLinha(int velha[3][3], int tipoDeVitoria, int indexLinha);

bool verificaVitoriaEmColuna(int velha[3][3], int tipoDeVitoria, int indexColuna);