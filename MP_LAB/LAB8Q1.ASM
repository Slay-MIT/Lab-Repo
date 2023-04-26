printstr macro msg
LEA DX, msg
MOV AH, 09H
INT 21H
endm

printchar macro
MOV AH, 02H
INT 21H
endm


Data Segment
msg1 dB "Enter character without echo $"
msg2 dB "Entered Character without echo : $"
msg3 dB "Enter character with echo $"
msg4 dB "Entered character with echo: $"
newline dB 10, 13, "$"

Code Segment
Assume CS:Code, DS:Data
Start:      MOV AX, Data
            MOV DS, AX

            printstr msg1
            call InputWoe
            printstr newline
            printstr msg2
            MOV DL, AL
            printchar
            printstr newline

            printstr msg3
            call InputWe
            printstr newline
            printstr msg4
            MOV DL, AL
            printchar
            printstr newline
            
            MOV AH, 4CH
            INT 21H

InputWoe proc
MOV AH, 08H
INT 21H
RET
InputWoe endp

InputWE proc
MOV AH, 01H
INT 21H
RET
InputWE endp

Code ends
end start
