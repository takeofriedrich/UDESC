import 'package:app_mobile/app/app_controller.dart';
import 'package:app_mobile/app/modules/login/interfaces/login_repository_interface.dart';
import 'package:flutter/cupertino.dart';
import 'package:mobx/mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';

import 'models/usuario.dart';

part 'login_controller.g.dart';

@Injectable()
class LoginController = _LoginControllerBase with _$LoginController;

abstract class _LoginControllerBase with Store {
  @observable
  int value = 0;

  @action
  void increment() {
    value++;
  }

  TextEditingController caixaUsuario = TextEditingController();
  TextEditingController caixaSenha = TextEditingController();

  Future<void> login() async {
    Usuario user = await Modular.get<ILoginRepository>()
        .realizarLogin(caixaUsuario.text, caixaSenha.text);
    Modular.get<AppController>().usuario = user;
    return Modular.to.pushReplacementNamed('/home');
  }
}
