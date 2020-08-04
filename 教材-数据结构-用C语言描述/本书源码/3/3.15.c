hanoi(3,A,B,C)
     hanoi(2, A, C, B):
          hanoi(1, A, B, C)
 move(A->C)        1�ŰᵽC
          move(A->B)             2�ŰᵽB
          hanoi(1, C, A, B)
 move(C->B)        1�Ű�ص�B
     move(A->C)                  3�ŰᵽC
     hanoi(2,B,A,C):
          hanoi(1, B, C, A)
 move(B->A)        1�ŰᵽA
          move(B->C)             2�ŰᵽC
          hanoi(1, A, B, C)
 move(A->C)        1�ŰᵽC
