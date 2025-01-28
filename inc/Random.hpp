#pragma once

#include "Defs.hpp"

/*! @file Random.hpp 
    @brief Estrutura do Gerador Aleatório (RNG)
*/

/**
 * @class Random
 * @brief Classe estática que gera números aleatórios
 * 
 * @details As funções aleatórias do C++ (Standard Library) geram números diferentes para a mesma seed
 * em ambientes diferentes (Arch Linux, Ubuntu, Windows 10, Windows 11, MacOs, etc.)
 * 
 * Para manter a consistência entre esses ambientes, foi criada essa classe
 */
class Random
{
private:
    /*! @var static uint next_number
    @brief Número aleatório
    */
    static uint next_number;
public:
    /*! @fn static uint GetRandomNum()
        @brief Devolve um inteiro positivo aleatório
        @return uint: Número aleatório

        @details Toda vez que a função for chamada, um novo número "aleatório" será retornado

        @warning Se SetRandomSeed() for chamado antes com a mesma semente, a sequência aleatória reinicia
        Portanto, é desaconselhado chamar SetRandomSeed() com a mesma seed e/ou múltiplas vezes
    */
    static uint GetRandomNum();

    /*! @fn static void SetRandomSeed(uint seed)
        @brief Atribui uma seed para o gerador
        @param seed Semente para o gerador

        @details Para garantir um sequência única do RNG, utilize time(nullptr) para gerar o valor da seed
    */
    static void SetRandomSeed(uint seed);

    Random() = delete;
};
