from lexer import Lexer

codigo_teste = """
sermão "Este e um comentario ignorado"
guarde nota1 = 7: total!
exibir("A nota foi:", nota1)!
"""

print("Iniciando o Interpretador Oxítona...\n")

# Testando apenas a Fase 1: Léxico
meu_lexer = Lexer(codigo_teste)
tokens_gerados = meu_lexer.tokenize()

print("--- TOKENS GERADOS PELO CÓDIGO OXÍTONA ---")
for token in tokens_gerados:
    print(token)