#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	if (mat->r != mat->c || mat->r != b->r || x->r != b->r || x->c != 1) {
        // Błędne rozmiary macierzy
        return 2;
    }

    int n = mat->r; // Rozmiar macierzy
    int i, j;

    
    for (i = n - 1; i >= 0; i--) {
        if (mat->data[i][i] == 0) {
            // Błąd dzielenia przez 0 (element na diagonali = 0)
            return 1;
        }
        x->data[i][0] = b->data[i][0] / mat->data[i][i]; // Obliczenie niewiadomej
        for (j = i + 1; j < n; j++) {
            b->data[i][0] -= mat->data[i][j] * x->data[j][0]; // Skorygowanie prawej strony
        }
    }

    return 0; // Wsteczne podstawienie zakończone sukcesem
}


