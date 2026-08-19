#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, std::vector<std::vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMasks;

        // Build bitmask for occupied seats (2 to 9) per row
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                rowMasks[row] |= (1 << (col - 2));
            }
        }
        
        // Start assuming 2 groups for all unreserved rows
        int maxGroups = (n - rowMasks.size()) * 2;
        
        // Masks for seating configurations
        int leftMask   = 0b00001111; // seats 2, 3, 4, 5
        int rightMask  = 0b11110000; // seats 6, 7, 8, 9
        int middleMask = 0b00111100; // seats 4, 5, 6, 7
        
        for (const auto& [row, mask] : rowMasks) {
            bool canLeft   = (mask & leftMask) == 0;
            bool canRight  = (mask & rightMask) == 0;
            bool canMiddle = (mask & middleMask) == 0;
            
            if (canLeft && canRight) {
                maxGroups += 2;
            } else if (canLeft || canRight || canMiddle) {
                maxGroups += 1;
            }
        }
        return maxGroups;
    }
};
