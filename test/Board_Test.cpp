#include "TestHeader.hpp"

#include "Board.hpp"

class BoardTest : public Board
{
public:
    bool IsDraw()
    {
        return false;
    }
    uint GetWinner()
    {
        return 0;
    }

    uint Test_Vec2ToIndex(Vec2 position)
    {
        return Vec2ToIndex(position);
    }
    Vec2 Test_IndexToVec2(uint index)
    {
        return IndexToVec2(index);
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
    
    CHECK(object->Test_Vec2ToIndex(Vec2{3,7}) == 73);
    bool reverse = object->Test_IndexToVec2(73) == Vec2{3,7};
    CHECK(reverse == true);

    Piece* piece_a = new Piece(Vec2{1,1});
    CHECK(alias->AddPiece(piece_a) == true);

    Piece* piece_b = new Piece(Vec2{1,1});
    CHECK(alias->AddPiece(piece_b) == false);
    piece_b->SetPosition(Vec2{2,2});
    CHECK(alias->AddPiece(piece_b) == true);

    CHECK(alias->MovePiece(Vec2{1,1}, Vec2{2,2}) == false);
    CHECK(alias->MovePiece(Vec2{1,1}, Vec2{1,0}) == true);
    CHECK(alias->MovePiece(Vec2{1,1}, Vec2{0,1}) == false);
    CHECK(alias->MovePiece(Vec2{1,0}, Vec2{3,3}) == true);

    CHECK(piece_a->GetPosition().x == 3);
    CHECK(piece_a->GetPosition().y == 3);

    delete object;
}