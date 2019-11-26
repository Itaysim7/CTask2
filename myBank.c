#include <stdio.h>
#define numberOfMembers 50
#define row 2
#define PREFIX 901
double account[row][numberOfMembers]={0};

int inputTest(int account_number){
        if(account_number<951&&account_number>900)
                return 1;
	printf("it is not a real account number\n");
        return 0;
}

double doubleInputFixer(double amount){
        amount=((int long long)(amount*100))/100.0;
        return amount;
}


void open(double amount){
	int i;
	if(amount<0){
		printf("you need to enter a positive number when you ask for the amount,the operation was not accepted\n");
		return;
	}
	for(i=0;i<50;i++){
		if(account[0][i]==0){
			account[0][i]=1;
			account[1][i]=amount;
			printf("the number of your new acount is %d \n",(i+PREFIX));
			break;
		}
	}
	if(i==50)
		printf("no avilable acount\n");
}

void balance(int account_number)
{
	if(inputTest(account_number)==1){
		if(account[0][account_number-PREFIX]==1)
			printf("your balance is %0.2lf \n",account[1][account_number-PREFIX]);
		else
			printf("this acount number is close\n");
	}
}
void deposit(int account_number,double amount){
	if(amount<0){
                printf("you need to enter a positive number when you ask for the amount,the operation was not accepted\n");
                return;
        }
	if(inputTest(account_number)==1){
		if(account[0][account_number-PREFIX]==1){
			account[1][account_number-PREFIX]+=amount;
                	printf("your balance is %0.2lf\n",account[1][account_number-PREFIX]);
		}
        	else
                	printf("this account number is close\n");
	}
}

void withdrew(int account_number,double amount){
	if(amount<0){
                printf("you need to enter a positive number when you ask for the amount,the operation was not accepted\n");
                return;
        }

	if(inputTest(account_number)==1){
		if(account[0][account_number-PREFIX]==1){
			if(account[1][account_number-PREFIX]>=amount){
				account[1][account_number-PREFIX]-=amount;
				printf("your balance is %0.2lf\n",account[1][account_number-PREFIX]);
			}
				else
					printf("you dont have enough money\n");
		}
        	else
                	printf("this account number is close\n");
	}
}
void close(int account_number){
	if(inputTest(account_number)==1){
	 	if(account[0][account_number-PREFIX]==1){
			 account[0][account_number-PREFIX]=0;
			 account[1][account_number-PREFIX]=0;
		 }
	 	else
			 printf("this account number is already close\n");
	}
}
void interest(int interest_rate){
        if(interest_rate<0||interest_rate>100){
                printf("you need to enter number between 0 and 100 when you ask for the interest rate,the operation was not accepted\n");
                return;
        }

	double percentTrans=1.0+(interest_rate/100.0);
	for(int i=0;i<50;i++){
                if(account[0][i]==1){
                   	account[1][i]=doubleInputFixer(account[1][i]*(percentTrans));
        	}
	}

}
void print(){

	for(int i=0;i<numberOfMembers;i++){
		if(account[0][i]==1){
			printf("the account number %d is open and has %0.2lf in the account\n",i+901,account[1][i]);
		}
	}
}
void exitFromAll(){
	for(int i=0;i<numberOfMembers;i++){
		account[0][i]=0;
		account[1][i]=0;
	}
}




	
