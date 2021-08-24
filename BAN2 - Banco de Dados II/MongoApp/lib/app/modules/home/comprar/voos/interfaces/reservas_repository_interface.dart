import 'package:flutter_modular/flutter_modular.dart';

abstract class IReservasRepository implements Disposable {
  Future fetchPost();
}
