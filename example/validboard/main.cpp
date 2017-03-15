#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValidBoard(const vector<string> &board);

int main(int argc, const char *argv[])
{
    cout << boolalpha;
    const vector<string> invalidBoard = {
        ".....xoox...",
        ".....xooxx..",
        "......xxxo..",
        ".....xooxo..",
        "......xxx...",
        "......o.x...",
        ".......oxo..",
    };

    cout  <<  "invalidBoard check " << isValidBoard(invalidBoard) << "\n";

    const vector<string> validBoard = {
        ".....xooxo..",
        ".....oo.xo..",
        ".xx...xxxo..",
        ".....x..xo..",
        ".oo...xxx...",
        "......o.x...",
        ".......oxo..",
    };
    cout  <<  "validBoard check " << isValidBoard(validBoard) << "\n";
    return 0;
}

bool isValidPos(const std::vector<string>& board, std::vector<string>& boardmap, int x, int y)
{
    static int steps[4][2] = {
        {-1, 0}, {0, -1}, {0, 1}, {1, 0}
    };
    if(board[x][y] == '.') {
        // v: is valid 
        boardmap[x][y] = 'v';
        return true;
    }
    if(boardmap[x][y] == 'v')
        return true;
    // p : pass through, to be checked
    boardmap[x][y] = 'p';
    for(int i = 0; i < 4; i++) {
        int nextx = x + steps[i][0];
        int nexty = y + steps[i][1];
        if( nextx < 0 || nextx > board.size()) continue;
        if( nexty < 0 || nexty > board[x].size()) continue;
        if(board[nextx][nexty] == board[x][y]) {
            if(boardmap[nextx][nexty] == 'p')
                continue;
            if(boardmap[nextx][nexty] == 'v')
                return true;
            if(isValidPos(board, boardmap, nextx, nexty)) {
                boardmap[x][y] = 'v';
                return true; 
            }
        }

        if(board[nextx][nexty] == '.') {
            boardmap[x][y] = 'v';
            return true;
        }
    }
    return false;
}

bool isValidBoard(const vector<string> &board)
{
    auto boardmap = board;
    int xsize = board.size();
    for(int x = 0; x < xsize; x++) {
        int ysize = board[0].size();
        for(int y = 0; y < ysize; y++) {
            if(!isValidPos(board, boardmap, x, y)) {
                cout << "not valid at {" << x << ',' << y << "}";
                return false;
            }
        }
    }
    return true;
}
