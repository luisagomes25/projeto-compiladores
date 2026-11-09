class Node: pass

class GuardeNode(Node):
    # Representa: guarde id = expr: tipo!
    def __init__(self, name, expr, var_type):
        self.name = name
        self.expr = expr
        self.var_type = var_type

class TestarNode(Node):
    # Representa a condição: testar (condicao) abrir ... fechar[cite: 2]
    def __init__(self, condition, if_body, else_body):
        self.condition = condition
        self.if_body = if_body
        self.else_body = else_body

class DefNode(Node):
    # Representa funções definidas com 'def'
    def __init__(self, name, params, body):
        self.name = name
        self.params = params
        self.body = body