#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
	int top;
	char data[4];
} stack;

char *intToRoman(int num) {
    if (num > 3999) return NULL;

    char *res = (char *)malloc(17);
    memset(res, '\0', 17);
	res += 15;

    char roman[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	stack st = {0, {'\0'}};
    int pow = 0;
    while (num % 10 > 0 || num / 10 > 0) {
		st.top = 0;
	    int mod = num % 10;
	    num /= 10;
	
	    char one,fiv,ten;
	    one = roman[pow];fiv = roman[pow+1];ten = roman[pow+2];

		int roman_size = 0;
	        
	    // 1,2,3 -> I,II,III
	    if (mod >=1 && mod < 4) {
		    while (--mod >= 0) {
				st.data[st.top++] = one;
		    }
	    } else if (4 == mod) {
			st.data[st.top++] = fiv;
			st.data[st.top++] = one;
	    } else if (9 == mod) {
			st.data[st.top++] = ten;
			st.data[st.top++] = one;
	    } else if (mod >=5 && mod < 9) {
	    	while (--mod >= 5) {
				st.data[st.top++] = one;
	    	}
			st.data[st.top++] = fiv;
	   	}
//		printf("the step result:%s, the top:%d\r\n", st.data, st.top);
		while (st.top-- > 0) {
			*res = st.data[st.top];
			res--;
		}

		pow += 2;
	}

    return res+1;
}

int main() {
	for (int i = 100 ; i < 2000; i+=100)
		printf("the integer:[%d], result:%s\r\n", i, intToRoman(i));
}
