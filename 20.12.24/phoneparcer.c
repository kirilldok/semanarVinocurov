#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _match{
	char* start;
	char* end;
} Match;


int parce_phone(char** str, Match* m){
	char* old = *str;
	Match country_code = {0, 0};
	Match local_phone;
	parce_const(str, "+"),
	int res = parce_country_code(str, &country_code);
	if ( res ) {
		m->start = country_code.start;
	} else {
		if(res =  parce_local_phone(str, &local_phone)){
			m->start = !m->start? local_phone.start:m->start;
			m->end = local_phone.end;
			return 1;
		} else {
			*str = old;
		}		
	}
	return res;

}


int parce_const(char** str, const char* seq)
{
	char* old = *str;
	if(!strncmp(*str, seq, strlen(seq))){
		(*str) += strlen(seq);
		return 1;
	}
	*str = old;
	return 0;
}

int parce_country_code(char** str, Match* m)
{
	char* old = *str;
	int county;
	Match city_code;
	m->start = 0;
	if( parce_country_number(str, m), 
			parce_city_code(str, m))
	{
		*m = city_code;
		return 1;
	}
	*str = old;
	return 0;
}


int parce_city_code(char** str, Match* m){
	char* old = *str;
	if ( parce_parenthized(str, m) 
			|| parce_digits(str, m))
		return 1;
	*str = old;
	return 0;
}

int parce_parenthized(char** str, Match* m){
	if ( parce_const(str, "(")
			&& parce_digits(str, m)
			&& parce_const(str, ")"))
		return 1;
	*str = old;
	return 0;
}


int parce_range(char** str, char from, char to){
	char* old = *str;
	if (**str <= to && **str >= from){
		(*str) ++;
		return 1;
	}
	*str = old;
	return 0;
}

int parce_digits(char** str, Match* m){
	char* old = *str;
	
	if ( perce_range(str, '0', '9')){
		m->start = m->start?m->start:(*str) - 1;
		m->end = (*str) + 1;
		parce_digits(str, m);
		return 1;
	}
	*str = old;
	return 0;

}


int parce_local_phone(char** str, Match* m)
{
	m->start = 0;
	if ( parce_digits(str, m)){
		while(parce_const(str, "-") && parce_digits(str, m))
		return 1;
	}
	return 0;
}

int parce_country_number(char** str, Match* m){
	return parce_digits(str, m);
}



int main()
{
	char buf[2048];
	if ( fgets(buf, sizeof(buf), stdin)){
		Match m;
		char* str =buf;
		if (parce_phone(str, m)){
			printf("Phone parsed: %.*s\n",(int)( m.end-m.start), m.start);
		} else {
			prinft(" not a phone number\n");
		}
	}

}
