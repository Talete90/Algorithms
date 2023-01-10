#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void create_array( int [], int);
void swap( int [], int, int);
void print_array( int [], int );

int main() {

     srand(time(NULL));

     int size;

     size = rand() % 50;

     int arr[size];

     create_array( arr, size);

     print_array( arr, size);

     puts("\n");

     int last_position_0 = 0;
     int last_position_2 = size - 1;

     for ( size_t i = 0 ; i < size ; ++i ) {

          while ( ( arr[i] == 0 && i > last_position_0 ) || ( arr[i] == 2 &&  i < last_position_2 ) ) {

               if (  arr[i] == 2  ) {

                    swap( arr, i, last_position_2);
                    --last_position_2;
               }

               else if ( arr[i] == 0 ) {

                    swap( arr, i, last_position_0);
                    ++last_position_0;
               }
          }
     }

     print_array( arr, size );

     puts("\n");

}

void create_array( int a[], int s) {

     for ( size_t i = 0 ; i < s ; ++i ) {

          a[i] = rand() % 3;
     }
 }

void swap( int a[], int i, int last_p ) {

     int hold;

     hold = a[last_p];
     a[last_p] = a[i];
     a[i] = hold;

}

void print_array( int a[], int s ) {

     for ( size_t i = 0 ; i < s ; ++i ) {

          printf("%d ", a[i]);
     }
}
