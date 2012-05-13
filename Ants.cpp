#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
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

/**
 * Вычисление время полной встречи для заданной конфигурации
 * @param Directions конфигурация (1,0,0,1)
 * @param Positions координаты
 * @return 
 */
float getTime( std::vector< int > Directions, int Positions[], int Count ){
	
	int Po[ MAXN ];
	int Protiv[ MAXN ];
	int po, protiv;
	float totalTime;
	
	//cout << "Ants " << Count << " \n";
	
	
	// считаем время до встречи каждого идущего по часовой стрелки с каждым 
	// идущим против часовой
	po = 0;
	protiv = 0;
	for( int i = 0; i < Count; i++ ){
		//cout << "Ant" << i << " Dir-" <<Directions[i] << " pos-" << Positions[i] << "\n";  
		
		// разделим по направлениям
		if( Directions[i] == 0 ){
			Po[po] = Positions[i];
			//cout << Positions[i] << " ";
			po++;
		} else {
			Protiv[protiv] = Positions[i];
			//cout << Positions[i] << " ";
			protiv++;
		}
	}
	
	//cout << "Po " << po << " protiv " << protiv << " ";
	
	totalTime = 0;
	for( int i = 0; i < po; i++ ){
		for( int j = 0; j < protiv; j++ ){
			if( Po[i] > Protiv[j] ){
				totalTime = totalTime + ( S - modRazn( Po[i], Protiv[j] ) ) / (2 * V);
			} else {
				totalTime = totalTime + modRazn( Po[i], Protiv[j] ) / (2 * V);
			}
		}
	}
	//cout << "Total time " << totalTime << " \n" ;
	
	return totalTime;
	
}

/**
 * Посчитать кол-во встреч для заданной конфигурации
 * @param Directions направления
 * @param Positions координаты
 * @param Count общее кол-во
 * @return 
 */
int getMeetsCount( std::vector< int > Directions, int Positions[], int Count ){
	
	// разобьем муравьев по направления и попарно вычислим кол-во встреч 
	int Po[ MAXN ];
	int Protiv[ MAXN ];
	int po, protiv;
	int totalCount;
	float Time; // время первой встречи пары
	
	po = 0;
	protiv = 0;
	for( int i = 0; i < Count; i++ ){
		//cout << "Ant" << i << " Dir-" <<Directions[i] << " pos-" << Positions[i] << "\n";  
		
		// разделим по направлениям
		if( Directions[i] == 0 ){
			Po[po] = Positions[i];
			//cout << Positions[i] << " ";
			po++;
		} else {
			Protiv[protiv] = Positions[i];
			//cout << Positions[i] << " ";
			protiv++;
		}
	}
	
	totalCount = 0;
	for( int i = 0; i < po; i++ ){
		for( int j = 0; j < protiv; j++ ){
			// найдем время их встречи
			if( Po[i] > Protiv[j] ){
				Time = ( S - modRazn( Po[i], Protiv[j] ) ) / (2 * V);
				
			} else {
				Time = modRazn( Po[i], Protiv[j] ) / (2 * V);
			}
			// теперь посчитаем 
			totalCount = totalCount + ( floor((T - Time) / ( S / (2 * V) )) + 1 )*2;
		}
	}
	
	return totalCount;
}

int getFirstMeetTime( int x1, int x2){
	
	
}

float solve( int Count, int Positions[] ){
	
	// конфигурация
	//int Directions[ MAXN ];
	int i, Return;
	std::vector< int > Directions;
	std::vector< int > tmp;
	
	float Times[1000][3];
	
	Times[0][0] = 0;
	Times[0][1] = 0;
	Times[0][3] = 0;
	
	//
	Directions.push_back(1);
	for( i = 1; i < Count; i++ ){
		tmp = Directions;
		Directions = vector<int>();
		tmp.push_back(0);
		//cout << tmp[0] << "  " << tmp[1]<< " ";
		// [[] 0]
		Times[i][0] = Times[i-1][3] + getTime( tmp, Positions, i+1 );
		tmp.pop_back();
		tmp.push_back(1);
		// [[] 1]
		Times[i][1] = Times[i-1][3] + getTime( tmp, Positions, i+1 );
		if( Times[i][0] > Times[i][1] ){
			Directions.push_back(1);
			Times[i][3] = Times[i][1];
		} else {
			Directions.push_back(0);
			Times[i][3] = Times[i][0];
		}
		
	}
	
	tmp = Directions;
	Directions = vector<int>();
	Return = getMeetsCount( tmp, Positions, Count );
	
	return Return;
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
	
	//R = getFirtsAntDirection( Positions[0], Positions[1] );
	//cout << R[0] << " " << R[1] << "\n";
	//cout << floor((T - R[1]) / ( S / (2 * V) )) + 1;
	cout << solve( i, Positions );
	return 0;
}