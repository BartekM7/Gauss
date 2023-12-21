#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	double v[mat->r+1][mat->c];
	for(int i = 0; i < mat->c ; i++){
		for(int j = 0; j < mat->r; j++){
			v[j][i]=mat->data[j][i];
		}
	}
	for(int k = 0; k<mat->c; k++){
		v[mat->r+1][k]=mat->data[1][k];
	}
	for(int l = 0; l<mat->r; l++){
		for(int m = l+1; m<mat->r;m++){
			if(v[l][l]==0){
				return 1;
			}else{
				double x = v[m][l]/v[l][l];
				for(int h = l; h<= mat->r; h++){
					v[m][h] -= x * v[l][h];
				}
			}
		}
	}
	return 0;
}

