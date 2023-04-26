DATA SEGMENT
        ARR DB 2 DUP(?)
        RES DW ?
        MSG1 DB "ENTER THE NUMBER$"
        MSG2 DB 10, 13, "$"
        MSG3 DB "$"
        MSG4 DB 10, "$"
        MSG5 DB "THE NUMBERS ARE : $"
DATA ENDS

PRINT MACRO MSG
        LEA DX, MSG
        MOV AH, 09H
        INT 21H
ENDM

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
        MOV AX, DATA
        MOV DS, AX
        LEA SI, ARR
        MOV CX, 02
BACK:   PRINT MSG1
        PUSH CX
        PRINT MSG2
        CALL READ
        POP CX
        INC SI
        PRINT MSG2
        LOOP BACK

        LEA SI, ARR
        MOV CX, 02
BACK2:   PRINT MSG5
        PUSH CX
        PRINT MSG2
        CALL DISP
        POP CX
        INC SI
        PRINT MSG2
        LOOP BACK2

        LEA SI, ARR
        PRINT MSG2
        MOV AH, 0
        MOV AL, [SI]
        ADD AL, [SI+1]
        ADC AH, 0
        MOV RES, AX

        MOV [SI], AL
        CALL DISP


        MOV AH, 4CH
        INT 21H

READ PROC
        MOV AH, 01H
        INT 21H
        SUB AL, 30H
        CMP AL, 0AH
        JC DOWN
        SUB AL, 07H
DOWN:   MOV CL, 04
        SHL AL, CL
        MOV DL, AL
        MOV AH, 01H
        INT 21H
        SUB AL, 30H
        CMP AL, 0AH
        JC DOWN1
        SUB AL, 07H
DOWN1:   ADD DL, AL
        MOV [SI], DL
        RET
READ ENDP      

DISP PROC
        MOV DL, [SI]
        MOV CL, 04
        SHR DL, CL
        CMP DL, 0AH
        JC DOWN2
        ADD DL, 07H
DOWN2:  ADD DL, 30H
        MOV AH, 02H
        INT 21H
        MOV DL, [SI]
        AND DL, 0FH
        CMP DL, 0AH
        JC DOWN3
        ADD DL, 07H
DOWN3:  ADD DL, 30H
        MOV AH, 02H
        INT 21H
        RET
DISP ENDP


CODE ENDS
END START
