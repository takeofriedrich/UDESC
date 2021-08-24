import 'package:app_mobile/app/modules/home/checkin/models/reserva.dart';
import 'package:flutter_modular/flutter_modular.dart';

abstract class ICheckinRepository implements Disposable {
  Future<List<Reserva>> listarReservas(int codp);

  Future<void> realizarCheckin(int codr);
}
