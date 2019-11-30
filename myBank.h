#ifndef _MYBANK_H_
#define _MYBANK_H_
#define numberOfMembers 50
#define row 2
#define PREFIX 901
extern double account[row][numberOfMembers];


void open(double);
void balance(int);
void deposit(int,double);
void withdrew(int,double);
void close(int);
void interest(int);
void print();
void exitFromAll();

#endif
