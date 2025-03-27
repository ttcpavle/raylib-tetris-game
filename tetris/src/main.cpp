#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "raylib.h"
#include "../includes/game.h"

double lastUpdateTime = 0;
bool EventTriggered(double interval) {
	double currentTime = GetTime();
	// if interval has passed
	if (currentTime - lastUpdateTime >= interval) {
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

int main() {

	InitWindow(500, 620, "raylib Tetris");
	SetTargetFPS(60);
	Font font = LoadFontEx("Assets/Font/monogram.ttf", 64, 0, 0);
	Game game = Game();

	while (!WindowShouldClose()) {

		UpdateMusicStream(game.music);
		// handle user input
		game.HandleInput();

		// move block down every 0.2 seconds
		if (EventTriggered(0.2)) {
			game.MoveBlockDown();
		}
		BeginDrawing();
		ClearBackground(darkBlue);
		DrawTextEx(font, "Score", { 365, 15 }, 38, 2, WHITE);
		DrawTextEx(font, "Next", { 370, 175 }, 38, 2, WHITE);
		if (game.gameOver) {
			DrawTextEx(font, "GAME OVER", { 320, 450 }, 38, 2, WHITE);
		}		
		DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, lightBlue);

		// draw score text
		char scoreText[10];
		sprintf(scoreText, "%d", game.score);
		Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
		DrawTextEx(font, scoreText, { 320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);

		DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3, 6, lightBlue);
		game.Draw();
		EndDrawing();
	}
	CloseWindow();
	return 0;
}