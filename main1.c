#include <stdio.h>
#include <stdlib.h>

#define SQUARE(x) ((x)*(x))
#define SUM(x,y) ((x)+(y))

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int a = 5;
	
	printf("%d %d\n", SQUARE(a), SUM(a,3));

	
	return 0;
}
