import 'package:app_mobile/app/app_controller.dart';
import 'package:app_mobile/app/modules/home/checkin/models/reserva.dart';
import 'package:app_mobile/app/modules/home/checkin/realizar/realizar_controller.dart';
import 'package:mobx/mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';

import 'interfaces/checkin_repository_interface.dart';

part 'checkin_controller.g.dart';

@Injectable()
class CheckinController = _CheckinControllerBase with _$CheckinController;

abstract class _CheckinControllerBase with Store {
  ICheckinRepository repository = Modular.get<ICheckinRepository>();

  @observable
  List<Reserva> reservas = [];

  Future<void> buscarReservas() async {
    print(Modular.get<AppController>().usuario.codp);
    List<Reserva> value = await repository
        .listarReservas(Modular.get<AppController>().usuario.codp);
    setReservas(value);
  }

  @action
  setReservas(value) => reservas = value;

  realizarCheckin(Reserva reserva) {
    Modular.get<RealizarController>().reserva = reserva;
    Modular.to.pushReplacementNamed('/home/checkin/realizar');
  }
}
