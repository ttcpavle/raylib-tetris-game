#include "../includes/block.h"

Block::Block()
{
    id = 0;
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    rowOffset = 0;
    columnOffset = 0;
}

// draw this block considering rotation and block offset
void Block::Draw(int offsetX, int offsetY) {
    std::vector<Position> tiles = GetCellPositions();
    for (Position item : tiles) {
        DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
    }
}

void Block::Move(int rows, int columns) {
    rowOffset += rows;
    columnOffset += columns;
}

// returns positions of cells on grid (rotation + offset)
std::vector<Position> Block::GetCellPositions() {
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for (Position item : tiles) {
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

void Block::Rotate(){
    rotationState++;
    if (rotationState == (int)cells.size()) {
        rotationState = 0;
    }
}

void Block::UndoRotation() {
    rotationState--;
    if (rotationState == -1) {
        rotationState = (int)cells.size() - 1;
    }
}