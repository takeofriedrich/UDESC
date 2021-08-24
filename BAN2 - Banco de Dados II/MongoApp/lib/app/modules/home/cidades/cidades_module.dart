import 'aeroportos_mongo_repository.dart';
import 'cidades_mongo_repository.dart';
import 'package:dio/dio.dart';
import 'package:app_mobile/app/modules/home/cidades/aeroportos/aeroportos_page.dart';

import 'aeroportos/aeroportos_controller.dart';
import 'cidades_controller.dart';
import 'package:flutter_modular/flutter_modular.dart';

import 'cidades_page.dart';

class CidadesModule extends ChildModule {
  @override
  List<Bind> get binds => [
        $AeroportosMongoRepository,
        $CidadesMongoRepository,
        $CidadesMongoRepository,
        $AeroportosController,
        $CidadesController,
      ];

  @override
  List<ModularRouter> get routers => [
        ModularRouter(Modular.initialRoute, child: (_, args) => CidadesPage()),
        ModularRouter('/aeroportos', child: (_, args) => AeroportosPage()),
      ];

  static Inject get to => Inject<CidadesModule>.of();
}
