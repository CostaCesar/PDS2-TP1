#include "Game_Puzzle.hpp"
#include "Random.hpp"
#include <iostream>

uint Game_Puzzle::Play(std::string player1, std::string player2)
{
    Vec2 move;
    do
    {
        Draw();

        while (1)
        {
            try 
            { 
                std::cout << std::endl << "Sua jogada, " << player1 << " <Numero>: ";
                move = ReadMove();
            }
            catch(const std::domain_error& end)
            {
                std::cout << std::endl << "Jogo abandonado" << std::endl;
                return 0;
            }
            catch(const std::exception& e)
            {
                std::cout << std::endl << "Entrada invalida" << std::endl;
                continue;
            }

            std::cout << std::endl;

            if(MovePiece(move) == true) break;
            else
            {
                std::cout << "Jogada inválida! ";
                if(move == GetSize())
                    std::cout << "[Nenhuma peça com esse numero]" << std::endl;
                else std::cout << "[" << move.x << "X " << move.y << "Y]"<< std::endl;
                continue;
            }
        }
        
        this->num_plays++;
        std::cout << std::endl;
        
        ResetScreen();
    
    } while (GetWinner() == 0);
    
    Draw();
    return 1;
}

bool Game_Puzzle::MovePiece(Vec2 position)
{
    if(GetPiece(position) == nullptr)
        return false;

    for (uint i = 0; i < 4; i++)
    {
        if(MatchUntilStep(position, (Direction) (i*2), 1) == MatchReturn::Empty)
        {
            Board::MovePiece(position, PosFromDirec(position, (Direction) (i*2)) );
            return true;
        }
    }
    return false;
}

bool Game_Puzzle::HandleOverlap_Move(Vec2 position, Vec2 new_position)
{
    return true;
}

bool Game_Puzzle::AddPiece(Vec2 position, Piece* new_piece)
{
    if(!Board::AddPiece(position, new_piece))
        return false;

    uint id = new_piece->GetPlayerId();
    if(id > 9)
        new_piece->SetSymbol('A' + (id - 10));

    return true;
}

bool Game_Puzzle::IsDraw()
{
    uint inv_count = 0; 

    for (uint i = 0; i < 8; i++)
    {
        Piece *i_piece = GetPiece(IndexToVec2(i));
        for (uint j = i + 1; j < 9; j++)
        {
            Piece *j_piece = GetPiece(IndexToVec2(j));

            if (i_piece == nullptr || j_piece == nullptr)
                continue;

            else if(i_piece->GetPlayerId() > j_piece->GetPlayerId())
               inv_count++;
        }
    }

    return (inv_count % 2 == 1);
}

uint Game_Puzzle::GetWinner()
{
    Vec2 limits = this->GetSize();

    // Dont check if last position is not empty
    if(GetPiece(Vec2{limits.x - 1, limits.y - 1}) != nullptr)
        return 0;

    for (uint i = 0; i < limits.x * limits.y - 2; i++)
    {
        Piece *i_piece = GetPiece(IndexToVec2(i));
        if(i_piece == nullptr)
            return 0;

        Piece *j_piece = GetPiece(IndexToVec2(i+1));
        if(j_piece == nullptr)
            return 0;

        if(j_piece->GetPlayerId() < i_piece->GetPlayerId())
            return 0;
    }
    
    return 1;
}

Vec2 Game_Puzzle::ReadMove()
{
    uint id;

    try { 
        id = GetUintFromInput();
        AssertEmptyInput();
    }
    catch(const std::exception& e)
    { 
        FlushInput();
        throw e;
    }

    if(id == 9) // Desistencia
        throw std::domain_error("Desistiu");
    
    Vec2 limits = GetSize();
    for (uint i = 0; i < limits.y; i++)
    {
        for (uint j = 0; j < limits.x; j++)
        {
            Vec2 position{j, i};
            if((GetPiece(position) != nullptr)
            && GetPiece(position)->GetPlayerId() == id)
            {
                return position;
            }
        }
    }
    
    return limits;
}
Game_Puzzle::Game_Puzzle(uint complexity, uint seed, Vec2 _size)
    : Board(_size)
{
    // Generate pieces
    for (uint i = 0; i < _size.y * _size.x - 1; i++)
    {
        AddPiece(Vec2{i % _size.x, i / _size.x}, new Piece(i + 1));
    }

    // Shuffle pieces & Check if it's playable
    Random::SetRandomSeed(seed);
    do
    {
        for (uint k = 0; k < complexity; k++)
        {
            Vec2 pos_i = Vec2{Random::GetRandomNum() % _size.x, Random::GetRandomNum()  % _size.y};
            Vec2 pos_j = Vec2{Random::GetRandomNum() % _size.x, Random::GetRandomNum()  % _size.y};
            
            Board::MovePiece(pos_i, pos_j);
        }

    } while ((IsDraw() == true) || (GetWinner() == 1));
}

Game_Puzzle::~Game_Puzzle()
{

}