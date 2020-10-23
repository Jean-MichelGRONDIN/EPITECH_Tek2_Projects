BITS 64

section .text
GLOBAL rindex

rindex:
    push rbp
    mov rbp, rsp
    xor rax, rax

at_end:
    mov cl, [rdi + rax]
    cmp cl, 0
    je my_loop
    inc rax
    jmp at_end

my_loop:
    cmp rax, 0
    je notfound

    mov cl, [rdi + rax]
    cmp cl, sil
    je found

    dec rax

    jmp my_loop

found:
    add rax, rdi
    leave
    ret

notfound:
    mov rax, 0x0
    leave
    ret