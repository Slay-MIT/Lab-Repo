GCD macro
First: CMP AX, BX
       JA Next
       XCHG AX, BX

Next:  MOV DX, 0H
       DIV BX
       CMP DX, 0H
       JE Exit
       MOV AX, DX
       JMP First

Exit:  MOV ANS, BX
 
endm

Data Segment
     Num dW 1200H, 600H, 1800H, 300H
     ANS dW  ?
Data ends
Code Segment
Assume CS:Code, DS:Data
Start:     MOV AX, Data
           MOV DS, AX

           LEA SI, Num
           MOV AX, [SI]
           INC SI
           INC SI
           MOV CX, 3

Back:      MOV BX, [SI]
           GCD
           MOV AX, ANS
           INC SI
           INC SI
           LOOP BACK


           MOV AH, 4CH
           INT 21H


Code ends
end start
