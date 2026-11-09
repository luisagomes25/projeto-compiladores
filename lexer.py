import re

class Lexer:
    def __init__(self, code):
        self.code = code
        self.tokens = []
        self.keywords = {
            'total', 'fração', 'sinal', 'textão', 'sermão', 'guarde', 
            'testar', 'senão', 'repetir', 'exibir', 'obter', 'fiel', 'fatal',
            'def', 'voltar', 'parar', 'pular', 'abrir', 'fechar', 'e', 'ou', 'não'
        }
        
    def tokenize(self):
        # Expressões regulares para os tokens
        token_specs = [
            ('COMMENT_MUL', r'/\*.*?\*/'),           # Comentários de bloco
            ('COMMENT_LIN', r'sermão\s+".*?"'),      # Comentários de linha
            ('STRING',      r'".*?"'),               # Textos
            ('NUMBER_FRAC', r'\d+\.\d+'),            # Reais (fração)[cite: 2]
            ('NUMBER_TOT',  r'\d+'),                 # Inteiros (total)[cite: 2]
            ('ID',          r'[A-Za-z_][A-Za-z0-9_]*'),
            ('OP_REL',      r'==|!=|>=|<=|>|<'),
            ('ASSIGN',      r'='),
            ('OP_ARITH',    r'[+\-*/%]'),
            ('PUNCT',       r'[():!]'),              # Símbolos e o terminador !
            ('WS',          r'\s+'),                 # Espaços (ignorados)[cite: 3]
        ]
        
        tok_regex = '|'.join(f'(?P<{pair[0]}>{pair[1]})' for pair in token_specs)
        for mo in re.finditer(tok_regex, self.code, re.DOTALL):
            kind = mo.lastgroup
            value = mo.group()
            
            if kind == 'WS' or kind.startswith('COMMENT'):
                continue
            if kind == 'ID' and value in self.keywords:
                kind = 'KEYWORD'
            self.tokens.append((kind, value))
            
        return self.tokens