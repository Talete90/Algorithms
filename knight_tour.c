#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findRandMove( int av[] );
void moveKnight( int b[][8], int v[], int h[], int, int );
void printBoard( int b[][8] );
void reInitializeArray( int av[] );
int reInitializeBoard ( int b[][8]);

int main() {

    srand(time(NULL));

    int board [8][8] = {0};

    int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

    int currentRow;
    int currentColumn;
    int moves, tours = 0;

    for ( int j = 0 ; j < 8 ; ++j ) {

        for ( int k = 0 ; k < 8 ; ++k ) {

             currentRow = j;
             currentColumn = k;

             printf("Row: %d  Column: %d\n\n", j, k);

             moveKnight( board, vertical, horizontal, currentRow, currentColumn );

             printBoard( board );

             moves = reInitializeBoard( board );

             if ( moves == 64 ) {

                ++tours;

             }

             printf("Moves: %d\n", moves);

             puts("");

          }

    }

    printf("\nCompleted tours: %d\n", tours);

}

void moveKnight( int b[][8], int v[], int h[], int currentRow, int currentColumn ) {

   int accessibility [8][8] = {{2,3,4,4,4,4,3,2}, {3,4,6,6,6,6,4,3}, {4,6,8,8,8,8,6,4}, {4,6,8,8,8,8,6,4},
                        {4,6,8,8,8,8,6,4}, {4,6,8,8,8,8,6,4}, {3,4,6,6,6,6,4,3}, {2,3,4,4,4,4,3,2}};

   int accessibilityValues[8] = {0};

   int oldRow;
   int oldColumn;

   int static c = 1;
   int move;
   int check = 0;

   if ( c == 1 ) {

       b[currentRow][currentColumn] = 1;

   }

   for ( int i = 0 ; i < 8 ; ++i ) {

        oldRow = currentRow;
        oldColumn = currentColumn;

        currentRow = currentRow + v[i];
        currentColumn = currentColumn + h[i];

        if ( ( currentRow >= 0 && currentRow < 8) && ( currentColumn >= 0 && currentColumn < 8 ) && b[currentRow][currentColumn] == 0 ) {

              accessibilityValues[i] = accessibility[currentRow][currentColumn];

              currentRow = oldRow;
              currentColumn = oldColumn;

              check = 1;

        }

        else {

              currentRow = oldRow;
              currentColumn = oldColumn;

         }

    }

   if ( check == 1) {

       move = findRandMove( accessibilityValues );

       currentRow = currentRow + v[move];
       currentColumn = currentColumn + h[move];

       --accessibility[ oldRow ][ oldColumn ];

       b[currentRow][currentColumn] = ++c;

       reInitializeArray( accessibilityValues );

       moveKnight( b, v, h, currentRow, currentColumn );

     }

   c = 1;

}

void printBoard( int b[][8] ) {

    for ( int i = 0 ; i < 8 ; ++i ) {

        for ( int j = 0 ; j < 8 ; ++j ) {

            printf( "%5d   ", b[i][j]);

        }

        puts("\n");

    }

}

int findRandMove( int av[] ) {

   int smallest = 8;

   int randMove;

   int size = 0;

   for ( int i = 0 ; i < 8 ; ++i) {

        if ( av[i] <= smallest && av[i] != 0 ) {

            smallest = av[i];

        }

   }

   int storeSmallest[8] = {0};

   for ( int i = 0 ; i < 8 ; ++i) {

        if ( av[i] == smallest ) {

            storeSmallest[i] = smallest;
            ++size;

        }

   }

   int storeMoves[size];

   int c = 0;

   for ( int i = 0 ; i < 8 ; ++i) {

        if ( storeSmallest[i] != 0 ) {

           storeMoves[c] = i;
           ++c;

        }

   }

   randMove = storeMoves[ rand() % size ];

   return randMove;

}

void reInitializeArray ( int av[] ) {

   for ( int i = 0 ; i < 8 ; ++i) {

        av[i] = 0;

   }

}

int reInitializeBoard ( int b[][8]) {

     int greatest = 0;

     for ( int i = 0 ; i < 8 ; ++i) {

       for ( int j = 0 ; j < 8 ; ++j) {

            if ( b[i][j] >= greatest) {

                greatest = b[i][j];

            }

           b[i][j] = 0;

       }

    }

    return greatest;

}

