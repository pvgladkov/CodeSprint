#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std ;
#define INF (int)1e9
#define MAXN 100002

int solve( char String[], char Pattern[] ){
    
	int LenString = strlen( String );
    int LenPattern = strlen( Pattern );
	
	for( int i = 0; i < LenString - LenPattern + 1; i++ ){

        int CountMismatch = 0;
        for( int j = 0; j < LenPattern; j++  ){
            if( CountMismatch > 1 ){
                break;
			}

            if( Pattern[j] != String[ i + j ]){
                CountMismatch++;
            }
		}
        if( CountMismatch < 2 ){
            cout << i << " ";
		}

	}

}
/*
int BoyerMooreHorspool(char *haystack, char *needle) {

	int i,j,k, needle_len = 0,haystack_len = 0;
	int needle_table[256];
	
 
	// длина куска
	for (char *p = needle; *p; *p++){
		++needle_len;
	}
	
	// длина текста
	for( char *p = haystack; *p; *p++ ){
		++haystack_len;
	}
 
	if( needle_len < haystack_len ) {
        
		// заполняем таблицу вхождений
		for( i = 0; i < 256; i++ ){
			needle_table[ i ] = needle_len;
		}
		
		for( i = 1; i < needle_len; i++ ){
			needle_table[ needle[ i - 1 ] ] = needle_len - i;
		}

		i = needle_len;
		j = i;

		while( j > 0 && i <= haystack_len ) {

			j = needle_len;
			k = i;
			while( j > 0 && haystack[k-1] == needle[ j - 1 ] ) {                     
				--k;
				--j;
			}
			i + = needle_table[ haystack[ i - 1 ] ];
		}

		if( k > haystack_len - needle_len ){
			return 0;
		} else {
			return k + 1;
		}
	} else {
		return 0;
	}
}
**/

int smartSolve( char String[], char Pattern[] ){
	
	int i, j, k, Errors ;
	int Table[ MAXN ];
	
	// длина строки
	int LenString = strlen( String );
    int LenPattern = strlen( Pattern );
	
	// строим таблицу смещений
	for( int i = 0; i <= 255; i++ ) {
		Table[ i ] = LenPattern;
	}
	for( int i = 0; i < LenPattern - 1; i++ ) {
        Table[ LenPattern - i - 1 ] = Pattern[ i ];
    }
	
	// символ с которго начинаем сравнение
	i = LenPattern - 1;
	
    j = i;
    k = i;
    while( j >= 0 && i <= LenString - 1 ) {
        j = LenPattern - 1;
        k = i;
		Errors = 0;
        while( j >= 0 && ( String[k] == Pattern[j] ) ) {

            k--;
            j--;
        } 
        i += Table[ String[ i ] ];
    }
    if (k >= LenString - LenPattern) {
        return -1;
    } else {
        cout << k + 1;
    }

}
   

int main() {
	int runs ;
	char HumanDNA[ MAXN ]; // днк человека
	char Virus[ MAXN ];
	cin >> runs ;
	while(runs--){
		cin >> HumanDNA >> Virus ;
		smartSolve( HumanDNA, Virus) ;
		cout << "\n" ;
	}
	return 0 ;
}