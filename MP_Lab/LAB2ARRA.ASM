Data Segment
array1 dB 10H, 26H, 0B1H, 15H, 0C5H
array2 dB 5 dup(?)
Data ends

Code Segment
Assume CS: code, ds: data
Start: MOV Ax, Data
       MOV DS, AX
       LEA SI, array1
       LEA DI, array2
       MOV CX, 05
       BACK: MOV AL, [SI]
             MOV [DI], AL
             INC SI
             INC DI
             LOOP BACK
       MOV AH, 4CH
       INT 21H
code ends
end start
                                                   
