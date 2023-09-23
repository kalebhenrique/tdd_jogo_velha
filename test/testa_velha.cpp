/**
 * Copyright [2023] <Kaleb Henrique>
 * \file testa_velha.cpp
 */

#include "../headers/velha.hpp"

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
  
TEST_CASE( "Jogo inválido: X tem dois ou mais que O", "[single-file]" ) {
	int teste1[3][3]= {   { 2, 0, 1 }, 
	                      { 0, 0, 1 },
						  { 0, 0, 1 }
					  };
					  
    REQUIRE( VerificaVelha(teste1) == -2 );
}
 
