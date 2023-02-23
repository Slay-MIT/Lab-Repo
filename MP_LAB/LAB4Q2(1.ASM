Data Segment
     Num1 dW 1234H
     Num2 db 56H
     Quotient db ?
     Remainder db ?
Data ends

Code Segment
Assume CS:Code, DS:Data
Start:
      MOV AX, Data
      MOV DS, AX
      MOV AX, Num1
      MOV CL, Num2
      DIV CL    
      MOV Quotient, AL
      MOV Remainder, AH
      MOV AH, 4CH
      INT 21H
code ends
end start


