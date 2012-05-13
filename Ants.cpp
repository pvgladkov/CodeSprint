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

#define debug true

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
	
	if( debug ){
		// проверим что координаты верно передались 
		for( int i = 0; i < Count; i++ ){
			cout << Positions[i] << " ";
		}
		cout << "\n";
	}
	
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
	
	if( debug ){
		cout << " расклад по позициям: \n";
		cout << "по ";
		for( int i = 0; i < po; i++ ){
			cout << Po[i] << " ";
		}
		cout << "\n против ";
		for( int i = 0; i < protiv; i++ ){
			cout << Protiv[i] << " ";
		}
		cout << "\n";
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
long long getMeetsCount( std::vector< int > Directions, int Positions[], int Count ){
	
	// разобьем муравьев по направления и попарно вычислим кол-во встреч 
	int Po[ MAXN ];
	int Protiv[ MAXN ];
	int po, protiv;
	long long totalCount;
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

long long solve( int Count, int Positions[] ){
	
	// конфигурация
	//int Directions[ MAXN ];
	int i;
	long long Return;
	std::vector< int > Directions;
	std::vector< int > tmp;
	
	float Times[1000][3];
	
	Times[0][0] = 0;
	Times[0][1] = 0;
	Times[0][3] = 0;
	
	if( debug ){
		// проверим что координаты верно передались 
		for( int i = 0; i < Count; i++ ){
			cout << Positions[i] << " ";
		}
		cout << "\n";
	}
	
	// надо решить как расположить первые два
	// [0 1] или [1 0]
	// [0 1]
	Directions.push_back(0);
	Directions.push_back(1);
	Times[1][1] = getTime( Directions, Positions, 2 );
	Directions.pop_back();
	Directions.pop_back();
	Directions.push_back(1);
	Directions.push_back(0);
	Times[1][0] = getTime( Directions, Positions, 2 );
	Directions.pop_back();
	Directions.pop_back();
	if( Times[1][1] > Times[1][0] ){
		Times[1][3] = Times[1][0];
		Directions.push_back(1);
		Directions.push_back(0);
	} else {
		Times[1][3] = Times[1][1];
		Directions.push_back(0);
		Directions.push_back(1);
	}
	
	if( debug ){
		cout << "оптимальный выобр начальной конфигурации: " 
			<< Directions[0] << " " << Directions[1] << "\n"
		;
	}
	
	for( i = 2; i < Count; i++ ){
		tmp = Directions;
		Directions = vector<int>();
		tmp.push_back(0);
		//cout << tmp[0] << "  " << tmp[1]<< " ";
		// [[] 0]
		Times[i][0] = Times[i-1][3] + getTime( tmp, Positions, i+1 );
		if( debug ){
			cout << "время если последний 0: " << Times[i][0] << "\n";
		}
		tmp.pop_back();
		tmp.push_back(1);
		// [[] 1]
		Times[i][1] = Times[i-1][3] + getTime( tmp, Positions, i+1 );
		if( debug ){
			cout << "время если последний 1: " << Times[i][1] << "\n";
		}
		if( Times[i][0] > Times[i][1] ){
			Directions.push_back(1);
			Times[i][3] = Times[i][1];
		} else {
			Directions.push_back(0);
			Times[i][3] = Times[i][0];
		}
		
		if( debug ){
			
			cout << " конфигурация для шага " << i << ": ";
			for( int j = 0; j < i+1; j++ ){
				cout << Directions[j] << " ";
			}
			cout << "\n";
		}
		
	}
	
	tmp = Directions;
	Directions = vector<int>();
	
	if( debug ){
	
		cout << "\n";
		cout << "финальная конфигурация: ";
		for( int i = 0; i < Count; i++ ){
			cout << tmp[i] << " ";
		}
		cout << "\n";
	}
	
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