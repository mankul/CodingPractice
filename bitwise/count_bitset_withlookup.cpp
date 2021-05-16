

#include<stdio.h>


#define A(n) n, n+1, n+1, n+2
#define B(n) A(n), A(n+1), A(n+1), A(n+2)
#define C(n) B(n), B(n+1), B(n+1), B(n+2)
//#define D(n) C(n),C(n+1), C(n+1), C(n+2)

#define count_bits C(0), C(1), C(1), C(2)

#define table_size 256




int bit_array[table_size]  = { count_bits };


int count_set_bits( int number)
{

int count= bit_array[number & 255] + bit_array[number>>8 & 255] + bit_array[number>>16 & 255] + bit_array[number>>24 & 255];

return count;
}

int main()
{

int test_cases;
int number;
scanf("%d", &test_cases);


for( int i = 0; i< test_cases; i++)
{
scanf("%d",&number);

printf("%d\n", count_set_bits(number));


//for(int i =0; i< table_size; i ++){
//	printf("%d\t%d\n", i, bit_array[i]);
//	}

}


return 0;

}



