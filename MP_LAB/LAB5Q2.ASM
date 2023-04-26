Data Segment
     Hex dB 0FFH
     BCD dB ?
Data ends
Code Segment
Assume CS:Code, DS:Data
Start:    MOV AX, Data
          MOV DS, AX

          MOV AL, HEX
          MOV AH, 0H
          MOV BL, 0AH
          DIV BL
          MOV BH, AH
          MOV AH, 00H
          DIV BL
          MOV BCD+1, AL
          MOV CL, 04H
          SHL AH, CL
          ADD AH, BH
          MOV BCD, AH
          MOV AH, 4CH
          INT 21H
Code ends
End Start


        
