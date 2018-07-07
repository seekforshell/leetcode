#include<stdio.h>
#include<string.h>

int romanToInt(char* s) {
	int r2i[7] = {1, 5, 10, 50, 100, 500, 1000};
	char i2r[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	int i = 0;
	int sum = 0;
	char *t_s = s;
	int s_len = strlen(t_s);
	for (int i = s_len - 1; i >= 0; i--) {
		int tmp = 0;
		if ('I' == s[i] || 'X' == s[i] || 'C' == s[i]) {
			int pos = 0;
			for (int idx = 0; idx < 7; idx+=2) {
				if (s[i] == i2r[idx]) {
					pos = idx;
					break; 
				}
			}

			tmp = r2i[pos];
			// like. VII, LX
			while (i > 0 && (i2r[pos+1] == s[i-1] || s[i] == s[i-1])) {
				if (s[i] == s[i-1]) {
					tmp += r2i[pos];
				} else {
					tmp += r2i[pos+1];
				}
				i--;
			}
			if ('I' != s[i]) {
			    // like IV
			    if (i > 0 && i2r[pos-2] == s[i-1]) {
			    	tmp -= r2i[pos-2]; 
			    	i--;
			    }
			}

			
			printf("debug::%d,i:%d\r\n", tmp, i);
		} else if ('V' == s[i] || 'L' == s[i] || 'D' == s[i]) {
			int pos = 0;
			for (int idx = 1; idx < 7; idx+=2) {
				if (s[i] == i2r[idx]) {
					pos = idx; break;
				}
			}
			tmp = r2i[pos];
			if ( i > 0 && i2r[pos-1] == s[i-1]) {
				tmp -= r2i[pos-1]; 
				i--;
			}
			printf("debug::%d,i:%d\r\n", tmp, i);
		} else if ('M' == s[i]) {
			int pos = 0;
			for (int idx = 2; idx < 7 ;idx += 2) {
				if (s[i] == i2r[idx]) {
					pos = idx; break;
				}
			}
			tmp = r2i[pos];
			if (i > 0 && i2r[pos-2] == s[i-1]) {
				tmp -= r2i[pos-2]; 
				i--;
			}

			printf("debug::-%d\r\n", tmp);

		}

		sum += tmp;
		printf("debug::%s-%d\r\n", s , tmp);
	}
	return sum;
}

int main() {
    char *s = "LVIII";
	printf("LVIII,the int is: %d \r\n", romanToInt(s));
	printf("MCMXCIV,the int is: %d \r\n", romanToInt("MCMXCIV"));
	printf("MMMCMXCIV,the int is: %d \r\n", romanToInt("MMMCMXCIV"));
	printf("XCIV,the int is: %d \r\n", romanToInt("XCIV"));
	printf("MCLXXXIV,the int is: %d \r\n", romanToInt("MCLXXXIV"));

}
