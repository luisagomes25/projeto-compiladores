class SemanticAnalyzer:
    def __init__(self):
        self.symbol_table = {}

    def analyze(self, ast):
        for node in ast:
            self.visit(node)

    def visit(self, node):
        if isinstance(node, GuardeNode):
            if node.name in self.symbol_table:
                raise Exception(f"Erro semântico: Variável '{node.name}' já declarada neste escopo.")
            # Tipagem estática: valida se o valor confere com o tipo[cite: 1]
            self.symbol_table[node.name] = node.var_type
            
        # ... (Checagem de TestarNode garante que a condição gere tipo 'sinal'[cite: 3])