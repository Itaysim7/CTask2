#include <stdio.h>
#include <math.h>
#include "myBank.h"

double doubleInputFixer(double);

int main(){
	char transactionType;
	double amount;
	int account_number;
	int interest_rate;	
	do{
		printf("Transaction type?\n");
		if(scanf(" %1c",&transactionType)!=1)
                        printf("illegal input for the transation type");
		else{
		        switch(transactionType){
				case 'O':
					printf("Initial deposit?\n");
                                        if(scanf(" %lf",&amount)!=1){
						printf("illegal input for amount\n");break;
					}
				        open(doubleInputFixer(amount));break;
			        case 'B':
				        printf("Account number?\n");
		         		if(scanf(" %d",&account_number)!=1){
                                                 printf("illegal input for account number\n");break;
                                        }
					balance(account_number);break;
				case 'D':
			        	printf("Account number?\n");
                                	if(scanf(" %d",&account_number)!=1){
                                                 printf("illegal input for account number\n");break;
                                        }
					printf("Initial deposit?\n");
                                	if(scanf(" %lf",&amount)!=1){
                                                printf("illegal input for amount\n");break;
                                        }

					deposit(account_number,doubleInputFixer(amount));break;
				case 'W':
			        	printf("Account number?\n");
                                	if(scanf(" %d",&account_number)!=1){
                                                 printf("illegal input for account number\n");break;
                                        }
                                	printf("Initial deposit?\n");
                                	if(scanf(" %lf",&amount)!=1){
                                                printf("illegal input for amount\n");break;
                                        }
					withdrew(account_number,doubleInputFixer(amount));break;
				case 'C':
                                	printf("Account number?\n");
                                	if(scanf(" %d",&account_number)!=1){
						 printf("illegal input for account number\n");break;
					}
					close(account_number);break;
				case 'I':   
			   		printf("Interest rate?\n");
                                	if(scanf(" %d",&interest_rate)!=1){
						 printf("illegal input for interest rate\n");break;
					}
					interest(interest_rate);break;
				case 'P':print();break;
				case 'E':exitFromAll();break;
				default:
					 printf("the letters you can enter are O,B,D,W,C,I,P and E. if you want to exit press E\n");break;
			}
		}
	}while(transactionType!='E');
}

