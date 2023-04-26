Data Segment
     BCD dW 1234H
     HEX dW ?
Data Ends

Code Segment
     Assume CS:Code, DS:Data
Start: MOV AX,Data
       MOV DS,AX
       CLC
       MOV AX, BCD
       MOV BX, 0AH
       MOV CL, 04H
       AND AX, 000FH
       ADC HEX, AX
       MOV AX, BCD
       AND AX, 00F0H
       SHR AX, CL
       MUL BX
       ADD HEX, AX
       MOV CL, 08H
       MOV AX, 0AH
       MUL BX
       MOV BX, AX
       MOV AX, BCD
       AND AX, 0F00H
       SHR AX, CL
       MUL BX
       ADD HEX, AX
       MOV AX, 000AH
       MUL BX
       MOV BX, AX
       MOV AX, BCD
       ADD CL, 04H
       AND AX, 0F000H
       SHR AX, CL
       MUL BX
       ADD HEX, AX
       MOV AH, 4CH
       INT 21H
Code Ends
End Start

       

