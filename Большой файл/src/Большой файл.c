/*
 ============================================================================
 Name        : Большой.c
 Author      : D.Linnik
 Version     :
 Copyright   : lol
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <stdint.h>



#define CFREE(x) { free(x); x = NULL; }
#define FILE_SIZE 100000000
#define SAMPLE_SIZE 4

extern int posix_memalign(void**, size_t, size_t);

int find_cashsize() {
	int l1dcls = sysconf(_SC_LEVEL1_DCACHE_LINESIZE);
	if( l1dcls == -1 )
		l1dcls = sizeof(void*);
	return l1dcls;
}

int make_random_file( FILE* f, size_t size, char * name ) {
	f = fopen( name, "wb" );
	if(!f) {
		printf( "File can't be open \n" );
		return 0;
	}
	char * tmp = malloc( size * sizeof( char ) );
	if(!tmp) {
		printf( "NULL returned \n" );
		return 0;
	}
	int i, err_code = 0;
	for( i = 0; i < size; i++ ) {
		*( tmp + i ) = rand() % 94 + 32;
	}
	err_code = fwrite( tmp, sizeof( char ), size, f );
	if( err_code < size ) {
		printf( "Wrong write operation \n" );
		return 0;
	}
	CFREE( tmp );
	err_code = fclose( f );
	if( err_code == EOF ) {
		printf("File not closed");
		return 0;
	}
	return 1;
}

char * read_file( FILE * f, size_t size, char * name ) {
	int l1dcls = find_cashsize();
	char * data = NULL;
	size_t err_code = 0;
	err_code = posix_memalign( (void**)&data, l1dcls, size * sizeof( char ) );
	if(err_code != 0) {
		printf( "Wrong work of posix_memalign() \n" );
		return NULL;
	}
	f = fopen( name, "rb");
	if(!f) {
		CFREE( data );
		printf( "File can't be open \n" );
		return NULL;
	}
	err_code = fread( data, sizeof( char ), size, f );
	if( err_code < size ) {
			printf( "Wrong read operation \n" );
			CFREE( data );
			return NULL;
	}
	err_code = fclose( f );
	if( err_code == EOF ) {
		printf("File not closed");
	}
	return data;
}

int compare( char * a, char * b, size_t size ) {
	for(int i = 0; i < size; i++) {
		if( *(a + i) != *(b + i) )
			return 0;
	}
	return 1;
}

int find_position( char * sample, size_t sample_size, char * file, size_t file_size) {
	int i = 0;
	for(; i < file_size; i++) {
		if( *(sample) == *(file + i) ) {
			if(compare( sample, file + i, sample_size ))
				return i;
		}
	}
	return -1;
}



int find_position_opti2( char * sample, size_t sample_size, char * file, size_t file_size) {
	int i = 0;
	for(; i < file_size; i+=4) {
		if( *(sample) == *(file + i) ) {
			if(compare( sample, file + i, sample_size ))
				return i;
		}
		if( *(sample) == *(file + i + 1) ) {
			if(compare( sample, file + i + 1, sample_size ))
				return i;
		}
		if( *(sample) == *(file + i + 2) ) {
			if(compare( sample, file + i + 3, sample_size ))
				return i;
		}
		if( *(sample) == *(file + i + 3) ) {
			if(compare( sample, file + i + 3, sample_size ))
				return i;
		}
	}
	return -1;
}

int main(void) {
    long usec;
    struct timeval tv1, tv2;
    gettimeofday(&tv1, NULL);



	srand(time(NULL));
	FILE *fp = NULL;
	char * file_name = "my_file.txt";
	char sample [SAMPLE_SIZE] = { 'd', 'o', 'c', 'k' };
	char * sample_m = NULL;
	int l1dcls = find_cashsize();
	size_t err_code = 0;
	err_code = posix_memalign( (void**)&sample_m, l1dcls, sizeof( sample ) );
	if(err_code != 0) {
		printf( "Wrong work of posix_memalign() \n" );
		return 0;
	}
	for(int i = 0 ;i < SAMPLE_SIZE; i++)
		*(sample_m + i) = *(sample + i);
//	err_code = make_random_file( fp, FILE_SIZE, file_name );
//	if( !err_code ) {
//		CFREE( sample_m );
//		return 0;
//	}
	char * text;
	text = read_file( fp, FILE_SIZE, file_name );
	if( !text ) {
		CFREE( sample_m );
		CFREE( text );
		return 0;
	}

	int pos = find_position_opti2( sample_m, SAMPLE_SIZE, text, FILE_SIZE);

    gettimeofday(&tv2, NULL);

    usec  = (tv2.tv_sec - tv1.tv_sec) * 1000000L +
            (tv2.tv_usec - tv1.tv_usec);

    printf("Execution time:\t%10ld microseconds\n", usec);

	printf( "%d", pos+1 );
	CFREE( text );
	CFREE( sample_m );
	return EXIT_SUCCESS;
}
