import 'package:cloud_firestore/cloud_firestore.dart';

import 'package:mobx/mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:molhei_o_pe/app/modules/home/mapas/mapas_repository.dart';
import 'package:molhei_o_pe/app/modules/home/models/ocorrencia.dart';

part '../mapas_controller.g.dart';

@Injectable()
class MapasController = _MapasControllerBase with _$MapasController;

abstract class _MapasControllerBase with Store {
  MapasRepository repository = Modular.get<MapasRepository>();

  @observable
  ObservableList<Ocorrencia> ocorrencias = ObservableList<Ocorrencia>();

  _MapasControllerBase() {
    repository.buscarRegiao(this.onData);
  }

  onData(DocumentSnapshot event) {
    ocorrencias.clear();
    if (event != null)
      event.data().forEach((key, value) async {
        Ocorrencia o = Ocorrencia.fromJson(value);
        if (value['img'] == null)
          repository.buscarFoto(repository.data(), key).then((value) {
            o.img = value;
          });
        o.uid = key;
        add(o);
      });
  }

  @action
  void add(Ocorrencia o) => ocorrencias.add(o);

  @override
  dispose() {
    repository.cancel();
  }
}
