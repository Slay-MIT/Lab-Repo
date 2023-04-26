GCD Macro

First: CMP AX, BX
       JA Next
       XCHG AX, BX

Next:  MOV DX, 0H
       DIV BX
       CMP DX, 0H
       JE Exit
       MOV AX, DX
       JMP First

Exit:  MOV Ans, BX
endm

Data Segment
     Num1 dW 0096H
     Num2 dW 003CH
     Ans dW ?
Data ends
Code Segment
Assume CS:Code, DS:Data
Start:   MOV AX, Data
         MOV DS, AX

         MOV AX, Num1
         MOV BX, Num2
         GCD
         MOV AH, 4CH
         INT 21H
Code ends
end start

