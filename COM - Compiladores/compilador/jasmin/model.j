.class public Output
.super java/lang/Object

.method public <init>()V
   aload_0
 
   invokenonvirtual java/lang/Object/<init>()V
   return
.end method

.method public static read()I
    .limit locals 10 
    .limit stack 10 
    ldc 0 
    istore 1  ; variavel que vai retornar
LabelRead1: 
    getstatic java/lang/System/in Ljava/io/InputStream; 
    invokevirtual java/io/InputStream/read()I 
    istore 2 
    iload 2 
    ldc 10   ; delimitador de nova linha 
    isub 
    ifeq LabelRead2 
    iload 2 
    ldc 32   ; delimitador de espaco
    isub 
    ifeq LabelRead2 
    iload 2 
    ldc 48   ; digitos em ASCII, é necessário subtrair 48 letra a eh a primeira
    isub 
    ldc 10 
    iload 1 
    imul 
    iadd 
    istore 1 
    goto LabelRead1 
LabelRead2: 
    ; quando um inteiro estiver na variavel 1 ele vai ser retornado
    iload 1 
    ireturn 
.end method

.method public static main([Ljava/lang/String;)V
   .limit stack 1000
   .limit locals 1000
   