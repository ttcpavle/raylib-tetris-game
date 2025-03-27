#pragma once
#include "../src/blocks.cpp"
#include "grid.h"

class Game {
public:
	Game();
	~Game();
	void Draw();	
	void HandleInput();
	void MoveBlockDown();
	bool gameOver;
	int score;
	Music music;

private:
	Grid grid;
	std::vector<Block> GetAllBlocks(); // get all possible blocks
	Block GetRandomBlock();            // get random block from all possible blocks	
	void MoveBlockLeft();              // move block 1 position to the left
	void MoveBlockRight();             // move block 1 position to the right
	std::vector<Block> blocks;         // different kinds of blocks
	Block currentBlock;                // it's like a state variable; holds a block that is controlled and moves down
	Block nextBlock;                   // next block to appear at default position
	void RotateBlock();                // rotate block
	bool IsBlockOutside();             // check if block is outside of boundaries
	void LockBlock();                  // lock block in place
	bool BlockFits();                  // check if block collides with already locked blocks on grid
	void Reset();                      // resets game when game is lost and user presses any key
	void UpdateScore(int linesCleared, int moveDownPoints);
	Sound rotateSound;
	Sound clearSound;
};