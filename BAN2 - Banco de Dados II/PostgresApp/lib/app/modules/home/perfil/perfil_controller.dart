import 'package:app_mobile/app/app_controller.dart';
import 'package:mobx/mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';

part 'perfil_controller.g.dart';

@Injectable()
class PerfilController = _PerfilControllerBase with _$PerfilController;

abstract class _PerfilControllerBase with Store {
  @observable
  int value = 0;

  @action
  void increment() {
    value++;
  }

  logout() {
    Modular.get<AppController>().usuario = null;
    Modular.to.pushReplacementNamed('/');
  }
}
