#pragma once

/*! @file Defs.hpp 
    @brief Definições básicas para o resto do sistema
*/

typedef unsigned int uint;

/*!
    @enum Direction
    @brief Direções no tabuleiro, começando a partir do Norte, rodando no sentido horário

    @details É possível fazer a conversão de uint para Direction e virse-versa
*/
enum class Direction
{
    North = 0,      /*!< 0: Norte */
    NorthEast = 1,  /*!< 1: Nordeste */
    East = 2,       /*!< 2: Leste */
    SouthEast = 3,  /*!< 3: Sudeste */
    South = 4,      /*!< 4: Sul */
    SouthWest = 5,  /*!< 5: Sudoeste */
    West = 6,       /*!< 6: Oeste*/
    NorthWest = 7   /*!< 7: Noroeste*/
};

/*!
    @class Vec2
    @brief Estrutura para armazenar 2 valores inteiros positivos. Pode representar posição, tamanho, deltas, etc.
*/
struct Vec2
{
    /*! @var uint x
    @brief Representa a direção horizontal
    */
    uint x;

    /*! @var uint y
    @brief Representa a direção vertical
    */
    uint y; 

    bool operator== (const Vec2 &a) const
    { return ((this->x == a.x) && (this->y == a.y)); }
    bool operator!= (const Vec2 &a) const
    { return ((this->x != a.x) || (this->y != a.y)); }
};
