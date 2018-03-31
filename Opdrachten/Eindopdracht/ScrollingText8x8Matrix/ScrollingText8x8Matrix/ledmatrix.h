/*
 * ledmatrix.h
 *
 * Created: 3/31/2018 2:21:55 PM
 *  Author: Ricky
 */ 


#ifndef LEDMATRIX_H_
#define LEDMATRIX_H_

void writeData(int, int);
void wait(int);
void twi_tx(unsigned char);
void twi_stop(void);
void twi_start(void);
void twi_init(void);



#endif /* LEDMATRIX_H_ */