BITS 64

section .text
GLOBAL strcmp

strcmp:
    push rbp
    mov rbp, rsp
    xor rax, rax

my_loop:
    mov cl, [rdi + rax]
    cmp cl, 0
    je end

    mov ch, [rsi + rax]
    cmp ch, 0
    je end

    cmp cl, ch
    je extension

    jmp end

extension:
    inc rax
    jmp my_loop

end:
    mov rcx, rax
    mov r8b, [rdi + rcx]
    mov r9b, [rsi + rcx]
    sub r8b, r9b
    movzx rax, r8b
    leave
    ret