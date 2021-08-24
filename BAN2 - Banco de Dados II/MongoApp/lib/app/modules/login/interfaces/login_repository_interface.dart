import 'package:app_mobile/app/modules/login/models/usuario.dart';
import 'package:flutter_modular/flutter_modular.dart';

abstract class ILoginRepository implements Disposable {
  Future<Usuario> realizarLogin(String usuario, String senha);
}
