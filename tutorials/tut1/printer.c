#include <stdio.h>

int main(){
	int i;
	for(i = 0; i < 20; ++i){
		// Even numbers to stdout
		if(i % 2 == 0) fprintf(stdout,"%d\n",i);

		// Odd numbers to stderr
		else fprintf(stderr,"%d\n",i);
	}
}
