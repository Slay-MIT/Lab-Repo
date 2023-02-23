Data Segment
        num1 dw 0A912H
        num2 dw ?
Data ends
Code Segment
        Assume CS:Code, DS:Data
        Start:
                mov ax,data
                mov ds,ax
                MOV AX, num1
                MOV num2, AX
                mov ah, 4ch
                int 21h

Code ends
end start
