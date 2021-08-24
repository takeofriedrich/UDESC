import 'package:app_mobile/app/modules/home/perfil/perfil_page.dart';

import 'checkin/checkin_controller.dart';
import 'comprar/trechos/trechos_controller.dart';
import 'perfil/perfil_controller.dart';
import 'package:app_mobile/app/modules/home/checkin/checkin_module.dart';
import 'package:app_mobile/app/modules/home/cidades/cidades_module.dart';
import 'package:app_mobile/app/modules/home/comprar/comprar_module.dart';

import 'home_controller.dart';
import 'package:flutter_modular/flutter_modular.dart';

import 'home_page.dart';

class HomeModule extends ChildModule {
  @override
  List<Bind> get binds => [
        $PerfilController,
        $HomeController,
        $TrechosController,
        $CheckinController,
      ];

  @override
  List<ModularRouter> get routers => [
        ModularRouter(Modular.initialRoute, child: (_, args) => HomePage()),
        ModularRouter('/cidades', module: CidadesModule()),
        ModularRouter('/comprar', module: ComprarModule()),
        ModularRouter('/checkin', module: CheckinModule()),
        ModularRouter('/perfil', child: (_, args) => PerfilPage()),
      ];

  static Inject get to => Inject<HomeModule>.of();
}
