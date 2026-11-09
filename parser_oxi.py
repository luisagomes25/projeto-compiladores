class Parser:
    def __init__(self, tokens):
        self.tokens = tokens
        self.pos = 0

    def match(self, expected_kind, expected_value=None):
        if self.pos < len(self.tokens):
            kind, value = self.tokens[self.pos]
            if kind == expected_kind and (expected_value is None or value == expected_value):
                self.pos += 1
                return value
        raise SyntaxError(f"Erro sintático: esperado {expected_value or expected_kind}")

    def parse(self):
        statements = []
        while self.pos < len(self.tokens):
            statements.append(self.parse_statement())
        return statements

    def parse_statement(self):
        kind, value = self.tokens[self.pos]
        
        if kind == 'KEYWORD' and value == 'guarde':
            # Formato: guarde base = 10: total!
            self.match('KEYWORD', 'guarde')
            var_name = self.match('ID')
            self.match('ASSIGN', '=')
            expr = self.parse_expression()
            self.match('PUNCT', ':')
            var_type = self.match('KEYWORD') # total, fração, etc[cite: 1]
            self.match('PUNCT', '!') # Toda instrução termina com ![cite: 3]
            return GuardeNode(var_name, expr, var_type)
            
        elif kind == 'KEYWORD' and value == 'def':
            # Declaração de função
            self.match('KEYWORD', 'def')
            func_name = self.match('ID')
            self.match('PUNCT', '(')
            params = self.parse_params()
            self.match('PUNCT', ')')
            self.match('KEYWORD', 'abrir')
            body = self.parse_block()
            self.match('KEYWORD', 'fechar')
            return DefNode(func_name, params, body)
            
        # ... (Outros comandos como testar, exibir, repetir)
        
    def parse_expression(self):
        # Implementação de precedência de operadores[cite: 2]
        # Parênteses > aritméticos > relacionais > lógicos[cite: 2]
        pass
        
    def parse_block(self):
        # Lê comandos até encontrar 'fechar'
        pass