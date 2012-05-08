#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std ;
#define INF (int)1e9
#define MAXN 100002

long long solve( char String[] ){
    
    int Count = 0;	
	int Len = strlen( String );
	
	for( int i = 0; i < Len; i++ ){

		for( int j = 0; j< Len; j++ ){

			if( String[ j ] == String[ i + j ] ){
				Count++;
			} else {
				break;
			}
		}

	}
	
	return Count;
}

int main() {
    int runs ;
    char string[MAXN]; // строка
    cin >> runs ;
    while(runs--){
        cin >> string ;
        long long ret = solve(string) ;
        cout << ret << endl ;
    }
    return 0 ;
}