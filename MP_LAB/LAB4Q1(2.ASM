Data Segment
     Num1 dB 12H
     Num2 dB 96H
     Result dW ?
Data ends
Code Segment
Assume CS:Code, DS:Data
Start:
     MOV AX, Data
     MOV DS, AX
     MOV AL, Num1
     MOV BL, Num2
     IMUL BL
     MOV Result, AX
     MOV AH, 4CH
     INT 21H
code ends
end start
