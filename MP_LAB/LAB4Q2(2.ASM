Data Segment
     Num1 dW 0d234H
     Num2 db 94H
     Q db ?
     R db ?
Data ends

Code Segment
Assume CS:Code, DS:Data
Start:
      MOV AX, Data
      MOV DS, AX
      MOV AX, Num1
      MOV CL, Num2
      IDIV CL    
      MOV Q, Al
      MOV R, ah
      MOV AH, 4CH
      INT 21H
code ends
end start


