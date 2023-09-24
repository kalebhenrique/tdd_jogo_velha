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
					  
    REQUIRE( VerificaVelha(vitoriaInjusta) == -2 );
	REQUIRE( VerificaVelha(tudoX) == -2 );
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
					  
    REQUIRE( VerificaVelha(vitoriaEmColuna) == 1);
	REQUIRE( VerificaVelha(vitoriaEmColuna2) == 1);
	REQUIRE( VerificaVelha(vitoriaEmLinha) == 1);
	REQUIRE( VerificaVelha(vitoriaCruzada) == 1);
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
					  
    REQUIRE( VerificaVelha(vitoriaEmColuna) == 2);
	REQUIRE( VerificaVelha(vitoriaEmLinha) == 2);
	REQUIRE( VerificaVelha(vitoriaCruzada) == 2);
}

TEST_CASE( "Jogo inválido: há dois vencedores", "[single-file]" ) {
	int doisVencedores[3][3] = {    { 1, 0, 2 }, 
									{ 1, 0, 2 },
									{ 1, 0, 2 }
							   };
					  
    REQUIRE( VerificaVelha(doisVencedores) == -2 );
}

TEST_CASE( "Jogo finalizado: era para ter empatado", "[single-file]" ) {
	int empate[3][3] = {    { 1, 1, 2 }, 
							{ 2, 2, 1 },
							{ 1, 1, 2 }
					   };
					  
    REQUIRE( VerificaVelha(empate) == 0 );
}