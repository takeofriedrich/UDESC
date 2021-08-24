import 'package:app_mobile/app/modules/home/checkin/checkin_controller.dart';
import 'package:app_mobile/app/modules/home/checkin/interfaces/checkin_repository_interface.dart';
import 'package:app_mobile/app/modules/home/checkin/models/reserva.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:mobx/mobx.dart';

part 'realizar_controller.g.dart';

@Injectable()
class RealizarController = _RealizarControllerBase with _$RealizarController;

abstract class _RealizarControllerBase with Store {
  Reserva reserva;

  void efetuar() {
    print(reserva.codr);
    Modular.get<ICheckinRepository>()
        .realizarCheckin(reserva.codr)
        .whenComplete(() {
      Modular.get<CheckinController>()
          .buscarReservas()
          .whenComplete(() => Modular.to.pushReplacementNamed('/home/'));
    });
  }
}
