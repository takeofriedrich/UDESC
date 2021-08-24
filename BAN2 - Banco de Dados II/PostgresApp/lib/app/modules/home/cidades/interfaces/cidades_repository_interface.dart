import 'package:app_mobile/app/modules/home/cidades/models/cidade.dart';
import 'package:flutter_modular/flutter_modular.dart';

abstract class ICidadesRepository implements Disposable {
  Future<List<Cidade>> buscarCidades();

  Future<Cidade> buscarCidade(int cod);
}
