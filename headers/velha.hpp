/**
 * Copyright [2023] <Kaleb Henrique>
*/
int VerificaVelha( int velha[3][3] );
 
bool verificaDesequilibrioXO(int x, int o);

bool verificaVitoria(int velha[3][3], int tipoDeVitoria);

bool ganhouCruzado(int velha[3][3], int tipoDeVitoria);

bool ganhouEmLinha(int velha[3][3], int tipoDeVitoria, int indexLinha);

bool ganhouEmColuna(int velha[3][3], int tipoDeVitoria, int indexColuna);