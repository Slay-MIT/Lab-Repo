Data Segment
     HEX dW 1234H
     BCD dW 2 dup(?)
Data ends
Code Segment
Assume CS:Code, DS:Data
Start:  MOV AX, Data
        MOV DS, AX
        MOV DX, 0H
        MOV AX, HEX
        MOV BX, 0AH
        DIV BX
        MOV CX, DX
        MOV DX, 0H

        DIV BX
        MOV CL, 04H
        SHL DX, CL
        ADD DX, CX
        MOV CX, DX
        ADD CL, 04H
        MOV DX, 0H

        DIV BX
        SHL DX, CL
        ADD DX, CX
        MOV CX, DX
        ADD CL, 04
        MOV DX, 0H

        DIV BX
        SHL DX, CL
        ADD DX, CX
        MOV CX, DX
        MOV BCD, AX
        MOV BCD+1, CX

        MOV AH, 4CH
        INT 21H
Code ends
end start




