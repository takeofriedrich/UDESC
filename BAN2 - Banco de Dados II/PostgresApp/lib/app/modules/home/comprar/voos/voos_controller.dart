import 'package:app_mobile/app/modules/home/comprar/trechos/trechos_controller.dart';
import 'package:app_mobile/app/modules/home/home_page.dart';
import 'package:flutter/material.dart';
import 'package:mobx/mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';

import 'models/voo.dart';

part 'voos_controller.g.dart';

@Injectable()
class VoosController = _VoosControllerBase with _$VoosController;

abstract class _VoosControllerBase with Store {
  @observable
  List<Voo> voos = [];

  @observable
  int selecionado;

  @action
  alterarVoos(List<Voo> voos) {
    this.voos = voos;
  }

  @action
  selecionarVoo(int index) {
    selecionado = index;
  }

  confirmarSelecionado() {
    Modular.get<TrechosController>().definirTrechos(voos[selecionado].trechos);
    Modular.to.pushNamed('/home/comprar/trechos');
  }

  voltar() {
    Modular.to.pushReplacementNamed('/home');
  }
}
