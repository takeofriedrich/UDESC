import 'package:app_mobile/app/modules/home/cidades/models/aeroporto.dart';

class Reserva {
  int codr;
  DateTime data;
  bool confirmada;
  Aeroporto origem = Aeroporto();
  Aeroporto destino = Aeroporto();

  Reserva(this.codr, int ano, int mes, int dia, int hora, int minuto,
      int segundo, this.confirmada) {
    this.data = DateTime(ano, mes, dia, hora, minuto, segundo);
  }

  Reserva.fromMap(Map<String, dynamic> json) {
    this.codr = json['codr_'];
    this.data = json['data_'];
    this.confirmada = json['confirmada_'];
  }

  @override
  String toString() {
    return '$codr $confirmada ${data.toString()} $origem $destino';
  }
}
