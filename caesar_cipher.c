#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 27

void getKey( char * );
void generateAlphabet( char *, char *, char * );
void printAlphabets( char *, char * );
void convertToUpper( char * );

int main() {

   char key[KEY_SIZE];

   char * plainAlphabet = "abcdefghijklmnopqrstuvwxyz";
   char cipherAlphabet[KEY_SIZE] = {"\0"};

   getKey( key );

   generateAlphabet( plainAlphabet, cipherAlphabet, key );

   printf("\nPlain alphabet:    %s\n\nCipher alphabet:   %5s\n", plainAlphabet, cipherAlphabet );

}

void getKey( char * k ) {

   printf("%s", "Enter key or new alphabet: ");
   fgets( k, KEY_SIZE, stdin );

}

void generateAlphabet( char * plnAlphabet, char * ciphAlphabet, char * k ) {

   char * endKey;
   size_t distance;

   strcpy( ciphAlphabet, k );

   endKey = strchr( ciphAlphabet, '\n');

   if ( endKey != NULL ) {

      distance = strcspn( plnAlphabet, endKey - 1);

      plnAlphabet += ( distance + 1 );       

      while ( strlen( ciphAlphabet ) < KEY_SIZE - 1 || *( ciphAlphabet + KEY_SIZE - 2 ) == '\n') {   

         for ( ; *plnAlphabet != '\0' ; ++plnAlphabet ) {       

            if ( strchr( ciphAlphabet, *plnAlphabet ) == NULL ) {

               *endKey = *plnAlphabet;
               ++endKey;
            }
         } 

         plnAlphabet -=  KEY_SIZE - 1;        
      }
   }

   convertToUpper( ciphAlphabet );

}

void convertToUpper( char * ciphAlphabet ) {

   for ( ; *ciphAlphabet != '\0' ; ++ciphAlphabet ) {

      *ciphAlphabet = toupper(*ciphAlphabet);
   }

}

/*Possible improvements:

- Right now a key containing more of the same letter will result in undefined behaviour; a function could be added so that repeated letters of the key will be eliminated.

- A function to encrypt the word with the given key.

- A less nested generateAlphabet function.*/

































