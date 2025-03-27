#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

// One thing to note is that each block is seen as a set of independent tiles, so every problem of 
// block manipulation breaks down to a problem of individual tiles

class Block {
public:
	Block();
	int id;
	std::map<int, std::vector<Position>> cells; // (key) rotation state of block - (value) occupied positions for that rotation
	void Draw(int offsetX, int offsetY);
	void Move(int rows, int columns);
	std::vector<Position> GetCellPositions();
	void Rotate();
	void UndoRotation();
private:
	int cellSize;
	int rotationState;
	std::vector<Color> colors;
	int rowOffset;
	int columnOffset;	
};