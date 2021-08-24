import 'package:app_mobile/app/modules/home/comprar/trechos/trechos_controller.dart';
import 'package:app_mobile/app/modules/home/comprar/voos/models/trecho.dart';
import 'package:mobx/mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';

part 'assentos_controller.g.dart';

@Injectable()
class AssentosController = _AssentosControllerBase with _$AssentosController;

abstract class _AssentosControllerBase with Store {
  @observable
  Map<int, bool> assentos = {};

  int inicial = 1;

  @observable
  Trecho trecho;

  @observable
  int selecionado = 0;

  int index;

  @action
  definirAssentos(Map<int, bool> assentos) {
    this.assentos = assentos;
    inicial = this.assentos.entries.first.key;
  }

  @action
  definirTrecho(Trecho trecho) {
    this.trecho = trecho;
  }

  @action
  selecionar(int poltrona) {
    selecionado = poltrona;
  }

  definirIndex(int index) {
    this.index = index;
  }

  salvar() {
    Modular.get<TrechosController>()
        .selecionarAssento(index, selecionado, inicial);
    Modular.to.pop();
  }
}
