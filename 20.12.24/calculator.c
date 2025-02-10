#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/*
 *EXPR := TERM ([+-] TERM)* 
 *TERM := FACT (BINOP FACT)*
 *FACT := ATOM (^ FACT)* 
 *ATOM := NUMBER | '(' EXPR ')'
 *NUMBER := '-'? INTEGER | FPL | FPR
 *INTEGER := DIGIT+
 *FPL := DIGIT+ FRACTION EXP?
 *FPR := DIGIT* FRACTION DIGIT+ EXP?
 *EXP := ('e' | 'E') [+-] INTEGER
 *FRACTION := '.'
 *DIGIT := [0-9]
 */


int parse_oneof(char** str, const char* oneof, char* res){
	char* old = *str;
	if ( strchr(oneof, **str)){
		*res = **str;
		(*str) ++;
		return 1;
	}
	return 0;
}

int parse_const(char** str, const char* seq){
	char* old =*str;
	if (!strncmp(*str, seq, strlen(seq))){
	}

}

int parse_number(char** str, double*res, char** err)
{
	char* old = str;
	*res =0;
	char digit;
	if (parse_oneof(str, "0123456789", &digit)){
		*res = digit -'0';
		while(parse_oneof(str,"0123456789", &digit)){
			*res =*res  * 10 + digit - '0';
		}
		return 1;
	}
	*str = old;
	return 0;
}


int parse_atom(char** str, double* res, char** err)
{
	char* old = *str;
	if ( parce_number(str, res,err))
		return 1;
	if ( parce_const(str, "(")){
		if (calc(str, re, err)){
			if( parse_const(str, ")")) return 1;
			fprintf(stderr, "Closing ')' expecten");
			*err = *str;
			*str =old;
			return 0;
		} else {
			fprintf(stderr, "Expression expected\n");
			*err = *str;
			*str = old;
			return 0;
		}
		return 1;
	}
	*str = old;
	return 0;
}

int parse_fact(char** str, double* res, char** err){
	char* old = *str;
	if ( parse_atom(str, res, err)){
		char op;
		if(parse_oneof(str, "^", &op)){
			double e;
			if ( parse_fact(str, &e, err)){
				*res = pow(*res, e);
				return 1;
			} else {
				fprintf(stderr, "Factor expected\n");
				*err = *str;
				return 0;
			}
		}
		return 1;
	}
	*str = old;
	return 0;
}


int parse_term(char** str, double* res, char** err){
	char* old =*str;
	if(parse_fact(str, res, err)){
		char op;
		while (parse_oneof(str, "*/", &op)){
			double operand;
			if ( parse_fact(str, &operand, err)){
				switch(op){
					case '*': *res *= operand; break;
					case '/': *res /= operand; break;
					default: fprintf(stderr, "Unknown factor operand '%c'\n", op); *err = *str; return 0;
				}
			} else {
				fprintf(stderr, "Operand expected\n");
				*err = *str;
				return 0;
			}
		}
		*res = r;
		return 0;
	}
	return 1;
}



int calc(char** str, double res, char** err){
	double r;
	char* old = *str;
	if(parse_term(str, &r)){
		char op;
		while(parce_oneof(str, "+-", &op)){
			double operand;
			if(parse_term(str, &operand)){
				switch(op){
					case '+': r+= operand; break;
					case '-': r-= operand; break;
					default:
						fprintf(stderr, "unknown operand '%c'\n", op)
						*err = *str;
						return 0;
				}	
			} else {
				fprintf(stderr, "Operand expected\n");
				*err = *str;
				return 0;
			}
		}
		*res = r;
		return 0;
	}
	return 1;
}



int main(){
	char buf[2048];
	while(fgets(buf, sizeof(buf), stdin)){
		double res = 0;
		char* str = buf;
		char* errptr = NULL;
		if ( calc(buf, &res, &errptr)) {
			printf("Result: %lf\n", res);
		} else  {
			printf("Cannot parse: error at %ld\n", errptr-buf);
		}
	}
}















