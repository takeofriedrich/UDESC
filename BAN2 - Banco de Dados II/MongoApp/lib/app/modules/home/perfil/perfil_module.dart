import 'perfil_controller.dart';
import 'package:flutter_modular/flutter_modular.dart';

import 'perfil_page.dart';

class PerfilModule extends ChildModule {
  @override
  List<Bind> get binds => [
        $PerfilController,
      ];

  @override
  List<ModularRouter> get routers => [
        ModularRouter(Modular.initialRoute, child: (_, args) => PerfilPage()),
      ];

  static Inject get to => Inject<PerfilModule>.of();
}
