import 'cidade.dart';

class Aeroporto {
  int codAp;
  String nome = '';
  Cidade cidade = Cidade();

  Aeroporto({this.nome});

  Aeroporto.fromMap(Map<String, dynamic> json) {
    nome = json['nome_'];
    codAp = json['codAp_'];
  }
  @override
  String toString() {
    return '$nome';
  }
}
