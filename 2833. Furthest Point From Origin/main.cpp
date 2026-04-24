class Solution {
public:
    int furthestDistanceFromOrigin(string moves) 
    {
        int leftMoves = 0;
        int rightMoves = 0;
        int anyMoves = 0;

        for (const char move : moves)
        {
            if (move == 'L')
            {
                ++leftMoves;
            }
            else if (move == 'R')
            {
                ++rightMoves;
            }
            else
            {
                ++anyMoves;
            }
        }

        return max(leftMoves - rightMoves, rightMoves - leftMoves) + anyMoves;
    }
};