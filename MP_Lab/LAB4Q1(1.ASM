Data Segment
     Num1 dW 1234H
     Num2 dW 5678H
     result1 dW ?
     result2 dW ?
Data ends

Code Segment
Assume CS:Code, DS:Data
Start:
      MOV AX, Data
      MOV DS, AX
      MOV AX, Num1
      MOV BX, Num2
      MUL BX    
      MOV result1, AX
      MOV result2, DX
      MOV AH, 4CH
      INT 21H
code ends
end start


