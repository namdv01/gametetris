#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;
const int M=20;
const int N=10;
const int SIZE=20;
const string menu="menutetris.png";
enum GAMEPHASE
{
   GAMESTART,GAMEPLAY,GAMEOVER
};

const string frame="New Bitmap Image.bmp";
const string finish=" ";

struct color
{
   int r,g,b,a;
};
color GetColor(int r,int g,int b,int a);
const color COLORS[]=
{
   GetColor(255,0,0,0),
   GetColor(0,255,0,0),
   GetColor(0,0,255,0),
   GetColor(255,255,0,0),
   GetColor(255,0,255,0),
   GetColor(0,255,255,0),
   GetColor(255,127,64,0)
};
struct tetrino
{
   int x,y;
   color mau;
};
const int SetTetrino[7][4]=
{
   1,5,9,13,   //I
   1,5,6,9,    //T
   1,5,9,10,   //L
   5,6,9,10,   //O
   2,5,6,9,    //S
   1,5,6,10,   //Z
   2,6,9,10    //J
};
void GetTetrino(tetrino a[4],int &random,int &restorerandom);
void MoveTetrino(tetrino a[4],tetrino b[4],int &dx);
void RotateTetrino(tetrino a[4],int &rotation);
void DrawTetrino(SDL_Renderer *renderer,tetrino a[4]);
void SoftTetrino(SDL_Renderer *renderer,tetrino a[4],tetrino b[4]);
bool Check(tetrino a[4],int BOARD[M][N]);
void DrawBoard(SDL_Renderer *renderer,int BOARD[M][N]);
void EraseBoard(int BOARD[M][N]);
SDL_Texture* LoadImage(SDL_Renderer *renderer,const string &image);
void DrawNext(SDL_Renderer *renderer,tetrino a[4],int &random);
bool GameLose(int BOARD[M][N]);
#endif // GAME_H
