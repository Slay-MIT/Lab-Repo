Data Segment
Array1 dw 7078H, 7A90H, 89B9H, 902FH, 9822H
Array2 dw 5 dup(?)
Data ends
Code Segment
Assume CS: Code, DS: Data
       Start: MOV AX, Data
              MOV DS, AX
              LEA SI, Array1
              LEA DI, Array2
              MOV CX, 5
       Back: MOV AX, [SI]
             MOV [DI], AX
             INC SI
             INC SI
             INC DI
             INC DI
             LOOP BACK
       MOV AH, 4CH
       INT 21H
Code ends
end Start
