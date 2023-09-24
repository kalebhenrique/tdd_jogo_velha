/**
 * Copyright [2023] <Kaleb Henrique>
 * \file testa_velha.cpp
 */

#include "../headers/velha.hpp"

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
  
TEST_CASE( "Jogo inválido: há desiquilibrio entre X e O", "[single-file]" ) {
    int vitoriaInjusta[3][3] = {    { 1, 0, 2 }, 
                                    { 0, 0, 2 },
                                    { 0, 0, 2 }
                               };
    int tudoX[3][3] = {   { 1, 1, 1 }, 
                          { 1, 1, 1 },
                          { 1, 1, 1 }
                      };
					  
    REQUIRE( verificaVelha(vitoriaInjusta) == -2 );
    REQUIRE( verificaVelha(tudoX) == -2 );
}

TEST_CASE( "Jogo finalizado: X era para ter ganhado", "[single-file]" ) {
    int vitoriaEmColuna[3][3] = {   { 2, 0, 1 }, 
                                    { 0, 2, 1 },
                                    { 0, 0, 1 }
                                };

    int vitoriaEmColuna2[3][3] = {   { 1, 0, 2 }, 
                                     { 1, 0, 2 },
                                     { 1, 0, 0 }
                                 };

    int vitoriaEmLinha[3][3] = {   { 2, 0, 2 }, 
                                   { 1, 1, 1 },
                                   { 0, 0, 0 }
                               };
    int vitoriaCruzada[3][3] = {   { 1, 0, 2 },
                                   { 0, 1, 2 },
                                   { 0, 0, 1 }
                               };

    REQUIRE( verificaVelha(vitoriaEmColuna) == 1);
    REQUIRE( verificaVelha(vitoriaEmColuna2) == 1);
    REQUIRE( verificaVelha(vitoriaEmLinha) == 1);
    REQUIRE( verificaVelha(vitoriaCruzada) == 1);
}

TEST_CASE( "Jogo finalizado: O era para ter ganhado", "[single-file]" ) {
    int vitoriaEmColuna[3][3] = {   { 0, 2, 0 }, 
                                    { 0, 2, 1 },
                                    { 0, 2, 1 }
                                };
    int vitoriaEmLinha[3][3] = {   { 0, 0, 0 }, 
                                   { 1, 1, 0 },
                                   { 2, 2, 2 }
                               };
    int vitoriaCruzada[3][3] = {   { 0, 0, 2 }, 
                                   { 0, 2, 1 },
                                   { 2, 0, 1 }
                               };

    REQUIRE( verificaVelha(vitoriaEmColuna) == 2);
    REQUIRE( verificaVelha(vitoriaEmLinha) == 2);
    REQUIRE( verificaVelha(vitoriaCruzada) == 2);
}

TEST_CASE( "Jogo inválido: há dois vencedores", "[single-file]" ) {
    int doisVencedores[3][3] = {    { 1, 0, 2 }, 
                                    { 1, 0, 2 },
                                    { 1, 0, 2 }
                               };
					  
    REQUIRE( verificaVelha(doisVencedores) == -2 );
}

TEST_CASE( "Jogo finalizado: era para ter empatado", "[single-file]" ) {
    int empate[3][3] = {    { 1, 1, 2 }, 
                            { 2, 2, 1 },
                            { 1, 1, 2 }
                       };
					  
    REQUIRE( verificaVelha(empate) == 0 );
}

TEST_CASE( "Jogo indefinido: a partida nao acabou", "[single-file]" ) {
    int apenasUmX[3][3] = {    { 0, 0, 0 }, 
                               { 0, 1, 0 },
                               { 0, 0, 0 }
                          };

    int meioDaPartida[3][3] = {    { 0, 0, 1 }, 
                                   { 2, 1, 0 },
                                   { 2, 0, 1 }
                              };
					  
    REQUIRE( verificaVelha(apenasUmX) == -1 );
    REQUIRE( verificaVelha(meioDaPartida) == -1 );
}	