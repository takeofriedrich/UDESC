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
    this.codr = (json['_id'] as double).toInt();
    this.data = json['data'];
    this.confirmada = json['confirmada'] == 'true' ? true : false;
  }

  @override
  String toString() {
    return '$codr $confirmada ${data.toString()} $origem $destino';
  }
}
