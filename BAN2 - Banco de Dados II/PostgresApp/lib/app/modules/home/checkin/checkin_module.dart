import 'checkin_postgres_repository.dart';
import 'realizar/realizar_controller.dart';
import 'checkin_controller.dart';
import 'package:flutter_modular/flutter_modular.dart';

import 'checkin_page.dart';
import 'realizar/realizar_page.dart';

class CheckinModule extends ChildModule {
  @override
  List<Bind> get binds => [
        $RealizarController,
        $CheckinController,
      ];

  @override
  List<ModularRouter> get routers => [
        ModularRouter(Modular.initialRoute, child: (_, args) => CheckinPage()),
        ModularRouter('/realizar', child: (_, args) => RealizarPage()),
      ];

  static Inject get to => Inject<CheckinModule>.of();
}
