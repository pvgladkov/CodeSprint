/**
 * Dynamic programming 
 */
#include<iostream>
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
using namespace std ;
#define INF (int)1e9
#define MAXN 100002
#define debug true

long long counter( long long Values[] ){
	
	long long Summ = 0;
	int i = 0;
	while( long long val = Values[i] ){
		Summ = Summ + val;
		i++;
	}
	return Summ;
}
/*
int solve( int Values[], int Count, int CountTogether ){

	int StartSumm;
	int MaxSumm;
	int Summs[ MAXN ];
	int Summ;
	int DeleteItem;
	
	// посчитаем сумму всех значений на момент старта
	StartSumm = counter( Values );
	Summ = StartSumm;
	for( int j = 0; j < CountTogether + 1; j++ ){
		DeleteItem = j;
		while( DeleteItem < Count - CountTogether + 1){
			Summ = Summ - Values[ DeleteItem ];
			
			DeleteItem = DeleteItem + CountTogether + 1;
		}
		Summs[j] = Summ;
	}
	
	/*
	for( int j = 0; j < CountTogether + 1; j++ ){
		Summ = StartSumm;
		for( int i = j; i < Count+1; i++ ){
			if( ((i-j) % CountTogether) == 0 ){
				Summ = Summ - Values[ i + 1];
			}
		}
		Summs[j] = Summ;
	}
	*/
	
	// вывод всех сумм
	//			
	//for( int i = 0; i < CountTogether+1; i++ ){
	//	cout << Summs[i] << " "; 
	//}
	
	/*
	// определение максимальной суммы
	MaxSumm = Summs[0];
	for( int i = 0; i < CountTogether; i++ ){
		if( Summs[i] > MaxSumm ){
			MaxSumm = Summs[i];
		}
	}
	
	return MaxSumm ;
}

int solve_2( int Values[], int Count, int CountTogether ){
	
	int LocalMin, StartSumm;
	int DeleteItemNumber, DeleteItemValue;
	
	// посчитаем сумму всех значений на момент старта
	StartSumm = counter( Values );
	int i = 0;
	while( i < Count ){
		LocalMin = Values[ i + 1 ];
		for( int j = i + 1; j < i + CountTogether + 1; j++  ){
			if( LocalMin >= Values[j] ){
				LocalMin = Values[j];
				DeleteItemNumber = j;
			}
		}
		StartSumm = StartSumm - LocalMin;
		i = DeleteItemNumber;
	}
	
	return StartSumm;
}
*/
long long solve_3( long long Values[], int Count, int CountTogether ){
	
	long long StartSumm;
	long long DeleteItem;
	int DeleteItemNum;
	int Limit;
	int i;
	//int j;
	
	// посчитаем сумму всех значений на момент старта
	StartSumm = counter( Values );
	
	Limit = CountTogether;
	i = 0;
	
	while( i < Count - CountTogether ){
		DeleteItem = Values[i];
		for( int j = i; j < Limit; j++ ){
			if( DeleteItem >= Values[j] ){
				DeleteItem = Values[j];
				DeleteItemNum = j;
			}
			
		}
		if( debug ){
			cout << "delete number: " << DeleteItemNum << "\n";
		}
		StartSumm = StartSumm - DeleteItem;
		Limit = i + CountTogether + 1;
		i = DeleteItemNum + 1;
	}
	
	return  StartSumm;
}

int main() {
	
	int Runs, CountTogether, Profit ;
	long long Values[ MAXN ]; // полезности билбордов
	
	cin >> Runs >> CountTogether;
	int i = 0;
	while( Runs-- ){
		cin >> Values[ i ];
		i++;
	}
	Profit = solve_3( Values, i, CountTogether );
	cout << Profit << endl;
	return 0 ;
}