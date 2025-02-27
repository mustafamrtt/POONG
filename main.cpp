#include <stdio.h>
#include "raylib.h"


int main() {

	InitWindow(1500,768, "PONG");
	SetWindowState(FLAG_VSYNC_HINT);
	int game_over = 0;
	float ballposx = GetScreenWidth() / 2; float ballposy = GetScreenHeight() / 2;
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
	char scoreright = '0';
	int player = 0;
	Image image =  LoadImage("ball.jpeg");
	Texture2D texture =  LoadTextureFromImage(image);


	
	float singlepbuttonpos = GetScreenHeight() / 2 +50 ;
	float twopbuttonpos = GetScreenHeight() / 2 +100;
	int buttonflag = 0;
	while (!WindowShouldClose()) {

		

		if (player==2 ) {
			
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
				if(ballspeedx<6)
				ballspeedx = -ballspeedx * 1.1;
				






			}
			if (CheckCollisionCircleRec(Vector2{ ballposx,ballposy }, ballradius, Rectangle{ left_racket_posx - left_racketwidth / 2,left_racket_posy,left_racketwidth,150 })) {
				if(ballspeedx<6)
				ballspeedx = -ballspeedx * 1.1;



			}
			if (ballposx < 0) {
				ballposx = GetScreenWidth() / 2;
				ballposy = GetScreenHeight() / 2;
				ballspeedx = -3;
				ballspeedy = -3;
				scoreleft++;

			}
			if (ballposx > GetScreenWidth()) {
				ballposx = GetScreenWidth() / 2;
				ballposy = GetScreenHeight() / 2;
				ballspeedx = 3;
				ballspeedy = 3;
				scoreright++;
			}

			if (scoreleft > 56 || scoreright > 56) {
				game_over = 1;
				BeginDrawing();
				ClearBackground(RED);
				DrawText("Game Over", GetScreenWidth() / 2-200, GetScreenHeight() / 2-200, 100, WHITE);
				EndDrawing();
				if (IsKeyPressed(KEY_SPACE)) {
					game_over = 0;
					scoreleft = '0';
					scoreright = '0';
					ballposx = GetScreenWidth() / 2;
					ballposy = GetScreenHeight() / 2;

				}

			}
			else if (game_over == 0) {

				BeginDrawing();
				DrawText("POONG", GetScreenWidth() / 2, GetScreenHeight() / 2, 25, RED);

				ClearBackground(BLACK);
				DrawCircle(ballposx, ballposy, ballradius, DARKGREEN);
				DrawTextureEx(texture, { ballposx - 9,ballposy - 9 }, 1, 0.15, RED);
				DrawRectangle(left_racket_posx, left_racket_posy, left_racketwidth, 150, RAYWHITE);
				DrawRectangle(right_racket_posx, right_racket_posy, right_racketwidth, 150, RAYWHITE);

				DrawTextCodepoint(GetFontDefault(), scoreright, { 100,100 }, 50, RED);
				DrawTextCodepoint(GetFontDefault(), scoreleft, { 1300,100 }, 50, RED);

				EndDrawing();


			}
		}
		else if(player==1)  {
			ballposx += ballspeedx;
			ballposy += ballspeedy;
			if (IsKeyDown(KEY_W) && left_racket_posy > 5) {
				left_racket_posy -= l_racket_speed;

			}
			if (IsKeyDown(KEY_S) && left_racket_posy < GetScreenHeight() - 150) {
				left_racket_posy += l_racket_speed;
			}
			if (ballposy>right_racket_posy&&ballposx>200&&right_racket_posy<GetScreenHeight()-150) {
				if (ballspeedy >= 3 && ballposy > 650) {


				}
				else {



					right_racket_posy += r_racket_speed;
				}

				
			}
			
			if (ballposy < right_racket_posy  && ballposx > 200) {
				if (ballspeedy >= 3 && ballposy < 100) {
					
				}
				else {
					right_racket_posy -= r_racket_speed;
				}
			}
			if (ballposy >= GetScreenHeight() || ballposy <= 0) {
				
				ballspeedy = -ballspeedy;

			}
			if (CheckCollisionCircleRec(Vector2{ ballposx,ballposy }, ballradius, Rectangle{ right_racket_posx - right_racketwidth / 2,right_racket_posy,right_racketwidth,150 })) {
				if(ballspeedx<6)
				ballspeedx = -ballspeedx * 1.1;






			}
			if (CheckCollisionCircleRec(Vector2{ ballposx,ballposy }, ballradius, Rectangle{ left_racket_posx - left_racketwidth / 2,left_racket_posy,left_racketwidth,150 })) {
				if (ballspeedx < 6) 
					ballspeedx = -ballspeedx * 1.01;
				


			}
			if (ballposx < 0) {
				ballposx = GetScreenWidth() / 2;
				ballposy = GetScreenHeight() / 2;
				ballspeedx = -3;
				ballspeedy = -3;
				scoreleft++;

			}
			if (ballposx > GetScreenWidth()) {
				ballposx = GetScreenWidth() / 2;
				ballposy = GetScreenHeight() / 2;
				ballspeedx = 3;
				ballspeedy = 3;
				scoreright++;
			}

			if (scoreleft > 56 || scoreright > 56) {
				game_over = 1;
				BeginDrawing();
				ClearBackground(RED);
				DrawText("Game Over", GetScreenWidth() / 2-200, GetScreenHeight() / 2-200, 100, WHITE);
				EndDrawing();
				if (IsKeyPressed(KEY_SPACE)) {
					game_over = 0;
					scoreleft = '0';
					scoreright = '0';
					ballposx = GetScreenWidth() / 2;
					ballposy = GetScreenHeight() / 2;

				}

			}
			else if (game_over == 0) {

				BeginDrawing();
				DrawText("POONG", GetScreenWidth() / 2, GetScreenHeight() / 2, 25, RED);

				ClearBackground(BLACK);

				DrawCircle(ballposx, ballposy, ballradius, DARKGREEN);
				DrawTextureEx(texture, {ballposx-9,ballposy-9}, 1,0.15,RED);
				DrawRectangle(left_racket_posx, left_racket_posy, left_racketwidth, 150, RAYWHITE);
				DrawRectangle(right_racket_posx, right_racket_posy, right_racketwidth, 150, RAYWHITE);

				DrawTextCodepoint(GetFontDefault(), scoreright, { 100,100 }, 50, RED);
				DrawTextCodepoint(GetFontDefault(), scoreleft, { 1300,100 }, 50, RED);

				EndDrawing();


			}


		}
		else {
			BeginDrawing();
			DrawText("for selection:K-I\nfor rackets:W-S-arrow_up-arrow_down\nfor replay:SPACE ", GetScreenWidth() / 2-100, GetScreenHeight() / 2 + 100, 30, WHITE);
			if (buttonflag == 1) {
				DrawText("POONG", GetScreenWidth() / 2-200, GetScreenHeight() / 2-50, 50, RED);
				DrawText("Single Player", GetScreenWidth() / 2-200, singlepbuttonpos-50, 50, RED);
				DrawText("Two Player", GetScreenWidth() / 2-200, twopbuttonpos-50, 50, WHITE);
			}
			if (buttonflag == 0) {
				DrawText("POONG", GetScreenWidth() / 2-200, GetScreenHeight() / 2-50, 50, RED);
				DrawText("Single Player", GetScreenWidth() / 2-200, singlepbuttonpos-50, 50, WHITE);
				DrawText("Two Player", GetScreenWidth() / 2-200, twopbuttonpos-50, 50, RED);
			}
			if (IsKeyDown(KEY_K)) {
				EndDrawing();
				BeginDrawing();
				
				buttonflag = 1;
				DrawText("POONG", GetScreenWidth() / 2-200, GetScreenHeight() / 2-50, 50, RED);
				DrawText("Single Player", GetScreenWidth() / 2-200, singlepbuttonpos-50, 50, RED);
				DrawText("Two Player", GetScreenWidth() / 2-200, twopbuttonpos-50, 50, WHITE);
				EndDrawing();


			}
			if (IsKeyDown(KEY_I)) {
				DrawText("POONG", GetScreenWidth() / 2-200, GetScreenHeight() / 2-50, 50, RED);
				DrawText("Single Player", GetScreenWidth() / 2-200, singlepbuttonpos-50, 50, WHITE);
				DrawText("Two Player", GetScreenWidth() / 2-200, twopbuttonpos-50, 50, RED);
				buttonflag = 0;

			}
			if (buttonflag==1 && IsKeyDown(KEY_SPACE)) {
				player = 2;
			}
			if (buttonflag == 0 && IsKeyDown(KEY_SPACE)) {
				player = 1;
			}

			EndDrawing();


		}
	}
	CloseWindow();

}
