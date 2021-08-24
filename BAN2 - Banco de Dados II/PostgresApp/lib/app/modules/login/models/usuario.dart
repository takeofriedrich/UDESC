class Usuario {
  int codp;
  String nome;

  Usuario({this.codp, this.nome});

  Usuario.fromMap(Map<String, Object> json) {
    codp = json['codp_'];
    nome = json['nome_'];
  }

  @override
  String toString() {
    return '$codp => $nome';
  }
}
