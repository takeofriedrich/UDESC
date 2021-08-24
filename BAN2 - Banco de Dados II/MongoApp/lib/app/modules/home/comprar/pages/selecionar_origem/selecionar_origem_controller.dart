import 'package:app_mobile/app/modules/home/cidades/cidades_controller.dart';
import 'package:app_mobile/app/modules/home/cidades/interfaces/cidades_repository_interface.dart';
import 'package:app_mobile/app/modules/home/cidades/models/cidade.dart';
import 'package:app_mobile/app/modules/home/comprar/comprar_controller.dart';
import 'package:mobx/mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';

part 'selecionar_origem_controller.g.dart';

@Injectable()
class SelecionarOrigemController = _SelecionarOrigemControllerBase
    with _$SelecionarOrigemController;

abstract class _SelecionarOrigemControllerBase with Store {
  @observable
  List<Cidade> cidadesDisponiveis = [];

  @observable
  int index;

  @action
  Future<void> buscarCidades() async {
    cidadesDisponiveis =
        await Modular.get<ICidadesRepository>().buscarCidades();
    return Future.delayed(Duration(seconds: 2)).whenComplete(() => null);
  }

  @action
  definirCidade() {
    Modular.get<ComprarController>().origem = cidadesDisponiveis[index];
    Modular.to.pop();
  }

  @action
  selectIndex(int index) {
    this.index = index;
  }
}
