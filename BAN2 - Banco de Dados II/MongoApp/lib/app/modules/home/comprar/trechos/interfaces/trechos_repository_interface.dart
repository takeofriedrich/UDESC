import 'package:app_mobile/app/modules/home/comprar/voos/models/trecho.dart';
import 'package:flutter_modular/flutter_modular.dart';

abstract class ITrechosRepository implements Disposable {
  Future<List<Trecho>> listarTrechos(int codV);
}
