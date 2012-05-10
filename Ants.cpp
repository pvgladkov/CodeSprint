#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std ;
#define MAXN 100002

#define S 1000
#define V 0.1
#define T 1000000006

int modRazn( int a, int b ){
	if( a >= b ){
		return a - b;
	} else {
		return b - a;
	}
}
/**
 * Получить направление движения первого муравья
 * @param x1
 * @param x2
 * @return boolean 1 - по часовой 0 - против
 */
int* getFirtsAntDirection( int x1, int x2 ){
	
	float t1, t2;
	int* R = new int[2];
	
	t1 = modRazn( x1, x2 ) / (2 * V);
	
	t2 = ( S - modRazn( x1, x2 ) ) / (2 * V);
	
	if( t1 = t2 ){
		R[0] = 1;
		R[1] = t1;
		return R;
	}
	
	if( t1 > t2 ){
		R[0] = (int)( x1 > x2 );
		R[1] = t2;
	} else {
		R[0] = (int)( x2 >= x1 );
		R[1] = t1;
	}
	
	return R;
}

int getFirstMeetTime( int x1, int x2){
	
	
}

int solve( int Count, int Positions[] ){
	
}

int main(){
	
	int Count;
	int i = 0;
	int Positions[ MAXN ];
	int* R;
	
	cin >> Count;
	while( Count-- ){
		scanf( "%d", &Positions[i] );
		i++;
	}
	R = getFirtsAntDirection( Positions[0], Positions[1] );
	cout << R[0] << " " << R[1] << "\n";
	cout << floor((T - R[1]) / ( S / (2 * V) )) + 1;
	//cout << solve( Count, Positions );
	return 0;
}