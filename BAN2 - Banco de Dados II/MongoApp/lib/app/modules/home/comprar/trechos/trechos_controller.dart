import 'package:app_mobile/app/modules/home/comprar/assentos/assentos_controller.dart';
import 'package:app_mobile/app/modules/home/comprar/assentos/assentos_repository_interface.dart';
import 'package:app_mobile/app/modules/home/comprar/voos/models/trecho.dart';
import 'package:app_mobile/app/modules/home/home_controller.dart';
import 'package:mobx/mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';

part 'trechos_controller.g.dart';

@Injectable()
class TrechosController = _TrechosControllerBase with _$TrechosController;

abstract class _TrechosControllerBase with Store {
  @observable
  List<Trecho> trechos = [];

  @observable
  Map<int, int> assentosSelecionados = Map<int, int>().asObservable();

  Map<int, int> iniciais = Map<int, int>();

  @action
  definirTrechos(List<Trecho> trechos) {
    this.trechos = trechos;
  }

  limpar() {
    trechos = [];
    assentosSelecionados = Map<int, int>().asObservable();
    iniciais = Map<int, int>();
  }

  @action
  selecionarAssento(int trecho, int assento, int inicial) {
    assentosSelecionados[trecho] = assento;
    print(iniciais);
  }

  onTap(int index) async {
    Map<int, bool> assentos = await Modular.get<IAssentosRepository>()
        .listarAssentos(trechos[index].codT);
    print(assentos);
    iniciais[index] = assentos.entries.first.key;
    Modular.get<AssentosController>().definirAssentos(assentos);
    Modular.get<AssentosController>().definirTrecho(trechos[index]);
    Modular.get<AssentosController>().definirIndex(index);
    Modular.to.pushNamed('home/comprar/assentos');
  }

  realizarReservas() async {
    for (int trecho in assentosSelecionados.keys) {
      await Modular.get<IAssentosRepository>()
          .reservarAssento(assentosSelecionados[trecho] + iniciais[trecho] - 1);
    }
    limpar();
    Modular.to.pushNamed('/home');
  }
}
