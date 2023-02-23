Data Segment
Array1 dB 10H, 79H, 29H, 0F1H, 0B5H
Array2 dB 3 dup(?)
Data ends

Code Segment
Assume CS: Code, DS: Data
       Start: MOV AX, Data
              MOV DS, AX
              LEA SI, Array1
              ADD SI, 04
              LEA DI, Array2
              MOV CX, 05
       Back:  MOV AL, [SI]
              MOV [DI], AL
              DEC SI
              DEC DI
              LOOP BACK
       MOV AH, 4CH
       INT 21H
Code ends
end Start
