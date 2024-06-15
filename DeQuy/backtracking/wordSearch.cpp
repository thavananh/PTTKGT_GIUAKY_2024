#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<char>> board, vector<bool>& lock, string target, int i, int j, int wordIndex) {
    if (wordIndex == target.length() - 1)
    {
        /* code */
    }
}

bool exsits(vector<vector<char>> board, vector<bool>& lock, int x, int y, string word) {
    for (size_t i = 0; i < board.size(); i++)
    {
        for (size_t j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == word[0] && )
            {
                /* code */
            }
            
        }
        
    }
    
}

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'}, 
        {'S', 'F', 'C', 'S'}, 
        {'A', 'D', 'E', 'E'}
    };
    vector<bool> lock(board.size() * board[0].size() + 1, false);
}

