Data Segment
     Num1 dW 9123H
     Num2 dW 8678H
     Result1 dW ?
     Result2 dW ?
Data ends
Code Segment
Assume CS:Code, DS:Data
Start:
     MOV AX, Data
     MOV DS, AX
     MOV AX, Num1
     MOV BX, Num2
     IMUL BX
     MOV Result1, AX
     MOV Result2, DX
     MOV AH, 4CH
     INT 21H
code ends
end start
