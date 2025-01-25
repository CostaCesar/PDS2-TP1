#include "TestHeader.hpp"

#include "Board.hpp"

class BoardTest : public Board
{
public:
    bool IsDraw() override
    {
        return false;
    }
    uint GetWinner() override
    {
        return 0;
    }
    uint Play() override
    {
        return 0;
    }
    Piece* GetPiece(Vec2 pos)
    {
        return Board::GetPiece(pos);
    }
    
    BoardTest(uint _x, uint _y)
    : Board(Vec2{_x, _y})
    {

    }
    ~BoardTest()
    {

    }
};

TEST_CASE("Board Creation")
{
    BoardTest* object = new BoardTest(10,10);
    REQUIRE(object != nullptr);
    Board* alias = object;

    Vec2 sizes = alias->GetSize();
    CHECK(sizes.x == 10);
    CHECK(sizes.y == 10);

    Piece* piece_a = new Piece(1, 'A');
    CHECK(alias->AddPiece(Vec2{1,1}, piece_a) == true);

    Piece* piece_b = new Piece(2);
    CHECK(alias->AddPiece(Vec2{1,1}, piece_b) == false);
    CHECK(alias->AddPiece(Vec2{2,2}, piece_b) == true);

    CHECK(alias->MovePiece(Vec2{1,1}, Vec2{2,2}) == false);
    CHECK(alias->MovePiece(Vec2{1,1}, Vec2{1,0}) == true);
    CHECK(alias->MovePiece(Vec2{1,1}, Vec2{0,1}) == false);
    CHECK(alias->MovePiece(Vec2{1,0}, Vec2{3,3}) == true);

    CHECK(object->GetPiece(Vec2{3,3}) == piece_a);
    CHECK(object->GetPiece(Vec2{2,2}) == piece_b);

    object->Draw();

    delete object;
}