Data Segment
     Array dB 20H, 30H, 10H, 12H, 16H, 40H, 48H, 26H, 33H
     Num db 8H
     notfound dB "Not Found $"
     found dB "Found $"
     msg1 dB 10,13, "$"
Data ends
Code Segment
Assume CS:Code, DS:Data

    Start: MOV AX, Data
           MOV DS, AX
           MOV AL, Num
           MOV CX, 12H
           LEA SI, Array
           Dec SI
          
     Back: Inc SI
           CMP AL, [SI]
           JZ Exit1
           Loop Back

    Exit0: LEA DX, notfound
           JMP Exit2

    Exit1: LEA DX, found
           JMP Exit2

    Exit2: MOV AH, 09H
           INT 21H
           MOV AH, 4CH
           INT 21H
Code ends
end start
                    
