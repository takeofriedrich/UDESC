import 'package:app_mobile/app/modules/home/cidades/models/aeroporto.dart';

class Cidade {
  int codC;
  String nome = '';
  List<Aeroporto> aeroportos = [];

  Cidade({this.nome});

  Cidade.fromMap(Map<String, dynamic> json) {
    nome = json['nome'];
    codC = (json['_id'] as double).toInt();
  }

  @override
  String toString() {
    return nome;
  }
}
