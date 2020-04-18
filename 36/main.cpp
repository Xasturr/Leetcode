#include <vector>
#include <iostream>

using namespace std;

struct Digits_struct {
    bool one = false, two = false, three = false, four = false, five = false,
    six = false, seven = false, eight = false, nine = false, zero = false;

    bool setDigit(char& digit) {
        if (digit == '0' && !zero)
            zero = true;
        else if (digit == '1' && !one)
            one = true;
        else if (digit == '2' && !two)
            two = true;
        else if (digit == '3' && !three) 
            three = true;
        else if (digit == '4' && !four) 
            four = true;
        else if (digit == '5' && !five)
            five = true;
        else if (digit == '6' && !six)
            six = true;
        else if (digit == '7' && !seven)
            seven = true;
        else if (digit == '8' && !eight)
            eight = true;
        else if (digit == '9' && !nine)
            nine = true;
        else if (digit != '.')
            return false;
        return true;
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int sq_i = 0;
        int sq_j = 0;
        for (int i = 0; i < board.size(); i++) {
            sq_j = 0;
            Digits_struct row;
            Digits_struct col;
            for (int j = 0; j < board.at(i).size(); j++) {
                if (!row.setDigit(board.at(i).at(j)))
                    return false;
                if (!col.setDigit(board.at(j).at(i)))
                    return false;
                if ((i == 0 && j == 0) || i / 3 > sq_i && j % 3 == 0 || j / 3 > sq_j && i % 3 == 0) {
                    sq_i = i / 3;
                    sq_j = j / 3;
                    //cout << "i: " << i << " j: " << j << endl;  
                    //cout << "sq_i: " << sq_i << " sq_j: " << sq_j << endl;    
                    Digits_struct sq;
                    for (int k = sq_i * 3; k < (sq_i + 1) * 3; k++) {
                        for (int n = sq_j * 3; n < (sq_j + 1) * 3; n++) {
                            if (!sq.setDigit(board.at(k).at(n)))
                                return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main() {

    vector<vector<char>>board5 { //false
        {'.','2','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','5','.','1'},
        {'.','.','.','.','.','.','8','1','3'},
        {'4','.','9','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','2','.','.','.','.','.','.'},
        {'7','.','6','.','.','.','.','.','.'},
        {'9','.','.','.','.','4','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'}
    };

    vector<vector<char>>board4 { //false
        {'.','.','.','.','.','.','5','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'9','3','.','.','2','.','4','.','.'},
        {'.','.','7','.','.','.','3','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','.','3','4','.','.','.','.'},
        {'.','.','.','.','.','3','.','.','.'},
        {'.','.','.','.','.','5','2','.','.'}
    };

    vector<vector<char>>board { // false
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','7'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    vector<vector<char>>board2 {
        {'.','.','.','.','5','.','.','1','.'},
        {'.','4','.','3','.','.','.','.','.'},
        {'.','.','.','.','.','3','.','.','9'},
        {'8','.','.','.','.','.','.','2','.'},
        {'.','.','2','.','7','.','.','.','.'},
        {'.','1','5','.','.','.','.','.','.'},
        {'.','.','.','.','.','2','.','.','.'},
        {'.','2','.','9','.','.','.','.','.'},
        {'.','.','4','.','.','.','.','.','.'}
    };

    vector<vector<char>>board3 { // false
        {'.','4','.','.','.','.','.','.','.'},
        {'.','.','4','.','.','.','.','.','.'},
        {'.','.','.','1','.','.','7','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','.','3','.','.','.','6','.'},
        {'.','.','.','.','.','6','.','9','.'},
        {'.','.','.','.','1','.','.','.','.'},
        {'.','.','.','.','.','.','2','.','.'},
        {'.','.','.','8','.','.','.','.','.'}
    };

    Solution sol; 

    cout << sol.isValidSudoku(board5) << endl;
}