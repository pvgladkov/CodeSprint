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


int main() {
    int runs ;
    char HumanDNA[ MAXN ]; // днк человека
    char Virus[ MAXN ];
    cin >> runs ;
    while(runs--){
        cin >> HumanDNA >> Virus ;
        solve( HumanDNA, Virus) ;
        cout << "\n" ;
    }
    return 0 ;
}