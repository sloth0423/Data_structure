#include <stdio.h>
#define WHITE 0
#define BLACK 1
#define YELLOW 2
int screen[30][30];
char read_pixel(int x, int y) {
	return screen[x][y];
}
void write_pixel(int x, int y,int color) {
	screen[x][y] = color;
}
void flood_fill(int x, int y) {
	
	if (read_pixel(x, y) == WHITE) {
		write_pixel(x, y, BLACK);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				printf("%d", screen[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		flood_fill(x + 1, y);
		flood_fill(x - 1, y);
		flood_fill(x, y + 1);
		flood_fill(x, y - 1);
	}
}
int main(){
	for (int i = 0; i < 10; i++) {
		screen[0][i] = 2;
		screen[9][i] = 2;
		screen[i][0] = 2;
		screen[i][9] = 2;
	}
	screen[1][2] = 2;
	screen[1][4] = 2;
	screen[1][5] = 2;
	screen[1][7] = 2;
	screen[2][4] = 2;
	screen[2][7] = 2;
	screen[3][1] = 2;
	screen[5][1] = 2;
	screen[5][8] = 2;
	screen[6][1] = 2;
	screen[6][2] = 2;
	screen[6][7] = 2;
	screen[6][8] = 2;
	screen[7][5] = 2;
	screen[8][1] = 2;
	screen[8][2] = 2;
	screen[8][3] = 2;
	screen[8][5] = 2;
	screen[8][7] = 2;
	screen[8][8] = 2;
	
	flood_fill(3, 3);
}

//#include <stdio.h>
//int ackermann(int m, int n) {
//	int stack[4092];
//	stack[0] = m;
//	stack[1] = n;
//	int last = 1;
//	int length = 2;
//	while (length != 1) {
//		if (stack[last] == 0) {
//			stack[last] += 1;
//			stack[last - 1] -= 1;
//		}
//		else if (stack[last - 1] == 0) {
//			stack[last - 1] = stack[last] + 1;
//			stack[last] = 0;
//			last -= 1;
//			length -= 1;
//		}
//		else{
//			stack[last + 1] = stack[last] - 1;
//			stack[last] = stack[last - 1];
//			stack[last - 1] -= 1;
//			last += 1;
//			length += 1;
//		}
//	}
//	return stack[0];
//}
//
//int main() {
//	int input1 = 3;
//	int input2 = 2;
//	int rslt = ackermann(input1, input2);
//	printf("%d\n", rslt);
//	return 0;
//}

//#include <stdio.h>
//int ackermann(int m, int n) {
//	if (m == 0) return n + 1;
//	else if (n == 0) return ackermann(m - 1, 1);
//	else return ackermann(m - 1, ackermann(m, n - 1));
//}
//
//int main() {
//	int input1 = 2;
//	int input2 = 3;
//	int rslt = ackermann(input1, input2);
//	printf("%d\n", rslt);
//	return 0;
//}

//#include <stdio.h>
// int bi_co(int n, int k){
//	int n1 = 1;
//	int n2 = 1;
//	for(int i = n; i > k; i--){
//		n1 *= i;
//		n2 *= i - k;
//	}
//	return n1 / n2;
//}
//
//int main() {
//	int input1 = 6;
//	int input2 = 3;
//	int rslt = bi_co(input1, input2);
//	printf("%d\n", rslt);
//	return 0;
//}

//#include <stdio.h>
//void unknown(){
//	int ch;
//	if ((ch = getchar()) != '\n') {
//		unknown();
//	}
//	putchar(ch);
//}
//
//int main() {
//	unknown();
//	return 0;
//}

//#include <stdio.h>
//void hanoi_tower(int n, char from, char tmp, char to) {
//	if (n == 1) {
//		printf("원판 1을 %c에서 %c로 옮긴다.\n", from, to);
//	}
//	else {
//		hanoi_tower(n - 1, from, to, tmp);
//		printf("원판 %d를 %c에서 %c로 옮긴다.\n", n, from, to);
//		hanoi_tower(n - 1, tmp, from, to);
//	}
//}
//
//int main() {
//
//	hanoi_tower(5, 'A', 'B', 'C');
//	return 0;
//}
//
//#include <stdio.h>
//int fib(int n) {
//	int prev = 0;
//	int now = 1;
//	int next;
//	if (n == 0) {
//		return prev;
//	}
//	if (n == 1) {
//		return now;
//	}
//	for (int i = 1; i < n; i++) {	
//	next = prev + now;
//	prev = now;
//	now = next;
//	}
//	return next;
//}
//
//int main() {
//	int idx = 10000;
//	int rslt = fib(idx);
//	printf("%d\n", rslt);
//	return 0;
//}

//#include <stdio.h>
//int fib(int n) {
//	if (n == 0) return 0;
//	else if (n == 1) return 1;
//	else return fib(n - 2) + fib(n - 1);
//}
//
//int main() {
//	int idx = 10000;
//	int rslt = fib(idx);
//	printf("%d\n", rslt);
//	return 0;
//}

/*#include <stdio.h>
double power(double x, int n) {
	if (n == 0) {
		return 1;
	}
	else if (n % 2 == 0) {
		return power(x*x, n / 2);
	}
	else if (n % 2 == 1) {
		return x * power(x*x, (n-1)/2 );
	}

}

int main() {
	double num = 2;
	int input = 10;
	double rslt = power(num, input);
	printf("%g", rslt);
	return 0;
}*/

//#include <stdio.h>
//double power(double x, int n) {
//	double result = 1.0;
//	for (int i = 0; i < n; i++) {
//		result *= x;
//	}
//	return result;
//}
//
//int main() {
//	double num = 2;
//	int input = 10;
//	double rslt = power(num,input);
//	printf("%d", rslt);
//	return 0;
//}


//#include <stdio.h>
//int sub(int n) {
//	int num = 0;
//	for(; n > 0 ;n -= 3){
//		num += n;
//	}
//	return num;
//}
//
//int main() {
//	int input = 10;
//	int rslt = sub(input);
//	printf("%d", rslt);
//	return 0;
//}


//#include <stdio.h>
//int fac(int n) {
//	if (n == 0) 
//		return 1;
//	else {
//		int rslt = 1;
//		for (;n > 0; n--){
//			rslt = rslt * n;
//		}
//		return rslt;
//	}
//}
//int main() {
//	int input = 5;
//	int rslt = fac(input);
//	printf("%d", rslt);
//	return 0;
//}

//#include <stdio.h>
//int fac(int n) {
//	if (n <= 1) return 1;
//	else return n * fac(n - 1);
//}
//int main() {
//	int input = 5;
//	int rslt = fac(input);
//	printf("%d", rslt);
//	return 0;
//}