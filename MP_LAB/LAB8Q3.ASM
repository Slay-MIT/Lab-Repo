DATA SEGMENT
        NUM DB 2 DUP(?)
        MSG1 DB "ENTER THE NO$"
        MSG2 DB 10, 13, "$"
        MSG3 DB "THE SUM IS $"
        ANS DB ?
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
        LEA SI, NUM
        MOV CX, 02

BACK:   PRINT MSG1
        PRINT MSG2
        PUSH CX
        CALL READ
        POP CX
        INC SI
        PRINT MSG2
        LOOP BACK

        
        LEA SI, NUM
        MOV AL, [SI]
        ADD AL, [SI+1]
	DAA
        MOV ANS, AL

        MOV ANS, AL
	LEA SI,ANS
        CALL DISP

        MOV AH, 4CH
        INT 21H

READ PROC
        MOV AH, 01H
        INT 21H
        MOV BL, 10H
        SUB AL, 30H
        MUL BL
        MOV BH, AL
        MOV AH, 01H
        INT 21H
        SUB AL, 30H
        ADD AL, BH
        MOV [SI], AL
        RET
READ ENDP

DISP PROC
        MOV DL, [SI]
        MOV CL, 04
        SHR DL, CL
        ADD DL, 30H
        MOV AH, 02H
        INT 21H
        MOV DL, [SI]
        AND DL, 0FH
        ADD DL, 30H
        MOV AH, 02H
        INT 21H
        RET
DISP ENDP

CODE ENDS
END START
