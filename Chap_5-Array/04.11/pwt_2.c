// #include "tsmatrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool add_matrix(const TSMatrix* pM, const TSMatrix* pN, TSMatrix* pQ)
{
    int p = 0, q = 0, t = 0;
    if (pM->m != pN->m || pM->n != pN->n)
        return false;

    pQ->m = pM->m;
    pQ->n = pN->n;

    while (p <= pM->len - 1 && q <= pN->len - 1) {
        if (pM->data[p].i == pN->data[q].i && pM->data[p].j == pN->data[q].j) {
            if (pM->data[p].e + pN->data[q].e == 0) {
                p++;
                q++;
            } else {
                pQ->data[t].i = pM->data[p].i;
                pQ->data[t].j = pM->data[p].j;
                pQ->data[t].e = pM->data[p].e + pN->data[q].e;
                p++;
                q++;
                t++;
            }
        }

        else if (pM->data[p].i == pN->data[q].i && pM->data[p].j < pN->data[q].j) {
            while (pM->data[p].i == pN->data[q].i && pM->data[p].j < pN->data[q].j) {
                pQ->data[t].i = pM->data[p].i;
                pQ->data[t].j = pM->data[p].j;
                pQ->data[t].e = pM->data[p].e;
                p++;
                t++;
                break;
            }
        }

        else if (pM->data[p].i == pN->data[q].i && pM->data[p].j > pN->data[q].j) {
            while (pM->data[p].i == pN->data[q].i && pM->data[p].j > pN->data[q].j) {
                pQ->data[t].i = pN->data[q].i;
                pQ->data[t].j = pN->data[q].j;
                pQ->data[t].e = pN->data[q].e;
                q++;
                t++;
                break;
            }
        }

        else if (pM->data[p].i > pN->data[q].i) {
            while (pN->data[q].i < pM->data[p].i) {
                pQ->data[t].i = pN->data[q].i;
                pQ->data[t].j = pN->data[q].j;
                pQ->data[t].e = pN->data[q].e;
                q++;
                t++;
                break;
            }
        }

        else if (pM->data[p].i < pN->data[q].i) {
            while (pN->data[q].i > pM->data[p].i) {
                pQ->data[t].i = pM->data[p].i;
                pQ->data[t].j = pM->data[p].j;
                pQ->data[t].e = pM->data[p].e;
                p++;
                t++;
                break;
            }
        }
    }

    if (p == pM->len) {
        while (q <= pN->len - 1) {
            pQ->data[t].i = pN->data[q].i;
            pQ->data[t].j = pN->data[q].j;
            pQ->data[t].e = pN->data[q].e;
            q++;
            t++;
        }
    }

    else if (q == pN->len) {
        while (p <= pM->len - 1) {
            pQ->data[t].i = pM->data[p].i;
            pQ->data[t].j = pM->data[p].j;
            pQ->data[t].e = pM->data[p].e;
            p++;
            t++;
        }
    }

    pQ->len = t;
    return true;
}
