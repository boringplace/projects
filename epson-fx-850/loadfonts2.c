#include <stdio.h>

int data[] = { 0, 80, 170, 0, 47, 0, 170, 80, 0 };
int *cursor = data;

void READ(int *v) {
    *v = *cursor;
    cursor++;
}

#define PUTC(a) putc(a, stdout)

int main() {
    for (unsigned char p = 58; p < 64; p++) {
	PUTC(p);
	PUTC(' ');
//	PUTC('\n'); PUTC('\r');
    }
    PUTC('\n'); PUTC('\r');
    int k = 1;
    int a;
    if (k > 3) {
	a = 58;
    }
    else {
	a = 60;
    }
    PUTC(27); PUTC(':'); PUTC(0); PUTC(0); PUTC(0);
//	PUTC('\n'); PUTC('\r');
    PUTC(27); PUTC('%'); PUTC(1); PUTC(0);
//	PUTC('\n'); PUTC('\r');
    PUTC(27); PUTC('&'); PUTC(0); PUTC(a); PUTC( a - 1 + k );
//	PUTC('\n'); PUTC('\r');
    for ( int z = 1; z <= k; z++) {
	PUTC(128);
	    //PUTC('\n'); PUTC('\r');
	for ( int x = 1; x <= 9; x++) {
	    int r;
	    READ(&r);
	    PUTC(r);
	//	PUTC('\n'); PUTC('\r');
	}
	PUTC(0); PUTC(0);
	//    PUTC('\n'); PUTC('\r');
    }
    for (unsigned char p = 58; p < 64; p++) {
	PUTC(p);
	PUTC(' ');
	//PUTC('\n'); PUTC('\r');
    }
    PUTC('\n'); PUTC('\r');
    return 0;
}
