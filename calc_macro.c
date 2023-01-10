#include <stdio.h>

void readValues( char *[], float [], float * );
void calculateMacro ( float [], float [], float * );

int main() {
	
	char *macro[4] = { "Calories", "Carbohydrates", "Proteins", "Fats" };
	
	float macro100[4];
	float calc_macro100[4];
	
	float amount;
	
    readValues( macro, macro100, &amount );
    
    calculateMacro( macro100, calc_macro100, &amount );
    
    puts("\n------------------------------------------------------------------");
    
    printf("\n%34s%19s\n\n", "Original values", "New values");
    
    size_t i = 0;
    
    for ( i = 0 ; i < 4 ; ++i ) {
    	
    	printf("\n%-13s%20.2f%20.2f\n", macro[i], macro100[i], calc_macro100[i] );
    }
    
}

void readValues( char *m[], float m100[], float * a ) {
	
	size_t i = 0;
	
	puts("Enter value per 100 gr :\n");
	
	for (  i = 0 ; i < 4 ; ++i ) {
		
		printf(" %13s -->  ", m[i]);
		scanf("%f", &m100[i] );
	}
	
	printf( "\n%s", "Enter the amount of food in gr. you wish to calculate:  " );
	scanf("%f", a);
}

void calculateMacro ( float m100[], float c_m100[], float * a ) {
	
	size_t i = 0;
	
	for (  i = 0 ; i < 4 ; ++i ) {
		
		c_m100[i] = (*a) * ( m100[i] / 100 );
    }
}
