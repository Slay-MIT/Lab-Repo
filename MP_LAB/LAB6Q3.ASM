Data Segment
     Num1 dB 25H
     Num2 dB 15H
     Ans db ?
Data ends
Code Segment
Assume CS:Code, DS:Data
Start:   MOV AX, Data
         MOV DS, AX

         MOV AL, Num1
         MOV BL, Num2

         call LCM

         MOV Ans, DL
         MOV AH, 4CH
         INT 21H


LCM Proc

First: CMP AL, BL
       JA Next
       XCHG AL, BL

Next:  MOV DL, AL
       MOV CL, AL
       MOV AH, 0H
       DIV BL
       CMP AH, 0H
       JE Last
       MOV AL, DL
       ADD AL, CL
       JMP Next
Last:  MOV Ans, DL
       RET
LCM endp
       
code ends
end start
