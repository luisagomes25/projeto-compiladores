class Interpreter:
    def __init__(self):
        self.memory = {}

    def execute(self, ast):
        for node in ast:
            self.evaluate(node)

    def evaluate(self, node):
        if isinstance(node, GuardeNode):
            # Avalia a expressão matemática ou valor[cite: 3]
            val = self.evaluate_expr(node.expr)
            self.memory[node.name] = val
            
        elif isinstance(node, TestarNode):
            # Comandos condicionais[cite: 2]
            condicao = self.evaluate_expr(node.condition)
            if condicao:  # se for 'fiel'
                self.execute(node.if_body)
            elif node.else_body:
                self.execute(node.else_body)