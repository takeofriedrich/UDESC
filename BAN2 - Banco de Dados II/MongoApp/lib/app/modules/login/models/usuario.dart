class Usuario {
  int codp;
  String nome;

  Usuario({this.codp, this.nome});

  Usuario.fromMap(Map<String, Object> json) {
    codp = (json['_id'] as double).toInt();
    nome = json['nome'];
  }

  @override
  String toString() {
    return '$codp => $nome';
  }
}
