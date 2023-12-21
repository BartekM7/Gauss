#include "gauss.h"

/**
 * Zwraca 0 - eliminacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b) {
    double v[mat->r + 1][mat->c];

    for (int i = 0; i < mat->c; i++) {
        for (int j = 0; j < mat->r; j++) {
            v[j][i] = mat->data[j][i];
        }
    }
    for (int k = 0; k < mat->c; k++) {
        v[mat->r][k] = b->data[k][0];
    }

    for (int l = 0; l < mat->r; l++) {
        int pR = l;
        for (int i = l + 1; i < mat->r; i++) {
            if (fabs(v[i][l]) > fabs(v[pR][l])) {
                pR = i;
            }
        }
        for (int i = 0; i < mat->c; i++) {
            double temp = v[l][i];
            v[l][i] = v[pR][i];
            v[pR][i] = temp;
        }
        for (int m = l + 1; m < mat->r; m++) {
            if (v[l][l] == 0) {
                return 1;
            } else {
                double x = v[m][l] / v[l][l];
                for (int h = l; h <= mat->r; h++) {
                    v[m][h] -= x * v[l][h];
                }
            }
        }
    }
    for (int i = 0; i < mat->c; i++) {
        for (int j = 0; j < mat->r; j++) {
            mat->data[j][i] = v[j][i];
        }
    }
    for (int k = 0; k < mat->c; k++) {
        b->data[k][0] = v[mat->r][k];
    }

    return 0;
}

