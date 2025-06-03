# Connect-4-Game

A classic Connect-4 implementation in C where two players compete to connect four of their symbols vertically, horizontally, or diagonally on a 6×7 grid.

🎮 Features
- Two-player gameplay** (Player 1: 'X', Player 2: 'O')
- **Color-coded turns** (Red for Player 1, Yellow for Player 2)
- **Input validation** for column selection
- **Full grid detection** - prevents moves in full columns
- **Win detection** checks all possible 4-in-a-row combinations:
  - Horizontal
  - Vertical
  - Diagonal (both directions)
- **Draw detection** after 42 moves (full board)

## 🛠️ How It Works
1. Players alternate turns selecting columns (0-6)
2. Pieces "fall" to the lowest available row in the selected column
3. Game continues until:
   - A player connects four pieces (wins)
   - The board fills completely (draw)

## ⚙️ Technical Details
- **Grid Representation**: 6 rows × 7 columns 2D array
- **Key Functions**:
  - `displayGrid()` - Shows current board state
  - `turn()` - Handles piece placement
  - `checks()` - Validates player input
  - `isWinner()` - Checks all win conditions

## 🚀 How to Run
1. Compile with any C compiler:
   ```bash
   gcc lab16T5.c -o connect4
   ```
2. Run the executable:
   ```bash
   ./connect4
   ```

## 🎯 Game Rules
1. Players take turns dropping their symbol into columns
2. First to connect four of their symbols wins
3. If the board fills with no winner, the game is a draw

Enjoy this terminal-based version of the classic Connect-4 game! The simple interface makes it easy to play while preserving all the strategic depth of the original.
