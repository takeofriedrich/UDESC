import 'package:app_mobile/app/modules/home/cidades/aeroportos/aeroportos_controller.dart';
import 'package:app_mobile/app/modules/home/cidades/interfaces/cidades_repository_interface.dart';
import 'package:mobx/mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';

import 'models/cidade.dart';

part 'cidades_controller.g.dart';

@Injectable()
class CidadesController = _CidadesControllerBase with _$CidadesController;

abstract class _CidadesControllerBase with Store {
  @observable
  List<Cidade> cidades = [];

  @action
  Future<void> buscarCidades() async {
    cidades = await Modular.get<ICidadesRepository>().buscarCidades();
    await Future.delayed(Duration(seconds: 2));
  }

  navegarParaAeroportos(int i) {
    Modular.get<AeroportosController>().cidade = cidades[i];
    Modular.to.pushNamed('/home/cidades/aeroportos');
  }
}
