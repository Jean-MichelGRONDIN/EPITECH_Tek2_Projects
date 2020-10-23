BITS 64

extern to_lower_case

section .text
GLOBAL strcasecmp

strcasecmp:
    push rbp
    mov rbp, rsp
    xor rax, rax

get_chars:
    mov cl, [rdi + rax]
    mov ch, [rsi + rax]

    cmp cl, 0
    je end

    cmp ch, 0
    je end

put_lower_cl:
    cmp cl, 'A'
    jb put_lower_ch
    cmp cl, 'Z'
    ja put_lower_ch
    add cl, 0x20

put_lower_ch:
    cmp ch, 'A'
    jb compare_part
    cmp ch, 'Z'
    ja compare_part
    add ch, 0x20


compare_part:
    cmp cl, ch
    je extension

    jmp end

extension:
    inc rax
    jmp get_chars

end:
    mov rcx, rax
    mov r8b, [rdi + rcx]
    mov r9b, [rsi + rcx]
    sub r8b, r9b
    movzx rax, r8b
    leave
    ret