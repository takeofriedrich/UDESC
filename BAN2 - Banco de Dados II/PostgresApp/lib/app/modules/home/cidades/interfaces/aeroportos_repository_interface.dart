import 'package:app_mobile/app/modules/home/cidades/models/aeroporto.dart';
import 'package:flutter_modular/flutter_modular.dart';

abstract class IAeroportosRepository implements Disposable {
  Future<List<Aeroporto>> buscarAeroportos(int codC);
  Future<Aeroporto> buscarAeroporto(int codA);
}
