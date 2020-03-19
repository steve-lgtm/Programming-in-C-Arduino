#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "k.h"



bool update(struct game *game, int dy, int dx){
if ((dy==0 && dx==0) || (dy!=0 && dx!=0) || (dy==0 && (dx!=1 && dx!=-1)) || (dx==0 && (dy!=1 && dy!=-1)))
        return false;
int medz=0;
char array[SIZE][SIZE];
for (int i = 0; i < SIZE; i++)
{
    for (int j = 0; j < SIZE; j++)
    {
        array[i][j]=game->board[i][j];
        
    }
    
}
if(medz==16)
return false;


 char abk[]="ABCDEFGHIJK";
 int hod[11]={2,4,8,16,32,64,128,256,512,1024,2048};
 int p=0;
 if(dx==1){
 //PRESUN do prava
 for (int i = 0; i < SIZE; i++)
 {
     //medzery
     for (int q = 0; q < SIZE; q++)
{
    for (int j = 3; j > 0; j--)
{
    if(game->board[i][j]==' '){
        char temp=game->board[i][j];
        game->board[i][j]=game->board[i][j-1];
        game->board[i][j-1]=temp;
        p++;
    }
}
}
//presun
     for (int j = 3; j > 0; j--)
     {
        if (game->board[i][j]==game->board[i][j-1])
    {

    game->board[i][j-1]=' ';
            for (int q = 0; q < strlen(abk); q++)
            {
            if(game->board[i][j]==abk[q]){
            game->board[i][j]=abk[q+1];
            game->score=game->score+(2*hod[q]);
            p++;
            break;
            }
    } 
 }
 }
 //medzery
for (int q = 0; q < SIZE; q++)
{
    for (int j = 3; j > 0; j--)
{
    if(game->board[i][j]==' '){
        char temp=game->board[i][j];
        game->board[i][j]=game->board[i][j-1];
        game->board[i][j-1]=temp;
        p++;
    }
}
}
 }
 }
  if(dx==-1){
 //PRESUN do lava
 for (int i = 0; i < SIZE; i++)
 {
     //medzery
     for (int q = 0; q < SIZE; q++)
{
    for (int j = 0; j < 3; j++)
{
    if(game->board[i][j]==' '){
        char temp=game->board[i][j];
        game->board[i][j]=game->board[i][j+1];
        game->board[i][j+1]=temp;
        p++;
    }
}
}
//presun
     for (int j = 0; j < 3; j++)
     {
        if (game->board[i][j]==game->board[i][j+1])
    {

    game->board[i][j+1]=' ';
            for (int q = 0; q < strlen(abk); q++)
            {
            if(game->board[i][j]==abk[q]){
            game->board[i][j]=abk[q+1];
            game->score=game->score+(2*hod[q]);
            p++;
            break;
            }
    } 
 }
 }
 //medzery
for (int q = 0; q < SIZE; q++)
{
    for (int j = 0; j < 3; j++)
{
    if(game->board[i][j]==' '){
        char temp=game->board[i][j];
        game->board[i][j]=game->board[i][j+1];
        game->board[i][j+1]=temp;
        p++;
    }
}
}
 }
 }
 if(dy==-1){
 //PRESUN hore
 for (int j = 0; j < SIZE; j++)
 {
     //medzery
     for (int q = 0; q < SIZE; q++)
{
    for (int i = 0; i < 3; i++)
{
    if(game->board[i][j]==' '){
        char temp=game->board[i][j];
        game->board[i][j]=game->board[i+1][j];
        game->board[i+1][j]=temp;
        p++;
    }
}
}
//presun
     for (int i = 0; i < 3; i++)
     {
        if (game->board[i][j]==game->board[i+1][j])
    {

    game->board[i+1][j]=' ';
            for (int q = 0; q < strlen(abk); q++)
            {
            if(game->board[i][j]==abk[q]){
            game->board[i][j]=abk[q+1];
            game->score=game->score+(2*hod[q]);
            p++;
            break;
            }
    } 
 }
 }
 //medzery
for (int q = 0; q < SIZE; q++)
{
    for (int i = 0; i < 3; i++)
{
    if(game->board[i][j]==' '){
        char temp=game->board[i][j];
        game->board[i][j]=game->board[i+1][j];
        game->board[i+1][j]=temp;
        p++;
    }
}
}
 }
 }
 if(dy==1){
 //PRESUN dole
 for (int j = 0; j < SIZE; j++)
 {
     //medzery
     for (int q = 0; q < SIZE; q++)
{
    for (int i = 3; i > 0; i--)
{
    if(game->board[i][j]==' '){
        char temp=game->board[i][j];
        game->board[i][j]=game->board[i-1][j];
        game->board[i-1][j]=temp;
        p++;
    }
}
}
//presun
     for (int i = 3; i > 0; i--)
     {
        if (game->board[i][j]==game->board[i-1][j])
    {

    game->board[i-1][j]=' ';
            for (int q = 0; q < strlen(abk); q++)
            {
            if(game->board[i][j]==abk[q]){
            game->board[i][j]=abk[q+1];
            game->score=game->score+(2*hod[q]);
            p++;
            break;
            }
    } 
 }
 }
 //medzery
for (int q = 0; q < SIZE; q++)
{
    for (int i = 3; i > 0; i--)
{
    if(game->board[i][j]==' '){
        char temp=game->board[i][j];
        game->board[i][j]=game->board[i-1][j];
        game->board[i-1][j]=temp;
        p++;
    }
}
}
 }
 }
 p=0;
 for (int i = 0; i < SIZE; i++)
{
    for (int j = 0; j < SIZE; j++)
    {
        
    if(array[i][j]==game->board[i][j])
    p++;
        
    }
    
}
 //pohyb?
 if (p==16)
 {
    return false;
 }
 else{
 return true;
 }
}

bool is_move_possible(const struct game game){
 for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (game.board[i][j]==' ')
            {
                return true;
            }
            if (game.board[i][j]==game.board[i][j+1] || game.board[i][j]==game.board[i+1][j]
            || game.board[i][j]==game.board[i][j-1] || game.board[i][j]==game.board[i-1][j])
            {
                return true;
            }
            
        }
        
    }   
    return false;
}

bool is_game_won(const struct game game){
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (game.board[i][j]=='K')
            {
                return true;
            }
            
        }
        
    }
    return false;
}


void add_random_tile(struct game *game){
    int row, col;
    // find random, but empty tile
    do{
        row = rand() % SIZE;
        col = rand() % SIZE;
    }while(game->board[row][col] != ' ');

    // place to the random position 'A' or 'B' tile
    if(rand() % 2 == 0){
        game->board[row][col] = 'A';
    }else{
        game->board[row][col] = 'B';
    }
}
