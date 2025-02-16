#include <stdio.h>
#include "raylib.h"
#include <time.h>

int main() {
	
	InitWindow(1500, 768, "PONG");
	SetWindowState(FLAG_VSYNC_HINT);
	InitAudioDevice();
	int game_over = 0;
	float ballposx = GetScreenWidth() / 2; float ballposy =GetScreenHeight()/2;
	float left_racket_posx = 10;
	float right_racket_posx = GetScreenWidth() - 10;
	float left_racket_posy = GetScreenHeight() / 2;
	float right_racket_posy = GetScreenHeight() / 2;
	float right_racketwidth = 10;
	float left_racketwidth = 10;
	int l_racket_speed = 4;
	int r_racket_speed = 4;
	float ballspeedx = 3;
	float ballspeedy = 3;
	int ballradius = 10;
	char scoreleft = '0';
	char scoreright='0';
	
	while (!game_over || !WindowShouldClose()) {
		ballposx += ballspeedx;
		ballposy += ballspeedy;
		if (IsKeyDown(KEY_W) && left_racket_posy > 5) {
			left_racket_posy -= l_racket_speed;

		}
		if (IsKeyDown(KEY_S) && left_racket_posy < GetScreenHeight() - 150) {
			left_racket_posy += l_racket_speed;
		}
		if (IsKeyDown(KEY_UP) && right_racket_posy > 5) {
			right_racket_posy -= r_racket_speed;
		}
		if (IsKeyDown(KEY_DOWN) && right_racket_posy < GetScreenHeight() - 150) {
			right_racket_posy += r_racket_speed;
		}
		if (ballposy == GetScreenHeight() || ballposy == 0) {
			ballspeedy = -ballspeedy;

		}
		if (CheckCollisionCircleRec(Vector2{ ballposx,ballposy }, ballradius, Rectangle{ right_racket_posx - right_racketwidth / 2,right_racket_posy,right_racketwidth,150 })) {
			ballspeedx = -ballspeedx * 1.1;






		}
		if (CheckCollisionCircleRec(Vector2{ ballposx,ballposy }, ballradius, Rectangle{ left_racket_posx - left_racketwidth / 2,left_racket_posy,left_racketwidth,150 })) {

			ballspeedx = -ballspeedx * 1.1;



		}
		if (ballposx < 0) {
			ballposx = GetScreenWidth() / 2;
			ballposy = GetScreenHeight() / 2;
			ballspeedx = 3;
			ballspeedy = 3;
			scoreright++;

		}
		if (ballposx > GetScreenWidth()) {
			ballposx = GetScreenWidth() / 2;
			ballposy = GetScreenHeight() / 2;
			ballspeedx = 3;
			ballspeedy = 3;
			scoreleft++;
		}

		if (scoreleft > 56 || scoreright > 56) {
			game_over = 1;
			BeginDrawing();
			DrawText("Game Over", GetScreenWidth() / 2, GetScreenHeight() / 2, 100, WHITE);
			EndDrawing();
			if (IsKeyPressed(KEY_SPACE)) {
				game_over = 0;
				scoreleft = '0';
				scoreright = '0';
				ballposx = GetScreenWidth() / 2;
				ballposy = GetScreenHeight() / 2;

			}

		}
		else if(game_over==0){

			BeginDrawing();
			DrawText("POONG", GetScreenWidth() / 2, GetScreenHeight() / 2, 25, RED);

			ClearBackground(BLACK);

			DrawCircle(ballposx, ballposy, ballradius, DARKGREEN);
			DrawRectangle(left_racket_posx, left_racket_posy, left_racketwidth, 150, RAYWHITE);
			DrawRectangle(right_racket_posx, right_racket_posy, right_racketwidth, 150, RAYWHITE);

			DrawTextCodepoint(GetFontDefault(), scoreright, { 100,100 }, 50, RED);
			DrawTextCodepoint(GetFontDefault(), scoreleft, { 1400,100 }, 50, RED);

			EndDrawing();


		}
	}
	CloseWindow();

}
