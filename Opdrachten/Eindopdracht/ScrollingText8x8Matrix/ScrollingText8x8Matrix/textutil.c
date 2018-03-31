/*
* textUtil.c
*
* Created: 3/31/2018 4:26:54 PM
*  Author: Ricky Hoogerdijk && Kevin Quist
*/

#include <string.h>
#include <stdlib.h>
#include "textutil.h"
#include "ledmatrix.h"

void stringToTextArray(){

	int *text = malloc(1000 * sizeof(int));
	char data[] = "The quick brown fox jumped over the lazy dog";
	int length = strlen(data);
	
	int offset;
	for(offset = 0; offset < 8; offset++){
		text[offset] = 0x00;
	}
	
	int A[5] = {0x3e, 0x09, 0x09, 0x09, 0x3e};
	int B[5] = {0x3f, 0x25, 0x25, 0x25, 0x1a};
	int C[5] = {0x1e, 0x21, 0x21, 0x21, 0x21};
	int D[5] = {0x3f, 0x21, 0x21, 0x21, 0x1e};
	int E[5] = {0x3f, 0x25, 0x25, 0x21, 0x21};
	int F[5] = {0x3f, 0x05, 0x05, 0x05, 0x01};
	int G[5] = {0x3f, 0x21, 0x25, 0x25, 0x3d};
	int H[5] = {0x3f, 0x04, 0x04, 0x04, 0x3f};
	int I[5] = {0x21, 0x21, 0x3f, 0x21, 0x21};
	int J[4] = {0x31, 0x21, 0x21, 0x3f};
	int K[4] = {0x3f, 0x04, 0x0a, 0x31};
	int L[4] = {0x3f, 0x20, 0x20, 0x20};
	int M[5] = {0x3f, 0x01, 0x07, 0x01, 0x3f};
	int N[5] = {0x3f, 0x02, 0x04, 0x08, 0x3f};
	int O[5] = {0x3f, 0x21, 0x21, 0x21, 0x3f};
	int P[5] = {0x3f, 0x09, 0x09, 0x09, 0x06};
	int Q[5] = {0x06, 0x09, 0x09, 0x09, 0x3f};
	int R[5] = {0x3f, 0x09, 0x19, 0x29, 0x06};
	int S[5] = {0x16, 0x25, 0x25, 0x29, 0x1a};
	int T[5] = {0x01, 0x01, 0x3f, 0x01, 0x01};
	int U[5] = {0x0f, 0x10, 0x10, 0x08, 0x1f};
	int V[5] = {0x07, 0x08, 0x10, 0x08, 0x07};
	int W[5] = {0x1f, 0x20, 0x1c, 0x20, 0x1f};
	int X[5] = {0x11, 0x0a, 0x04, 0x0a, 0x11};
	int Y[5] = {0x22, 0x14, 0x08, 0x04, 0x02};
	int Z[6] = {0x41, 0x61, 0x51, 0x49, 0x45, 0x43};
	
	int i;
	for(i = 0; i < length; i++){
		char letter = tolower(data[i]);
		
		switch (letter)
		{
			case 'a':
			memcpy(text + offset, A, sizeof(A));
			offset += sizeof(A) / 2;
			break;
			case 'b':
			memcpy(text + offset, B, sizeof(B));
			offset += sizeof(B) / 2;
			break;
			case 'c':
			memcpy(text + offset, C, sizeof(C));
			offset += sizeof(C) / 2;
			break;
			case 'd':
			memcpy(text + offset, D, sizeof(D));
			offset += sizeof(D) / 2;
			break;
			case 'e':
			memcpy(text + offset, E, sizeof(E));
			offset += sizeof(E) / 2;
			break;
			case 'f':
			memcpy(text + offset, F, sizeof(F));
			offset += sizeof(F) / 2;
			break;
			case 'g':
			memcpy(text + offset, G, sizeof(G));
			offset += sizeof(G) / 2;
			break;
			case 'h':
			memcpy(text + offset, H, sizeof(H));
			offset += sizeof(H) / 2;
			break;
			case 'i':
			memcpy(text + offset, I, sizeof(I));
			offset += sizeof(I) / 2;
			break;
			case 'j':
			memcpy(text + offset, J, sizeof(J));
			offset += sizeof(J) / 2;
			break;
			case 'k':
			memcpy(text + offset, K, sizeof(K));
			offset += sizeof(K) / 2;
			break;
			case 'l':
			memcpy(text + offset, L, sizeof(L));
			offset += sizeof(L) / 2;
			break;
			case 'm':
			memcpy(text + offset, M, sizeof(M));
			offset += sizeof(M) / 2;
			break;
			case 'n':
			memcpy(text + offset, N, sizeof(N));
			offset += sizeof(N) / 2;
			break;
			case 'o':
			memcpy(text + offset, O, sizeof(O));
			offset += sizeof(O) / 2;
			break;
			case 'p':
			memcpy(text + offset, P, sizeof(P));
			offset += sizeof(P) / 2;
			break;
			case 'q':
			memcpy(text + offset, Q, sizeof(Q));
			offset += sizeof(Q) / 2;
			break;
			case 'r':
			memcpy(text + offset, R, sizeof(R));
			offset += sizeof(R) / 2;
			break;
			case 's':
			memcpy(text + offset, S, sizeof(S));
			offset += sizeof(S) / 2;
			break;
			case 't':
			memcpy(text + offset, T, sizeof(T));
			offset += sizeof(T) / 2;
			break;
			case 'u':
			memcpy(text + offset, U, sizeof(U));
			offset += sizeof(U) / 2;
			break;
			case 'v':
			memcpy(text + offset, V, sizeof(V));
			offset += sizeof(V) / 2;
			break;
			case 'w':
			memcpy(text + offset, W, sizeof(W));
			offset += sizeof(W) / 2;
			break;
			case 'x':
			memcpy(text + offset, X, sizeof(X));
			offset += sizeof(X) / 2;
			break;
			case 'y':
			memcpy(text + offset, Y, sizeof(Y));
			offset += sizeof(Y) / 2;
			break;
			case 'z':
			memcpy(text + offset, Z, sizeof(Z));
			offset += sizeof(Z) / 2;
			break;
			default:
			memcpy(text + offset, 0x00, sizeof(int));
			offset++;
			break;
			
		}
		text[offset] = 0x00;
		offset++;
	}
	
	int tempoffset = offset;
	for(offset; offset < tempoffset + 8; offset++){
		text[offset] = 0x00;
	}
	
	int x = 0;
	while(1){
		writeData(14,	text[x]);
		writeData(12,	text[x+1]);
		writeData(10,	text[x+2]);
		writeData(8,	text[x+3]);
		writeData(6,	text[x+4]);
		writeData(4,	text[x+5]);
		writeData(2,	text[x+6]);
		writeData(0,	text[x+7]);
		wait(750);			 
		if(x<offset-8){
			x++;
		}
		else{
			x = 0;
		}
	}
	
}
	



