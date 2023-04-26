DATA SEGMENT
        NUM DB ?
        RES DB 2 DUP(?)
        MSG1 DB "ENTER THE NO $"
        MSG2 DB 10, 13, "$"
        MSG3 DB "THE DECIMAL EQUIVALENT IS : $"
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

        PRINT MSG1
	CALL READ

        PRINT MSG2
        PRINT MSG3

        MOV AL, NUM
        CALL CONVERT
	
	LEA SI,RES+1
	CALL DISP
	LEA SI,RES
	CALL DISP
        
        MOV AH,4CH
        INT 21H

CONVERT PROC
        MOV AH, 0
        MOV BL, 0AH
        DIV BL
        MOV DL, AH
        MOV AH, 0
        DIV BL
        MOV RES+1, AL
        MOV CL, 4
        SHL AH, CL
        ADD AH, DL
        MOV RES, AH
        RET
CONVERT ENDP

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
        MOV NUM, DL
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
