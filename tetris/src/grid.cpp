#include <iostream>
#include "../includes/grid.h"
#include "../includes/colors.h"

Grid::Grid() {
	this->numRows = 20;
	this->numCols = 10;
	this->cellSize = 30;
	Initialize();
	this->colors = GetCellColors();
}

void Grid::Initialize() {
	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {
			grid[row][col] = 0;
		}
	}
}

void Grid::Print() {
	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {
			std::cout << grid[row][col] << " ";
		}
		std::cout << std::endl;
	}
}

void Grid::Draw() {
	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {
			int cellValue = grid[row][col];
			DrawRectangle(col * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);
		}
	}
}

// check if single cell is outside of boundaries
bool Grid::IsCellOutside(int row, int column) {
	if (row >= 0 && row < numRows && column >= 0 && column < numCols) 
		return false;
	return true;
}

bool Grid::IsCellEmpty(int row, int column) {
	if (grid[row][column] == 0) {
		return true;
	}
	return false;
}

bool Grid::IsRowFull(int row){
	for (int column = 0; column < numCols; column++) {
		if (grid[row][column] == 0)
			return false;
	}
	return true;
}

void Grid::ClearRow(int row){
	for (int column = 0; column < numCols; column++) {
		grid[row][column] = 0;
	}
}

void Grid::MoveRowDown(int row, int numRows){
	for (int column = 0; column < numCols; column++) {
		grid[row + numRows][column] = grid[row][column];
		grid[row][column] = 0;
	}
}

int Grid::ClearFullRows(){
	int completed = 0; // total number of completed rows
	for (int row = numRows - 1; row >= 0; row--) {
		if (IsRowFull(row)) {
			ClearRow(row);
			completed++;
		}
		else if (completed > 0) {
			MoveRowDown(row, completed);
		}
	}
	return completed;
}