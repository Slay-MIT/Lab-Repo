Code Segment

Assume CS:Code
Start:
    MOV BL,8AH
    MOV CL,BL
    MOV AH, 4CH
    INT 21H
code ends
end start                 
