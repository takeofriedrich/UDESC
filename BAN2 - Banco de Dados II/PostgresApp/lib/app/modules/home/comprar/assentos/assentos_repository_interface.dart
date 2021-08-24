import 'package:flutter_modular/flutter_modular.dart';

abstract class IAssentosRepository implements Disposable {
  Future<Map<int, bool>> listarAssentos(int codT);
  Future<void> reservarAssento(int coda);
}
