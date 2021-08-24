import 'package:app_mobile/app/modules/home/cidades/cidades_postgres_repository.dart';

import 'package:app_mobile/app/modules/home/cidades/interfaces/cidades_repository_interface.dart';
import 'package:app_mobile/app/modules/home/cidades/models/cidade.dart';
import 'package:mobx/mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';

import '../../comprar_controller.dart';

part 'selecionar_destino_controller.g.dart';

@Injectable()
class SelecionarDestinoController = _SelecionarDestinoControllerBase
    with _$SelecionarDestinoController;

abstract class _SelecionarDestinoControllerBase with Store {
  @observable
  List<Cidade> cidadesDisponiveis = [];

  @observable
  int index;

  @action
  Future<void> buscarCidades() async {
    cidadesDisponiveis =
        await Modular.get<ICidadesRepository>().buscarCidades();
    await Future.delayed(Duration(seconds: 2));
  }

  @action
  definirCidade() {
    Modular.get<ComprarController>().destino = cidadesDisponiveis[index];
    Modular.to.pop();
  }

  @action
  selectIndex(int index) {
    this.index = index;
  }
}
