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
 
