Data segment
array1 db 10h, 79h, 29h, 0f1h, 0b5h
array2 db 11h, 80h, 30h, 0f2h, 0b6h
data ends
code segment
assume cs: code, ds: data
start: mov ax, data
       mov ds, ax
       lea si, array1
       lea di, array2
       mov cx, 5
       back: mov al, [si]
             mov bl, [di]
             mov [di], al
             mov [si], bl
             inc si
             inc di
             loop back
       mov ah, 4ch
       int 21h
code ends
end start
