#include "stringslib.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

size_t str_length(const char *str) {

	int i = 0;
	if (str == NULL){
  		return 0;
	}

	while (str[i]!='\0') {
		i++;
	}
	return i;
}

int str_compare(const char *str1, const char *str2) {

	int k = str_length(str1);

	if (k<str_length(str2)) {
		k=str_length(str2);
	}


	int i =0;
	do {
		if ((int)str1[i]<(int)str2[i]) {
			return -1;
		} else {
			 if ((int)str1[i]>(int)str2[i]) {
				return 1;
			}
		}

		i++;
	} while(i<k);
	return 0;
}
	

	
	

const char *str_search(const char *haystack, const char *needle) {

	size_t i = 0;
	
	while (haystack[i] != '\0') {
	
		size_t j = 0;
		while ( (needle[j] && haystack[i + j]) && (needle[j] == haystack[i + j]) ) {
			j++;
		}
		
		if (needle[j] == '\0') {
			return haystack + i;
		}
		i++;
	}
	return NULL;
}
	



const char *str_search_first_char(const char *haystack, char needle) {

	size_t hayLength = str_length(haystack);
	
	for(int i=0;i<hayLength;i++) {
		if (haystack[i]==needle) {
			return haystack+i;
		}
	
	}
	/*
	while (haystack[i] != '\0') {
	
		size_t j = 0;
		while ( (needle[j] && haystack[i + j]) && (needle[j] == haystack[i + j]) ) {
			j++;
		}
		
		if (needle[j] == '\0') {
			return haystack + i;
		}
		i++;
	}*/
	return NULL;
}

const char *str_search_last_char(const char *haystack, char needle) {
/*
	size_t hayLength = str_length(haystack);
	size_t hayLengthReverse = 0-hayLength;
	
	for(int i=-1;i>=hayLengthReverse;i--) {
	
		if (haystack[i]==needle) {
			return haystack+(hayLength-i+1);
		}
	
	}
	*/
	size_t hayLength = str_length(haystack);
	int recup=-1;
	for(int i=0;i<hayLength;i++) {
		if(haystack[i]==needle) {
		recup = i;
		}
	}
	if (recup!=-1){
		return haystack+recup;
	} 
  return NULL;
}


size_t str_prefix_accept(const char *str, const char *chars) {

	size_t i, j;

	for (i = 0; str[i] != '\0'; i++) {

		for (j = 0; chars[j] != str[i]; j++) {

			if (chars[j] == '\0')
			return i;
		}
	}

	return i;
}

size_t str_prefix_reject(const char *str, const char *chars) {

	int i,j;
	int len = 0;

	for(i=0; str[i] !='\0'; i++) {

		for(j=0; chars[j] !='\0'; j++) {

			if(str[i] == chars[j]) {
				return len;
			}
		}

		if(str[i] == chars[j]) {
			return len;
		}
		len++;
	}
	return len;
}

int str_to_integer(const char *str) {

	int m=0;
	
	for (int i = 0 ; str[i]!='\0'; i++) {
	
		if ((str[i]<58) && (str[i]>=48) ) {
			m=m*10+str[i]-'0';
		}

	}
  return m;
  
  
}


int str_to_integer_ex(const char *str, const char **endptr, int base) {
	int i=0;
	if (base==36) {
		
		if ( (str[0]<='9') ) {

			return (str[0]-'0');

		}
		if ( (str[i]<='Z')) {

			return (str[i]-'A'+10);

		}
		if ( (str[i]<='z')) {

			return (str[i]-'a'+10);

		}
	}

	if (base==2) {
		
		int k=0;
		int test = str_length(str); //10

		if(str[i]>'1') 
			return 0;
		

		for(i=0; i<test; i++) {

			if ( (str[i]=='1') || (str[i]=='0') ) {

				int z = (test-i-1);

				k= k + ( (int) (str[i]-'0') ) * pow(2,z);

			} else {
				return 0;
		    	}
			
	    	}
  		return k; 
  
    	}
	if (base==16) {
		
		int k=0;
		int test = str_length(str); //10

		for(i=0; i<test; i++) {

			

			int z = (test-i-1);

			k= k + ( (int) (str[i]-'0') ) * pow(16,z);

			
			
	    	}
  		return k; 
  
    	}
	if (base==10) {
			
		int k=0;
		int test = str_length(str); //10
	
		if(str[i]>'9') 
			return 0;
		
  		return k; 
  
	}
}

void str_from_integer(char *dest, size_t size, int n) {
	
	int length_n = log(n)+1;
	
	if (n==0) {
		dest[0]='0';
		dest[1]='\0';
		dest[2]='X';
		return dest;
	}
	if (n<10) {
		dest[0]=n+'0';
		dest[1]='\0';
		dest[2]='X';
		return dest;
	}
	int base = 10;
	int i =0;
	
	return dest;
	
}

void str_copy(char *dest, size_t size, const char *str) {
	

	int size_str = str_length(str);

	if (size<size_str) {

		for (int i =0; i<size-1; i++) {
			dest[i]=str[i];
		}
		
		dest[size-1]='\0';
	} else{
		
		
		for (int i =0; i<size_str; i++) {

			dest[i]=str[i];

		}
		
		dest[size_str]='\0';
	}
}

char *str_duplicate(const char *str) {

	int str2_length = str_length(str);

	char *str2 = calloc(str2_length, sizeof(char));

	if (str2 != NULL) {
		for (int i =0; i<str2_length; i++) {

			str2[i]=str[i];

		}
		str2[str2_length]='\0';

		return str2;
	}
	return NULL;

}

void str_concat_string(char *dest, size_t size, const char *str) {
}

void str_concat_char(char *dest, size_t size, char c) {
	if (dest[0]=='\0') {
	dest[0]=c;
	dest[1]='\0';
	} else {
		int i = 0 ;
		while (dest[i]!='\0') {
			i++;
		}
		dest[i]=c;
		dest[i+1]='\0';				
	}
}

void str_concat_integer(char *dest, size_t size, int n) {
}

void str_concat_array(char *dest, size_t size, const char *args[], char separator) {
}

char *str_join_string(const char *str1, const char *str2, char separator) {
  return NULL;
}

char *str_join_array(const char *args[], char separator) {
  return NULL;
}
