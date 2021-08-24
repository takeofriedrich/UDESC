import 'package:app_mobile/app/modules/home/cidades/models/aeroporto.dart';

class Trecho {
  int codT;
  DateTime data;
  Aeroporto origem;
  Aeroporto destino;
  int assentosDisponiveis;
  int assentosTotais;
  Trecho(
      {this.codT,
      this.data,
      this.origem,
      this.destino,
      this.assentosDisponiveis,
      this.assentosTotais});
  Trecho.fromJson(Map<String, dynamic> json) {
    this.codT = json['codtr_'];
    this.data = json['data_'];
  }
}
