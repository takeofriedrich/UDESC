import 'cidade.dart';

class Aeroporto {
  int codAp;
  String nome = '';
  Cidade cidade = Cidade();

  Aeroporto({this.nome});

  Aeroporto.fromMap(Map<String, dynamic> json) {
    nome = json['nome'];
    codAp = (json['_id'] as double).toInt();
  }
  @override
  String toString() {
    return '$nome';
  }
}
