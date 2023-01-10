#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

void load( int *);
void execute( int [], int *, int *, int *, int *, int * );
void dump( int[], int *, int *, int *, int *,int *);

int main() {

     int memory[SIZE] = {0};

     int accumulator = 0;
     int instructionCounter = 0;
     int instructionRegister = 0;
     int operationCode = 0;
     int operand = 0;

     int end = false;

     puts("*** Welcome to simpletron! ***");
     puts("*** Please enter your program one instruction ***");
     puts("*** (or data word ) at a time. I will type the ***");
     puts("*** location number and the question mark (?). ***");
     puts("*** You then type the word for that location ***");
     puts("*** Type -99999 to stop entering your program *** ");
     puts("");

     load( memory );

     while ( end == false ) {

          instructionRegister = memory[instructionCounter];
          operationCode = instructionRegister / 100;
          operand = instructionRegister % 100;

          execute( memory, &operationCode, &operand, &accumulator, &instructionCounter, &end );

     }

     dump( memory, &accumulator, &instructionCounter, &instructionRegister, &operationCode, &operand );

}

void load( int *mem ) {

     for ( size_t i = 0 ; i < SIZE ; ++i ) {

          printf("%02lu  ?  ", i);
          scanf("%d", mem );

          while ( ( *mem < -9999 || *mem > 9999 ) && *mem != -99999 ) {

               puts("");
               puts("*** Invalid number *** ");
               puts("");

               printf("%02lu  ?  ", i);
               scanf("%d", mem );
          }

          if ( *mem == -99999 ) {

               *mem = 0;
               break;
          }

          ++mem;
     }

     puts("");
     puts("*** Program loading completed ***");
     puts("*** Program execution begins ***");
     puts("");
}

void execute( int *mem, int *opCode, int *oper, int * acc, int * instrC, int *e) {

     switch ( *opCode ) {

     case READ:

          printf("%c  ", '?');
          scanf("%d", mem + *oper);
          *instrC = *instrC + 1;
          break;

     case WRITE:

          printf("\n%+05d", *(mem + *oper) );
          puts("");
          *instrC = *instrC + 1;
          break;

     case LOAD:

          *acc = *(mem + *oper);
          *instrC = *instrC + 1;
          break;

     case STORE:

          *(mem + *oper) = *acc;
          *instrC = *instrC + 1;
          break;

     case ADD:

          *acc = *acc + *(mem + *oper);
          *instrC = *instrC + 1;
          break;

     case SUBTRACT:

          *acc = *acc - *(mem + *oper);
          *instrC = *instrC + 1;
          break;

     case DIVIDE:

          if ( *(mem + *oper) == 0 ) {

               *acc = 0;
               *e = true;
               puts("");
               puts("*** Attempt to divide by zero ***");
               puts("*** Execution abnormally terminated ***");
          }

          else {

               *acc = *acc / *(mem + *oper);
               *instrC = *instrC + 1;
          }

          break;

     case MULTIPLY:

          *acc = *acc * *(mem + *oper);
          *instrC = *instrC + 1;
          break;

     case BRANCH:

          *instrC = *oper;
          break;

     case BRANCHNEG:

          *acc < 0  ?  *instrC = *oper  :  (*instrC = *instrC + 1);
          break;

     case BRANCHZERO:

          *acc == 0  ?  *instrC = *oper  :  (*instrC = *instrC + 1);
          break;

     case HALT:

          *e = true;
          puts("");
          puts ("*** Simpletron execution terminated ***");
          break;

     default:

          *e = true;
          puts("");
          puts("*** Invalid operative code ***");
          puts("*** Execution abnormally terminated ***");
     }

     if ( *acc < -9999 || *acc > 9999 ) {

          *acc > 0  ?  (*acc = 9999)  :  (*acc = -9999);
          *e = true;
          puts("");
          puts("*** Accumulator overflow ***");
          puts("*** Execution abnormally terminated ***");
     }

}

void dump( int mem[], int *acc, int *instC, int *instR, int *opC, int *op ) {

     puts("\nREGISTERS:\n");
     printf("accumulator:             %+05d\n", *acc );
     printf("instructionCounter:      %01d\n", *instC );
     printf("instructionRegister:     %+05d\n", *instR );
     printf("operationCode:           %01d\n", *opC );
     printf("operand:                 %02d\n", *op );

     puts("\nMEMORY:\n");
     puts("        0      1      2      3      4      5      6      7      8      9");

     printf("%s", "0 ");

     for ( size_t i = 0 ; i < SIZE ; ++i ) {

          printf("  %+05d", mem[i] );

          if ( ( i + 1 ) % 10 == 0 && i != 99) {

               puts("");
               printf("%lu", i + 1);
          }
     }

}


