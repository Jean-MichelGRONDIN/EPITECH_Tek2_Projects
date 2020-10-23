BITS 64

section .text
GLOBAL strstr

strstr:
    push rbp
    mov rbp, rsp
    xor rax, rax

my_loop:
    mov cl, [rdi + rax]
    cmp cl, 0
    je notfound
    cmp cl, sil
    je found

    inc rax

    jmp my_loop

found:
    add rax, rdi
    leave
    ret

notfound:
    mov rax, 0
    leave
    ret