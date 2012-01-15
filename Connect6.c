#define BOARD_SIZE 19

#include <stdio.h>
#include <stdlib.h>

void initialize_game_board();
void print_game_board();
void human_place_piece();
void ai_move_offensively();
void ai_move_defensively();
void play_move( int x, int y );

int moves_remaining = 2;

char game_board[BOARD_SIZE][BOARD_SIZE];

int start_move_x = 5;
int start_move_y = 5;

int algorithm_progress = 0;

int main( void )
{
initialize_game_board();

while( 1 )
{
human_place_piece();
ai_move_defensively();
}

return(0);
}

// A function which allows a user to place a piece on the
// game board.
void human_place_piece()
{
int x, y = 0;

printf( "Enter Coordonate to Place Piece In\n" );
scanf( "%d", &x );
scanf( "%d", &y );

game_board[x-1][y-1] = 'B';

printf( "Enter Coordonate to Place Piece In\n" );
scanf( "%d", &x );
scanf( "%d", &y );

game_board[x-1][y-1] = 'B';

print_game_board();
}

// A function that will capture the offensive (game winning)
// movemnets of the AI.
void ai_move_offensively()
{
int t = 0;
int x = start_move_x;
int y = start_move_y;
int planning = 1;


if( algorithm_progress == 0 )
{
play_move( x, y );
play_move( x, y+1 );
algorithm_progress += 1;
}
else if( algorithm_progress == 1 )
{
play_move( x, y+2 );
play_move( x, y+3 );
algorithm_progress += 1;
}
else if( algorithm_progress == 2 )
{
play_move( x+1, y+3 );
play_move( x-1, y+3 );
algorithm_progress += 1;
}
else if( algorithm_progress == 3 )
{
play_move( x+2, y );
play_move( x+1, y+1 );
algorithm_progress += 1;
}
else if( algorithm_progress == 4 )
{
play_move( x+1, y );
play_move( x+1, y+2 );
algorithm_progress += 1;
}
else if( algorithm_progress == 5 )
{
play_move( x-1, y );
play_move( x-2, y-1 );
algorithm_progress += 1;
}

//
void ai_move_defensively()
{
	int x = 0;
	int rstones, dstones, diastones = 0;
	for( x = 0; x < (BOARD_SIZE); x++)
	{
		if(game_board[x][x % (BOARD_SIZE - 1)] == 'W')
		{
			//Check to the right, down and diag-right for next 5 squares including this one.
			for(int y = 0; y < 6; y++)
			{
				//Check right
				if(game_board[x + y][x % (BOARD_SIZE - 1)] == 'W')
				{
					rstones++;
				}
				//Check down
				if(game_board[x + y][x % (BOARD_SIZE - 1) + y] == 'W')
				{
					dstones++;
				}
				//Check diagonal
				if(game_board[x + y][x % (BOARD_SIZE - 1) + y] == 'W')
				{
					diastones++;
				}
			}
			//play defensive move and decrement remaining moves/stones. 
			if(rstones >= 4)
			{
				
			}
			if(dstones >= 4)
			{

			}
			if(diastones >= 4)
			{

			}
		}
	}
	//If moves remaining, play offensive
	if(moves_remaining > 0)
	{
		ai_move_offensively();
	}
}

print_game_board();
}

// Used to print out the game board for visual display to the
// user.
void print_game_board()
{
int x, y = 0;

for( x = 0; x < (BOARD_SIZE*2)+1; x++ )
{
if( x%2 == 0 )
printf( "+" );
if( x%2 != 0 )
printf( "|" );
for( y = 0; y < BOARD_SIZE; y++ )
{
if( x%2 == 0 )
printf( "---+" );
if ( x%2 != 0 )
printf( " %c |", game_board[x/2][y] );
}
printf( "\n" );
}
}

void initialize_game_board()
{
int x, y = 0;

for( x = 0; x < BOARD_SIZE; x++ )
{
for( y = 0; y < BOARD_SIZE; y++ )
{
game_board[x][y] = ' ';
}
}
}

void play_move( int x, int y )
{
if( x > 1 && x < BOARD_SIZE && y > 1 && y < BOARD_SIZE && game_board[x-1][y-1] == ' ' )
{
printf( "Play Move: ( %d, %d )\n", x, y );
game_board[x-1][y-1] = 'W';
}

}