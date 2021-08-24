import 'package:app_mobile/app/modules/home/cidades/models/aeroporto.dart';
import 'package:app_mobile/app/modules/home/comprar/voos/models/trecho.dart';

class Voo {
  int codV;
  DateTime data;
  Aeroporto origem;
  Aeroporto destino;
  List<Trecho> trechos;
  Voo({this.codV, this.data, this.origem, this.destino, this.trechos});
  Voo.fromJson(Map<String, dynamic> json) {
    codV = json['codv'];
    data = json['data'];
  }
}
