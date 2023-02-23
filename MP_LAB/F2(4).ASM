Data Segment
        num1 db 12
        num2 db ?
Data ends
Code Segment
        Assume CS:Code, DS:Data
        Start:
                mov ax,data
                mov ds,ax
                MOV AL, num1
                MOV num2, AL
                mov ah, 4ch
                int 21h

Code ends
end start
