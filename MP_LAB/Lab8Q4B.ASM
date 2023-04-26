DATA SEGMENT
        RES DB 2 DUP(?)
        BUFFER DB 10
        LEN DB ?
        STR DB 10 DUP(?)
        MSG1 DB "ENTER THE NUM $"
        MSG2 DB 10, 13, "$"
        MSG3 DB "THE DECIMAL EQUIVALENT IS $"
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
        PRINT MSG2

        LEA DX, BUFFER
        MOV AX, 0AH
        INT 21H

	PRINT MSG3
	
	LEA SI,STR
	MOV AL, [SI]
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

