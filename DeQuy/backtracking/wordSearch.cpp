#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<char>> board, vector<vector<bool>>& lock, string target, int i, int j, int wordIndex) {
    if (wordIndex == target.length() - 1)
    {
        return true;
    }
    lock[i][j] = true;
    if (i > 0 && board[i-1][j] == target[wordIndex + 1] && !lock[i-1][j])
    {
        if (dfs(board, lock, target, i - 1, j, wordIndex + 1))
        {
            return true;
        }
    }
    if (i < board.size() - 1 && board[i+1][j] == target[wordIndex + 1] && !lock[i+1][j])
    {
        if (dfs(board, lock, target, i + 1, j, wordIndex + 1))
        {
            return true;
        }
    }
    if (j > 0 && board[i][j-1] == target[wordIndex + 1] && !lock[i][j-1])
    {
        if (dfs(board, lock, target, i, j - 1, wordIndex + 1))
        {
            return true;
        }
    }
    if (j < board[0].size() - 1 && board[i][j+1] == target[wordIndex + 1] && !lock[i][j+1])
    {
        if (dfs(board, lock, target, i, j + 1, wordIndex + 1))
        {
            return true;
        }
    }
    lock[i][j] = false;
    return false;
}

bool exsits(vector<vector<char>> board, vector<vector<bool>>& lock, int x, int y, string target) {
    for (size_t i = 0; i < board.size(); i++)
    {
        for (size_t j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == target[0] && dfs(board, lock, target, i, j, 0))
            {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'}, 
        {'S', 'F', 'C', 'S'}, 
        {'A', 'D', 'E', 'E'}
    };
    vector<vector<bool>>lock(board.size(), vector<bool>(board[0].size(), false));
    if (exsits(board, lock, 0, 0, "ABCCE"))
    {
        cout << "Tim Thay";
    }
    
}

